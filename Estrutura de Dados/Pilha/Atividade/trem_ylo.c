#include <stdio.h>
#include <stdlib.h>
//Máximo de 26 vagões
#define max 26

typedef struct {
    char pilha_direita[max]; //Pilha do lado direito
    char pilha_esquerda[max]; //Pilha do lado esquerdo
    int topo_direita; //Topo do lado direito
    int topo_esquerda; //Topo do lado esquerdo
} Pilhas;

//Função para inicializar as pilhas
void inicializar(Pilhas *p) {
    p->topo_direita = -1; //pilha direita
    p->topo_esquerda = -1; //pilha esquerda
}

void empilhar(Pilhas *p, char vagao, int lado) { // lado 1 = direito, lado 2 = esquerdo, assim fica melhor para saber o lado
    if (lado == 1) { // Lado direito
        if (p->topo_direita < max - 1) {
            p->pilha_direita[++(p->topo_direita)] = vagao; //empilhar no lado direito
        } else {
            printf("Erro: pilha do lado direito cheia.\n"); //se não for menor que max - 1, então a pilha estará cheia
            exit(1);
        }
    } else if (lado == 2) { // Lado esquerdo
        if (p->topo_esquerda < max - 1) {
            p->pilha_esquerda[++(p->topo_esquerda)] = vagao; //empilhar o lado esquerdo
        } else {
            printf("Erro: pilha do lado esquerdo cheia.\n"); //se não for menor que max - 1, então a pilha estará cheia
            exit(1);
        }
    }
}

char desempilhar(Pilhas *p, int lado) {
    if (lado == 1) { // Lado direito
        if (p->topo_direita >= 0) {
            return p->pilha_direita[(p->topo_direita)--]; //desempilhar o lado direito
        } else {
            printf("Erro: pilha do lado direito vazia.\n"); //se não tiver mais nada, então estará vazia
            exit(1);
        }
    } else if (lado == 2) { // Lado esquerdo
        if (p->topo_esquerda >= 0) {
            return p->pilha_esquerda[(p->topo_esquerda)--]; //desempilhar o lado esquerdo
        } else {
            printf("Erro: pilha do lado esquerdo vazia.\n"); //se não tiver mais nada, então estará vazia
            exit(1);
        }
    }
}

int main() {
    int num; //número de vagões
    char sequencia[max]; //sequência de vagões
    char op; //operação (D ou E)
    Pilhas vagao_pilhas; //Struct pilha

    printf("Número de vagões: ");
    scanf("%d", &num);

    //O número máximo de vagões deve ser 26
    if(num > 26){
            printf("Erro!\n");
            exit(-1);
    }

    printf("Sequência dos vagões: ");
    scanf(" %s", sequencia);

    inicializar(&vagao_pilhas);

    int i = 0;
    printf("Sequência de operação: ");
  //Como o i = 0 e após a iteração ele é incrimentado (i++), então um laço while enquanto i < num
    while (i < num) {
        scanf(" %c", &op); //vai ler as operações
        if (op == 'E' || op == 'e') { //se a operação for pra esquerda
            empilhar(&vagao_pilhas, sequencia[i], 2); // 2 = Lado esquerdo
            i++; //acrescentar +1 no i apenas no lado esquerdo até acabar os vagoes
        } else if (op == 'D' || op == 'd') { //se a operação for pra direita
            if (vagao_pilhas.topo_esquerda < 0) {
                printf("Erro: operação 'D' não pode ser realizada.\n"); //Se a pilha esquerda tiver vazia, não tem como empilhar na direita
                exit(1);
            }
            char vagao = desempilhar(&vagao_pilhas, 2); // Lado esquerdo, vai desempilhar um para empilhar depois no lado direito
            empilhar(&vagao_pilhas, vagao, 1); // Empilhando no lado direito
        }

    }

    printf("Vagões do lado direito: ");
  //Percorrer a pilha do lado direito e imprimir os vagões
    for (int j = 0; j <= vagao_pilhas.topo_direita; j++) {
       printf("%c ", vagao_pilhas.pilha_direita[j]);
    }
    printf("\n");
      for (int j = 0; j <= vagao_pilhas.topo_esquerda; j++) {
       printf("%c ", vagao_pilhas.pilha_esquerda[j]);
    }
    printf("\n");

    return 0;
}