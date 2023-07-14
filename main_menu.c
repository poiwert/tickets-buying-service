#include <stdio.h>
#include <string.h>
#include "categories.h"

int account_info(){}
int buy(){}

void print_menu_styles() {
    printf(" Choose menu section\n");
    printf("__________________________________\n");
    printf("| Account (1) Film catalog (2) |\n");
    printf("__________________________________\n");
}

int main(){
    while (1) {
        int menu_section, info, purchase;
        print_menu_styles();
        for (int i = 0; i < num_categories; i++) {
            printf("(%d) %s\n", i + 1, categories[i]);
        }
        scanf("%d", &menu_section);
        
        switch (menu_section) {
            case 1:
                info = account_info();
                break;
            case 2:
                purchase = buy();
                break;
            default:
                printf("Input another key\n");
                break;
        }
    }
    return 0;
}
