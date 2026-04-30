#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no * prox;
} Lista;

typedef struct no2 {
    int dado;
    struct no2 *next;
} Lista2;

Lista * criarLista() {
    return NULL;
}

Lista * insere(Lista *lst, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = lst;
    return novo;
}

Lista2* insere2(Lista2* lst, int valor) {
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->dado = valor;
    novo->next = lst;
    return novo;
}

void imprimir(Lista *lst) {
    Lista *p;
    for (p = lst; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
}

Lista * busca(Lista *l, int v) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        }
    }
    return NULL;
}

Lista* buscaRecursiva(Lista* l, int v) {
    if (l == NULL) return NULL;
    if (l->info == v) return l;
    return buscaRecursiva(l->prox, v);
}

int contagem(Lista *l) {
    Lista *p;
    int x = 0;
    for (p = l; p != NULL; p = p->prox) {
        x++;
    }
    printf("TOTAL DE NÓS: %d\n", x);
    return x;
}

int contagemRecursiva(Lista *l) {
    if (l == NULL) return 0;
    return 1 + contagemRecursiva(l->prox);
}

int qtdPares(Lista *l) {
    int x = 0;
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info % 2 == 0) {
            x++;
        }
    }
    return x;
}

int qtdParRecursivo(Lista *l) {
    if (l == NULL) return 0;
    if (l->info % 2 == 0)
        return 1 + qtdParRecursivo(l->prox);
    else
        return qtdParRecursivo(l->prox);
}

Lista * juntarLista(Lista *lst, Lista2 *p) {
    while (p != NULL) {
        lst = insere(lst, p->dado);
        p = p->next;
    }
    return lst;
}

int main() {
    Lista *myLista;
    Lista2 *teste = NULL;

    myLista = criarLista();
    myLista = insere(myLista, 12);
    myLista = insere(myLista, 45);
    myLista = insere(myLista, 4);

    teste = insere2(teste, 60);
    teste = insere2(teste, 2);
    teste = insere2(teste, 1);

    printf("\nVALORES DA LISTA 1 -> ");
    imprimir(myLista);

    Lista *encontrado = buscaRecursiva(myLista, 4);
    if (encontrado != NULL) {
        printf("\nO VALOR %d FOI ENCONTRADO.\n", encontrado->info);
    } else {
        printf("\nValor não encontrado.\n");
    }

    int total = contagemRecursiva(myLista);
    if (total > 0) {
        printf("Foram encontrados %d elementos.\n", total);
    } else {
        printf("Lista vazia.\n");
    }

    int totalPares = qtdParRecursivo(myLista);
    printf("Total de pares: %d\n", totalPares);

    Lista *novaLista = juntarLista(myLista, teste);

    printf("\nLISTA FINAL (APÓS JUNTAR) -> ");
    imprimir(novaLista);

    return 0;
}
