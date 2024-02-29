// Doesnt work for some Reason
// Listst sometimes some wierd chars in category
// Sometimes prints some random chars to file



// help command
// attach command
// detach command

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    

    int known_command = 0;
    
    FILE *ENTRYS = fopen("/home/p/.CLI_TODO/Entrys.txt", "r");
    if(ENTRYS == NULL){
        ENTRYS = fopen("/home/p/.CLI_TODO/Entrys.txt", "w");
    }
    fclose(ENTRYS);
    ENTRYS = fopen("/home/p/.CLI_TODO/Entrys.txt", "a+");

    if(argc == 2 && strcmp(argv[1], "-list") == 0){
        known_command = 1;

        printf("----------Todo's----------\n");
        // move function to main and replace variables
        char beginn_red[] = "\x1b[1;31m";
        char beginn_green[] = "\x1b[1;31m";
        char beginn_yellow[] = "\x1b[1;31m";
        char beginn_blue[] = "\x1b[1;31m";
        char beginn_purple[] = "\x1b[1;31m";
        char beginn_cyan[] = "\x1b[1;31m";
        char end_color[] = "\x1b[0m";

        char cont[1000];
        int line_number = 1;

        while(fgets(cont, 1000, ENTRYS)){
            if(line_number < 10){
                printf("%d  : ", line_number);
            }
            else{
                printf("%d : ", line_number);
            }
        
            char first = cont[0];
            char second = cont[1];
            char check[] = "*";
            char funny_str[100];

            char Red[] = "R";
            char Blue[] = "B";
            char Cyan[] = "C";
            char Yellow[] = "Y";
            char Purple[] = "P";
            char Green[] = "G";
        
            char seach_for[] = "$";
            char new_string[1100];

            int n;
            bool wierd = false;

            // if that works its done
            // print str at pointer, so u have everything exept categorys
            // in the end, print newstr and rest of str
            char *pointer_to_endofstr = strchr(cont, 36);
            if(pointer_to_endofstr != NULL){
                //printf("LOS:%sEND", pointer_to_endofstr);
            }

            if(first == check[0] && second == Red[0]){
                for(n = 0; n < 100; n++){
                    if(cont[n] == seach_for[0]){
                        cont[n] = 32;
                        break;
                    }
                    cont[0] =  32;
                    cont[1] = 32;
                    funny_str[n] = cont[n];
                }
                strcat(new_string, beginn_red);
                strcat(new_string, funny_str);
                strcat(new_string, end_color);
                //printf("%s", new_string); 

                //printf("%s", cont);
            }
            if(first == check[0] && second == Blue[0]){
                printf("workd");
            }
            if(first == check[0] && second == Yellow[0]){
                printf("workd");
            }
            if(first == check[0] && second == Cyan[0]){
                printf("workd");
            }
            if(first == check[0] && second == Purple[0]){
                printf("workd");
            }
            if(first == check[0] && second == Green[0]){
                printf("workd");
            }
            if(pointer_to_endofstr == NULL){
                printf("%s", cont);
            }
            else{
                printf("%s%s", new_string, pointer_to_endofstr);
            }
            line_number++;
        }
        fclose(ENTRYS);
    }

    if(argc == 3 && strcmp(argv[1], "-add") == 0){
        known_command = 1;

        char *str;
        str = malloc(strlen(argv[2]) + sizeof(char)*2);
        str = argv[2];
        strcat(str, "\n");

        fprintf(ENTRYS, "%s", str);
        fclose(ENTRYS);
    }

    if(argc == 3 && strcmp(argv[1], "-rm") == 0){
        known_command = 1;

        char buffer[1000];
        FILE *TMP__FILE = fopen("/home/p/.CLI_TODO/Tmp__Entrys.txt", "w");

        char *line = argv[2];
        int line_to_rm = *line - '0';
        int current_line = 1;

        bool eof = false;

        do{
            fgets(buffer, 1000, ENTRYS);

            if(feof(ENTRYS)){
                eof = true;
            }

            else if(current_line == line_to_rm){
                printf("Excludet : %d - %s", current_line, buffer);
            }
            
            else if(current_line != line_to_rm){
                fputs(buffer, TMP__FILE);
            }
            current_line++;
        }
        while(eof != true);

        fclose(TMP__FILE);
        fclose(ENTRYS);

        remove("/home/p/.CLI_TODO/Entrys.txt");
        rename("/home/p/.CLI_TODO/Tmp__Entrys.txt", "/home/p/.CLI_TODO/Entrys.txt");
    }

    if(argc == 4 && strcmp(argv[1], "-rename") == 0){
        known_command = 1;

        char buffer[1000];
        FILE *TMP__FILE = fopen("/home/p/.CLI_TODO/Tmp__Entrys.txt", "w");

        char *line = argv[2];
        int line_to_rm = *line - '0';
        int current_line = 1;

        bool eof = false;

        do{
            fgets(buffer, 1000, ENTRYS);

            if(feof(ENTRYS)){
                eof = true;
            }

            else if(current_line == line_to_rm){
                printf("Renamed : %d to %s \n", current_line, argv[3]);
                
                char Str[sizeof(argv[3])+sizeof(char)*2];
                strcat(Str, argv[3]);
                strcat(Str, "\n");

                fputs(Str, TMP__FILE);
            }
            
            else if(current_line != line_to_rm){
                fputs(buffer, TMP__FILE);
            }
        }
        while(eof != true);

        fclose(TMP__FILE);
        fclose(ENTRYS);

        remove("/home/p/.CLI_TODO/Entrys.txt");
        rename("/home/p/.CLI_TODO/Tmp__Entrys.txt", "/home/p/.CLI_TODO/Entrys.txt");
    }


    if(argc == 5 && strcmp(argv[1], "-attach_category") == 0){
        known_command = 1;

        char buffer[1000];
        FILE *TMP__FILE = fopen("/home/p/.CLI_TODO/Tmp__Entrys.txt", "w");

        char *line = argv[2];
        int line_to_attach = *line - '0';
        int current_line = 1;

        bool eof = false;

        do{
            fgets(buffer, 1000, ENTRYS);

            if(feof(ENTRYS)){
                eof = true;
            }

            else if(current_line == line_to_attach){
                printf("Attached : %s to %d\n", argv[3], current_line);
                
                char str_beginn[2];
                char str_end[] = "$";
                bool known = false;

                if(strcmp(argv[4], "-r") == 0){
                    char str_beginn[] = "*R";
                    known = true;
                }
                if(strcmp(argv[4], "-b") == 0){
                    char str_beginn[] = "*B";
                    known = true;
                }
                if(strcmp(argv[4], "-c") == 0){
                    char str_beginn[] = "*C";
                    known = true;
                }
                if(strcmp(argv[4], "-p") == 0){
                    char str_beginn[] = "*P";
                    known = true;
                }
                if(strcmp(argv[4], "-y") == 0){
                    char str_beginn[] = "*Y";
                    known = true;
                }
                if(strcmp(argv[4], "-g") == 0){
                    char str_beginn[] = "*G";
                    known = true;
                }

                if(known == false){
                    printf("Unknown Color given\n");
                    return -1;
                }

                char new_str[1003];
                strcat(new_str, str_beginn);//doesnt works
                strcat(new_str, argv[3]);
                strcat(new_str, str_end);
                strcat(new_str, buffer);
                fputs(new_str, TMP__FILE);
                current_line++;
            }
            
            else if(current_line != line_to_attach){
                fputs(buffer, TMP__FILE);
            }
            current_line++;
        }
        while(eof != true);

        fclose(TMP__FILE);
        fclose(ENTRYS);

        remove("/home/p/.CLI_TODO/Entrys.txt");
        rename("/home/p/.CLI_TODO/Tmp__Entrys.txt", "/home/p/.CLI_TODO/Entrys.txt");
    }
        
    
    if(known_command == 0){
        printf("Something went wrong, either you messed up the arguments or u typed in a wrong command\n");
        printf("Use -help for help\n");
        return -1;
    }

    return 0;
}
