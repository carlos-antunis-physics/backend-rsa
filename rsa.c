#include <stdio.h>
#include <math.h>
#include <string.h>

static inline unsigned long long ipow_modular(unsigned long long b, unsigned long long e, unsigned long long m)
{
    /*
        computacao de (b^e) mod m pelo algoritmo de
        exponenciacao modular rapida
    */
    unsigned long long b_pow_e = 1;
    b %= m;
    for (int i = 0; i < e; i++)
    {
        b_pow_e = (b * b_pow_e) % m;
    }
    return b_pow_e;
}

unsigned long long euclides_extendido(unsigned long long a, unsigned long long b, unsigned long long *x, unsigned long long *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    unsigned long long x1, y1;
    unsigned long long d = euclides_extendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return d;
}

static inline unsigned long long inverso_modular(unsigned long long d, unsigned long long m)
{
    unsigned long long x, y;
    euclides_extendido(d, m, &x, &y);
    unsigned long long int inverso_d = x % m;
    return (inverso_d < 0) ? inverso_d + m : inverso_d;
}

void cifrar(char *mensagem, unsigned long long n, unsigned long long e)
{
    //  contabilizar quantidade de caracteres na mensagem
    const unsigned N = strlen(mensagem);

    //  abrir arquivo para salvar mensagem encriptada
    // FILE *mensagem_encriptada = fopen("cifrada.txt", "w");

    //  encriptar mensagem caractere a caractere
    for (size_t i = 0; i < N; i++)
    {
        // escreva o caractere cifrado separado por ' '
        printf("%llu ", ipow_modular((int)mensagem[i], e, n));
    }

    // fprintf(mensagem_encriptada, "\n");
    // fclose(mensagem_encriptada);

    return;
}

void decifrar(unsigned long long *cifrada, const unsigned N, unsigned long long p, unsigned long long q, unsigned long long e)
{
    //  obter a chave privada
    const unsigned long long n = p * q;
    unsigned long long d = inverso_modular(e, /* (p - 1) * (q - 1) = p*q - p*1 - 1*q + (-1)*(-1) = */ n - p - q + 1);

    //  abrir arquivo para salvar mensagem encriptada
    // FILE *mensagem = fopen("mensagem.txt", "w");

    //  desencriptar mensagem caractere a caractere
    for (size_t i = 0; i < N; i++)
    {
        // escreva o caractere decifrado separado por ' '
        printf("%llu ", ipow_modular(cifrada[i], e, n));
    }

    // fprintf(mensagem, "\n");
    // fclose(mensagem);
    
    return;
}

long long mdc(long long a, long long b)
{
    long long r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

short eh_primo(long long unsigned n)
{
    const short False = 0, True = 1;
    for (int i = 2; i * i <= n; i++)
    { // para todos os possiveis divisores
        //  caso o resto da divisao entre n e o divisor seja 0
        if (!(n % i))
        {
            return False; // o numero eh composto
        }
    }
    //  caso nenhum dos possiveis divisores o divida
    return True; // o numero eh primo
}

long long unsigned gerarChave(long long unsigned p, long long unsigned q, long long unsigned e)
{
    long long unsigned mult = (p - 1) * (q - 1);
    if (!(eh_primo(p) && eh_primo(q)))
    {
        printf("insira apenas numeros primos");
        return 0;
    }

    long long unsigned n = p * q;

    if (mdc(e, mult) != 1)
    {
        printf("insira um 'e' que seja coprimo a p e q");
        return 0;
    }
    else
    {
        return n;
    }
}

int main()
{
    short resposta;
    printf("qual operacao voce deseja operar?\n");
    printf("[1] gerar chave publica\n");
    printf("[2] encriptar uma mensagem\n");
    printf("[3] desencriptar uma mensagem\n");
    printf("operacao: ");
    scanf("%hd", &resposta);
    if (resposta == 1)
    {
        unsigned long long p, q, e;
        printf("insira o primo p: ");
        scanf("%llu", &p);
        printf("insira o primo q: ");
        scanf("%llu", &q);
        printf("insira o valor de e (coprimo a (p - 1)(q - 1)): ");
        scanf("%llu", &e);
        // gerar chave
        printf("chave publica: %llu %llu\n", gerarChave(p, q, e), e);
    }
    else if (resposta == 2)
    {
        unsigned len;
        printf("insira a quantidade de caracteres na mensagem: ");
        scanf("%u", &len);
        char mensagem[len];
        unsigned long long n, e;
        // encriptar
        printf("insira a mensagem: ");
        scanf("%s", mensagem);
        printf("insira a chave publica: ");
        scanf("%llu%llu", &n, &e);
        printf("a mensagem cifrada e:\n");
        cifrar(mensagem, n, e);
    }
    else if (resposta == 3)
    {
        unsigned len;
        printf("insira a quantidade de caracteres na mensagem: ");
        scanf("%u", &len);
        unsigned long long p, q, e;
        unsigned long long mensagem[len];
        // desencriptar
        printf("insira a mensagem cifrada: ");
        for (size_t i = 0; i < len; i++)
        {
            scanf("%llu", &mensagem[i]);
        }
        printf("insira a chave privada: ");
        scanf("%llu%llu%llu", &p, &q, &e);
        decifrar(mensagem, len, p, q, e);
    }
}
