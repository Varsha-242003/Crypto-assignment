#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to encrypt a single character
long long encrypt(long long m, long long e, long long n) {
    long long result = 1;
    while (e > 0) {
        if (e & 1)
            result = (result * m) % n;
        m = (m * m) % n;
        e >>= 1;
    }
    return result;
}

// Function to decrypt a single character
long long decrypt(long long c, long long d, long long n) {
    long long result = 1;
    while (d > 0) {
        if (d & 1)
            result = (result * c) % n;
        c = (c * c) % n;
        d >>= 1;
    }
    return result;
}

int main() {
    long long e, d, n;
    char word[MAX_WORD_LENGTH];
    long long encrypted[MAX_WORD_LENGTH];

    // Get RSA parameters from user
    printf("Enter the value for n: ");
    scanf("%lld", &n);

    printf("Enter the public exponent e: ");
    scanf("%lld", &e);

    printf("Enter the private exponent d: ");
    scanf("%lld", &d);

    // Consume the newline character
    getchar();

    // Get word from user
    printf("Enter a word to encrypt: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0; // Remove trailing newline if present

    // Encrypt each character
    printf("\nEncrypted values:\n");
    for (int i = 0; word[i] != '\0'; i++) {
        encrypted[i] = encrypt(word[i], e, n);
        printf("%c: %lld\n", word[i], encrypted[i]);
    }

    // Decrypt and print the result
    printf("\nDecrypted word: ");
    for (int i = 0; word[i] != '\0'; i++) {
        long long decrypted = decrypt(encrypted[i], d, n);
        printf("%c", (char)decrypted);
    }
    printf("\n");

    return 0;
}

/* OUTPUT
Enter the value for n: 3233
Enter the public exponent e: 17
Enter the private exponent d: 2753
Enter a word to encrypt: HELLOWORLD

Encrypted values:
H: 3000
E: 28
L: 2726
L: 2726
O: 1307
W: 604
O: 1307
R: 1859
L: 2726
D: 1759

Decrypted word: HELLOWORLD
*/
