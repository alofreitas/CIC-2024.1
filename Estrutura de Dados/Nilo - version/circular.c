#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista (slide)
struct elemento {
    int valor;
    struct elemento *proximo;
};
typedef struct elemento Pno;

// Estrutura para criar o nó (slide)
Pno *criarNo(int valor) {
    Pno *novo;
    novo = malloc(sizeof(Pno));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Estrutura para criar a lista
Pno *criarLista(int valor) {
    Pno *primeiro = criarNo(1); // Cria o primeiro nó da lista com valor 1
    Pno *ultimo = primeiro; // Criação do ponteiro ultimo que aponta para o primeiro nó

    for (int i = 2; i <= valor; i++) { //i = 2 porque já foi criado o 1 (criarNo)
        ultimo->proximo = criarNo(i); // Conecta o próximo nó ao nó atual
        ultimo = ultimo->proximo; // Move o ponteiro ultimo para o próximo nó
    }

    ultimo->proximo = primeiro; // O último nó aponta de volta para o primeiro (lista circular)
    return primeiro; // Retorna para o primeiro nó da lista
}

// Estrutura para eliminação
int Eliminar(Pno **inicio, int valor) {
    Pno *atual = *inicio; // Inicializa o nó atual a partir do início da lista
    Pno *anterior = NULL; // Inicializa o nó anterior como null
    int i = 1; // Inicializa o contador em 1

    while (atual->proximo != atual) { // Enquanto houver mais de um amigo na lista, continue a eliminação
        if (i == valor) { // Se o contador atingir o valor de eliminação K
            if (anterior) { // Se houver um nó anterior
                anterior->proximo = atual->proximo; // O nó anterior aponta para o próximo do nó atual
                free(atual); // Libera a memória
                atual = anterior->proximo; // Atualiza o nó atual para o próximo
            } else { // Se não houver um nó anterior
                Pno *aux; //Criação de um auxiliar
                aux = atual->proximo; // Auxiliar aponta para o próximo do nó atual
                while (aux->proximo != *inicio) { // Encontra o último nó da lista circular
                    aux = aux->proximo;
                }
                aux->proximo = atual->proximo; // O último nó aponta para o próximo do nó atual
                free(atual); // Libera a memória
                *inicio = aux->proximo; // Atualiza o início da lista para o próximo do último nó
                atual = *inicio; // Atualiza o nó atual para o novo início
            }
            i = 1; // No final, volta a valer 1 novamente
        } else {
            i++; // Incrementar +1
            anterior = atual; // Define o nó anterior como o nó atual
            atual = atual->proximo; // Atualiza o nó atual para o próximo da lista
        }
    }

    int vencedor;
    vencedor = atual->valor; // Obtém o valor do vencedor
    free(atual); // Libera a memória
    *inicio = NULL; // Define o início da lista como NULL
    return vencedor; // Retorna o vencedor, o último que ficou na lista e não foi eliminado
}

int main() {
    int teste;
    scanf("%d", &teste); // Quantidade de testes para ser feito

    int *resultados = (int *)malloc(teste * sizeof(int)); // Vetor para armazenar os resultados

    for (int i = 0; i < teste; i++) {
        int N, K;
        scanf("%d %d", &N, &K); // N = número de amigos, K = número de eliminações
        Pno *lista = criarLista(N); // Criar a lista com N números de amigos
        resultados[i] = Eliminar(&lista, K); // Armazena o resultado do teste
    }

    // Imprime os resultados
    for (int i = 0; i < teste; i++) {
        printf("%d\n", resultados[i]);
    }

    free(resultados); // Libera a memória alocada para os resultados

    return 0;
}