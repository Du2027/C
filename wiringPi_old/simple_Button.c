#include<wiringPi.h>
#include<stdio.h>

#define Gpio1_IN 0
#define Gpio2_IN 1
#define Gpio3_IN 2

#define Gpio1_OUT 3
#define Gpio2_OUT 4
#define Gpio3_OUT 5

int main(){
    if(wiringPiSetup()== -1){
        return 1;
    }

    int i;
    for(i=0;i<6;i++){
        if(i<3){
            pinMode(i,INPUT);
            printf("IN : %d\n",i);
        }
        else{
            pinMode(i,OUTPUT);
            printf("OUT : %d\n",i);
        }
    }

    int Color_array[]={LOW,LOW,LOW};
    while(1){
        for(i=0;i<3;i++){
            Color_array[i]=LOW;
        }
        if(digitalRead(Gpio1_IN)==0){
            Color_array[0] = HIGH;
        }
        if(digitalRead(Gpio2_IN)==0){
            Color_array[1] = HIGH;
        }
        if(digitalRead(Gpio3_IN)==0){
            Color_array[2] = HIGH;
        }

        digitalWrite(Gpio1_OUT,Color_array[0]);
        digitalWrite(Gpio2_OUT,Color_array[1]);
        digitalWrite(Gpio3_OUT,Color_array[2]);

        printf("COLOR : %d%d%d\n", Color_array[0], Color_array[1], Color_array[2]);
        }
  return 0;
}