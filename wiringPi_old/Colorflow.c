#include<stdio.h>
#include<wiringPi.h>
#include<softPwm.h>

#define GPIO1 0;
#define GPIO2 1;
#define GPIO3 2;


int colorset(int r,int g,int b){
  softPwmWrite(0, r);
  softPwmWrite(1, g);
  softPwmWrite(2, b);
}
int higher(){
    int i;
    for(i=0;i<256;i++){
        colorset(i,0,0);
        delay(10);
    }
    for(i=256;i>0;i--){
        colorset(i,0,0);
        delay(10);
    }
    for(i=0;i<256;i++){
        colorset(0,i,0);
        delay(10);
    }
    for(i=256;i>0;i--){
        colorset(0,i,0);
        delay(10);
    }
    for(i=0;i<256;i++){
        colorset(0,0,i);
        delay(10);
    }
    for(i=256;i>0;i--){
        colorset(0,0,i);
        delay(10);
    }
    for(i=0;i<256;i++){
        colorset(0,i,i);
        delay(10);
    }
    for(i=256;i>0;i--){
        colorset(0,i,i);
        delay(10);
    }
    for(i=0;i<256;i++){
        colorset(i,i,0);
        delay(10);
    }
    for(i=256;i>0;i--){
        colorset(i,i,0);
        delay(10);
    }
    for(i=0;i<256;i++){
        colorset(i,i,i);
        delay(10);
    }
    for(i=256;i>0;i--){
        colorset(i,i,i);
        delay(10);
    }

}

int main(){
    if(wiringPiSetup()==-1){
        printf("Wiring Pi Setup failed\n");
    }

    int i;
    for(i=0;i<4;i++){
        softPwmCreate(i,0,100);
        printf("OUTPUT : %d\n",i);
    }
  
    higher();
    return 1;
}

