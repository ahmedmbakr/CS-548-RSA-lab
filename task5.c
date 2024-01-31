/* task4.c
    Signing a message
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
    BIGNUM *M = BN_new();
    BIGNUM *signature1 = BN_new();
    BIGNUM *generated_M1 = BN_new();
    BIGNUM *signature2 = BN_new();
    BIGNUM *generated_M2 = BN_new();

    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "4C61756E63682061206D697373696C652E"); // This is the hex value of the message "Launch a missile."
    BN_hex2bn(&signature1, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F"); // This is the hex value of the message "Launch a missile."

    BN_hex2bn(&signature2, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F"); // This is the same value as signature1, but we altered the last but one bit to be 3 instead of 2.

    // generated_M1 = signature1^e mod n
    BN_mod_exp(generated_M1, signature1, e, n, ctx);

    printBN("Message = ", M);
    printBN("Signature 1 = ", signature1);

    printf("Validating the signature by comparing the generated message with the original message\n");
    // if generated_M1 == M1, then the signature is valid
    if (BN_cmp(generated_M1, M) == 0)
    {
        printf("Signature1 is valid.\n");
    }
    else
    {
        printf("Signature1 is invalid.\n");
    }

    printf("Check what happens if one bit was altered in the signature\n");


    // generated_M2 = signature2^e mod n
    BN_mod_exp(generated_M2, signature2, e, n, ctx);

    printBN("Message = ", M);
    printBN("Signature 2 = ", signature2);
    printf("Validating the signature by comparing the generated message with the original message\n");
    // if generated_M1 == M, then the signature is valid
    if (BN_cmp(generated_M2, M) == 0)
    {
        printf("Signature2 is valid.\n");
    }
    else
    {
        printf("Signature2 is invalid.\n");
    }

    return 0;
}
