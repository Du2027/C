#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char hello[] = "Hello World"; // actually creates a list with the characters
    char greetings[] = "Hello World!";
    printf("%c", hello[0]);     // since hello is actually a list you can print out an index
    hello[0] = 'J';             // change Hello World to Jello World
    printf("%s", hello)

    char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'}; // \0 to tell that the string ends here
    // also possible since both ways create a list of chars

    // u cant put "" or '' or \ in a string like the normal way u have to use \' or \" or \\

    // u can use \n to go to a new line or \t to make a tab


    //------------------------------------------------string functions
    int string_lenght = strlen(hello); // get lenght of str
    int string_lenght = sizeof(hello); // does the same but includes the \0

    char result[40]; 
    strcat(result,hello) // copies the hello array and puts it in result array

    strcpy(result, "hello"); // assigns hello to result

    strcmp(result,hello) // returns -4 if strings are not equal and 0 if they are

    char a = "a";       
    char A = toupper(a);            // possiable because of the ctype.h header
    char a = tolower(toupper(a));

    return 0;
}