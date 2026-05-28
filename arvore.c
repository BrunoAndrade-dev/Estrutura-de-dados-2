#include <stdio.h>
#include <stdlib.h>

// Estrutura da árvore binária de busca
typedef struct Arvbb {
    int info;
    struct Arvbb *esq;
    struct Arvbb *dir;
} Arvbb;

// Função para verificar se a árvore está vazia
int isEmpty(Arvbb *a) {
    return (a == NULL);
}

// Criar árvore vazia
Arvbb* criarArbb() {
    return NULL;
}

// Impressão da árvore
void imprime(Arvbb *a, int nivel) {
    if (!isEmpty(a)) {

        imprime(a->dir, nivel + 1);

        for (int i = 0; i < nivel; i++) {
            printf("   ");
        }

        printf("%d\n", a->info);

        imprime(a->esq, nivel + 1);
    }
}

// Inserção na árvore
Arvbb* insere(Arvbb *a, int v) {

    if (isEmpty(a)) {

        Arvbb *novo = (Arvbb*) malloc(sizeof(Arvbb));

        novo->info = v;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;

    } else {

        if (v < a->info) {
            a->esq = insere(a->esq, v);
        } else {
            a->dir = insere(a->dir, v);
        }

        return a;
    }
}

int main() {

    Arvbb *MyArvbb = criarArbb();

    MyArvbb = insere(MyArvbb, 8);
    MyArvbb = insere(MyArvbb, 12);
    MyArvbb = insere(MyArvbb, 9);
    MyArvbb = insere(MyArvbb, 14);
    MyArvbb = insere(MyArvbb, 13);

    imprime(MyArvbb, 0);

    return 0;
}
