#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Structure for the Caesar Cipher
typedef struct 
{
    char text[1000];
    char result[1000];
    int key;
} caesar;

// Structure for the Caesar Cipher
typedef struct{
    char text[1000];
    char key[1000];
    char result[1000];
}vigenere;

// FUNCTIONS for the Caesar Cipher
void csr_cipher();      
void csr_encrypt();     
void csr_decrypt();     

// FUNCTIONS for the Caesar Cipher
void vig_cipher();     
void vig_encrypt();     
void vig_decrypt();   

// Misc Functions
void uppercase(char*, int);


int main(){
    int choice;
    printf("===========================================================\n");
    printf("             Welcome to the Cipher Machine                 \n");
    printf("===========================================================");

    do{
        printf("\n\nWhat encryption method do you want to do?\n1. Caesar Cipher \n2. Vigenere Cipher \n3. Exit \n(Press 1 for Caesar Cipher, 2 for Vigenere Cipher and 3 to exit the program. ): ");
        scanf(" %d", &choice);
        if(choice == 1){
            csr_cipher();
        }
        else if(choice == 2){
            vig_cipher();
        }
        else if (choice != 1 && choice != 2 && choice != 3) {
            printf("Please enter a valid option!");
            continue;
        }
    }
    while (choice != 3);
    
    printf("Program exited sucessfully!");

    return 0;
}

//========================= Caesar Cipher Fucntion =========
void csr_cipher(){
    
    int Enc_Dec;
    printf("\n-------------------------------------------------------------------------");
    printf("\n\nDo you want to Encrypt or Decrypt the text? \n(1 = Encrypt, 2 = ecrypt): ");
    scanf(" %d", &Enc_Dec);

    while(getchar() != '\n');                                        // Clear the input buffer

    if(Enc_Dec == 1){
        csr_encrypt();
    }
    else if(Enc_Dec == 2){
        csr_decrypt();
    }
    else{
        printf("\nError: Invalid option chosen!");

    }
}
void csr_encrypt(){    
        caesar s1;
        printf("\n-------------------------------------------------------------------------");
        printf("\nEnter the plaintext you want to encrypt: ");
        fgets(s1.text, 1000, stdin);

        //<<| printf("The text you entered is: %s", s1.text);             // for debugging purposes
    
        printf("\nEnter the key (as an integer): ");
        scanf("%d", &s1.key);

        //<<| printf("The key entered is: %d", s1.key);                   // for debugging purposes
        for(int i =0; s1.text[i] != '\0'; i++){

            if(s1.text[i] >= 'a' && s1.text[i] <= 'z'){
                s1.result[i] =  (s1.text[i] - 'a' + s1.key) % 26 + 'a'; 
                //<<| printf("\nThe encrypted char: %s", s1.result);      // for debugging purposes
            }

            else if(s1.text[i] >= 'A' && s1.text[i] <= 'Z'){
                s1.result[i] =  (s1.text[i] - 'A' + s1.key) % 26 + 'A'; 
                //<<| printf("\nThe encrypted char: %s", s1.result);      // for debugging purposes
            }       
            else{
                s1.result[i] =  s1.text[i];
            }     
        } 
        s1.result[strlen(s1.text)] = '\0';

        printf("\n-------------------------------\n");
        printf("The Encrypted Text:\n%s\n", s1.result);
        printf("-------------------------------\n");

}
void csr_decrypt(){
        caesar s1;
        printf("\n-------------------------------------------------------------------------");
        // Taking the ciphertext and the key from the user
        printf("\nEnter the ciphertext you want to decrypt: ");
        fgets(s1.text, 1000, stdin);
        printf("Enter the key (as an integer): ");
        scanf("%d", &s1.key);


        for(int i =0; s1.text[i] != '\0'; i++){
            // For lowercase characters
            if(s1.text[i] >= 'a' && s1.text[i] <= 'z'){
                s1.result[i] =  (s1.text[i] - 'a' - s1.key +26) % 26 + 'a'; 
            }
            // For uppercase characters
            else if(s1.text[i] >= 'A' && s1.text[i] <= 'Z'){
                s1.result[i] =  (s1.text[i] - 'A' - s1.key + 26) % 26 + 'A'; 
            }
            // For non-alphabets       
            else{
                s1.result[i] =  s1.text[i];
            }
        } 
        s1.result[strlen(s1.text)] = '\0';
        printf("\n-------------------------------\n");
        printf("The Decrypted Text:\n%s\n", s1.result);
        printf("-------------------------------\n");
}

//========================= Vigenere Cipher Function =======

void vig_cipher(){

    int Enc_Dec;
    printf("\n-------------------------------------------------------------------------");
    printf("\n\nDo you want to Encrypt or Decrypt the text? \n(1 = Encrypt, 2 = ecrypt): ");
    scanf(" %d", &Enc_Dec);

    while(getchar() != '\n');                                        // To clear the input buffer

    if(Enc_Dec == 1){
        vig_encrypt();
    }
    else if(Enc_Dec == 2){
        vig_decrypt();
    }
    else{
        printf("\nError: Invalid option chosen!");

    }

}
void vig_encrypt(){
    
    vigenere s1;
    printf("\n-------------------------------------------------------------------------");
    printf("\nEnter the plaintext: ");
    fgets(s1.text, 1000, stdin);

    printf("Enter the key (as a string): ");
    fgets(s1.key, 1000, stdin);
    s1.key[strcspn(s1.key, "\n")] = '\0';

    for(int i =0; i< strlen(s1.key); i++){  //  converting to uppercase..
        uppercase(s1.key, i);
    }

    int keyIndex = 0;
    int keyLen = strlen(s1.key);

    for(int i =0; i < strlen(s1.text); i++){
        if(s1.text[i] >= 'a' && s1.text[i] <= 'z'){
            s1.result[i] = ((s1.text[i] - 'a') + (s1.key[keyIndex % keyLen] - 'A')) % 26 + 'a';
            keyIndex++;
            
        }
        else if(s1.text[i] >= 'A' && s1.text[i] <= 'Z'){
            s1.result[i] = ((s1.text[i] - 'A') + (s1.key[keyIndex % keyLen] - 'A')) % 26 + 'A';
            keyIndex++;
        }
        else{
            s1.result[i] = s1.text[i];
        }
    }
    s1.result[strlen(s1.text)] = '\0';
    printf("\n-------------------------------\n");
    printf("The Encrypted Text:\n%s\n", s1.result);
    printf("-------------------------------\n");

}
void vig_decrypt(){
    vigenere s1;
    printf("\n-------------------------------------------------------------------------");    
    printf("\nEnter the ciphertext: ");
    fgets(s1.text, 1000, stdin);

    printf("Enter the key (as an string): ");
    fgets(s1.key, 1000, stdin);

    s1.key[strcspn(s1.key, "\n")] = '\0';

    for(int i =0; i< strlen(s1.key); i++){  //  converting to uppercase..
        uppercase(s1.key, i);
    }

    int keyIndex = 0;
    int keyLen = strlen(s1.key);

    for(int i =0; i < strlen(s1.text); i++){
        if(s1.text[i] >= 'a' && s1.text[i] <= 'z'){
            s1.result[i] = ((s1.text[i] - 'a') - (s1.key[keyIndex % keyLen] - 'A') +26) % 26 + 'a';
            keyIndex++;
            
        }
        else if(s1.text[i] >= 'A' && s1.text[i] <= 'Z'){
            s1.result[i] = ((s1.text[i] - 'A') - (s1.key[keyIndex % keyLen] - 'A') +26) % 26 + 'A';
            keyIndex++;
        }
        else{
            s1.result[i] = s1.text[i];
        }
        
    }
    s1.result[strlen(s1.text)] = '\0';
    printf("\n-------------------------------\n");
    printf("The Decrypted Text:\n%s\n", s1.result);
    printf("-------------------------------\n");
}

void uppercase(char *a, int i){
    if(a[i] >= 'a' && a[i] <= 'z'){
        a[i] = a[i] - 'a' + 'A'; 
    }
}