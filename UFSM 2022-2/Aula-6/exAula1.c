#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int nSorted, nUser, quantidadeChutes = 0;

    nSorted = rand();

    while(nSorted != nUser){
        printf("\nDigite um numero: ");
        scanf("%d", &nUser);
        quantidadeChutes += 1;
        if(nSorted > nUser){
            printf("\nNumero e maior");
        }else if(nSorted < nUser){
            printf("\nNumero e menor");
        }else{
            printf("\nVoce acertou, parabens");
            printf("\nSorteado: %d | Chutes : %d", nSorted, quantidadeChutes);
        }}


    return 0;
}
