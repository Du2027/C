#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[]){

    int Command = 0;
    // No Arguments
    if(argc == 1){
        printf("No Arguments given on Execution,\n");
        printf("add -h Flag for help\n");
        Command++;
        return -1;
    }

    // Help Command
    if(strcmp(argv[1], "-help")==0||strcmp(argv[1], "-h")==0){
        printf("Commands:\n-h, -a, -rm, -e, -l\n\n-help              ~show commands\n\n-add -dd.mm.yy     ~add entry for day\n                   ~format: day.month.year\n\n-remove -dd.mm.yy  ~removes entry for a day\n\n-edit -dd.mm.yy    ~edit entry for day\n\n-list              ~lists the exsisting entrys\n");
        Command++;
    }
    
    // List Command
    if(strcmp(argv[1], "-list")==0 || strcmp(argv[1], "-l")==0){
        Command++;
        if(argc >= 3){
            printf("Too many arguments given while using list command\n");
            return -1;
        }
        system("ls ~/Repos/C/CLI-Journal/Entrys/");  // to write a bash commadn
    }
    
    // Remove Command
    if(strcmp(argv[1], "-remove")==0 || strcmp(argv[1], "-rm")==0){
        Command++;
        if(argc == 2 || argc >= 4){
            printf("Too many or too less Arguments\n");
            return -1;
        }
        char* remOve = (char*) malloc(100*sizeof(char));
        strcat(remOve, "rm ~/Repos/C/CLI-Journal/Entrys/");
        strcat(remOve, argv[2]);
        system(remOve);
        free(remOve);
    }

    // Add Command
    if(strcmp(argv[1], "-add")==0||strcmp(argv[1], "-a")==0){
        Command++;
        if(argc == 2 || argc >= 4){
            printf("Too many or too less Arguments\n");
            return -1;
        }
        char* add = (char*) malloc(100*sizeof(char));
        strcat(add, "touch ~/Repos/C/CLI-Journal/Entrys/");
        strcat(add, argv[2]);
        system(add);
        free(add);
    }

    // Edit Command
    if(strcmp(argv[1], "-edit")==0||strcmp(argv[1], "-e")==0){
        Command++;
        if(argc == 2 || argc >= 4){
            printf("Too many or too less Arguments\n");
            return -1;
        }
        char* edit = (char*) malloc(100*sizeof(char));
        strcat(edit, "vim ~/Repos/C/CLI-Journal/Entrys/");
        strcat(edit, argv[2]);
        system(edit);
        free(edit);
    }
    
    // Unknown Command
    if(Command == 0){
        printf("Unknown Command\n");
    }
}
