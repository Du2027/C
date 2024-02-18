#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_Todos(FILE *entrys){
    printf("Todo's --------------------------\n");   

    char cont[100];
    int line_num = 1;
    while(fgets(cont, 100, entrys)){
        if(line_num >= 10){
             printf("%d : ", line_num);
        }
        else {
            printf("%d  : ", line_num);
        }
        printf("%s", cont);
        line_num++;
    } 
}

int main(int argc, char *argv[]){
    int command = 1;
    char *final_str;

    // Crash if no arguments where given
    if(argc == 1){
        printf("add -help for help \n");
        return -1;
    }

    // Crash if too many arguments where given
    if(argc > 3){
        printf("too many arguments given\n");
        return -1;
    }

    // Open Entrys.txt, if it doesnt exsist, creating
    FILE *entrys = fopen("Entrys.txt", "r");
    if(entrys == NULL){
        entrys = fopen("Entrys.txt", "w");
    }
    fclose(entrys);
    entrys = fopen("Entrys.txt", "a+");
    
    // Help command
    if(strcmp(argv[1], "-help") == 0){
        printf("available commands : -help, -list, -add, -rm\n-help     -shows help for execution\n-list/-l  -shows Todo's\n-add xy   -adds xy as Todo\n-rm xy    -removes xy Todo (line)\n");
        command = 0;
    }

    // List command
    if(strcmp(argv[1], "-list") == 0 || strcmp(argv[1], "-l") == 0){
        list_Todos(entrys);
        command = 0;
    }
    
    // Add command
    if(strcmp(argv[1], "-add" ) == 0){
        final_str = malloc(strlen(argv[2])+ sizeof(char)*2);
        final_str = argv[2];
        strcat(final_str, "\n");
        fprintf(entrys, "%s", final_str);
        command = 0;
    }

    // Remove command
    if(strcmp(argv[1], "-rm") == 0){
        char buffer[1000];
        FILE *tmpf = fopen("tmp__Entrys.txt", "w"); // creating temp file
        char *line = argv[2];
        int line_to_rm = *line - '0'; // storing witch line to remove
        bool end_of_file = false;
        int current_line = 1;

        // Cloning Entrys.txt to tmp__Entrys.txt without removed line
        do{
            fgets(buffer, 1000, entrys);
            if(feof(entrys)){
                end_of_file = true;
            }
            else if(current_line != line_to_rm){
                fputs(buffer, tmpf);
            }
            current_line++;
        }
        while (end_of_file != true);
            
        // Closing
        fclose(entrys);
        fclose(tmpf);

        // Removing Entrys.txt and renaming tmp file to Entrys
        remove("Entrys.txt");
        rename("tmp__Entrys.txt", "Entrys.txt");
        command = 0;
        
    }

    // If command was unknown crash
    if(command == 1){
        printf("unknown command\n");
        return -1;
    }

   return 0;
}
