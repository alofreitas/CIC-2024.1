#include <stdio.h>
#include <stdlib.h>

typedef struct Vagao{
    int top;
    char vagao[27];
} trem;

void addesq(trem* esq, char letras[], int *onde ){
    // Verifica se chegamos no final de letras
    if (letras[*onde] == '\n'){
        printf("Erro, não há mais vagões\n");
        exit(2);
    }

    // Verifica se o contador está na posição dos espaços
    if (*onde % 2){
        *onde = *onde + 1;
    }

    // Adiciona o vagão no topo da pilha
    esq->vagao[++esq->top] = letras[*onde];
    *onde = *onde + 1; 
}

void adddir(trem* dir, trem *esq){
    // Encerra o programa caso o trem da esquerda esteja vazio
    if (esq->top == -1){
        printf("Erro, Trem da esquerda vazio\n");
        exit(3);
    }

    // Trem da direita no topo da pilha recebe o vagao da esquerda no topo da pilha
    // Também incrementa no topo da direita e decrementa no da esquerda
    dir->vagao[++dir->top] = esq->vagao[esq->top--];
    // Adiciona \0 no final para ficar mais fácil na hora de imprimir;
    dir->vagao[dir->top + 1] = '\0';
}

int main(void){
    /* Na minha implementação não vi a necessidade de utilizar a variavel vagoes
    pois eu leio em uma array de caracteres e depois percorro até o \n
    */
    int vagoes;
    char letras[53];
    char operacoes[105];

    // Lê as variáveis
    scanf("%d ", &vagoes);
    fgets(letras, 53, stdin);
    fgets(operacoes, 105, stdin);

    trem *esq = malloc(sizeof(trem)), *dir = malloc(sizeof(trem));
    esq->top = -1;
    dir->top = -1;

    int *ondeLetra = malloc(sizeof(int));
    *ondeLetra = 0;

    for (int c = 0; operacoes[c] != '\n'; c++){
        // Verifica se estamos nos espaços e pula pro próximo caractere
        if (c % 2) continue;

        if (operacoes[c] == 'E'){
            addesq(esq, letras, ondeLetra);
        } else if (operacoes[c] == 'D'){
            adddir(dir, esq);
        } else{
            printf("Digite entradas válidas E/D\n");
            exit(1);
        }
    }

    for(int c = 0; dir->vagao[c] != '\0'; c++){
        printf("%c", dir->vagao[c]);
        printf(" ");
    }
    printf("\n");

 for(int c = 0; dir->vagao[c] != '\0'; c++){
        printf("%c", esq->vagao[c]);
        printf(" ");
    }
    printf("\n");
    return 0;
}