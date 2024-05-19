#include <stdio.h>
#include <stdlib.h>

// Estrutura dada no slide
// Cria um nó com um dado valor, um ponteiro para esquerda e direita
struct raiz
{
    int valor;
    struct raiz *esq;
    struct raiz *dir;
};

typedef struct raiz No;
typedef struct raiz *Pno;

// função para criar uma árvore, dado o valor do nó, a esquerda e a direita
Pno criar_arvore(int x, Pno esq, Pno dir)
{
    // alocando memória para o nó criado
    Pno novo = malloc(sizeof(No));
    // atribuindo valores
    novo->valor = x;
    novo->esq = esq;
    novo->dir = dir;
    // retornando o nó criado
    return novo;
}

// função para imprimir uma árvore
void imprime_arv(Pno raiz)
{
    // se a raiz não é nula, ou seja, há algum elemento
    if (raiz != NULL)
    {
        // vamos printar esse elemento
        printf("%d ", raiz->valor);
        // e chamar recursivamente o nó da esquerda
        imprime_arv(raiz->esq);
        // quando o nó da esquerda for igual a NULL, a função vai voltar para onde foi chamada e executar a linha abaixo
        imprime_arv(raiz->dir);
    }
}

int cont_folha(Pno raiz)
{
    // se a raiz for nula, não há oq contar, retornamos 0
    if (raiz == NULL)
        return 0;
    // se o nó que encontramos é uma folha, seu ponteiro esquerdo é nulo e o direito também
    if ((raiz->esq == NULL) && (raiz->dir == NULL))
        // se for, somamos um a chamada da função
        return 1 + cont_folha(raiz->esq) + cont_folha(raiz->dir);
    // se não, só chamamos o próximo
    else
    {
        return cont_folha(raiz->esq) + cont_folha(raiz->dir);
    }
}

Pno remov_folha(Pno raiz, int x)
{
    // se a raiz é nula, não temos mais o que procurar
    if (raiz == NULL)
        return NULL;
    // se o nó que encontramos é uma folha, seu ponteiro esquerdo é nulo e o direito também
    if ((raiz->esq == NULL) && (raiz->dir == NULL))
    {
        // já que encontramos uma folha, precisamos saber se ela guarda um valor igual ao x dado
        if (raiz->valor == x)
        {
            // se sim, vamos liberar esse nó
            free(raiz);
            // vamos retornar null para a chamada da função
            return NULL;
        }
    }
    // chamamos recursivamente com o próximo nó
    raiz->esq = remov_folha(raiz->esq, x);
    raiz->dir = remov_folha(raiz->dir, x);
    // por fim, retornamos a árvore modificada
    return raiz;
}

int comp_arv(Pno raiz, Pno raiz2)
{
    // se apenas uma das raízes for igual a NULL, uma árvore é maior que a outra, então elas não são iguais, logo, resultado será diferente de 0
    if (((raiz == NULL) && (raiz2 != NULL)) || ((raiz != NULL) && (raiz2 == NULL)))
        return 1;
    // se elas forem iguais a NULL simultaneamente, ao final das comparações, são iguais
    if ((raiz == NULL) && (raiz2 == NULL))
        return 0;
    // se os elementos analisados são iguais, analisaremos os próximos
    if (raiz->valor == raiz2->valor)
        // como 0 é o elemento neutro da soma, se elas passarem pelas condições a função retornará 0.
        return comp_arv(raiz->esq, raiz2->esq) + comp_arv(raiz->dir, raiz2->dir);
    // se não são, resultado será diferente de 0
    else
    {
        return 1;
    }
}

int main(void)
{
    // primeira árvore do exemplo
    Pno arvore = criar_arvore(1, NULL, NULL);
    // segunda árvore do exemplo
    Pno arvore2 = criar_arvore(6,
                               criar_arvore(9, criar_arvore(6, NULL, NULL), criar_arvore(7, criar_arvore(7, NULL, NULL), NULL)),
                               criar_arvore(5, NULL, criar_arvore(8, criar_arvore(5, NULL, NULL), criar_arvore(7, NULL, NULL))));
    // terceira árvore do exemplo
    Pno arvore3 = criar_arvore(6,
                               criar_arvore(9, criar_arvore(6, NULL, NULL), NULL),
                               criar_arvore(7, NULL, criar_arvore(8, criar_arvore(5, NULL, NULL), criar_arvore(7, NULL, NULL))));
    Pno arvore4 = criar_arvore(6,
                               criar_arvore(9, criar_arvore(6, NULL, NULL), NULL),
                               criar_arvore(7, NULL, criar_arvore(8, criar_arvore(5, NULL, NULL), NULL)));
    Pno arvore5 = criar_arvore(6,
                               criar_arvore(9, criar_arvore(6, NULL, NULL), NULL),
                               criar_arvore(7, criar_arvore(8, NULL, criar_arvore(5, NULL, NULL)), NULL));
    // chamando as funções implementadas
    imprime_arv(arvore2);

    // printando a quantidade de folhas
    int c = cont_folha(arvore2);
    printf("\n");
    printf("%d\n", c);

    // chamando as funções implementadas
    remov_folha(arvore2, 7);
    imprime_arv(arvore2);
    printf("\n");

    // chamando as funções implementadas
    c = comp_arv(arvore4, arvore4);
    if (c == 0)
        printf("Verdadeiro\n");
    else
        printf("Falso\n");
    /*
    printf("%d", c);
    printf("\n");
    */

    return 0;
}
