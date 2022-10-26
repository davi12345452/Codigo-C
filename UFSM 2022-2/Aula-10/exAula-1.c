#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

/*
    1 - Receber um valor
    2 - Chutar valores aleatórios
    3 - Ir verificando se valor * valor = num

*/


float randEntre(max, min){

    float valor;
    valor = rand() % (max - min) + min;
    return valor;

}

float raiz(float num){

    float maior, menor, randomNumber;

    maior = num;
    menor = 1;

    while(true){
        randomNumber = randEntre(maior, menor);
        if(randomNumber * randomNumber > 1.05 * num){
            maior = randomNumber * 0.95;
        }else if(randomNumber * randomNumber < 0.95* num){
            menor = randomNumber * 1.05;
        }else{
            return randomNumber;
        }
    }
    return randomNumber;
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    float entrada, saida;

    printf("\nDigite o número que deseja saber a raiz: ");
    scanf("%f", &entrada);

    saida = raiz(entrada);

    printf("A raiz de %.2f é %.2f", entrada, saida);

    return 0;
}
