#include<stdio.h>
int main(){
    int example;
    printf("Address example : %p \n", &example);
    int* pointer;
    scanf("%p", pointer);
    int* what = &pointer;
    printf("On that Address is: %d", what);
    scanf("%d");
    return 0;
}