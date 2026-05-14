#include <stdio.h>
#include <stdlib.h>
#define  MAXElem 10

typedef struct {
    int inicio;
    int fim;
    int *pElem; // Ponteiro que guardará o array dinâmico
} Fila;

void CriarFila(Fila *f, int cap) {
    f->inicio = 0;
    f->fim = -1;
    // CORREÇÃO: Aloca a memória necessária para os elementos
    f->pElem = (int *)malloc(cap * sizeof(int));
}

void mostrarFila(Fila *f) {
    // CORREÇÃO: Loop começa do início real da fila
    for (int i = f->inicio; i <= f->fim; i++) {
        printf(" %d ->", f->pElem[i]);
    }
    printf("\n");
}

void enfileirar(Fila *f, int v) {
    // CORREÇÃO: Uso do '=' para atribuição, não '=='
    f->pElem[++f->fim] = v;
}

int retirar(Fila *f) {
    int v = f->pElem[f->inicio];
    for (int i = 0 ; i <= f->fim ; i ++) {
        f->pElem[i] = f->pElem[i+1];
    }
    f->fim-- ;
    return v ;
}
int main() {
    // CORREÇÃO: Criada a variável local (alocação estática da estrutura)
    Fila myfila;

    // CORREÇÃO: Passando o endereço com '&'
    CriarFila(&myfila, MAXElem);

    enfileirar(&myfila, 10);
    enfileirar(&myfila, 5);
    enfileirar(&myfila, 40);
    int valor;
    valor = retirar(&myfila);
    printf("Valor %d retirado com sucesso.", valor);
    valor = retirar(&myfila);
    // Boa prática: liberar a memória alocada pelo malloc antes de fechar
    free(myfila.pElem);

    return 0;
}
