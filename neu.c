#include<stdio.h>
#include<stdbool.h> // for using booleans
int main(){
    int age = 20;
    printf("Age is %d", age);
    age = 21;
    printf("\nNew: Age %d", age);

    // strings = char string1[] = "name"; %s
    /*
    int     4bytes  %d
    double  8bytes  %lf
    float   4bytes  %f
    char    1byte   %c
    bool    1bit    %d   printf - 0 for false 1 for true stdbool.h required
    */
    //double result = (int)a+b; a is converted to a int and then printed as an double
    // <,>,==,!=,<=,>=
    //&& || ! and or not
    // bool result = (a < b)&&(a<c);

    // ternary: (1=1) ? code_when_true : code_when_false;

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

    if (1=1) && (1=1) || (1=2){
        //code
    }
    else if (1=2){
        //code2
    }
    else{
        //code3
    }
    
    return 0;
}