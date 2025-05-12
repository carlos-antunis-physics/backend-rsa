#include "./backend.c"


int main(int argc, char const *argv[])
{
    printf("==============================================================\n");
    printf("====  RSA Protocol backend test using Emscripten and GMP  ====\n");
    printf("==============================================================\n");

    short operacao;

    while (true)
    {
        printf("\n");
        printf("************ Qual operação que você irá realizar? ************\n");
        printf("\n");
        printf("[1] Gerar chave pública\n");
        printf("[2] Criptografar mensagem\n");
        printf("[3] Descriptografar mensagem\n");
        printf("[0] Encerrar execução\n");
        printf("\n");
        printf("Digite a operação desejada: ");
        scanf("%hd", &operacao);
        printf("\n");
        if (operacao == 0)
        {
            return 0;
        }
        else if (operacao == 1)
        {
            char p[MAX_SIZE], q[MAX_SIZE], e[MAX_SIZE];
            printf("Digite o valor de p: ");
            scanf("%s", p);
            printf("Digite o valor de q: ");
            scanf("%s", q);
            printf("Digite o valor de e: ");
            scanf("%s", e);
            printf("Chave pública gerada: (%s, %s)\n", generatePublicKey(p, q, e), e);
        }
        else if (operacao == 2)
        {
            unsigned length;
            printf("Qual a quantidade de caracteres da mensagem? ");
            scanf("%u", &length);
            char msg[length];
            printf("Informe a chave pública (n, e): ");
            char n[MAX_SIZE], e[MAX_SIZE];
            scanf("%s %s", n, e);
            FILE *file = fopen("mensagem.txt", "r");
            {
                size_t i = 0;
                while (i < length)
                {
                    fscanf(file, "%c", &msg[i]);
                    i++;
                }
            }
            fclose(file);
            printf("Mensagem criptografada: %s\n", encryptMessage(msg, n, e));
        }
        else if(operacao == 3)
        {
            unsigned length;
            printf("Qual a quantidade de caracteres da mensagem? ");
            scanf("%u", &length);
            char msg[length * MAX_SIZE];
            printf("Informe a chave privada (p, q, e): ");
            char p[MAX_SIZE], q[MAX_SIZE], e[MAX_SIZE];
            scanf("%s %s %s", p, q, e);
            FILE *file = fopen("cifra.txt", "r");
            {
                size_t i = 0;
                while (fscanf(file, "%c", &msg[i]) != EOF)
                    i++;
            }
            fclose(file);
            printf("Mensagem decifrada: %s\n", decryptMessage(msg, p, q, e));
        }
    }
}
