void show_history(){

    if(quantity_of_tickets==0){
        printf("History is empty\n");
    }

    else{
        printf("Your account history\nFor more convenient viewing of statistics  you can watch it in file %s in program ditrectory\n",history_filename);
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