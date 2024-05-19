#include <stdio.h>
#include <stdlib.h>

struct elemento{
   int valor;
   struct elemento *prox;
   struct elemento *ant;
};

typedef struct elemento *No;
typedef struct elemento *Pno;

void Desloca_No(Pno *inicio, int pos){
    Pno lista = *inicio;
    Pno aux = (*inicio)->prox;
    while (lista->prox != NULL){
        for (int i=0; i<pos; i++){
            aux = lista;
            lista = lista->prox;
            
    }
    aux->prox = lista->prox;
    lista->prox = lista->prox->prox;
    aux->prox->prox = lista;

}