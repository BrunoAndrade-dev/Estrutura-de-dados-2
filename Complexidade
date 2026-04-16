#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void preencher (int * v , int n) {
    for (int i = 0; i ,i<n; i++){
        v[i] = rand()%1001;
    }
}

int encontrarPar(int * vetor, int n , int alvo) {
    int contador = 0 ;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j< n ; j++) {
           if (vetor[i] + vetor[j]== alvo) {
            contador += 1 ;
           }
        }
    /*
    if (contador == 0 ) {
        printf ("Nenhum par encontrado.");
        }
    */
    }
    return contador;
}


int main() {
    srand(time(NULL));
    int n = 100;
    int *vet = (int*)malloc(n*sizeof(int));
    preencher(vet, n );
    int teste ;
    int alvo = 70;
    //printf ("Qual valor será seu alvo ?") ;
    //scanf("%d", &alvo) ;
    teste = encontrarPar(vet ,  n ,  alvo );
    printf ("Total de pares encontrados -> %d", teste) ;

    return 0 ;
}
