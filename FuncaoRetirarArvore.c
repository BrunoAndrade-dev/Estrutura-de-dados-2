#include <stdio.h>
#include <stdlib.h>

// Estrutura da �rvore bin�ria de busca
typedef struct Arvbb {
    int info;
    struct Arvbb *esq;
    struct Arvbb *dir;
} Arvbb;

// Fun��o para verificar se a �rvore est� vazia
int isEmpty(Arvbb *a) {
    return (a == NULL);
}

// Criar �rvore vazia
Arvbb* criarArbb() {
    return NULL;
}

// Impress�o da �rvore
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

// Inser��o na �rvore
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
Arvbb *retirar (Arvbb *a, int v) {
    if (isEmpty(a)) {
        return NULL;
    }else if(v < a->info) {
        a ->esq = retirar(a->esq, v);
    }else if(v > a->info) {
        a->dir = retirar(a->dir, v);
    }else { // encontrou o nó
        if (a->esq == NULL && a->dir == NULL ) {
            free(a);
            a=NULL;
        }else if (a->dir == NULL) { // Um filho no lado esquerdo
            Arvbb * aux = a->esq;
            free(a);
            a= aux;
        }else if(a->esq == NULL ) {// Um filho no lado direito
            Arvbb * aux = a->dir;
            free(a);
            a= aux;
        } else { // tem os dois filhos
            Arvbb * aux = a->esq;
            while (aux -> dir !NULL) {
                aux = aux -> dir ;
            }
            a->info = aux ->info;
            aux ->info = v;
            a -> esq = retirar (a->esq, v);


        }
        return a ;
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
