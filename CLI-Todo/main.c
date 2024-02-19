#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list(FILE *entrys){
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
        printf("Incorrect argument count, add -help for help \n");
        return -1;
    }

    // Crash if too many arguments where given
    if(argc > 3 && strcmp(argv[1], "-attach_category") == 1 && strcmp(argv[1], "-rename") == 1){
        printf("Incorrect argument count\n");
        return -1;
    }

    // Open Entrys.txt, if it doesnt exsist, creating
    FILE *entrys = fopen("/home/p/.CLI_TODO/Entrys.txt", "r");
    if(entrys == NULL){
        entrys = fopen("/home/p/.CLI_TODO/Entrys.txt", "w");
    }
    fclose(entrys);
    entrys = fopen("/home/p/.CLI_TODO/Entrys.txt", "a+");
    
    // Help command
    if(strcmp(argv[1], "-help") == 0){
        printf("available commands : -help, -list, -add, -rm\n-help     -shows help for execution\n-list/-l  -shows Todo's\n-add xy   -adds xy as Todo\n-rm xy    -removes xy Todo (line)\n");
        command = 0;
    }

    // List command
    if(strcmp(argv[1], "-list") == 0 || strcmp(argv[1], "-l") == 0){
        printf("Todo's --------------------------\n"); 
        list(entrys);
        command = 0;
    }
    
    // Add command
    if(strcmp(argv[1], "-add" ) == 0){
        if(argc == 2){
            printf("Incorrect argument count\n");
            return -1;
        }
        final_str = malloc(strlen(argv[2])+ sizeof(char)*2);
        final_str = argv[2];
        strcat(final_str, "\n");
        fprintf(entrys, "%s", final_str);
        command = 0;
    }

    // Remove command
    if(strcmp(argv[1], "-rm") == 0){
        char buffer[1000];
        FILE *tmpf = fopen("/home/p/.CLI_TODO/tmp__Entrys.txt", "w"); // creating temp file
        char *line = argv[2];
        int line_to_rm = *line - '0'; // storing witch line to remove
        bool end_of_file = false;
        int current_line = 1;

        // Cloning Entrys.txt to tmp__Entrys.txt without removed line
        do{
            fgets(buffer, 1000, entrys);
            if(current_line == line_to_rm){
                printf("Excludet line : %d : %s",line_to_rm, buffer);
            }

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
        remove("/home/p/.CLI_TODO/Entrys.txt");
        rename("/home/p/.CLI_TODO/tmp__Entrys.txt", "/home/p/.CLI_TODO/Entrys.txt");
        command = 0;
        
    }

    if(strcmp(argv[1], "-attach_category") == 0){
        command = 0;
        if(argc != 4){
            printf("Incorrect argument count");
            return -1;
        }
    }

    if(strcmp(argv[1], "-detach_category") == 0){
        command = 0;
    }

    // Rename Command
    if(strcmp(argv[1], "-rename") == 0){
        command = 0;
        if(argc != 4){
            printf("Incorrect argument count\n");
            return -1;
        }

        FILE *TMP = fopen("/home/p/.CLI_TODO/tmp__Entrys.txt", "w");
        char buffer[1000];
        int line = 1;
        char *Line = argv[2];
        int line_to_rn = *Line - '0';
        bool END = false;
        char Stinggggg[sizeof(argv[3])+sizeof(char)*2];
        strcat(Stinggggg, argv[3]);
        strcat(Stinggggg, "\n");

        do{
            fgets(buffer, 1000, entrys);

            if(feof(entrys)){
                END = true;
            }
            
            else if(line != line_to_rn){
                fputs(buffer, TMP);
            }

            else if(line == line_to_rn){
                fputs(Stinggggg, TMP);
            }
            line++;
        }
        while(END != true);

        fclose(TMP);
        fclose(entrys);

        remove("/home/p/.CLI_TODO/Entrys.txt");
        rename("/home/p/.CLI_TODO/tmp__Entrys.txt", "/home/p/.CLI_TODO/Entrys.txt");
    }

    // If command was unknown crash
    if(command == 1){
        printf("unknown command\n");
        return -1;
    }

   return 0;
}
