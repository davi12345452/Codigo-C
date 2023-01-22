// T5 - Davi Jansich Maia

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define CHANCES 10
#define N_JOGADAS 4
#define N_CORES 7
#define N_MAX_PARTIDAS 20

void cor_texto(int vermelho, int verde, int azul){
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_fundo(int vermelho, int verde, int azul){
    printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_normal(){
    printf("\e[m");
}

void espaco(int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("\n ");
    }
}

void imprime_retangulo(int vermelho, int verde, int azul, char texto[]){
  cor_fundo(vermelho, verde, azul);
  cor_texto(0, 0, 0);
  espaco(1);
  printf(" %s ", texto);
  espaco(1);
  cor_normal();
}

int main(){
    imprime_retangulo(20, 200, 100, "Ola");
    return 0;
}