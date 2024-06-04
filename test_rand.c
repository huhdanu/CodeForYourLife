/* comment require */


/* Standard lib */
#include <stdio.h>  		/* for scanf and printf */	
#include <stdlib.h>		/* for dynamic allocation */
#include <string.h>		/* for strlen */			


/**************************** Prototype ******************************/


/* Macro */
void Copy(char* a, char* b){
    int dataLength = 0;
    int i;
    while (*a != '\0')
    {
        dataLength++;
        a++;
    }

    a = a - dataLength;
    for (i = 0; i < dataLength; i++)
    {
        b[i] = a[i];
    }
    b[i] = '\0';
}

void PrintString(char* str){
    while(*str != '\0'){
        printf("%c ",*str);
        str++;
    }
}

/* Main function */
int main() {
    char a[5] = "abc"; 
    char b[5]; 

    PrintString(a);
    Copy(a,b);
    PrintString(b);
   
}