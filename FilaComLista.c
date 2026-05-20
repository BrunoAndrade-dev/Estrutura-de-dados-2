#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct no*prox;
}No ;

typedef struct {
    No*inicio;
    No*fim;
}Fila;

void criarFila (Fila *f){
    f->inicio = NULL ;
    f->fim = NULL ;
}

void inserir(Fila*f, int valor) {
    No*novo = (int*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->incio = novo;
        f->fim = novo ;

    }else {
        f->fim->prox = novo;
        f->fim = novo;
    }

}

int retirarDaFila(Fila*f) {
    if (f->inicio == NULL ) {
        printf ("\n A fila está vazia");
        return -1;

    }

    No*temp = f->inicio;
    int valor = temp->valor;

    f->inicio = temp->prox;

    if (f-> inicio == NULL ){
        f->fim = NULL ;
    }

    free(temp);
    return valor;
}





