#include<stdio.h>

// enum stands for "specifically listed"
// it is a list of constants 
// its unchangeable

enum Level {        // by default, low has the value 0, medium 1 and high 2
  LOW,  
  MEDIUM,
  HIGH
};

enum Level2 {
  LOW = 20,  
  MEDIUM = 213,
  HIGH = 123231
};

enum Level2 {   // it will assign automatically so med is now 21 and high is 22
  LOW = 20,  
  MEDIUM,
  HIGH 
};

int main(){
    enum Level variable = MEDIUM;       // so variable is 1
    enum Level2 variable = MEDIUM;      // is 213
    return 0;
}