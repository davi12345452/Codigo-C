//T4
//Davi Janisch Maia
//SI1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CONSTANTE_X 35
#define TAMANHO_STRING 75

/*
    Função que recebe um vetor e devolve o termo com maior valor
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
    Função recebe dois vetores e devolve o termo com maior valor entre eles
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
    Função que calcula a quantidade de X para um valor,
    levando em conta o maior termo e a constante que
    equivale esse maior valor à 35.
*/

int tamanhoDeX(float maior, float valor){
    int tamanho;
    tamanho = (int)(CONSTANTE_X * (valor / maior));
    return tamanho;
}

/*
    Função sem retorno que imprive uma linha da pirâmide.
    Recebe o maior valor, dois valores dos vetores e uma
    faixa de idade. Define os tamanhos das strings, levando
    em conta a função tamanhoDeX(). Após, cria duas strings
    vazias, com tamanho de 35, valor pré-estabelecido. Após,
    atribui X, com base no tamanho devolvido da função tamanhoDeX().
    Imprime o resultado, sem retornar nada.
*/

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

/*
    Função que cria a pirâmide, chamando a função que exibe as linhas.
    Criei de maneira contrária, sem usar i--, pois meu console não imprimia
    nada quando usava assim. Dentro dos vetores, fazemos as operações X-i
    para gerar a pirâmide com a faixa de idade decrescendo.
*/

void geraPiramide(float vetor1[], float vetor2[]){
    int maior = maiorEntreVetores(vetor1, vetor2);
    printf("\n%+30s%s\n", " ", "PIRÂMIDE ETÁRIA");
    for(int i = 1; i <= 21; i++){
        linhaDeX(maior, vetor1[21-i], vetor2[21-i], (105-(5*i)));
    }
    printf("\n\n");
}

int main(void){ //Função main, chama a função que gera pirâmide
    setlocale(LC_ALL, "portuguese");
    float ph1[21] = { 200, 190, 180, 170, 160, 150, 140, 129, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };
    float pf1[21] = { 200, 190, 220, 170, 160, 150, 140, 129, 120, 40, 100, 90, 80, 70, 70, 50, 40, 30, 20, 10, 0 };
    float ph2[21] = { 160, 170, 190, 210, 220, 240, 240, 230, 230, 220, 200, 190, 180, 140, 110, 90, 60, 40, 30, 10, 0 };
    float pf2[21] = { 170, 170, 200, 210, 220, 240, 240, 230, 230, 220, 200, 190, 180, 150, 120, 90, 70, 50, 30, 20, 10 };
    geraPiramide(ph1, pf1);
    geraPiramide(ph2, pf2);
    return 0;
}
