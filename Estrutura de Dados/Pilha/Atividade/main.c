#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// pilhas (last-in first-out)

// Estrutura da pilha
struct pilha {
  int topo;
  char vagao[26];
};

// Função para mover oo vagão para esquerda
void movetoL(struct pilha *left, char vagao) {
  if (left->topo == 25) {
    printf("ERRO- PILHA CHEIA");
    return;
  }

  left->topo++;
  left->vagao[left->topo] = vagao;
}
// Função para mover o vagão para direita
void movetoR(struct pilha *left, struct pilha *right) {
  if (left->topo == -1)
    return;
  else {
    right->topo++;
    right->vagao[right->topo] = left->vagao[left->topo];
    left->topo--;
  }
}

int main(void) {
  int num;
  // Quantidade de letras
  scanf("%d", &num);
  getchar();

  char vagoes[26];
  char comando[52];

  // Comandos
  fgets(vagoes, 26, stdin);
  fgets(comando, 52, stdin);

  // Criação das duas pilhas dentro da main
  struct pilha left;
  struct pilha right;

  // Inicialização das pilhas
  left.topo = -1;
  right.topo = -1;

  int j = 0;
  for (int i = 0; i < strlen(comando); i += 2) {
    // Se a operação for esquerda
    if (comando[i] == 'E') {
      movetoL(&left, vagoes[j]); // Chamada da função para esquerda
    }
    // Se a operação for direita
    if (comando[i] == 'D') {
      movetoR(&left, &right); // Chamada da função para direita
      j -= 2;
    }
    j += 2;
  }
  // Printar no final os da direita
  printf("%s\n", right.vagao);

  return 0;
}