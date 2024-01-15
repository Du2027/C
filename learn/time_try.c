#include<time.h>
#include<stdio.h>

int main(){
    time_t time_1 = time(NULL);
    printf("? : %ld", time_1);
    return 0;
}