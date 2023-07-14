// categories.h
#ifndef CATEGORIES_H
#define CATEGORIES_H

const char* categories[] = {
    "Account",
    "Film catalog"
};

const int num_categories = sizeof(categories) / sizeof(categories[0]);

#endif

// main_menu.c
#include <stdio.h>
#include <string.h>
#include "menu_styles.h"
#include "categories.h"

int account_info(){}
int buy(){}

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
