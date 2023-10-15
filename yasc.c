//Imports
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variables
    char phrase[10000]; //The phrase that will be encrypted or decrypted.
    int mode = 0; // Creates mode variable, to determine whether to encrypt or decrypt. Set to 2 to set for neither.
    char newCharacter; //Sets temp variable for changing the characters.

// MAIN FUNCTION
int main() {
    // ASK FOR MODE
    printf("--SELECT MODE--\n\v"); // Select Mode Text
    printf("Type the number for the mode you wish to use.\n\v"); //Instructions
    printf("(1) Encryption\n\v"); // Option 1: Encryption
    printf("(2) Decryption\n\v"); // Option 2: Decryption
    scanf("%d", &mode); // Grabs Input

    // MESSAGE INPUT
    printf("\n\vType/Insert your message to "); // Asks for message input.
    if (mode == 1){ //Decides Final Word
        printf("Encrypt: \n\v"); //Says Encrypt
    } else if (mode == 2){
        printf("Decrypt: \n\v"); //Says Decrypt
    }
    scanf(" %[^\n]", phrase); // Grabs Input


    // INITIATING THE FUNCTIONS
    if (mode == 1) {
        encrypt(); // Initiates Encrypt Function
    } else if (mode == 2) {
        decrypt(); // Initiates Decrypt Function
    }

    //OUTRO
    printf("\n\vFeel free to copy it from your terminal!\n\v"); // Prints outro line
    return 0; // Return Function for Main (Unused, but needed for C).
}

// ENCRYPTION FUNCTION
int encrypt() {
    printf("\n\vYour encrypted phrase is:\n\v"); // Prints intro line
    for (int i = 0; i < strlen(phrase); i++) { // Loops if i is less than the string length.
        newCharacter = phrase[i]; //Sets the New Character Variable equal to the current character of the array (i).
        if ((newCharacter > 127) && (newCharacter < 165)) {  
            newCharacter = newCharacter + 4; // Adds some Non-English Letters by 14 to avoid conflicts.
        } else if (newCharacter < 57){
            newCharacter = newCharacter;
        } else {
            newCharacter = newCharacter - 7; // Subtracts English Alphabet and a few Non-English Letters by 29.
        }
        phrase[i] = newCharacter; // Adds random letter to the array, gradually creating the encrypted phrase.
        printf("%c", phrase[i]); // Writes each letter of the new phrase.  
    }
    return 0; // Return Function for Main (Unused, but needed for C)
}

// DECRYPTION FUNCTION
int decrypt() {
    printf("\n\vYour encrypted phrase is:\n\v"); // Prints intro line
    for (int i = 0; i < strlen(phrase); i++) { // i was chosen to start at 1 due to character limits typically starting at 1 and not 0.
        newCharacter = phrase[i]; //Sets the New Character Variable equal to the current character of the array (i).
        if ((newCharacter > 127) && (newCharacter < 165)) {  
            newCharacter = newCharacter - 4; // Subtracts some Non-English Letters by 14 to avoid conflicts, and bringing them back where they should be.
        } else if (newCharacter < 57){
            newCharacter = newCharacter;
        } else {
            newCharacter = newCharacter + 7; // Adds English Alphabet and a few Non-English Letters by 29, bringing them back where they should be.
        }
        phrase[i] = newCharacter; // Adds random letter to the array, gradually creating the decrypted phrase.
        printf("%c", phrase[i]); // Writes each letter of the new phrase.  
    }
    return 0; // Return Function for Main (Unused, but needed for C)
}