#include <stdio.h>
#include <string.h>

// Structure for the Caesar Cipher
typedef struct {
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
void csr_break();   

// FUNCTIONS for the Caesar Cipher
void vig_cipher();     
void vig_encrypt();     
void vig_decrypt();   

// Misc Functions
void uppercase(char*, int);
void output(char*);


int main(){
    int choice;
    printf("===========================================================\n");
    printf("             Welcome to the Cipher Machine                 \n");
    printf("===========================================================");

    do{
        printf("\n\nWhat encryption method do you want to use?\n1. Caesar Cipher \n2. Vigenere Cipher \n3. Exit \n(Press 1 for Caesar Cipher, 2 for Vigenere Cipher and 3 to exit the program): ");
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
    
    printf("Program exited sucessfully");

    return 0;
}

//========================= Caesar Cipher Fucntion =========
void csr_cipher(){
    
    int Enc_Dec;
    printf("\n-------------------------------------------------------------------------");
    printf("\n\nDo you want to Encrypt, Decrypt or break the text ? \n(1 = Encrypt, 2 = Derypt, 3 = Break): ");
    scanf(" %d", &Enc_Dec);

    while(getchar() != '\n');                                        // Clear the input buffer

    if(Enc_Dec == 1){
        csr_encrypt();
    }
    else if(Enc_Dec == 2){
        csr_decrypt();
    }
    else if(Enc_Dec == 3){
        csr_break();
    }
    else{
        printf("\nError: Invalid option chosen!");
    }
}
void csr_encrypt(){    
        caesar cipher;
        printf("\n-------------------------------------------------------------------------");
        //Taking plaintext and the key as input
        printf("\nEnter the plaintext you want to encrypt: ");
        fgets(cipher.text, 1000, stdin);
        printf("\nEnter the key (as an integer): ");
        scanf("%d", &cipher.key);

        // Converting the Plaintext to Ciphertext 
        for(int i =0; cipher.text[i] != '\0'; i++){

            if(cipher.text[i] >= 'a' && cipher.text[i] <= 'z'){                 //For lowercase characters
                cipher.result[i] =  (cipher.text[i] - 'a' + cipher.key) % 26 + 'a'; 
            }

            else if(cipher.text[i] >= 'A' && cipher.text[i] <= 'Z'){            //For uppercase characters
                cipher.result[i] =  (cipher.text[i] - 'A' + cipher.key) % 26 + 'A'; 
            }       
            else{                                                       //For non-alphabets
                cipher.result[i] =  cipher.text[i];
            }     
        } 
        cipher.result[strlen(cipher.text)] = '\0';                             //Adds a Null terminator

        // The Output message
        printf("\n-------------------------------\n");
        printf("The Encrypted Text:\n%s", cipher.result);
        printf("-------------------------------\n");
        output(cipher.result);

}
void csr_decrypt(){
        caesar cipher;
        printf("\n-------------------------------------------------------------------------");

        // Taking the ciphertext and the key from the user
        printf("\nEnter the ciphertext you want to decrypt: ");
        fgets(cipher.text, 1000, stdin);
        printf("Enter the key (as an integer): ");
        scanf("%d", &cipher.key);

        // Converting the Ciphertext to Plaintext
        for(int i =0; cipher.text[i] != '\0'; i++){   
            if(cipher.text[i] >= 'a' && cipher.text[i] <= 'z'){                         // For lowercase characters
                cipher.result[i] =  (cipher.text[i] - 'a' - cipher.key +26) % 26 + 'a'; 
            }
            else if(cipher.text[i] >= 'A' && cipher.text[i] <= 'Z'){                    // For uppercase characters
                cipher.result[i] =  (cipher.text[i] - 'A' - cipher.key + 26) % 26 + 'A'; 
            }     
            else{                                                               // For non-alphabets  
                cipher.result[i] =  cipher.text[i];
            }
        } 
        cipher.result[strlen(cipher.text)] = '\0';

        //The Output message
        printf("\n-------------------------------\n");
        printf("The Decrypted Text:\n%s", cipher.result);
        printf("-------------------------------\n");
        output(cipher.result);
}
void csr_break(){

        caesar cipher;
        cipher.key = 0;
        char Y_N;
        printf("\n-------------------------------------------------------------------------");
        //Taking Ciphertext as input
        printf("\nEnter the Ciphertext you want to break: ");
        fgets(cipher.text, 1000, stdin);
        
        for(int j = 1; cipher.key < 26;){
            for(int i =0; cipher.text[i] != '\0'; i++){   
                if(cipher.text[i] >= 'a' && cipher.text[i] <= 'z'){                // For lowercase characters
                    cipher.result[i] =  (cipher.text[i] - 'a' - cipher.key +26) % 26 + 'a'; 
                }
                else if(cipher.text[i] >= 'A' && cipher.text[i] <= 'Z'){           // For uppercase characters
                    cipher.result[i] =  (cipher.text[i] - 'A' - cipher.key + 26) % 26 + 'A'; 
                }     
                else{                                                               // For non-alphabets  
                    cipher.result[i] =  cipher.text[i];
                }
            } 
            cipher.result[strlen(cipher.text)] = '\0';

            printf("\n-------------------------------\n");
            printf("The Encrypted Text:\n%s", cipher.result);
            printf("-------------------------------\n");
            cipher.key += 1;
        }
}

//========================= Vigenere Cipher Function =======

void vig_cipher(){

    int Enc_Dec;
    printf("\n-------------------------------------------------------------------------");
    printf("\n\nDo you want to Encrypt or Decrypt the text? \n(1 = Encrypt, 2 = Decrypt): ");
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
    
    vigenere cipher;
    printf("\n-------------------------------------------------------------------------");
    printf("\nEnter the plaintext: ");
    fgets(cipher.text, 1000, stdin);

    printf("Enter the key (as a string): ");
    fgets(cipher.key, 1000, stdin);
    cipher.key[strcspn(cipher.key, "\n")] = '\0';

    for(int i =0; i< strlen(cipher.key); i++){  //  converting to uppercase..
        uppercase(cipher.key, i);
    }

    int keyIndex = 0;
    int keyLen = strlen(cipher.key);

    for(int i =0; i < strlen(cipher.text); i++){
        if(cipher.text[i] >= 'a' && cipher.text[i] <= 'z'){
            cipher.result[i] = ((cipher.text[i] - 'a') + (cipher.key[keyIndex % keyLen] - 'A')) % 26 + 'a';
            keyIndex++;
            
        }
        else if(cipher.text[i] >= 'A' && cipher.text[i] <= 'Z'){
            cipher.result[i] = ((cipher.text[i] - 'A') + (cipher.key[keyIndex % keyLen] - 'A')) % 26 + 'A';
            keyIndex++;
        }
        else{
            cipher.result[i] = cipher.text[i];
        }
    }
    cipher.result[strlen(cipher.text)] = '\0';
    printf("\n-------------------------------\n");
    printf("The Encrypted Text:\n%s", cipher.result);
    printf("-------------------------------\n");
    output(cipher.result);
}
void vig_decrypt(){
    vigenere cipher;
    printf("\n-------------------------------------------------------------------------");    
    printf("\nEnter the ciphertext: ");
    fgets(cipher.text, 1000, stdin);

    printf("Enter the key (as an string): ");
    fgets(cipher.key, 1000, stdin);

    cipher.key[strcspn(cipher.key, "\n")] = '\0';

    for(int i =0; i< strlen(cipher.key); i++){  //  converting to uppercase..
        uppercase(cipher.key, i);
    }

    int keyIndex = 0;
    int keyLen = strlen(cipher.key);

    for(int i =0; i < strlen(cipher.text); i++){
        if(cipher.text[i] >= 'a' && cipher.text[i] <= 'z'){
            cipher.result[i] = ((cipher.text[i] - 'a') - (cipher.key[keyIndex % keyLen] - 'A') +26) % 26 + 'a';
            keyIndex++;
            
        }
        else if(cipher.text[i] >= 'A' && cipher.text[i] <= 'Z'){
            cipher.result[i] = ((cipher.text[i] - 'A') - (cipher.key[keyIndex % keyLen] - 'A') +26) % 26 + 'A';
            keyIndex++;
        }
        else{
            cipher.result[i] = cipher.text[i];
        }
        
    }
    cipher.result[strlen(cipher.text)] = '\0';
    printf("\n-------------------------------\n");
    printf("The Decrypted Text:\n%s", cipher.result);
    printf("-------------------------------\n");
    output(cipher.result);
}

void uppercase(char *a, int i){
    if(a[i] >= 'a' && a[i] <= 'z'){
        a[i] = a[i] - 'a' + 'A'; 
    }
}

void output(char *a){
    FILE *fptr;
    fptr = fopen("output.txt", "w");

    fprintf(fptr, "===== THE OUTPUT RESULT =======\n");
    fprintf(fptr, "%s\n", a);

    printf("\nThe output has been written to the file \"output.txt\".");

    fclose(fptr);
}