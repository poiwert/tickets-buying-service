#include <stdio.h>
#include <string.h>
#include "categories.h"
#include "menu_styles.h"

extern const char* categories[];
extern const int num_categories;

int account_info() {}
int buy() {}

void display_categories() {
    for (int i = 0; i < num_categories; i++) {
        printf("(%d) %s\n", i + 1, categories[i]);
    }
}

int main() {
    while (1) {
        int menu_section;
        print_menu_styles();
        display_categories();
        scanf("%d", &menu_section);

        switch (menu_section) {
            case 1:
                account_info();
                break;
            case 2:
                film_catalog();
                break;
            default:
                printf("Input another key\n");
                break;
        }
    }
    return 0;
}
