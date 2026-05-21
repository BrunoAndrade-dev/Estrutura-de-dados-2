#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    int senha;
    char nome[50];
    struct Cliente *prox;
} Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
    int contadorSenha;
} Fila;

void criarFila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
    f->contadorSenha = 0;
}

int isEmpty(Fila *f){
    return (f->inicio == NULL);
}

void inserirNaFila(Fila *f, char *nome){
    Cliente *novo = (Cliente*) malloc(sizeof(Cliente));

    novo->senha = ++f->contadorSenha;
    strcpy(novo->nome, nome);

    novo->prox = NULL;

    if(isEmpty(f)){
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    printf("\nCliente -- %s -- entrou na fila com a senha %d , aguarde para ser atendido", nome, novo->senha);
}

void mostarFila(Fila*f) {
    if(!isEmpty(f)){
        Cliente *aux = f-> inicio;
        while(aux!= NULL) {
            printf ("Nome : %s ; Senha :%d --> ", aux->nome, aux->senha);
            aux = aux->prox;
        }

    }else {
        printf("\n Fila está vazia");
    }
}
void atenderCliente(Fila *f) {
    if (!isEmpty(f){
        Cliente *temp = f->inicio;
        printf ("\n \%s -> %d", temp->nome, temp->senha);
        f->inicio = temp -> prox;
        if(f->inicio == NULL ) {
            f->fim == NULL;
        }
        free(temp);

    } else {
        printf("Nenhum cliente para ser atendido");
    }

}
int main () {
    Fila banco;
    criarFila(&banco);
    inserirNaFila(&banco, "Bruno");
    inserirNaFila(&banco, "maria");
    inserirNaFila(&banco, "mateus");
    mostarFila(&banco);


    return 0 ;
}
