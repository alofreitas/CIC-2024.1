#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor;
    struct elemento *prox;
};

typedef struct elemento No;
typedef struct elemento *Pno;

void Insere_Final(Pno *inicio, int num)
{
    Pno ultimo;
    Pno *novo = (Pno)malloc(sizeof(No));
    (*novo)->valor = num;
    (*novo)->prox = NULL;

    if (vazia(*inicio))
    {
        *inicio = *novo;
        (*inicio)->prox = *inicio; // mantem a propriedade circular
    }
    else
    {
        // percorre ate encontrar ultimo
        ultimo = *inicio;
        while (ultimo->prox != *inicio)
            ultimo = ultimo->prox;

        ultimo->prox = *novo;
        (*novo)->prox = *inicio; // mantem a propriedade circular
    }
}

void Remove_Ciclo(Pno *inicio, int ciclo)
{
    Pno anterior = *inicio;
    Pno ultimo = *inicio;
    Pno alvo = *inicio;

    if (!vazia(*inicio))
    {
        if ((*inicio)->prox == *inicio)
        { // se tem apenas 1 elemento
            free(*inicio);
            *inicio = NULL;
        }

        for (int i = 1; i < ciclo; i++)
        {
            anterior = alvo;
            alvo = alvo->prox;
        }

        if (*inicio == alvo)
        {
            while (ultimo->prox != *inicio)
                ultimo = ultimo->prox;

            *inicio = (*inicio)->prox;
            ultimo->prox = *inicio; // aponta para o novo inicio
            free(alvo);
        }
        // se alvo é elemento do início
        else {
        anterior->prox = alvo->prox;
        free(alvo);
        }
    }
}

int main()
{
    int n, pes, ciclo, num[n];
    Pno lista = NULL;

    // Pegando os dados do usuário
    printf("num: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", pes, ciclo);
        for (int i = 0; i <= pes; i++)
        {
            num[i] = i + 1;
            Insere_Final(&lista, num[i]);
        }
    }

    return 0;
}