#include<stdio.h>
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
        delay(1000);
    }
}

// work with argc and argv
int main(){
    if(wiringPiSetup()==-1){
        return -1;
        printf("Wiring Pi Setup failed\n");
    }

    int i;
    for(i=0;i<0;i++){
        if(i==7){
            continue;
        }
        pinMode(i,OUTPUT);
    }

    char charak;
    scanf("%d", &charak);
    if(&charak == "A"){
        _do(1,1,1,0,1,1,1,0);
    }

    _do(0,0,0,0,0,0,0,0);
    return 0;
}
