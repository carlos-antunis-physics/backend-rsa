#include <gmp.h>
#include "RSA.c"

int main()
{
    short answer = -1;


    main_loop:
        printf("Which operation do you want to perform?\n");
        printf("[1] Generate public key\n");
        printf("[2] Encrypt a message\n");
        printf("[3] Decrypt a message\n");
        printf("[0] Exit\n");
        printf("Operation: ");
        scanf("%hd", &answer);
        if (answer == 0)
        {
            return 0;
        }
        if (answer == 1)
        {
            mpz_t p, q, e;
            mpz_init(p);
            mpz_init(q);
            mpz_init(e);
            printf("Enter prime p: ");
            gmp_scanf("%Zd", p);
            printf("Enter prime q: ");
            gmp_scanf("%Zd", q);
            printf("Enter value of e: ");
            gmp_scanf("%Zd", e);
            // Generate public key
            public_key_result_t r = generatePublicKey(p, q, e);
            if (r != KEY_VALID)
            {
                printf("Error generating public key: ");
                switch (r)
                {
                    case KEY_ERROR_INVALID_PRIMES:
                        printf("Invalid primes.\n");
                        break;
                    case KEY_ERROR_INVALID_E:
                        printf("Invalid e - not coprime to (p - 1)(q - 1).\n");
                        break;
                }
            }
            mpz_clear(p);
            mpz_clear(q);
            mpz_clear(e);
            goto main_loop;
        }
        if (answer == 2)
        {
            size_t len;
            printf("Enter the number of characters in the message: ");
            scanf("%u", &len);
            char message[len];
            mpz_t n, e;
            mpz_init(n);
            mpz_init(e);
            printf("Enter the message: ");
            scanf("%s", message);
            printf("Enter the public key (n e): ");
            gmp_scanf("%Zd %Zd", n, e);
            // Encrypt message
            encryptMessage(message, n, e);
            mpz_clear(n);
            mpz_clear(e);
            goto main_loop;
        }
        if (answer == 3)
        {
            size_t len;
            printf("Enter the number of characters in the message: ");
            scanf("%u", &len);
            mpz_t p, q, e;
            mpz_t ciphertext[len];
            mpz_init(p);
            mpz_init(q);
            mpz_init(e);
            for (size_t i = 0; i < len; i++)
            {
                mpz_init(ciphertext[i]);
            }
            printf("Enter the ciphertext: ");
            for (size_t i = 0; i < len; i++)
            {
                gmp_scanf("%Zd", ciphertext[i]);
            }
            printf("Enter the private key (p q e): ");
            gmp_scanf("%Zd %Zd %Zd", p, q, e);
            // Decrypt message
            decryptMessage(ciphertext, len, p, q, e);
            mpz_clear(p);
            mpz_clear(q);
            mpz_clear(e);
            for (size_t i = 0; i < len; i++)
            {
                mpz_clear(ciphertext[i]);
            }
            goto main_loop;
        }
        else
        {
            answer = -1;
            printf("Invalid option. Please try again.\n");
            goto main_loop;
        }
}
