class No:
    """Esta classe representa um nó/elemento de uma árvore.
       Equivalente a função criar_arvore em C -- no slide
    """ 
    def __init__(self, valor, esquerda=None, direita=None):
        self.valor = valor
        self.esquerda = esquerda
        self.direita = direita


class Arvore:
    """Esta classe contem funções para a manipulação de árvores binárias."""
    
    # Recebe um Nó de uma árvore (raiz local) e um inteiro.
    # Retorna o No que contem o valor inteiro.
    def procurar_no (raiz: No, x: int) -> No:
        
        if raiz is None:
            return None
        
        if raiz.valor == x:
            return raiz
        
        esq = procurar_no(raiz.esquerda, x)
        if (esq is not None):
            return esq
        
        _dir = procurar_no(raiz.direita, x)
        if (_dir is not None):
            return _dir
        
        return None

    def numero_nos(raiz: No) -> int:
        if raiz is None:
            return 0
        n_esq=Arvore.numero_nos(raiz.esquerda)
        n_dir=Arvore.numero_nos(raiz.direita)
        return n_esq+n_dir+1
    
    def altura(raiz: No) -> int:
        if raiz is None:
            return 0
        h_esq = Arvore.altura(raiz.esquerda)
        h_dir = Arvore.altura(raiz.direita)
        return 1 + max(h_esq, h_dir)

    def pre_ordem(raiz: No):
        if raiz is not None:
            print(raiz.valor, end=' ')
            Arvore.pre_ordem(raiz.esquerda)
            Arvore.pre_ordem(raiz.direita)
            
    def pos_ordem(raiz: No):
        if raiz is not None:
            Arvore.pos_ordem(raiz.esquerda)
            Arvore.pos_ordem(raiz.direita)
            print(raiz.valor, end=' ')
    
    def in_ordem(raiz: No):
        if raiz is not None:
            Arvore.in_ordem(raiz.esquerda)
            print(raiz.valor, end=' ')
            Arvore.in_ordem(raiz.direita)
            
            
    def percurso_em_largura (raiz: No):
        f = list()
        f.append(raiz) #insere no fim
        while len(f)>0:
            raiz = f.pop(0) # removo no início
            if raiz is not None:
                f.append(raiz.esquerda)
                f.append(raiz.direita)
                print(raiz.valor, end=' ')


    ##### FUNÇÃO PARA IMPRIMIR ÁRVORE BONITA
    # código em C: https://pt.stackoverflow.com/questions/207358/como-imprimir-%C3%A1rvores-bin%C3%A1rias-gen%C3%A9ricas-usando-c
    # ÁRVORE estará mostrada da esquerda para direita, nao de cima pra baixo, como costumamos
    # A função auxiliar imprimeNo imprime o caracter
    # c precedido de 3b espaços e seguido de uma mudança
    # de linha.
    def imprimeNo(valor: int, b: int):
        for i in range(b):
            print("   ", end='')
        print(valor)
        
    # A função mostraArvore faz um desenho esquerda-direita-raiz
    # da árvore x. O desenho terá uma margem esquerda de
    # 3b espaços.
    def mostraArvore(a: No, b: int):
        if (a == None):
            Arvore.imprimeNo('*', b)
            return
        
        Arvore.mostraArvore(a.direita, b+1)
        Arvore.imprimeNo(a.valor, b)
        Arvore.mostraArvore(a.esquerda, b+1)



# Função A
def numFolhas(raiz: No) -> int:
    #Verifica se a árvore é vazia
    if raiz == None:
        return 0
    # Verifica se chegamos em uma folha
    elif raiz.esquerda == None and raiz.direita == None:
        return 1
    else:
        # Faz a soma das folhas da sub arvore da esquerda com a sub arvore da direita
        return numFolhas(raiz.esquerda) + numFolhas(raiz.direita)
    

#Função B
def rmFolha(raiz: No, val: int) -> int:
    #Verifica se o nó é nulo
    if raiz == None:
        return None
    # Verifica se encontramos o valor e se ele é uma folha
    elif raiz.valor == val and raiz.esquerda == None and raiz.direita == None:
        return None
    else:
        #Chama a busca para a esquerda e para a direita
        raiz.esquerda = rmFolha(raiz.esquerda, val)
        raiz.direita = rmFolha(raiz.direita, val)
        # Retorna o próprio nó para o pai que está esperando o retorno de uma das chamadas acima
        return raiz


#Função C
def isEqualTree(raiz1: No, raiz2: No) -> bool:
    # Verifica se um dos nós é nulo
    if raiz1 == None or raiz2 == None:
        #Verifica se ambos são nulos
        if raiz1 == raiz2:
            return True
        
        # Se ainda existe um nó não nulo, quer dizer que as árvores não são iguais
        return False
    #Verifica se os valores dos nós são iguais
    elif raiz1.valor != raiz2.valor:
        return False
    else:
        #Verifica se as subs árvores de ambos nós são iguais e se o mesmo vale para a direita
        return isEqualTree(raiz1.esquerda, raiz2.esquerda) and isEqualTree(raiz1.direita, raiz2.direita)


##############################################################################################################
#Função A

#1
#====================================================================
raiz1 = No(1)
print(numFolhas(raiz1))

#2
#====================================================================

# Criando árvore
folha1 = No(7)
galho1 = No(7, folha1, None)
folha2 = No(6)
galho2 = No(9,folha2, galho1)

folha3 = No(5)
folha4 = No(7)
galho3 = No(8, folha3, folha4)
galho4 = No(5, None, galho3)

raiz2 = No(6, galho2, galho4)
print(numFolhas(raiz2))

#Arvore.mostraArvore(raiz2,2)

#3
#====================================================================

# Criando árvore
folha01 = No(6)
galho01 = No(9, folha01)

folha02 = No(5)
folha03 = No(7)
galho02 = No(8, folha02, folha03)
galho03 = No(7, None, galho02)

raiz3 = No(6, galho01, galho03)
    
print(numFolhas(raiz3))

#Arvore.mostraArvore(raiz3,2)

##############################################################################################################
#Função B
#1
#====================================================================
rmraiz1 = rmFolha(raiz1, 1)
print("Raiz 1")
Arvore.mostraArvore(rmraiz1, 2)

#2
#====================================================================
rmraiz2 = rmFolha(raiz2, 7)
print("Raiz 2")
Arvore.mostraArvore(rmraiz2, 2)

#3
#====================================================================
rmraiz3 = rmFolha(raiz3, 7)
print("Raiz 3")
Arvore.mostraArvore(rmraiz3, 2)

##############################################################################################################
#Função C

#1
#====================================================================
# Criando árvore 1
folha1 = No(6)
galho1 = No(9, folha1)

folha2 = No(5)
galho2 = No(8, None, folha2)
galho3 = No(7, galho2)

raiz1 = No(6, galho1, galho3)

#Criando árvore 2
folha01 = No(6)
galho01 = No(9, folha01)

folha02 = No(5)
galho02 = No(8, folha02)
galho03 = No(7, None, galho02)

raiz2 = No(6, galho01, galho03)


print(isEqualTree(raiz1, raiz2))

#2
#====================================================================
# Criando árvore 1
folha1 = No(6)
galho1 = No(9, folha1)

folha2 = No(5)
galho2 = No(8, None, folha2)
galho3 = No(7, galho2)

raiz1 = No(6, galho1, galho3)

#Criando árvore 2
folha01 = No(6)
galho01 = No(9, folha01)

folha02 = No(5)
galho02 = No(8, None, folha02)
galho03 = No(7, galho02)

raiz2 = No(6, galho01, galho03)

print(isEqualTree(raiz1, raiz2))

