// main.c
#include <stdio.h>
#include <string.h>
#include "menu_styles.h"

int account_info(){}
int buy(){}

int main(){
    while (1) {
        int menu_section, info, purchase;
        print_menu_styles();
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
