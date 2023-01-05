#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define NUM_CHANCES 10
#define NUM_JOGADAS 4
#define NUM_CORES 7
#define NUM_MAX_PARTIDAS 20

const char* SIMBOLOS[] = {"V", "A", "R", "T", "E", "L", "C"};
const int COLOR_VALUES[][3] = {{0, 255, 0},{255, 255, 0},{153, 51, 153},{255, 0, 0},{0, 0, 255},{255, 165, 0},{128, 128, 128}};

void print_cor_texto(int vermelho, int verde, int azul){
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void print_cor_fundo(int vermelho, int verde, int azul){
    printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}

void print_cor_normal(){
    printf("\e[m");
}

void print_espaco(int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf(" ");
    }
}

void print_retangulo(int vermelho, int verde, int azul, char texto[]){
  print_cor_fundo(vermelho, verde, azul);
  print_cor_texto(0, 0, 0);
  print_espaco(1);
  printf("%s", texto);
  print_espaco(1);
  print_cor_normal();
}

void print_linha(){
    printf("%s\n", "---------------------------------------------------");
}

void print_explicacao(){
    printf("Para jogar, basta você escolher chutar 4 letras\nválidas de cores.\n");
    printf("Obs.:\n");
    printf("Comando ? : Devolve a tabela de cores e símbolos\n");
    printf("Comando ! : Devolve suas jogadas na partida\n");
    printf("Comando # : Sai do jogo\n");
}

void print_tabela_cores(){
    for(int n = 0; n < NUM_CORES; n++){
        printf("%s :", SIMBOLOS[n]);
        print_espaco(2);
        print_retangulo(COLOR_VALUES[n][0], COLOR_VALUES[n][1], COLOR_VALUES[n][2], SIMBOLOS[n]);
        printf("\n");
    }
}

void print_introducao(){
    print_linha();
    printf("%15s%s\n"," ", "Bem vindo ao MasterMind!");
    print_linha();
    print_explicacao();
    print_linha();
    printf("%+30s\n", "JOGADAS");
    print_tabela_cores();
    print_linha();
}

void print_tabela_jogadas(char tabela[][NUM_JOGADAS]){
    for(int k = 0; k < NUM_CHANCES; k++){
        printf("%s %d : %s", "JOGADA", k, tabela[k]);
    }
}

bool verifica_jogada(char jogada[]){
    int somador = 0, checador;
    if(strlen(jogada) != NUM_JOGADAS) return false;
    for(int i = 0; i < NUM_CORES; i++){
        checador = 0;
        for(int j = 0; j < NUM_JOGADAS; j++){
            if(jogada[j] == SIMBOLOS[i]){
                checador ++;
            }
        }
        if(checador > 1) return false;
        somador += checador;
    }
    if(somador == NUM_JOGADAS) return true;
}

void sorteia_cores(char cores[]){
    char coresPossiveis[NUM_CORES] = {'V', 'A', 'R', 'T', 'E', 'L', 'C'}, coresSorteadas[NUM_JOGADAS] = {'\0'};
    int numCoresSorteadas = 0;
    srand(time(0));
    do{
        numCoresSorteadas = 0;
        for (int i = 0; i < NUM_JOGADAS; i++){
            char cor = coresPossiveis[rand() % NUM_CORES];
            while(numCoresSorteadas > 0 && coresSorteadas[numCoresSorteadas - 1] == cor){
                cor = coresPossiveis[rand() % NUM_CORES];
            }
            coresSorteadas[numCoresSorteadas++] = cor;
        }
    } while(verifica_repeticao(coresSorteadas));
    strcpy(cores, coresSorteadas);
}

bool verifica_repeticao(char coresSorteadas[]){
    for(int i = 1; i < NUM_JOGADAS; i++){
        if(coresSorteadas[i] != coresSorteadas[0]){
            return false;
        }
    }
    return true;
}

void print_cor_jogadas(char cor){
    int r, g, b;
    print_cor_fundo(255, 50, 0);
    printf("     \n  %c  \n     \n", cor);
    print_cor_normal();
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    char cores[NUM_JOGADAS + 1], jogadas[NUM_CHANCES][NUM_JOGADAS + 1], chute[5];
    int tentativas = 0;
    bool jogando = true;
    sorteia_cores(cores);
    print_introducao();
    while(jogando){
        printf("\n%+30s\n", "CHUTE");
        scanf("%s", chute);
        if(chute[0] == '?'){
            print_tabela_cores();
        }
        else if(chute[0] == '!'){
            print_tabela_jogadas(jogadas);
        }
        else if(chute[0] == '#'){
            jogando = false;
            break;
        }
        else if(verifica_jogada(chute)){
            tentativas++;
            strcpy(jogadas[tentativas - 1], chute);
            if(strcmp(chute, cores) == 0){
                printf("\n%+30s\n", "PARABÉNS! VOCÊ VENCEU!");
                jogando = false;
                break;
            }
            if(tentativas == NUM_CHANCES){
                printf("\n%+30s\n", "QUE PENA! VOCÊ PERDEU!");
                jogando = false;
                break;
            }
        }
        else{
            printf("\n%+30s\n", "JOGADA INVÁLIDA!");
        }
    }
    printf("\n%+30s\n", "FIM DE JOGO!");
    return 0;
}


