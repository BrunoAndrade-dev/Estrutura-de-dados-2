#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no * prox;
}Lista;

// Desenvolver as seguintes funcionalidades :
/*
Criar Lista
insere
Listar
buscar
retirar
Liberar
*/

Lista * criarLista()  {
    return NULL ;
}

Lista * insere (Lista * lst, int valor) {
    Lista * novo = (Lista*)malloc(sizeof(Lista)) ;
    novo -> info = valor  ;
    novo -> prox = lst;
    return novo;
}

void imprimir(Lista * lst) {
    Lista *p ;
    for (p = lst; p!= NULL ;p=p->prox) {
        printf ("%d ->" , p->info) ;
    }

}
// Implementação da função busca de forma iterativa
Lista * busca(Lista * l , int v) {
    Lista * p ;
    for (p = 1 ; p!= NULL ; p=p -> prox) {
        if ( p->info == v) {
            return p ;
        }
    }
    return NULL ;
}

//Implementação da função busca de forma recursiva

Lista* buscaRecursiva ( Lista* l , int v) {
    if ( l == NULL) {
        return NULL ;
    }

    if ( l -> info == v) {
       return l ;
    }
    return buscaRecursiva(l->prox, v);
}
// Forma interativa
int contagem(Lista * l) {
    Lista *p ;
    int x = 0 ;
    for (p=1; p != NULL ; p = p -> prox) {
        x++ ;
    }
    return printf("TOTAL DE NÓS : %d", &x);
}

// Forma recursiva

int contagemRecursiva(Lista *l) {
    if (l==NULL){
        return 0 ;
    }
    return  1 + contagemRecursiva(l->prox);

}

int qtdPares(Lista *l) {
    int x = 0 ;
    Lista *p ;
    for (p=1 ; p!= NULL ; p=p->prox) {
        if (p->info % 2 == 0 ) {
            x+=1;
        }
    }
    return x ;
}

int qtdParRecursivo(Lista *l) {
    if (l==NULL) {
        return 0 ;
    }
    if (l-> info %2 == 0 ) {
        return 1 + qtdParRecursivo(l->prox);
    }else {
        return qtdParRecursivo(l->prox);
    }
}

int main() {
    Lista *myLista;
    myLista = criarLista();
    myLista = insere(myLista, 12);
    myLista = insere(myLista, 45);
    myLista = insere(myLista, 4) ;
    imprimir(myLista);
    myLista = buscaRecursiva(myLista, 4);
    if (myLista != NULL) {
        printf (" \n O VALOR %d FOI ENCONTRADO.",myLista->info);
    } else {
        printf("\n  Valor não encontrado.");
    }

    int total = contagemRecursiva(myLista);
    if (total != NULL ) {
        printf ("\n Foram encontrado %d elementos.",total);
    }else{
        printf("Lista VAZIA");
    }
    int totalPares = qtdParRecursivo(myLista);
    if (totalPares != NULL) {
        printf ("\n O numero total de pares  :   %d ", totalPares);
    }


    return 0;
}
