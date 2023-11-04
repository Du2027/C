#include<stdio.h>
#include<string.h>
#include<wiringPi.h>

int _do(int int1,int int2,int int3,int int4,int int5,int int6,int int7,int int8){
    int address[8]={int1,int2,int3,int4,int5,int6,int7,int8};
    int i;
    int x;
    for(i=0;i<9;i++){
        if(i==7){
            continue;
        }

        x = i;
        if(i==8){x=7;}
        if (i==9){x=8;}
        
        digitalWrite(i, address[x]);
    }
}

// work with argc and argv
int main(int argc, char* argv[]){

    if(argv[1]==NULL){
        printf("No Argument given on Execution\n");
        return -2;
    }
    
    if(wiringPiSetup()==-1){
        return -1;
        printf("Wiring Pi Setup failed\n");
    }
    
    int i;
    for(i=0;i<9;i++){
        if(i==7){
            continue;
        }
        pinMode(i,OUTPUT);
        printf("OUTP : %d\n", i);
    }

    long unsigned int longestword = 0;
    for(i=1; i<argc;i++){
        if(longestword < strlen(argv[i])){
            longestword = strlen(argv[i]);
        }
    }
    char word[longestword];

    for(i=0; i<argc; i++){
        printf("Command : %s\n",argv[i]);
    }

    for(i=1;i<argc;i++){
        printf("TIme : %d\n",i);
        strcpy(word, argv[i]);
        printf("word = %s\n", word);

        int chars_num[strlen(word)];
        for(i = 0;i < strlen(word); i++){
            chars_num[i] = (int) word[i];
            printf("NUM = %d\n",chars_num[i]);
        }
    }

    _do(0,0,0,0,0,0,0,0);
    return 0;
}
