void show_history(){

        printf("Your account history\n For more convenient viewing of statistics  you can watch it in file %s in program ditrectory\n",history_filename);
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