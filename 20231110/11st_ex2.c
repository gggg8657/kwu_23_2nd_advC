#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct categories{
    float price;
    char name[100];
    int ID;
};

struct order_list{
    struct categories *menu;
    struct categories *dessert, *drinks;
    int count;
};

struct struct_cafe{
    struct categories *dessert, *drinks;
    struct order_list *order;
};

struct struct_cafe cafe_ptr;
// Function declarations
void print_receipt(struct struct_cafe *tmp);
void print_drink_board(struct struct_cafe *tmp);
void print_dessert_board(struct struct_cafe *tmp);
void print_menu_board(struct struct_cafe *tmp);
void drink_count(int alpha, struct struct_cafe cafe_ptr);
void dessert_count(int beta, struct struct_cafe cafe_ptr);
void read_menu_from_file(const char *filename, struct categories *menu, int menu_size);
void initial_menulist(struct struct_cafe *cafe);


int main() {
    
    initial_menulist(&cafe_ptr);

    int alpha=0;
    int beta=0;

    while(1){

        printf("\n1. 음료 주문하기\n2. 디저트 주문하기\n0. 종료\t\t::\t");
        int input;    
        scanf("%d", &input);

        switch(input){
            case 999:
                print_menu_board(&cafe_ptr);
                break;
            case 1:
                drink_count(alpha, cafe_ptr);
                break;
            case 2:
                dessert_count(beta, cafe_ptr);
                break;
            case 0:
                print_receipt(&cafe_ptr);
                free(cafe_ptr.dessert);
                free(cafe_ptr.drinks);
                free(cafe_ptr.order->menu);
                free(cafe_ptr.order);
                return 0;
            default :
                printf("잘못입력하셨습니다.\n");
                break;
        }
    }
}
void print_receipt(struct struct_cafe *tmp) {
    FILE *receipt_file = fopen("Receipt.txt", "w");
    double total = 0;

    if (receipt_file == NULL) {
        perror("Error opening Receipt.txt");
        exit(1);
    }

    fprintf(receipt_file, "======================\n");
    fprintf(receipt_file, "      Receipt\n");
    fprintf(receipt_file, "======================\n");

    // Array to keep track of printed items
    int printed_items[tmp->order->count];
    memset(printed_items, 0, sizeof(printed_items));

    // Print items with quantities and total prices
    for (int i = 0; i < tmp->order->count; i++) {
        if (!printed_items[i]) {
            double item_total = tmp->order->menu[i].price;
            int item_quantity = 1;

            for (int j = i + 1; j < tmp->order->count; j++) {
                if (strcmp(tmp->order->menu[i].name, tmp->order->menu[j].name) == 0) {
                    item_total += tmp->order->menu[j].price;
                    item_quantity++;
                    printed_items[j] = 1;
                }
            }

            printed_items[i] = 1;
            total += item_total;
            fprintf(receipt_file, "%-15s\t%-4d :: \t%-20.2f\n", tmp->order->menu[i].name, item_quantity, item_total);
        }
    }

    fprintf(receipt_file, "======================\n");
    fprintf(receipt_file, "Total ::\t\t\t\t%.2f\n", total);

    fclose(receipt_file);
    printf("영수증이 Receipt.txt에 저장되었습니다.\n");
}

void print_drink_board(struct struct_cafe *tmp){
    printf("\ndrink menues\n");
    for(int k=0; k<5; k++)printf("[%d] %-15s\t%-20.2f\n",k+1 ,tmp->drinks[k].name, tmp->drinks[k].price); 
}

void print_dessert_board(struct struct_cafe *tmp){
    printf("\ndessert menues\n");
    for(int k=0; k<5; k++)printf("[%d] %-15s\t%-20.2f\n",k+1 , tmp->dessert[k].name, tmp->dessert[k].price);
}

void print_menu_board(struct struct_cafe *tmp){
    print_drink_board(tmp);
    print_dessert_board(tmp);   
}

void drink_count(int alpha, struct struct_cafe cafe_ptr){
    printf("주문하실 음료를 선택하세요\n");
    print_drink_board(&cafe_ptr);
    scanf("%d", &alpha);
                
    strcpy(cafe_ptr.order->menu[cafe_ptr.order->count].name, cafe_ptr.drinks[alpha - 1].name);
    cafe_ptr.order->menu[cafe_ptr.order->count].price = cafe_ptr.drinks[alpha - 1].price;
    cafe_ptr.order->count++;
}

void dessert_count(int beta, struct struct_cafe cafe_ptr){
    printf("주문하실 디저트를 선택하세요\n");
    print_dessert_board(&cafe_ptr);
    scanf("%d", &beta);
    strcpy(cafe_ptr.order->menu[cafe_ptr.order->count].name, cafe_ptr.dessert[beta - 1].name);
    cafe_ptr.order->menu[cafe_ptr.order->count].price = cafe_ptr.dessert[beta - 1].price;
    cafe_ptr.order->count++;
}

void read_menu_from_file(const char *filename, struct categories *menu, int menu_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char name[100];
    float price;
    int i = 0;
    while (fscanf(file, "%99s %f", name, &price) != EOF && i < menu_size) {
        menu[i].price = price;
        strcpy(menu[i].name, name);
        menu[i].ID = i + 1;
        i++;
    }

    fclose(file);
}

void initial_menulist(struct struct_cafe *cafe) {
    cafe->dessert = malloc(5 * sizeof(struct categories));
    cafe->drinks = malloc(5 * sizeof(struct categories));

    read_menu_from_file("dessert.txt", cafe->dessert, 5);
    read_menu_from_file("drink.txt", cafe->drinks, 5);

    cafe->order = malloc(sizeof(struct order_list));
    cafe->order->menu = malloc(20 * sizeof(struct categories));
    cafe->order->count = 0;
}