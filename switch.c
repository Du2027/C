#include<stdio.h>
int main(){
    int rndm_num;
    printf("Enter Number: ");
    scanf("%d",&rndm_num);
    switch(rndm_num){
        case 1:
        printf("Number: 1");
        break;
        case 2:
        printf("Number: 2");
        break;
        case 321:
        printf("Number: 321");
        break;
    }
    scanf("%d");
    return 0;
}