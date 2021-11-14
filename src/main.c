#include <stdio.h>
#include <stdlib.h>

#include "../includes/caesarCipher.h"

int main() {
    char s[] = "Panda Love";
    int key = 3;
    printf("Original Message: %s\n", s);
    printf("Encryption Key: %d\n", key);

    char * encryptedMessage = caesarEncrypt(key, s);
    printf("Encrypted Message: %s\n", encryptedMessage);

    char * decryptedMessage = caesarDecrypt(key, encryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    free(decryptedMessage);

    puts("\nBruteforcing the key..");
    bruteforceKey(encryptedMessage);
    free(encryptedMessage);
    return EXIT_SUCCESS;
}
