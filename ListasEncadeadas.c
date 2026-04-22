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

int main() {
    Lista *myLista;
    myLista = criarLista();
    myLista = insere(myLista, 12);
    myLista = insere(myLista, 45);
    myLista = insere(myLista, 4) ;
    imprimir(myLista);
    return 0;
}
