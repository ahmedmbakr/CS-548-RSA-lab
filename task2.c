/* task2.c
    Encrypting a message
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
    BIGNUM *d = BN_new();
    BIGNUM *C = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&M, "41686D656442616B722D3132323930323134"); // This is the hex value of the message "AhmedBakr-12290214"

    // C = M^e mod n
    BN_mod_exp(C, M, e, n, ctx); // The cipher text is stored in C

    printBN("n = ", n);
    printBN("e = ", e);
    printBN("d = ", d);
    printBN("Message = ", M);
    printBN("Encrypted Message = ", C);

    return 0;
}
