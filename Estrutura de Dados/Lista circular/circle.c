#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista (slide)
struct elemento
{
    int valor;
    struct elemento *prox;
};

typedef struct elemento No;
typedef struct elemento *Pno;

// Função para inserir no final (slide)
void Insere_Final(Pno *inicio, int num)
{
    Pno ultimo;
    Pno novo = (Pno)malloc(sizeof(No));
    novo->valor = num;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
        (*inicio)->prox = *inicio; // mantem a propriedade circular
    }
    else
    {
        // percorre ate encontrar ultimo
        ultimo = *inicio;
        while (ultimo->prox != *inicio)
            ultimo = ultimo->prox;

        ultimo->prox = novo;
        novo->prox = *inicio; // mantem a propriedade circular
    }
}

// Função para remover a pessoa
int Remove_Ciclo(Pno *inicio, int ciclo)
{
    Pno anterior = *inicio;
    Pno ultimo = *inicio;
    Pno alvo = *inicio;

    // Se o proximo de inicio for o inicio ele vai retornar o valor
    if ((*inicio)->prox == *inicio)
    {
        return (*inicio)->valor;
    }

    // Laço para chegar onde quer remover
    for (int i = 1; i < ciclo; i++)
    {
        anterior = alvo;
        alvo = alvo->prox; // Onde quer chegar
    }

    if (*inicio == alvo)
    {
        while (ultimo->prox != *inicio)
            ultimo = ultimo->prox; // Ir até o final

        *inicio = (*inicio)->prox; // Apontar para o inicio
        ultimo->prox = *inicio;    // Aponta para o novo inicio
        free(alvo);
    }
    // Se alvo é elemento do início
    else
    {
        anterior->prox = alvo->prox;
        *inicio = alvo->prox;
        free(alvo);
    }
    return Remove_Ciclo(inicio, ciclo); // Retornar o resultado após a eliminação
}

int main()
{
    int n;// Número de testes
    Pno lista = NULL; // Iniciar a lista como NULL

    // Pegando os dados do usuário
    scanf("%d", &n);

    // pes = pessoas
    // ciclo = eliminação
    int pes, ciclo;
    int ganhador[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &pes, &ciclo); // Vai ler a quantidade de pessoas e de ciclo de acordo com a quantidade de testes(n)

        // Enquanto j for menor que o numero de pessoas
        for (int j = 0; j < pes; j++)
        {
            Insere_Final(&lista, j + 1); // Vai inserir a pessoa no final da lista
        }

        ganhador[i] = Remove_Ciclo(&lista, ciclo); // O ganhador na posição i vai ser o que retornar da função
        lista = NULL; // Após isso, a lista fica vazia, para repetir o processo
    }

    // Laço para printar os ganhadores
    for (int j = 0; j < n; j++)
    {
        printf("%d\n", ganhador[j]);
    }

    return 0;
}