#include <stdio.h>

#define T_ARRAY 4
#define T_PALAVRA 20

int main(){

    char situacao[T_ARRAY][T_PALAVRA] = {"Nada", "Fraca", "Moderada", "Forte"};
    int sol, vento, chuva, i;

    printf("\nEscolha um das quatro opcoes para representar quantidade de chuva, vento e sol:");
    for(i = 0; i < 4; i++){
        printf("\n%d - %s", i, situacao[i]);
    }

    printf("\n\nSol: ");
    scanf("%d", &sol);

    printf("Chuva: ");
    scanf("%d", &chuva);

    printf("Vento: ");
    scanf("%d", &vento);

    if(sol == 0 || chuva == 3){
        printf("\nNAO DEVE SER ABERTO");
    }else if(vento == 2 || vento == 3) {
        printf("\nNAO DEVE SER ABERTO");
    }else if(sol == 3 && chuva != 2){
        printf("\nNAO DEVE SER ABERTO");
    }else if(sol == 2 && chuva != 1){
        printf("\nNAO DEVE SER ABERTO");
    }else {
        printf("\nPODE SER ABERTO");
    }

    return 0;
}
