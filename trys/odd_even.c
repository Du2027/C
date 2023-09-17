#include<stdio.h>
int main(){
    printf("Please Enter your Number: \n");
    int num;
    scanf("%d",&num);
    num = num %2;
    (num == 0) ? printf("Your number is even") : printf("Your number is odd");
    scanf("%d");
    return 0;
}