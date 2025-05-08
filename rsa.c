#include <stdio.h>
#include <math.h>

static inline unsigned long long ipow_modular(unsigned long long b, unsigned long long e, unsigned long long m)
{
    /*
        computacao de (b^e) mod m pelo algoritmo de
        exponenciacao modular rapida
    */
    unsigned long long b_pow_e = 1;
    for (int i = 0; i < e; i++)
    {
        b_pow_e = (b * b_pow_e) % m;
    }
    return b_pow_e;
}

long long int euclides_extendido(long long int a, long long int b, long long int *x, long long int *y)
{
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long int x1, y1;
    long long int d = euclides_extendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return d;
}

static inline unsigned long long inverso_modular(unsigned long long d, unsigned long long m)
{
    unsigned long long x, y;
    euclides_extendido(a, b, &x, &y);
    unsigned long long int inverso_d = x % b;
    return (inverso_d < 0) ? inverso_d + b: inverso_d;
}

void cifrar(char *mensagem, unsigned long long n, unsigned long long e)
{
    //  contabilizar quantidade de caracteres na mensagem
    const unsigned N = strlen(mensagem);

    //  abrir arquivo para salvar mensagem encriptada
    FILE *mensagem_encriptada = fopen("mensagem-cifrada.txt", "w");

    //  encriptar mensagem caractere a caractere
    for (size_t i = 0; i < N; i++)
    {
        // escreva o caractere cifrado separado por ' '
        fprintf(mensagem_encriptada, "%c ", ipow_modular((int)mensagem[i], e, n));
    }

    return;
}

void decifrar(char *cifrada, unsigned long long p, unsigned long long q, unsigned long long e)
{
    //  contabilizar quantidade de caracteres na mensagem
    const unsigned N = strlen(mensagem);

    //  obter a chave privada
    const unsigned long long n = p * q;
    unsigned long long d = inverso_modular(e, /* (p - q) * (q - 1) = pq - q - p + 1 = */n - p - q + 1);

    //  abrir arquivo para salvar mensagem encriptada
    FILE *mensagem = fopen("mensagem.txt", "w");

    //  desencriptar mensagem caractere a caractere
    for (size_t i = 0; i < N; i++)
    {
        // escreva o caractere decifrado separado por ' '
        fprintf(mensagem, "%c ", ipow_modular((int)cifrada[i], d, n));
    }

    return;
}
