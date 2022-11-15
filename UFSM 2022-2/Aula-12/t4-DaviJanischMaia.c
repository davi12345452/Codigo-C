#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONSTANTE_X 35.0

float encontraMaior(float vetor[]){
    float maior = 0;
    for(int j = 0; j <= sizeof(vetor); j++){
        if(vetor[j] > maior){
            maior = vetor[j];
        }
    }
    return maior;
}

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

int porcentagemParaX(float maior, float valor){
    int porcentagem;
    porcentagem = (int)(CONSTANTE_X * (valor / maior));
    return porcentagem;
}

void geraLinhaX(float maior, float valor1, float valor2, int idadeIndice){
    int porcentagemV1 = porcentagemParaX(maior, valor1);
    int porcentagemV2 = porcentagemParaX(maior, valor2);
    int espaco;
    espaco = (int)CONSTANTE_X - porcentagemV1;
    for(int i = 0; i < espaco; i++){
        printf("%s", " ");
    }
    for(int j = 0; j < porcentagemV1; j++){
        printf("%s", "X");
    }
    printf(" %d ", idadeIndice);
    for(int k = 0; k < porcentagemV2; k++){
        printf("%s", "X");
    }
}

void geraPiramide(float vetor1[], float vetor2[]){
    int maior = maiorEntreVetores(vetor1, vetor2);
    int tamanhoVetor = sizeof(vetor1);
    for(int i = tamanhoVetor; i < 0; i--){
        geraLinhaX(maior, vetor1[i], vetor2[i], (i*5));
    }
}


int main(void){
    float ph[21] = { 200, 190, 180, 170, 160, 150, 140, 129, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };
    float pf[21] = { 200, 190, 220, 170, 160, 150, 140, 129, 120, 40, 100, 90, 80, 70, 70, 50, 40, 30, 20, 10, 0 };
    geraLinhaX(220, 180, 120, 50);
    geraPiramide(ph, pf);
    return 0;
}


/*har * geraX(float _maior, float _valor){
    int porcentagem = porcentagemParaX(_maior, _valor);
    char *stringDeX;
    stringDeX = (char*)malloc(porcentagem*sizeof(char));
    for(int i = 0; i <= porcentagem; i++){
        strcat(stringDeX, "X");
    }
    return stringDeX;
}*/

/*char * geraLinhaX (float _maior, float _valor1, float _valor2, int faixaIdade){
    int porcentagemVet1 = porcentagemParaX(_maior, _valor1);
    int porcentagemVet2 = porcentagemParaX(_maior, _valor2);
    char stringDeX1[porcentagemVet1], stringDeX2[porcentagemVet2];
    memset(c_arr, 0, LENGTH);
    memset(c_arr, 0, LENGTH);
    //stringDeX1 = (char*)malloc(porcentagemVet1*sizeof(char));
    //stringDeX2 = (char**)malloc(porcentagemVet2*sizeof(char));
    for(int i = 0; i < porcentagemVet1; i++){
        strcat(stringDeX1, "X");
    }
    for(int j = 0; j < porcentagemVet2; j++){
        strcat(stringDeX2, "X");
    }
    printf("%+35s%3d %-35s", stringDeX1, faixaIdade, stringDeX2);
}*/
