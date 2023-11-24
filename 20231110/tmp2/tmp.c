#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct categories {
    float price;
    char name[100];
};

struct order_list {
    struct categories *menu;
    int count;
};

struct struct_cafe {
    struct categories *dessert, *drinks;
    struct order_list *order;
};

void print_order_list(struct struct_cafe *tmp) {
    printf("\norder list\n");
    for (int k = 0; k < tmp->order->count; k++)
        printf("%-15s\t%-20.2f\n", tmp->order->menu[k].name, tmp->order->menu[k].price);
    printf("\n");
}

void print_menu_board(struct struct_cafe *tmp) {
    printf("\ndrink menues\n");
    for (int k = 0; k < 5; k++) printf("[%d] %-15s\t%-20.2f\n", k + 1, tmp->drinks[k].name, tmp->drinks[k].price);

    printf("\ndessert menues\n");
    for (int k = 0; k < 5; k++) printf("[%d] %-15s\t%-20.2f\n", k + 1, tmp->dessert[k].name, tmp->dessert[k].price);
}

int main() {
    char *dessert_menu[] = {"Cake", "Pie", "Ice Cream", "Pecan Pie", "Scone"};
    float dessert_prices[] = {4.99, 3.49, 5.99, 4.99, 3.99};
    char *drink_menu[] = {"Coffee", "Tea", "Milk", "Water", "Soda"};
    float drink_prices[] = {2.99, 2.99, 2.99, 2.99, 2.99};
    struct struct_cafe cafe_ptr;

    cafe_ptr.dessert = malloc(5 * sizeof(struct categories));
    cafe_ptr.drinks = malloc(5 * sizeof(struct categories));

    for (int i = 0; i < 5; i++) {
        cafe_ptr.dessert[i].price = dessert_prices[i];
        strcpy(cafe_ptr.dessert[i].name, dessert_menu[i]);

        cafe_ptr.drinks[i].price = drink_prices[i];
        strcpy(cafe_ptr.drinks[i].name, drink_menu[i]);
    }

    cafe_ptr.order = malloc(sizeof(struct order_list));
    cafe_ptr.order->menu = malloc(1024 * sizeof(struct categories));
    cafe_ptr.order->count = 0;

    int alpha = 0;
    int beta = 0;
    
    while (1) {
        printf("\n1. 메뉴 보기\n2. 음료 주문하기\n3. 디저트 주문하기\n0. 종료\t");
        int input;
        scanf("%d", &input);

        switch (input) {
            case 1:
                print_menu_board(&cafe_ptr);
                break;
            case 2:
                printf("주문하실 음료를 선택하세요\n");
                print_menu_board(&cafe_ptr);
                scanf("%d", &alpha);

                if (alpha >= 1 && alpha <= 5) {
                    printf("\nthis is count of order :: %d", cafe_ptr.order->count);
                    printf("\nthis is name of ordered menu :: %s\n\n\n\n", cafe_ptr.drinks[alpha - 1].name);

                    strcpy(cafe_ptr.order->menu[cafe_ptr.order->count].name, cafe_ptr.drinks[alpha - 1].name);
                    cafe_ptr.order->menu[cafe_ptr.order->count].price = cafe_ptr.drinks[alpha - 1].price;
                    cafe_ptr.order->count++;
                } else {
                    printf("Invalid selection.\n");
                }
                break;
            case 3:
                printf("주문하실 디저트를 선택하세요\n");
                print_menu_board(&cafe_ptr);
                scanf("%d", &beta);

                if (beta >= 1 && beta <= 5) {
                    strcpy(cafe_ptr.order->menu[cafe_ptr.order->count].name, cafe_ptr.dessert[beta - 1].name);
                    cafe_ptr.order->menu[cafe_ptr.order->count].price = cafe_ptr.dessert[beta - 1].price;
                    cafe_ptr.order->count++;
                } else {
                    printf("Invalid selection.\n");
                }
                break;
            case 0:
                print_order_list(&cafe_ptr);
                return 0;
            default:
                printf("잘못입력하셨습니다.\n");
                break;
        }
    }

    // Free allocated memory before exiting
    free(cafe_ptr.dessert);
    free(cafe_ptr.drinks);
    free(cafe_ptr.order->menu);
    free(cafe_ptr.order);

    return 0;
}
