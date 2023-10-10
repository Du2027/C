#include<stdio.h>
int main(){
    int myarray[] = {1,2,3,4};              // creates a array with four numbers innit
    printf("num 1 is : %d", myarray[0]);     // prints number at index 0;
    myarray[0] = 44;                        // changes value at index 0 to 44
    int multidimensional_array[2][3] = { {1, 4, 2}, {3, 6, 8} };
    printf("num 1 is : %d", myarray[0][0]);
    return 0;
}