#include<stdio.h>
int main(){
    int var2 = 0;
    const var3 = 0;             // creates a constante variable
    int var = 0;              // creates a  int type varible with the value 0
    printf("%lu",sizeof(var)) // use sizeof(var) to see the variables size in bytes
                              // the compiler expects the sizeof operator to return a long unsigned int
                              // its better to use it but works with an int too, but with %lu its safer


    printf("%d",var);         // for an int value u need the %d format specifier to print something to the console
                              // use \n to go to a new line in the console in a printf statement
    scanf("%d", &var);        // Console waits until user inputs something and puts it into var
    scanf("%d %d", &var, &var2)       // awaits 2 inputs       
    return 0;
}                           

/*
char	        1 byte	                            -128 to 127 or 0 to 255
unsigned char	1 byte	                            0 to 255
signed char	    1 byte	                            -128 to 127
int	            2 or 4 bytes	                    -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
unsigned int	2 or 4 bytes	                    0 to 65,535 or 0 to 4,294,967,295
short	        2 bytes	                            -32,768 to 32,767
unsigned short	2 bytes	                            0 to 65,535
long	        8 bytes or (4bytes for 32 bit OS)	-9223372036854775808 to 9223372036854775807
unsigned long	8 bytes	                            0 to 18446744073709551615


%c	                Character
%d	                Signed integer
%f	                Float values
%hi	                Signed integer (short)
%hu	                Unsigned Integer (short)
%i	                Unsigned integer
%l or %ld or %li	Long
%lf	                Double
%Lf	                Long double
%lu	                Unsigned int or unsigned long
%lli or %lld	    Long long
%llu	            Unsigned long long
%p	                Pointer
%s	                String
%u	                Unsigned int
%x or %X	        Hexadecimal representation
*/