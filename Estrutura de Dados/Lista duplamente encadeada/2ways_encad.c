#include <stdio.h>
#include <stdlib.h>

// Estrutura dada na questão - dados
struct Sequencia
{
    int valor;
    struct Sequencia *prox;
    struct Sequencia *ant;
};

typedef struct Sequencia No;
typedef struct Sequencia *Pno;

// Função para inserir um novo elemento no final da lista (slide)
Pno Insere_Final(Pno *lista, int num)
{
    Pno new = (Pno)malloc(sizeof(No));
    new->valor = num;
    new->prox = NULL;
    new->ant = NULL;

    // Se a lista estiver vazia, o novo elemento será o primeiro
    if (*lista == NULL)
    {
        *lista = new;
    }
    else
    {
        Pno atual = *lista;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = new;
        new->ant = atual;
    }
    return new;
}

// Função para calcular a soma dos elementos das listas e retornar o ultimo elemento lista
Pno Soma(Pno *lista, Pno *fim)
{
    int num = 0;
    Pno new = NULL;
    Pno atual = *lista;
    Pno atual2 = *fim;

    // Enquanto houver elementos em ambas as listas
    while (atual != NULL && atual2 != NULL)
    {
        num = atual->valor + atual2->valor; // Soma dos valores
        Insere_Final(&new, num); // Inserir na nova lista o valor da soma
        atual2 = atual2->ant; // O atual da segunda lista aponta para o anterior
        atual = atual->prox; // O atual da primeira lista aponta para o próximo
    }

    return new;
}

int main(void)
{
    int n;
    // Pegando os dados do usuário
    scanf("%d", &n);
    while (n != 0) // Enquanto n for diferente de 0, para possibilitar ler mais de uma entrada
    {
        // Inicializar as listas como vazia
        Pno lista = NULL;
        Pno lista2 = NULL;
        int num[n];
        int num2[n];

        // Lendo e inserindo elementos na primeira lista
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            Insere_Final(&lista, num[i]);
        }

        // Lendo e inserindo elementos na segunda lista
        Pno fim = NULL;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 == n) // Se for o ultimo elemento
            {
                scanf("%d", &num2[i]);
                fim = Insere_Final(&lista2, num2[i]);
                break;
            }

            scanf("%d", &num2[i]);
            Insere_Final(&lista2, num2[i]);
        }
        
        // Chamada da função
        Pno new = Soma(&lista, &fim);

        // Imprimindo a soma dos elementos das listas
        Pno temp = new;
        while (temp != NULL)
        {
            printf("%d ", temp->valor);
            temp = temp->prox;
        }
        printf("\n");

        scanf("%d", &n);
    }

    return 0;
}