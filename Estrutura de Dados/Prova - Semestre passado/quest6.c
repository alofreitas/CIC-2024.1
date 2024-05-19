#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *prox;
    struct no *ant;
};

typedef struct no *pno;

void concatCirc(pno *inicio, pno *inicio2)
{
    pno ultimo = *inicio;
    pno ultimo2 = *inicio2;

    while (ultimo->prox != *inicio)
    {
        ultimo = ultimo->prox;
    }
    while (ultimo2->prox != *inicio2)
    {
        ultimo2 = ultimo2->prox;
    }
}

int main(){
    concatCirc(10, 20);
}