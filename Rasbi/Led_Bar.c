#include<stdio.h>
#include<wiringPi.h>

#define Gpio1 0;
#define Gpio2 1;
#define Gpio3 2;
#define Gpio4 3;
#define Gpio5 4;
#define Gpio6 5;
#define Gpio7 6;
#define Gpio8 8;
#define Gpio9 9;
#define Gpio10 10;

int main(){
    if(wiringPiSetup() == -1){
        printf("setup failed");
        return -1;
    }

    int i;
    for(i=0;i<11;i++){
        if(i==7){
            continue;
        }
        pinMode(i,OUTPUT);
    }

    for(i=0;i<11;i++){
        if(i==7){
            continue;
        }
        digitalWrite(i,LOW);
        delay(1000);
    }
    for(i=11;i>-1;i--){
        if(i==7){
            continue;
        }
        digitalWrite(i,HIGH);
        delay(1000);
    }
    return 0;
}