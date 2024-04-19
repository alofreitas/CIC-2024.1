#include <stdio.h>
#include <stdlib.h>

// Estrutura dada na questão - dados 
struct Sequencia
{
    int valor;
    struct Sequencia *prox;
    struct Sequencia *ant;
};

typedef struct Sequencia No;
typedef struct Sequencia *Pno;

// Função para inserir um novo elemento no final da lista
Pno Insere_Final(Pno *lista, int num)
{
    Pno new = (Pno)malloc(sizeof(No));
    new->valor = num;
    new->prox = NULL;
    new->ant = NULL;

    // Se a lista estiver vazia, o novo elemento será o primeiro
    if (*lista == NULL)
    {
        *lista = new;
    }
    else
    {
        Pno atual = *lista;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = new;
        new->ant = atual;
    }
    return new;
}

// Função para calcular a soma dos elementos das listas e retornar o ultimo elemento lista
Pno Soma(Pno *lista, Pno *fim)
{
    int num = 0;
    Pno new = NULL;
    Pno atual = *lista;
    Pno atual2 = *fim;
    atual2 = atual2->ant;

    // Enquanto houver elementos em ambas as listas
    while (atual != NULL && atual2 != NULL)
    {
        num = atual->valor + atual2->valor;
        printf("Soma de %d + %d é : %d\n", atual->valor, atual2->valor, num);
        Insere_Final(&new, num);
        atual2 = atual2->ant;
        atual = atual->prox;
    }

    return new;
}

int main(void)
{
    int n;
    Pno lista = NULL;
    Pno lista2 = NULL;

    // Pegando os dados do usuário
    printf("num: \n");
    scanf("%d", &n);
    if (n == 0)
    {
        exit(1);
    }
    int num[n];
    int num2[n];

    // Lendo e inserindo elementos na primeira lista
    printf("num: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        Insere_Final(&lista, num[i]);
    }

    // Lendo e inserindo elementos na segunda lista
    printf("num: ");
    Pno fim = NULL;
    for (int i = 0; i < n; i++)
    {
            scanf("%d", &num2[i]);
            Insere_Final(&lista2, num2[i]);
        if (i + 1 == n)
            fim = Insere_Final(&lista2, num2[i]);
    }    

    // Calculando a soma e armazenando o resultado em uma nova lista
    Pno new = Soma(&lista,&fim);

    // Imprimindo a soma dos elementos das listas
    Pno temp = new;
    while (temp != NULL)
    {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }

    printf("\n");

    scanf("%d", &n);

    return 0;
}
