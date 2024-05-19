#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento *No;
typedef struct elemento *Pno;

int Comp_lista(Pno *inicio, Pno *inicio2)
{
    int cont1 = 0, cont2 = 0;
    Pno lista = *inicio;
    Pno lista2 = *inicio2;
    if (lista != NULL)
    {
        while (lista->prox != NULL)
        {
            cont1++;
            lista = lista->prox;
        }
    }
    if (lista2 != NULL)
    {
        while (lista2->prox != NULL)
        {
            cont2++;
            lista2 = lista2->prox;
        }
    }
    if (cont1 > cont2)
        return -1;
    else if (cont2 > cont1)
        return 1;
    else
        return 0;                                                                                                                                                                                                  
}