//
// Created by drayr on 14/11/2021.
//

#ifndef CAESARCIPHER_CAESARCIPHER_H
#define CAESARCIPHER_CAESARCIPHER_H

#define UPPER_CASE_START 'A'
#define LOWER_CASE_START 'a'

char encrypt(int key, char c);
char decrypt(int key, char c);
char * caesarEncrypt(int key, char * message);
char * caesarDecrypt(int key, char * message);
void bruteforceKey(char * message);

#endif //CAESARCIPHER_CAESARCIPHER_H
