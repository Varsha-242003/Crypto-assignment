#include <stdio.h>
#include <ctype.h>

int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

void affine_encrypt(char *plaintext, int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = ((a * (plaintext[i] - 'A') + b) % 26) + 'A';
        }
    }
}

void affine_decrypt(char *ciphertext, int a, int b) {
    int a_inv = mod_inverse(a, 26);
    if (a_inv == -1) {
        printf("Error: 'a' and 26 are not coprime, decryption not possible.\n");
        return;
    }

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = ((a_inv * (ciphertext[i] - 'A' - b + 26)) % 26) + 'A';
        }
    }
}

int main() {
    char text[100];
    int a, b;

    printf("Enter the text to encrypt (uppercase letters only): ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the value of 'a' and 'b' for the Affine Cipher:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("Original Text: %s\n", text);
    affine_encrypt(text, a, b);
    printf("Encrypted Text: %s\n", text);

    affine_decrypt(text, a, b);
    printf("Decrypted Text: %s\n", text);

    return 0;
}

/*
Enter the text to encrypt (uppercase letters only): VARSHA
Enter the value of 'a' and 'b' for the Affine Cipher:
a: 5
b: 2
Original Text: VARSHA

Encrypted Text: DCJOLC

Decrypted Text: VARSHA
*/
