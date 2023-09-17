#include<stdio.h>
int main(){
    char a = "213123";
    a += 10; //math with a string is not possible jet
    printf("%d",a);
    char string_name[] ="";
    scanf("%s", &string_name);
    printf("%s",string_name);
    scanf("%X");
    return 0;
}