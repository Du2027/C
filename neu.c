#include<stdio.h>
int main(){
    int age = 20;
    printf("Age is %d", age);
    age = 21;
    printf("\nNew: Age %d", age);

    /*
    int     4bytes  %d
    double  8bytes  %lf
    float   4bytes  %f
    char    1byte   %c
    */

    double Number_double = 12.35;
    printf("\n%.2lf",Number_double); //.2lf for 2 decimal points. standart = 6 decimals
    float Number_Float = 22.1f;
    printf("\n%.1f",Number_Float);   //same for float

    printf("\nSize of a float: %d", sizeof(float)); //gives the datatype size in bytes

    int num1 = 11;
    int num2 = 22;
    printf("\n%d\n", num1+num2);

    int your_Age;
    scanf("%d", &your_Age);
    printf("your Age: = %d",your_Age);
    scanf("%d");
    //scanf("%d %c",var1,var2) also possible

    return 0;
}