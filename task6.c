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
    BIGNUM *e = BN_new(); // punlic exponent (key)
    BIGNUM *M = BN_new(); // hash of the certificate body
    BIGNUM *signature = BN_new(); // CA's signature
    BIGNUM *generated_M = BN_new(); // generated_M = signature^e mod n

    BN_hex2bn(&n, "CCF710624FA6BB636FED905256C56D277B7A12568AF1F4F9D6E7E18FBD95ABF260411570DB1200FA270AB557385B7DB2519371950E6A41945B351BFA7BFABBC5BE2430FE56EFC4F37D97E314F5144DCBA710F216EAAB22F031221161699026BA78D9971FE37D66AB75449573C8ACFFEF5D0A8A5943E1ACB23A0FF348FCD76B37C163DCDE46D6DB45FE7D23FD90E851071E51A35FED4946547F2C88C5F4139C97153C03E8A139DC690C32C1AF16574C9447427CA2C89C7DE6D44D54AF4299A8C104C2779CD648E4CE11E02A8099F04370CF3F766BD14C49AB245EC20D82FD46A8AB6C93CC6252427592F89AFA5E5EB2B061E51F1FB97F0998E83DFA837F4769A1");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "b2825cb7d71ec7093e7ff7026c562a29122de3b4900ed13dad63d1be73706e0d"); // This is the hash of the certificate body
    BN_hex2bn(&signature, "04e16e023e0de32346f4e3963505933522020b845de27386d4744ffc1b27af3ecaadc3ce46d6fa0fe271f90d1a9a13b7d50848bd5058b35e20638629ca3ecccc7826e1598f5dca8bbc49316f61bd42ff6162e1223524269b57ebe5000dff40336c46c233770898b27af643f96d48dfbffefa281e7b8acf2d61ff6c8798a42c629abb108cff34487066b76d72c369f9394b683956bda1b36df477f3465b5c19ac4fb3746b8cc5f189cc93fe0c016f8817dc427160e3ed7330429ca92f3ba2788ec86fbad1130cd0c75e8c10fb012e379bdbacf7a1acba7ff892e7cb4144c815f9f3c4bbad515fbedec7ac86079f40ecb90bf6b28bccb5553366ba33c2c4f0a2e9"); // This is the signature of CA on the server's certificate

    // generated_M = signature^e mod n
    BN_mod_exp(generated_M, signature, e, n, ctx); // Generate the hash of the body of the certificate. It has to match the original hash of the body of the certificate.

    printBN("N = ", n);
    printBN("e = ", e);
    printBN("Original hash of the certificate's body = ", M);
    printBN("Generated hash of the certificate's body = ", generated_M);
    printBN("Signature = ", signature);

    printf("Validating the signature by comparing the generated hash of the hash of body of the certificate with the original hash of the body of the certificate\n");
    // if generated_M1 == M1, then the signature is valid
    if (BN_cmp(generated_M, M) == 0)
    {
        printf("Signature is valid.\n");
    }
    else
    {
        printf("Signature is invalid.\n");
    }

    return 0;
}
