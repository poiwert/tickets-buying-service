// Глобальні змінні
int quantity_of_tickets = 0,money_spended_summary = 0;
int description_function() {
        printf("\tDescription\n");
        if (quantity_of_tickets == 0) {
            printf("You haven't watched films\n");
            printf("__________________________________\n");
            printf("\n");
        } else {
            printf("Overall you watched %d movies! All this cost you %d UAH\n", quantity_of_tickets, money_spended_summary);
            printf("__________________________________\n");
            printf("\n");
            
        }
        account_info();
}
