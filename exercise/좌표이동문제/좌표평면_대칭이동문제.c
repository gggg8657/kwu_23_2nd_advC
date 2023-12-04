#include <stdio.h>

void get_coordination(int *x_point, int *y_point);
void change_x_axis(int *x_point, int *y_point);
void change_y_axis(int *x_point, int *y_point);
void change_xy_axis(int *x_point, int *y_point);
void print_matrix(int x_point, int y_point);
void show_matrix(int x_point, int y_point);

int main(){
    int x_point, y_point;   

    get_coordination(&x_point, &y_point);
    show_matrix(x_point, y_point);
}

void get_coordination(int *x_point, int *y_point){
    printf("put X coordination : ");
    scanf("%d", x_point);
    printf("put Y coordination : ");
    scanf("%d", y_point);
}

void print_matrix(int x_point, int y_point){
    int change_x, change_y;

   switch(x_point){
   case 2:
   change_x = 3;
   break;
   case 1:
   change_x = 2;
   break;
   case -1:
   change_x = 1;
   break;
   case -2:
   change_x = 0;
    break;
   }

   switch(y_point){
   case 2:
   change_y = 0;
   break;
   case 1:
   change_y = 1;
   break;
   case -1:
   change_y = 2;
   break;
   case -2:
   change_y = 3;
    break;
   }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            //printf("[%d] [%d]", change_x, change_y);
            if(j == change_x && i == change_y){
                
                printf("X ");
            }
            else {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void show_matrix(int x_point, int y_point){

   print_matrix(x_point, y_point);

   change_x_axis(&x_point, &y_point);
   print_matrix(x_point, y_point);

   change_y_axis(&x_point, &y_point);
   print_matrix(x_point, y_point);

   change_xy_axis(&x_point, &y_point);
   print_matrix(x_point, y_point);
}

void change_x_axis(int *x_point, int *y_point){
   *x_point = *x_point * -1;
    }

void change_y_axis(int *x_point, int *y_point){
   *y_point = *y_point * -1;
    }

void change_xy_axis(int *x_point, int *y_point){
   *x_point = *x_point * -1;
   *y_point = *y_point * -1;
    }