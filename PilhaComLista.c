#include <stdio.h>

typedef struct No{
    int valor;
    struct No*prox;

}No;

typedef struct {
    struct No *topo
}Pilha;


// Implementar Pilha e fila com lista encadeada; com operações de criação, inserção e de retirar

/* CRIAÇÃO PILHA
*/
void criarPilha(Pilha *p) {
    return p-> topo =NULL;

}

void push(Pilha *p, int valor) {
    No *novo = (int*)malloc(sizeof(No));
    novo -> valor = valor;
    novo -> prox = p->topo;

    p->topo = novo;

}

int retirar (Pilha *p){
    if (p->topo == NULL) {
        printf ("\n PILHA VAZIA ");
        return  -1  ;
    }
    No*temp = p->topo;
    int valor = temp-> valor;
    p->topo = temp-> prox;

    return valor;
}
