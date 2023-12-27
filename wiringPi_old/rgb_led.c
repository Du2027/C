#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define Gpio27 2 //green
#define Gpio18 1 //blue
#define Gpio17 0 //red

#define uchar unsigned char
void Gpio_init(int Pin1,int Pin2,int Pin3){
    softPwmCreate(Pin1,0,100);
    softPwmCreate(Pin2,0,100);
    softPwmCreate(Pin3,0,100);
}

void colorset(uchar red, uchar green, uchar blue, int delay_num){
    softPwmWrite(Gpio17, red);
    softPwmWrite(Gpio27, green);
    softPwmWrite(Gpio18, blue);
    delay(delay_num);
}

int main(){
    if(wiringPiSetup() == -1){
        printf("setup failed");
        return 1;
    }
    Gpio_init(Gpio17,Gpio18,Gpio27);
    int i;        
    for(i=0;i<255;i++){
        colorset(i,0,0,500);
        colorset(i,i,i,500);
    }
    return 0;
}