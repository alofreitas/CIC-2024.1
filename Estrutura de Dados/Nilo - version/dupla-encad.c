#include <stdio.h>
#include <stdlib.h>
//Estrutura para lista duplamente encadeada
struct elemento {
  int valor;
  struct elemento *prox;
  struct elemento *ant;
};
typedef struct elemento No;

//Estrutura para lista simples
struct Lista {
  No *inicio;
  No *fim;
};
typedef struct Lista Lista;

//Fun��o para criar a lista
Lista *criarLista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->inicio = NULL;
  lista->fim = NULL;
  return lista;
}
//Fun��o para inserie no fim da lista
void inserirFim(Lista *lista, int valor) {
  No *novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->prox = NULL;
  novo->ant = lista->fim;
  if (lista->inicio == NULL) {
    lista->inicio = novo;
  } else {
    lista->fim->prox = novo;
  }
  lista->fim = novo;
}

// Fun��o para calcular a soma cruzada das duas listas e imprimir o resultado
void calcularSomaCruzada(Lista *lista1, Lista *lista2) {
  No *no1 = lista1->inicio; // Inicializa o ponteiro no1 para o in�cio da lista1
  No *no2 = lista2->fim; // Inicializa o ponteiro no2 para o final da lista2

  while (no1 != NULL && no2 != NULL) { // Enquanto os dois nos n�o forem vazios
    int soma = no1->valor + no2->valor; // Calcula a soma dos n�s apontados por no1 e no2

    printf("%d ", soma); // Imprime a soma

    no1 = no1->prox; // Avan�a no1 para o pr�ximo n�
    no2 = no2->ant;  // Retrocede no2 para o n� anterior
  }
  printf("\n"); // Imprime uma quebra de linha ao final da linha de soma
}

//Fun��o para liberar a mem�ria alocada
void liberarLista(Lista *lista) {
  No *atual = lista->inicio;
  while (atual != NULL) {
    No *proximo = atual->prox;
    free(atual);
    atual = proximo;
  }
  free(lista);
}

int main() {
  int n, valor, i;

  while (scanf("%d", &n) == 1) { // Verificar se a leitura foi correta, enquanto for inteiro ele vai continuar lendo
  // Cria��o de duas listas para armazenar as sequências de números
    Lista* lista1 = criarLista();
    Lista* lista2 = criarLista();
    // Leitura dos valores da primeira sequ�ncia e inser��o na lista1
    for (i = 0; i < n; i++) {
      scanf("%d", &valor);
      inserirFim(lista1, valor);
    }
 //Leitura dos valores da segunda sequ�ncia e inser��o na lista2
     for (i = 0; i < n; i++) {
       scanf("%d", &valor);
       inserirFim(lista2, valor);
     }
 // Chama a fun��o para calcular a soma cruzada e imprimir o resultado (o printf j� est� dentro da fun��o)
     calcularSomaCruzada(lista1, lista2);
// Libera a mem�ria alocada para as listas
      liberarLista(lista1);
      liberarLista(lista2);
  }

 return 0;
}