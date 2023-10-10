#include<stdio.h>
int main(){
    FILE *filepointer;  // creates a file pointer variable 
    filepointer = fopen("filename", "mode");    // opens a file 
                        // filename = xxx.txt
                        // mode = w - writing   
                        //        a - Appends new data to a file
                        //        r - reading

    filepointer = fopen("new.txt", "w");  // creates a new file if the file doesnt exisit

    filepointer = fopen("C:\directoryname\filename.txt", "w"); // if u want the file to a special path

    fclose(filepointer); // closes the file to make sure it is saved right and other things

    filepointer = fopen("lol.txt","w") //if u use w to write to the file, the old contnent gets deleted

    fprint(filepointer, "hello"); // use fprint to print to a file

    // Open a file in append mode
    fptr = fopen("filename.txt", "a");

    // Append some text to the file
    fprintf(fptr, "\nHi everybody!");

    fptr = fopen("filename.txt", "r");
    char myString[100];
    fgets(myString, 100, fptr); // stores the first line of the file in the string
        // sring, size, file

    // since fgets gets only the first line of the file u can loop tru it
    while(fgets(myString, 100, fptr)) {
        printf("%s", myString);
    }
    
    fclose(fptr);
    fclose(filepointer);
    return 0;
}