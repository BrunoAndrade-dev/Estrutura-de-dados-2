//Pesquisa Linear e Binária

// Linear
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void imprimir (int *v , int n ) {
    printf("\n ") ;
    for (int i = 0 ; i< n ; i++)  {
        printf ("%d , " , v[i]);
    }
    printf("\n ") ;

}

void popular_vetor (int *v , int n ) {
    for (int i = 0 ; i < n ; i++) {
        v[i] = rand() % 10001;
    }
}

int buscalinear(int * v , int x , int n ) {
    for (int i=0 ; i <n ; i ++) {
        if (v[i]== x ) {
            return i ;
        }
    }
    return -1 ;
}
int buscaBinaria(int *v ,int x  , int n ) {
    int inf, sup , m ;
    inf = 0 ;
    sup = n-1;
    while (inf <= sup) {
        m = (inf+sup) / 2 ;

        if (v[m] == x ) {
            return m ;

        } else if (x > v[m]){
            inf = m +1 ;

        }else {
            sup = m-1 ;
        }
    }
    return -1 ;

}
int main (){
    srand(time(NULL)) ;
    int n = 100;
    int v[n] ;
    popular_vetor(v, n);
    imprimir (v, n ) ;

    int x ;
    printf("Digite o valor a ser procurado ->") ;
    scanf("%d", &x) ;

    int posicao = buscalinear(v,x,n) ;
    prinf ("\n BUSCA LINEAR : \n") ;
    if (posicao != -1) {
         printf ("Valor encontrado!! NA POSIÇÃO %d: ", posicao) ;
    } else {
        printf ("Valor não foi encontrado !") ;
    }

    printf ("\n BUSCA BINARIA");
    int binaria = buscaBinaria(v,x,n);

    return 0 ;
}
