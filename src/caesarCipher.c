//
// Created by drayr on 14/11/2021.
//
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "../includes/caesarCipher.h"

char encrypt(int key, char c)
{
    return isupper(c) ?
                (char) ((c + key - UPPER_CASE_START) % 26 + UPPER_CASE_START) :
           islower(c) ?
                (char) ((c + key - LOWER_CASE_START) % 26 + LOWER_CASE_START) :
           isdigit(c) ?
                (char) ((c + key) % 10) : c;
}

char decrypt(int key, char c)
{
    return isupper(c) ?
           (char) ((c - key - UPPER_CASE_START + 26) % 26 + UPPER_CASE_START) :
           islower(c) ?
           (char) ((c - key - LOWER_CASE_START + 26) % 26 + LOWER_CASE_START) :
           isdigit(c) ?
           (char) ((c - key) % 10) : c;
}


char * caesarEncrypt(int key, char * message)
{
    char * encryptedMessage = malloc(strlen(message));

    for (int i = 0; message[i] != '\0'; ++i)
        encryptedMessage[i] = encrypt(key, message[i]);

    encryptedMessage[strlen(message)] = '\0';
    return encryptedMessage;
}

char * caesarDecrypt(int key, char * message)
{
    char * decryptedMessage = malloc(strlen(message));

    for (int i = 0; message[i] != '\0'; ++i)
        decryptedMessage[i] = decrypt(key, message[i]);

    decryptedMessage[strlen(message)] = '\0';
    return decryptedMessage;
}

void bruteforceKey(char * message)
{
    for (int key = 1; key < 26; ++key)
    {
        char * s = caesarDecrypt(key, message);
        printf("Key %d:\t%s\n", key, s);
        free(s);
        s = NULL;
    }
}