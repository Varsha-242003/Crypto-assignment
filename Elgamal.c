#include <stdio.h>
#include <stdlib.h>

long long mod_pow(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

long long mod_inverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    return x < 0 ? x + m0 : x;
}

int main() {
    long long e1, e2, r, d, p, m, c1, c2, decrypted;
    
    // Input El-Gamal parameters
    printf("Enter El-Gamal parameters (e1 e2 r d p): ");
    scanf("%lld %lld %lld %lld %lld", &e1, &e2, &r, &d, &p);
    
    // Input message
    printf("Enter message to encrypt (as number): ");
    scanf("%lld", &m);
    
    // Encryption
    c1 = mod_pow(e1, r, p);
    c2 = (m * mod_pow(e2, r, p)) % p;
    printf("\nCiphertext (c1 c2): %lld %lld\n", c1, c2);
    
    // Decryption
    long long temp = mod_pow(c1, d, p);
    long long temp_inv = mod_inverse(temp, p);
    decrypted = (c2 * temp_inv) % p;
    printf("Decrypted: %lld\n", decrypted);
    
    return 0;
}

/* OUTPUT
