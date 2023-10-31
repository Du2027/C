#include<stdio.h>
#include<wiringPi.h>

int main(){
    int Timer = 200;
    if(wiringPiSetup()==-1){
        return -1;
    }
    int i;
    for(i=0;i<9;i++){
        if(i==7){
            continue;
        }
        pinMode(i,OUTPUT);
    }
    for(i=0;i<9;i++){
        if(i==7){
            continue;
        }
        digitalWrite(i,LOW);
    }
    while(1){
        for(i=0;i<9;i++){
        if(i==7){
            continue;
        }
        printf("%d\n",i);
        digitalWrite(i, HIGH);
        delay(Timer);
        digitalWrite(i, LOW);
        if(i==8){
            for(i=8;i>-1;i--){
                digitalWrite(i, HIGH);
                delay(Timer);
                digitalWrite(i, LOW);
            }
        }
    }
    }

    return 0;
}