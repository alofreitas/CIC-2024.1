#include <stdio.h>
#include <stdlib.h>

/*
1. O código exemplo dado em sala de aula apenas remove a primeira ocorrência de um valor x
numa lista encadeada. Modifique o código para apagar todas as ocorrências de x.
Ex:
Seja a lista 1 → 2 → 2→ 3.
A remoção do valor 2 deve retornar uma lista com os seguintes elementos: 1→ 3.
*/

// Estrutura dada na questão - dados
struct elemento
{
    int valor;
    struct elemento *prox;
};

typedef struct elemento No;
typedef struct elemento *Pno;

void Inserir_Final(Pno *lista, int num)
{
    Pno new = (Pno)malloc(sizeof(No));
    new->valor = num;
    new->prox = NULL;
    // o elemento inserido será o primeiro
    if (*lista == NULL)
    {
        *lista = new;
    }
    else
    {
        Pno atual = *lista;
        while (atual->prox != NULL)
            // percorrendo a lista
            atual = atual->prox;
        atual->prox = new;
    }
}

void Remove_alvo(Pno *lista, int num)
{
    Pno aux = (*lista)->prox;
    Pno atual = *lista;
    while (aux != NULL)
    {
        if ((*lista)->valor == num)
            *lista = (*lista)->prox;
        else if (aux->valor == num)
            atual = aux->prox;
        aux = aux->prox;
        atual = atual->prox;
    }
}

int main()
{
    int num[6] = {1, 2, 3, 3, 4, 5};
    Pno lista = NULL;
    for (int i = 0; i < 6; i++)
    {
        Inserir_Final(lista, num[i]);
    }
    Remove_alvo(lista, 3);
    Pno aux = lista;
    while (aux->prox != NULL)
    {
        printf("%d", aux->valor);
        aux = aux->prox;
    }
    return 0;
}