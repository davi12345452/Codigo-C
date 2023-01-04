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

const char* COLORS[] = {"V", "A", "R", "T", "E", "L", "C"};
const int COLOR_VALUES[][3] = {{0, 255, 0},{255, 255, 0},{153, 51, 153},{255, 0, 0},{0, 0, 255},{255, 165, 0},{128, 128, 128}};


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
        printf(" ");
    }
}

void imprime_retangulo(int vermelho, int verde, int azul, char *texto){
  cor_fundo(vermelho, verde, azul);
  cor_texto(0, 0, 0);
  printf("%s", texto);
  cor_normal();
}

void imprimeSeqRetangulos(char * entrada[]){
    int index;
    for(int j = 0; j < N_JOGADAS; j++){
        for(int i = 0; i < N_CORES; i++){
            if(strcmp(entrada[j], COLORS[i]) == 0){
                index = i;
            }
        }
        int vermelho = COLOR_VALUES[index][0];
        int verde = COLOR_VALUES[index][1];
        int azul = COLOR_VALUES[index][2];
        if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255) {
            imprime_retangulo(vermelho, verde, azul, entrada[j]);
            espaco(1);
        } else {
            printf("Valores inválidos para vermelho, verde e azul: %d, %d, %d\n", vermelho, verde, azul);
        }
    }
}

void linha(){
    printf("%s\n", "---------------------------------------------------");
}

void explicaJogo(){
    linha();
    printf("%15s%s\n"," ", "Bem vindo ao MasterMind!");
    linha();
    printf("%s\n", "Observação: cada jogada é feita com 4 letras\nmaiúsculas, não pode usar outras letras senão\nas fornecidas nem repetir letra alguma.");
    linha();
    printf("%+30s\n", "JOGADAS");
    printf("V -> Verde\nA -> Amarelo\nR -> Roxo\nT -> Vermelho\nE -> Azul\nL -> Laranja\nC -> Cinza\n");
    linha();
}

bool checaJogada(char jogada[], char cores[]){
    int somador = 0, checador;
    if(strlen(jogada) != N_JOGADAS) return false;
    for(int i = 0; i < N_CORES; i++){
        checador = 0;
        for(int j = 0; j < N_JOGADAS; j++){
            if(jogada[j] == cores[i]){
                checador ++;
            }
        }
        if(checador > 1) return false;
        somador += checador;
    }
    if(somador == N_JOGADAS) return true;
    else return false;
}

char * recebeJogada(char cores[]){
    char jogadaDoJogador[N_JOGADAS], jogadaCorrigida[N_JOGADAS];
    while(true){
        printf("Sua jogada: ");
        scanf("%s", &jogadaDoJogador);
        strcat(jogadaCorrigida, strupr(jogadaDoJogador));
        if(checaJogada(jogadaCorrigida, cores)) break;
        else{
            linha();
            printf("Você fez uma jogada inválida\n");
            linha();
        }
    }
    return jogadaDoJogador;
}

int main(){
    setlocale(LC_ALL, "");
    char *entrada = "VART";
    imprimeSeqRetangulos(entrada);
    return 0;
}
