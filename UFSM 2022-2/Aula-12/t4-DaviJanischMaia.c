//T4
//Davi Janisch Maia
//SI1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONSTANTE_X 35
#define TAMANHO_STRING 75

/*
    Fun��o que recebe um vetor e devolve o termo com maior valor
*/

float encontraMaior(float vetor[]){
    float maior = 0;
    for(int j = 0; j <= sizeof(vetor); j++){
        if(vetor[j] > maior){
            maior = vetor[j];
        }
    }
    return maior;
}

/*
    Fun��o recebe dois vetores e devolve o termo com maior valor entre eles
*/

float maiorEntreVetores(float vetor1[], float vetor2[]){
    float maior1, maior2;
    maior1 = encontraMaior(vetor1);
    maior2 = encontraMaior(vetor2);
    if(maior1 > maior2){
        return maior1;
    }else {
        return maior2;
    }
}

/*
    Fun��o que calcula a quantidade de X para um valor,
    levando em conta o maior termo e a constante que
    equivale esse maior valor � 35.
*/

int tamanhoDeX(float maior, float valor){
    int tamanho;
    tamanho = (int)(CONSTANTE_X * (valor / maior));
    return tamanho;
}

void linhaDeX(float maior, float valor1, float valor2, int faixaIdade){
    int tamanhoStr1 = tamanhoDeX(maior, valor1);
    int tamanhoStr2 = tamanhoDeX(maior, valor2);
    char stringV1[CONSTANTE_X] ="\0", stringV2[CONSTANTE_X]="\0";

    for(int i = 0; i < tamanhoStr1; i++){
        strcat(stringV1, "X");
    }
    for(int j = 0; j < tamanhoStr2; j++){
        strcat(stringV2, "X");
    }

    if(faixaIdade < 100){
        printf("\n%+35s %3d %-35s", stringV1, faixaIdade, stringV2);
    }else{
        printf("\n%+35s %+3s %-35s", stringV1, "++", stringV2);
    }

}

void geraPiramide(float vetor1[], float vetor2[]){
    int maior = maiorEntreVetores(vetor1, vetor2);
    for(int i = 0; i < 21; i++){
        linhaDeX(maior, vetor1[21-i], vetor2[21-i], (110-(5*i)));
    }
    printf("\n\n\t\tPIR�MIDE ET�RIA");
}

int main(void){
    float ph[21] = { 200, 190, 180, 170, 160, 150, 140, 129, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };
    float pf[21] = { 200, 190, 220, 170, 160, 150, 140, 129, 120, 40, 100, 90, 80, 70, 70, 50, 40, 30, 20, 10, 0 };
    geraPiramide(ph, pf);
    return 0;
}
