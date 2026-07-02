#include <stdio.h>
#include <stdlib.h>

typedef struct Arvbb {
    int chave;
    struct No*esq;
    struct No*dir ;
    int fb;
} Arvbb;

int fb(Arvbb *n) {
    if (n== NULL )return -1;
    return n->fb;
}

int max(int a, int b) {
    return (a>b) ? a:b;
}


Arvbb * rotacaoDireita (Arvbb * noDesb){
    Arvbb *no = noDesb->esq;
    Arvbb *Y = u-> dir;

    no-> dir = noDesb;
    noDesb-> esq = Y;

    noDesb->fb = max(fb(p->esq), fb(p->dir)) + 1;

    return u;
}
