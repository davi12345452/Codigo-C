#include <stdio.h>
#include <math.h>

/* Programa que calcula equação de 2° grau, recebe de entrada o a, b e c
   devolvendo como saída os dois x.*/


int main() {

    float a, b, c; //Variáveis de entrada
    float x1, x2; //Variáveis de saída
    float delta;
    float xReal, xImag_1, xImag_2;

    /*Entrada de dados*/

    printf("Valor do A: ");
    scanf("%f", &a);

    printf("Valor do B: ");
    scanf("%f", &b);

    printf("Valor do C: ");
    scanf("%f", &c);

    /*Cálculos do programa*/

    delta = pow(b, 2) - (4 * a * c);

    if(delta > 0){

        /*Cálculos do programa*/

        x1 = (-b + sqrt(delta))/(2 * a);
        x2 = (-b - sqrt(delta))/(2 * a);

        /*Saída dos dados*/

        printf("\nX1 = %f\nx2 = %f\n", x1, x2);

    }else if (delta == 0){

        /*Cálculos do programa*/

        x1 = -b/(2*a);

        /*Saída dos dados*/

        printf("\nPossui apenas uma raiz, %f\n", x1);


    }else{

        /*Cálculos do programa*/

        xReal = -b / (2*a);
        xImag_1 = - sqrt(-delta)/(2*a);
        xImag_2 = sqrt(-delta)/(2*a);

        /*Saída dos dados*/

        printf("\nX1 = %f + %fi\nX2 = %f + %fi\n", xReal, xImag_1, xImag_2);

    }

    return 0;

}
