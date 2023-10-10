#include<stdio.h>
#include<stdbool.h>
int main(){
    int num_one = 123;
    int num_two = 213;    
    int i = 0;

    //-----------------------------------------------------------------------------if
    if (num_one == num_two){
        printf("same lol");
    }
    else if(num_one > num_two){
        printf("bigger lol");
    }
    else{
        printf("smaler");
    } 
    //-----------------------------------------------------------------------------ternary
    //same as if but shorter
    int num_three = (num_one<num_two) ? 120:213; //true:false

    //-----------------------------------------------------------------------------switch
    switch(num_one) {
  case 123:             // it num_one is 123 code is executed
    // code block
    break;
  case 124:
    // code block
    break;
  default:
    // code block
    }
    //-----------------------------------------------------------------------------while loop

    while(num_one < i){
        printf("lower");
        i++;
    }
    //-----------------------------------------------------------------------------do while loop

    do{     // do gets executed once
      int i = 0;
    }
    while(i < 5){
        printf("lower");
        i++;
    }
    //-----------------------------------------------------------------------------for loop
    for(i = 0; i < 5; i++){
      printf("\n %d",i);
    }
    //-----------------------------------------------------------------------------break and continue
    for(i = 0; i < 5; i++){
    printf("\n %d",i);
    if(i == 12){
      break;          // jump out of the loop
    }
    }

    for(i = 0; i < 5; i++){
    printf("\n %d",i);
    if(i == 12){
      continue;          // skips the loop once if i is 12
    }
    }
    return 0;
}
