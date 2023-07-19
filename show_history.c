void show_history(){

    if(quantity_of_tickets==0){
        printf("History is empty\n");
    }

    else{
        printf("Your account history\n");
        printf("______________________________________\n");
        FILE *file = fopen(history_filename, "r");
        if (file == NULL){
            printf("File open error\n");
            return;
        }

        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file) != NULL){
            printf("%s", buffer);
        }

        fclose(file);
        printf("______________________________________\n");
        printf("\n");
    }
    
}