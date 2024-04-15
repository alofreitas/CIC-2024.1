#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// pilhas são estruturas LIFO (last-in first-out)

struct pilha {
  int topo;
  char vagao[26];
};

void movetoL(struct pilha *left, char vagao) {
  if (left->topo == 25) {
    printf("ERRO- PILHA CHEIA");
    return;
  }

  left->topo++;
  left->vagao[left->topo] = vagao;
}

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
  printf("letras: \n");
  int num;
  scanf("%d",&num);
  getchar();

  char vagoes[26];
  char comando[52];

  printf("letras: \n");
  fgets(vagoes, 26, stdin);

  for(int i = 0; i < 26; i++){
    if (vagoes[i+1] == '\n')
      break;
    if (vagoes[i] == ' '){
      vagoes[i] = vagoes[i+1];
      vagoes[i+1] = ' ';
      
    }
  }

  printf("comandos: ");
  fgets(comando, 52, stdin);

  for(int i = 0; i < 52; i++){
    if (comando[i] == ' ')
      comando[i] = comando[i+1];
  }

  struct pilha left;
  struct pilha right;
  left.topo = -1;
  right.topo = -1;
  int j = 0;
  for (int i = 0; i < 52; i++) {
    if (comando[i] == 'E') {
      movetoL(&left, vagoes[j]);
      printf("%d %s\n",i, left.vagao);
    } 
    if (comando[i] == 'D'){
      movetoR(&left, &right);
      printf("%d %s\n",i, right.vagao);
      j--;
    }
    j++;
    }

  printf("Resultado: %s\n %s\n",right.vagao, left.vagao);

  return 0;
}