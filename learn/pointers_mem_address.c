#include<stdio.h>
int main(){
    int mynum = 43;
    printf("%p", &mynum);       // use %p to output mem. adress and the & symbol(reference operator)

    int* pointer &mynum;        // create a pointer with the * operator and store it in a variable

    printf("%p", pointer);      // prints out the memory address of mynum
    printf("%d", *pointer);     // uses the dereference operator(*) to print out the value of mynum


    int myNumbers[4] = {25, 50, 75, 100};
    int i;

    for (i = 0; i < 4; i++) {                   
        printf("%p\n", &myNumbers[i]);           // prints out the memory address of the elements
                                                 //   0x7ffe70f9d8f0
                                                 //   0x7ffe70f9d8f4
                                                 //   0x7ffe70f9d8f8
                                                 //   0x7ffe70f9d8fc
    // as example. note that the mem. address has an offset of 4 each time and note that an int has 4 bytes
    // so 4bytes * 4int's = 16 bytes array 
    printf("%lu",sizeof(myNumbers)) // 16
    }

    if(&myNumbers == &myNumbers[1]){
        printf("lol");                           // the name of the array has the same mem address as the first element in it
    }                                            

    *(myNumbers +1) = 17; // changes the second element to 17
    // 0x7ffe70f9d8f0 + 1 (4bytes) = 0x7ffe70f9d8f4 and the value at this address is changed to 17


    return 0;
}