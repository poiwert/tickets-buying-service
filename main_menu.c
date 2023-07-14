#include <stdio.h>
#include <string.h>

int main(){
    int menu_section, info, buy;
    printf("Choose menu section\n");
    printf("\t Account(1)\t Buy(2) \n");
    scanf("%d", &menu_section);
    
    switch (menu_section) {
        case 1:
            info = account_info();
            break;
        case 2:
            buy = buy_tickets();
            break;
        default:
            printf("Input another key\n");
            break;
        }
}