/* task3.c
    Decrypting a message
 */
#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM * a)
{
   /* Use BN_bn2hex(a) for hex string
    * Use BN_bn2dec(a) for decimal string */
   char * number_str = BN_bn2hex(a);
   printf("%s %s\n", msg, number_str);
   OPENSSL_free(number_str);
}

int main()
{
    BN_CTX *ctx = BN_CTX_new();

    BIGNUM *n = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *decrypted_M = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *C = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&C, "AE452DAD235C88BA4C15A7D81E3082E2F536D90A61ECD4AEC5A02D01B535B4AD"); // This is the encryption value from the previous task 2

    // decrypted_M = C^d mod n
    BN_mod_exp(decrypted_M, C, d, n, ctx); // The decrypted text is stored in decrypted_M

    printBN("n = ", n);
    printBN("e = ", e);
    printBN("d = ", d);
    printBN("Encrypted Message = ", C);
    printBN("Decrypted Message = ", decrypted_M);

    return 0;
}
