#include <stdio.h>
#include <string.h>

// CAESAR STRUCTURE...
typedef struct 
{
    char text[1000];
    int key;
} caesar;


int main(){
    printf("===========================================================\n");
    printf("             Welcome to the Cipher Machine                 \n");
    printf("===========================================================\n\n");



    // the caesar code
    caesar s1;


    printf("Enter the plaintext: ");
    fgets(s1.text, 1000, stdin);

    printf("The text you entered is: %s", s1.text);
    
    
    
    getchar();
    return 0;
}