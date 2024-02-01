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
    BIGNUM *M1 = BN_new();
    BIGNUM *M2 = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *signature1 = BN_new();
    BIGNUM *signature2 = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5"); // This is the public modulus (part of the public key)
    BN_hex2bn(&e, "010001"); // This is the public exponent (the other part of the public key)
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D"); // The private key
    BN_hex2bn(&M1, "41686D656442616B722D3132323930323134206F77657320796F752024323030302E"); // This is the hex value of the message "AhmedBakr-12290214 owes you $2000."
    BN_hex2bn(&M2, "41686D656442616B722D3132323930323134206F77657320796F752024333030302E"); // This is the hex value of the message "AhmedBakr-12290214 owes you $3000."

    // signature1 = M1^d mod n
    BN_mod_exp(signature1, M1, d, n, ctx);

    // signature2 = M2^d mod n
    BN_mod_exp(signature2, M2, d, n, ctx);

    printBN("n = ", n);
    printBN("e = ", e);
    printBN("d = ", d);
    printBN("Message 1 = ", M1);
    printBN("Signature 1 = ", signature1);
    printBN("Message 2 = ", M2);
    printBN("Signature 2 = ", signature2);

    return 0;
}
