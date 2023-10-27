#include<stdio.h>
#include<wiringPi.h>

int main(){
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
    int num;
    while(1){
        scanf("%d\n",&num);
        digitalWrite(num, HIGH);
        delay(1000);
        digitalWrite(num, LOW);
    }

    return 0;
}