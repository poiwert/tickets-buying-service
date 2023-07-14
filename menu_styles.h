// menu_styles.h
#ifndef MENU_STYLES_H
#define MENU_STYLES_H

#include <stdio.h>

void print_menu_styles() {
    printf(" Choose menu section\n");
    printf("__________________________________\n");
    printf("| Account (1) Film catalog (2) |\n");
    printf("__________________________________\n");
}

#endif

// main_menu.c
#include <stdio.h>
#include <string.h>
#include "menu_styles.h"
#include "categories.h"

int account_info(){}
int film_catalog(){}

int main(){
    while (1) {
        int menu_section, info, buy;
        print_menu_styles();
        scanf("%d", &menu_section);
        
        switch (menu_section) {
            case 1:
                info = account_info();
                break;
            case 2:
                buy = film_catalog();
                break;
            default:
                printf("Input another key\n");
                break;
        }
    }
    return 0;
}
