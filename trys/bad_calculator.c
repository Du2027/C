#include<stdio.h>
int main(){
    printf("Enter your Number\n");
    int Number;
    scanf("%d",&Number);
    printf("Choose your Operation\n");
    printf("+  -  /  *\n");
    printf("1  2  3  4\n");
    int operation;
    scanf("%d",operation);
    printf("Pick another Number\n");
    double Number2;
    scanf("%d",&Number2);
    double result;
   
    if(operation = 1){
        result = (double)Number + (double)Number2;
        printf("%d",result);
    }else if(operation = 2){
        result = Number - Number2;
        printf("%d",result);
    }else if(operation=3){
        result = Number / Number2;
        printf("%d",result);
    }else{
        result = Number * Number2;
        printf("%d",result);
    } 
    printf("%d",operation);
    //doesnt work somehow
    /*switch(operation){
        case 1: printf("%lf",Number+Number2); break;
        case 2: printf("%lf",Number-Number2); break;
        case 3: printf("%lf",Number/Number2); break;
        case 4: printf("%lf",Number * Number2); break; 
        default: printf("Was?"); break;
    }*/ 
    scanf("%X");
    return 0;
}