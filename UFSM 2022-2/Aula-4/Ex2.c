#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    float ang_1, ang_2, ang_3;
    char saida[2][20];

    printf("Digite os angulos: ");
    scanf("%f%f%f", &ang_1, &ang_2, &ang_3);

    if(ang_1 == 90 || (ang_2 == 90 || ang_3 == 90)){
        strcpy(saida[0], "Retangulo");
    }else if(ang_1 > 90 || (ang_2 > 90 || ang_3 > 90)){
        strcpy(saida[0], "Obtusangulo");
    }else{
        strcpy(saida[0], "Acutangulo");
    }

    if(ang_1 == ang_2 && ang_1 == ang_3){
        strcpy(saida[1], "Equilatero");
    }else if(ang_1 != ang_2 && (ang_1 != ang_3 && ang_2 != ang_3)){
        strcpy(saida[1], "Escaleno");
    }else{
        strcpy(saida[1], "Isosceles");
    }

    printf("Os angulos formam um triangulo %s e %s", saida[0], saida[1]);

    return 0;

}
