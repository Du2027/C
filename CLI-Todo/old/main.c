// Could be rewritten with functions with a couple of arguments istead of doing the same thing 4 times (rename, remove, rm cat and add cat)
// u can apply a category even if a cat is already applied

// adding the color doesnt work as intendet, because \x1b is converted to ^ somehow and fgets doesnt get it
// would need to rewrite whole category thingi, and dont add something to the file for the color, just put it on the string when it is listed

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
    char beginn_red[] = "\x1b[1;31m";
    char beginn_green[] = "\x1b[1;32m";
    char beginn_yellow[] = "\x1b[1;33m";
    char beginn_blue[] = "\x1b[1;34m";
    char beginn_purple[] = "\x1b[1;35m";
    char beginn_cyan[] = "\x1b[1;36m";
    char end_color[] = "\x1b[0m";

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
        printf("available commands : -help, -list, -add, -rm, -rename\n-help       -shows help for execution\n-list/-l    -shows Todo's\n-add xy     -adds xy as Todo\n-rm xy      -removes xy Todo (line)\n-rename x y -renames line x to y\n");
        command = 0;
        fclose(entrys);
    }

    // List command
    if(strcmp(argv[1], "-list") == 0 || strcmp(argv[1], "-l") == 0){
        printf("Todo's --------------------------\n"); 
        list(entrys);
        command = 0;
        fclose(entrys);
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
        fclose(entrys);
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
    
    // Attach a Category command
    if(strcmp(argv[1], "-attach_category") == 0){
        printf("WIP\n");
        return -1;
        command = 0;
        if(argc != 4){
            printf("Incorrect argument count\n");
            return -1;
        }


        //if(strcmp(argv[4], "-red") != 0 || strcmp(argv[4], "-green") != 0 || strcmp(argv[4], "-cyan") != 0 || strcmp(argv[4], "-yellow") != 0 || strcmp(argv[4], "-purple") != 0 || strcmp(argv[4], "-blue") != 0){
          //  printf("Unknown color given\n");
            //return -1;
        //}

        char buffer[1000];
        FILE *tmpf = fopen("/home/p/.CLI_TODO/tmp__Entrys.txt", "w"); // creating temp file
        char *line = argv[2];
        int line_to_coloradd = *line - '0'; // storing witch line to remove
        bool end_of_file = false;
        int current_line = 1;

        // Cloning Entrys.txt to tmp__Entrys.txt without removed line
        do{
            fgets(buffer, 1000, entrys);

            printf("char :%c\n",buffer[0]);
            //if(strcmp(&buffer[0], "^") == 0){
            //    printf("color already assigned\n");
            //    remove("/home/p/.CLI_TODO/tmp__Entrys.txt");
            //    return -1;
            //}

            if(feof(entrys)){
                end_of_file = true;
            }

            else if(current_line != line_to_coloradd){
                fputs(buffer, tmpf);
            }

            else if(current_line == line_to_coloradd && strcmp(argv[3], "-r") == 0){
                char newstr[1000];
                strcat(newstr, beginn_red);
                strcat(newstr, buffer);
                newstr[strcspn(newstr, "\n")] = 0;
                strcat(newstr, end_color);
                strcat(newstr, "\n");
                fputs(newstr, tmpf);
            }
            else if(current_line == line_to_coloradd && strcmp(argv[3], "-g") == 0){
                char newstr[1000];
                buffer[strspn(buffer, "\n")] = 0;
                strcat(newstr, beginn_green);
                strcat(newstr, buffer);
                strcat(newstr, end_color);
                strcat(newstr, "\n");
                fputs(newstr, tmpf);
            }
            else if(current_line == line_to_coloradd && strcmp(argv[3], "-b") == 0){
                char newstr[1000];
                buffer[strspn(buffer, "\n")] = 0;
                strcat(newstr, beginn_blue);
                strcat(newstr, buffer);
                strcat(newstr, end_color);
                strcat(newstr, "\n");
                fputs(newstr, tmpf);
            }
            else if(current_line == line_to_coloradd && strcmp(argv[3], "-c") == 0){
                char newstr[1000];
                buffer[strspn(buffer, "\n")] = 0;
                strcat(newstr, beginn_cyan);
                strcat(newstr, buffer);
                strcat(newstr, end_color);
                strcat(newstr, "\n");
                fputs(newstr, tmpf);
            }
            else if(current_line == line_to_coloradd && strcmp(argv[3], "-y") == 0){
                char newstr[1000];
                buffer[strspn(buffer, "\n")] = 0;
                strcat(newstr, beginn_yellow);
                strcat(newstr, buffer);
                strcat(newstr, end_color);
                strcat(newstr, "\n");
                fputs(newstr, tmpf);
            }
            else if(current_line == line_to_coloradd && strcmp(argv[3], "-p") == 0){
                char newstr[1000];
                buffer[strspn(buffer, "\n")] = 0;
                strcat(newstr, beginn_purple);
                strcat(newstr, buffer);
                strcat(newstr, end_color);
                strcat(newstr, "\n");
                fputs(newstr, tmpf);
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
    }

    // Detach command
    if(strcmp(argv[1], "-detach_category") == 0){
        printf("WIP\n");
        return -1;
        command = 0;
        
        fclose(entrys);
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
        fclose(entrys);       
        return -1;
    }

   return 0;
}
