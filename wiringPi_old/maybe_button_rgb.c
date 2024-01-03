#include<wiringPi>
#include<stdio.h>

#define Gpio1_IN 0
#define Gpio2_IN 1
#define Gpio3_IN 2

#define Gpio1_OUT 3
#define Gpio2_OUT 4
#define Gpio3_OUT 5

int main(){
  int Color_array={LOW,LOW,LOW}
  if(digitalread(Gpio1_IN)==0){
    Color_array[0] = HIGH;
  }
  if(digitalread(Gpio2_IN)==0){
    Color_array[1] = HIGH;
  }
  if(digitalread(Gpio3_IN)==0){
    Color_array[2] = HIGH;
  }

  digitalwrite(Gpio1_OUT,Color_array[0]);
  digitalwrite(Gpio2_OUT,Color_array[1]);
  digitalwrite(Gpio3_OUT,Color_array[2]);
  return 0;
}
