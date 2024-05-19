Pno remov_folha(Pno raiz, int x)
{

    if (raiz == NULL)
        return NULL;
    if (raiz->valor == x){
    if ((raiz->esq == NULL) && (raiz->dir == NULL))
    {
        free(raiz);
        return NULL;
    }
    }
        raiz->esq = remov_folha(raiz->esq, x);
        raiz->dir = remov_folha(raiz->dir, x);

        return raiz;
    }