#include<stdio.h>

void function(){     // declaration
    printf("LOL");      // definition (the body)
}

void newfunc();
                        // also possible
void newfunc(){
    // code;        
}

// use void to show that the function returns nothing
void newfunction(){     // creates a function that prints Lol
    printf("LOL");
}

void newfunction2(char name[], int age){     // function requieres an string name, and an int age
    printf("LOL");
}

int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);      // recursion, let a function call itself
  } else {
    return 0;
  }
}


int main(){
    newfunction();
    newfunction2("Miram", 23);          
    return 0;
}