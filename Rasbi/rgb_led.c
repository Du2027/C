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
    colorset(10,0,0,1000);
    colorset(0,255,0,1000);
    colorset(0,0,255,1000);
    return 0;
}