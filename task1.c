/* task1.c
    Deriving the private key d from p, q, and e
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

    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *p_minus_1 = BN_new();
    BIGNUM *q_minus_1 = BN_new();
    BIGNUM *phi_n = BN_new();
    BIGNUM *d_mul_e = BN_new();

    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF"); // big prime number
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F"); // big prime number
    BN_hex2bn(&e, "0D88C3");

    // n = p * q
    BN_mul(n, p, q, ctx);
    
    // p_minus_1 = p - 1
    p_minus_1 = BN_dup(p);
    BN_sub(p_minus_1, p_minus_1, BN_value_one());

    // q_minus_1 = q - 1
    q_minus_1 = BN_dup(q);
    BN_sub(q_minus_1, q_minus_1, BN_value_one());

    // phi_n = (p - 1) * (q - 1)
    BN_mul(phi_n, p_minus_1, q_minus_1, ctx);

    // d = e^-1 mod phi_n
    BN_mod_inverse(d, e, phi_n, ctx);

    printf("This is task 1\n");
    printBN("p = ", p);
    printBN("q = ", q);
    printBN("n = ", n);
    printBN("e = ", e);
    printBN("d = ", d);
    printf("To verify that d is correct, we calculate e * d mod phi_n, which should equal to 1 \n");
    BN_mod_mul(d_mul_e, d, e, phi_n, ctx);
    printBN("d * e mod phi_n = ", d_mul_e);

    return 0;
}
