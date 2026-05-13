#include <stdio.h>
#include <stdlib.h>

#define MAXelem 5

typedef struct {
    int topo;
    int *pelem;
} Pilha;

int menu() {
    int opcao;
    printf("\nBEM VINDO A PILHA");
    printf("\n1- Push");
    printf("\n2- Pop");
    printf("\n3- Mostrar topo");
    printf("\n4- Sair");
    printf("\nDigite a sua opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

void criarPilha(Pilha *p, int cap) {
    p->topo = -1;
    p->pelem = (int*)malloc(sizeof(int) * cap);
}

void push(Pilha *p, int v) {
    p->topo++;
    p->pelem[p->topo] = v;
}

int pop(Pilha *p) {
    return p->pelem[p->topo--];
}

int isFull(Pilha *p) {
    return (p->topo == MAXelem - 1);
}

int isEmpty(Pilha *p) {
    return (p->topo == -1);
}

int mostrarTopo(Pilha *p) {
    return p->pelem[p->topo];
}

int main() {
    Pilha myPilha;
    int opcao, valor;

    criarPilha(&myPilha, MAXelem);

    while (1) {
        opcao = menu();

        switch (opcao) {
            case 1:
                if (!isFull(&myPilha)) {
                    printf("Valor: ");
                    scanf("%d", &valor);
                    push(&myPilha, valor);
                } else {
                    printf("Pilha Cheia!\n");
                }
                break;

            case 2:
                if (!isEmpty(&myPilha)) {
                    printf("Removido: %d\n", pop(&myPilha));
                } else {
                    printf("Pilha Vazia!\n");
                }
                break;

            case 3:
                if (!isEmpty(&myPilha)) {
                    printf("Topo: %d\n", mostrarTopo(&myPilha));
                } else {
                    printf("Pilha Vazia!\n");
                }
                break;

            case 4:
                free(myPilha.pelem);
                return 0;

            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
