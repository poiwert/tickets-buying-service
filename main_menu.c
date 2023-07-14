#include <stdio.h>
#include <string.h>

int account_info(){}
int film_catalog(){}

int main(){
    while (1) {
    int menu_section, info, buy;
    printf("      Choose menu section\n");
    printf("__________________________________\n");
    printf("| Account (1)   Film catalog (2) |\n");
    printf("__________________________________\n");
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