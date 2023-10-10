#include<stdio.h>

struct mystructure{
    int num1;       // member of the struct
    char name[30];    // member of the structt
};

struct mystructure2;


int main(){
    struct mystructure str1;    // creates a sructure variable
    str1.num1 = 12;             // assigns the value 12 to the num1 member of the struct
    printf("%d", str1.num1)     // prints it

    strcpy(str1.name, "hello"); //assigns hello to name

    struct mystructure str1 = {12, "hello"};    // also possible

    struct mystructure2 str2;
    str2 = str1;

    return 0;
}