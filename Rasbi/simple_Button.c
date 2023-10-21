#include<wiringPi.h>
#include<stdio.h>
#define Gpio17 0
#define Gpio18 1
#define Gpio23 4
#define Gpio24 5
#define Gpio27 2
#define Gpio22 3

int main(){
    if(wiringPiSetup()==-1){
        return -1;
    }
    pinMode(Gpio17,OUTPUT);
    pinMode(Gpio27,OUTPUT);
    pinMode(Gpio22,OUTPUT);
    pinMode(Gpio18,INPUT);
    pinMode(Gpio23,INPUT);
    pinMode(Gpio24,INPUT);

    digitalWrite(Gpio17,LOW);

    while(1){
    if(digitalRead(Gpio18)==0 || digitalRead(Gpio23)==0 || digitalRead(Gpio24)==0){
        digitalWrite(Gpio17,HIGH);
    }
    if(digitalRead(Gpio23)==0){
        digitalWrite(Gpio27,HIGH);
    }
    if(digitalRead(Gpio24)==0){
        digitalWrite(Gpio22,HIGH);
    }
    else{
        digitalWrite(Gpio17,LOW);
        digitalWrite(Gpio27,LOW);
        digitalWrite(Gpio22,LOW);
    }}
    return 0;
}