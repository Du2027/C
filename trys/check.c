#include<stdio.h>
#include<stdbool.h>
int main(){
    double num;
    printf("Enter your Number: \n");
    scanf("%lf",&num);
    if (num < 0){
        printf("Your Number is negative");
    }
    else if (num = 0){
        printf("Your Number is 0");
    }
    else{
        printf("Your Number is positive");
    }
    scanf("%d");
}