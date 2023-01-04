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

const char* SIMBOLS[] = {"V", "A", "R", "T", "E", "L", "C"};
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

void imprime_retangulo(int vermelho, int verde, int azul, char texto[]){
  cor_fundo(vermelho, verde, azul);
  cor_texto(0, 0, 0);
  espaco(1);
  printf("%s", texto);
  espaco(1);
  cor_normal();
}

void linha(){
    printf("%s\n", "---------------------------------------------------");
}

void explicacao(){
    printf("Para jogar, basta você escolher chutar 4 letras\nválidas de cores.\n");
    printf("Obs.:\n");
    printf("Comando ? : Devolve a tabela de cores e símbols\n");
    printf("Comando ! : Devolve suas jogadas na partida\n");
    printf("Comando # : Sai do jogo\n");
}

void tabelaCores(){
    for(int n = 0; n < N_CORES; n++){
        printf("%s :", SIMBOLS[n]);
        espaco(2);
        imprime_retangulo(COLOR_VALUES[n][0], COLOR_VALUES[n][1], COLOR_VALUES[n][2], SIMBOLS[n]);
        printf("\n");
    }
}

void introducao(){
    linha();
    printf("%15s%s\n"," ", "Bem vindo ao MasterMind!");
    linha();
    explicacao();
    linha();
    printf("%+30s\n", "JOGADAS");
    tabelaCores();
    linha();
}

void tabelaJogadas(char tabela[][N_CORES]){
    for(int k = 0; k < CHANCES; k++){
        printf("%s %d : %s", "JOGADA", k, tabela[k]);
    }
}

bool checaJogada(char jogada[]){
    int somador = 0, checador;
    if(strlen(jogada) != N_JOGADAS) return false;
    for(int i = 0; i < N_CORES; i++){
        checador = 0;
        for(int j = 0; j < N_JOGADAS; j++){
            if(jogada[j] == SIMBOLS[i]){
                checador ++;
            }
        }
        if(checador > 1) return false;
        somador += checador;
    }
    if(somador == N_JOGADAS) return true;
    else return false;
}

void colocaEmMaiuscula(char jogada[]){
    for (int i = 0; i < strlen(jogada); i++) {
        jogada[i] = toupper(jogada[i]);
    }
}

void recebeJogada(char jogada[],char tabela[][N_JOGADAS]){
    bool jogadaValida = false;
    while(!jogadaValida){
        printf("Sua jogada: ");
        fgets(jogada, N_JOGADAS + 1, stdin);
        jogada[strcspn(jogada, "\n")] = 0;
        colocaEmMaiuscula(jogada);
        if(strcmp(jogada, "?") == 0){
            tabelaCores();
        }
        else if(strcmp(jogada, "!") == 0){
            tabelaJogadas(tabela);
        }
        else if(strcmp(jogada, "#") == 0){
            break;
        }
        else if(checaJogada(jogada)){
            jogadaValida = true;
        }
        else printf("Jogada inválida, digite novamente\n");
    }
}

int sorteiaIndex(){
    int index;
    srand(time(NULL));
    index = rand() % 7;
    return index;
}

void sorteia(char jogadaSorteada[]){
    while(true){
        for(int i = 0; i < N_JOGADAS; i++){
            jogadaSorteada = SIMBOLS[sorteiaIndex()];
        }
        if(checaJogada(jogadaSorteada)) break;
    }
}



bool desejaContinuar(){
    char resposta;
    printf("\nDeseja jogar novamente? [S/N] ");
    scanf("%c", &resposta);
    if(resposta == "S" || resposta == "s") return false;
    else return true;
}

void gameMinor(char sorteado[], char tabela[][N_JOGADAS]){
    for(int j = 0; j < CHANCES; j++){
        printf("%s %d\n", "RODADA", j);
        char jogou[N_JOGADAS];
        recebeJogada(jogou, tabela);
        if(jogou == "#") break;
        if(sorteado == jogou){
            printf("Você acertou na rodada %d", j);
            strcat(tabela[j], jogou);
            break;
        }
    }

}

void gameMajor(){
    char tabela[N_MAX_PARTIDAS][N_JOGADAS];
    char sorteado[N_JOGADAS];
    for(int m = 0; m < N_MAX_PARTIDAS; m++){
        printf("\t\t JOGO DE NÚMERO %d", m);
        sorteia(sorteado);
        printf("oi");
        gameMinor(sorteado, tabela);
        if(desejaContinuar) break;
    }
}

void game(){
    introducao();
    gameMajor();
    printf("Encerrando o jogo...");
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));
    char jogada[N_JOGADAS];
    sorteia(jogada);
    printf("%s", jogada);
    //game();
    return 0;
}
