/*
Davi Janisch Maia
T5 - L1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define NUM_STRING 5
#define NUM_CHANCES 9
#define NUM_CORES 7

#define PRETO 0, 0, 0
#define BRANCO 255, 255, 255

char SIMBOLOS[8] = "VARTELC\0";
int COLOR_VALUES[7][3] = {{0, 255, 0},{255, 255, 0},{153, 51, 153},{255, 0, 0},{0, 0, 255},{255, 165, 0},{128, 128, 128}};
/*
    Funções de impressão de cores
*/

void cor_texto(int vermelho, int verde, int azul)
{
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_fundo(int vermelho, int verde, int azul)
{
    printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_normal(void)
{
    printf("\e[m");
}

void imprimePreto(){
    cor_fundo(PRETO);
    printf("       ");
    cor_normal();
}

void imprimeBranco(){
    cor_fundo(BRANCO);
    printf("       ");
    cor_normal();
}

void imprimeCor(char simbol, int vermelho, int verde, int azul, bool verificador){ //Uso o bool para determinar se deve ou não imprimir a letra
    cor_fundo(vermelho, verde, azul);
    cor_texto(PRETO);
    if(verificador){
        printf("   %c   ", simbol);
    }else{
        printf("       ");
    }
    cor_normal();
}

void elementoTabelaDeCores(char simbol, int vermelho, int verde, int azul){
    printf("| ");
    imprimeCor(simbol, vermelho, verde, azul, false);
    printf("%+35s\n", "|");
    printf("| ");
    imprimeCor(simbol, vermelho, verde, azul, false);
    printf("%s%c%+12s", " ----------> Simbolo: ", simbol, "|");
    printf("\n");
    printf("| ");
    imprimeCor(simbol, vermelho, verde, azul, false);
    printf("%+35s\n", "|");
}

void tabelaDeCores(){
    printf("--------------------------------------------\n");
    printf("%s%+30s%+13s\n", "|", "TABELA DE CORES", "|");
    printf("--------------------------------------------\n");
    for(int i = 0; i < NUM_CORES; i++){
        elementoTabelaDeCores(SIMBOLOS[i], COLOR_VALUES[i][0], COLOR_VALUES[i][1], COLOR_VALUES[i][2]);
    }
    printf("--------------------------------------------");
}

void imprimeLinhaCor(char string[], int preto, int branco, bool verificador){
    int indices[4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < NUM_CORES; j++){
            if(string[i] == SIMBOLOS[j]){
                imprimeCor(SIMBOLOS[j], COLOR_VALUES[j][0], COLOR_VALUES[j][1], COLOR_VALUES[j][2], verificador);
                printf(" ");
            }
        }
    }
    printf("    ");
    for(int k = 0; k < preto; k++){
        imprimePreto();
        printf(" ");
    }
    for(int k = 0; k < branco; k++){
        imprimeBranco();
        printf(" ");
    }
    printf("\n");  
}

void imprimeResulatadoCores(char string[], int preto, int branco){
    printf("\n");
    imprimeLinhaCor(string, preto, branco, false);
    imprimeLinhaCor(string, preto, branco, true);
    imprimeLinhaCor(string, preto, branco, false);
    printf("\n");
}
/*
    Funções sem lógica, apenas de impressão, como apresentação, despedida...
*/
void regras(){
    printf("%-2s%-40s%+2s\n", "|", "COMANDO ADICIONAIS: ", "|");
    printf("%-2s%-40s%+2s\n", "|", "# -> Encerra a partida que esta jogando", "|");
    printf("%-2s%-40s%+2s\n", "|", "? -> Exibe a tabela de cores do jogo", "|");
    printf("%-2s%-40s%+2s\n", "|", "! -> Exibe suas jogadas na partida", "|");
    printf("%-2s%-40s%+2s\n", "|", "ATENCAO!! ", "|");
    printf("%-2s%-40s%+2s\n", "|", " -> Nao repita cores na jogada", "|");
    printf("%-2s%-40s%+2s\n", "|", " -> Use os simbolos da tabela somente", "|");
}

void apresentacao(){
    printf("--------------------------------------------\n");
    printf("%s%+33s%+10s\n", "|", "BEM VINDO AO MASTERMIND", "|");
    printf("--------------------------------------------\n");
    regras();
    tabelaDeCores();
}

void despedida(){

}

/*
    Demais funções do programa, com a lógica do jogo.
*/

bool verificaJogada(char jogadaJogador[]){
    int somador = 0, checador;
    for(int i = 0; i < NUM_CORES; i++){
        checador = 0;
        for(int j = 0; j < 4; j++){
            if(jogadaJogador[j] == SIMBOLOS[i]){
                checador ++;
            }
        }
        if(checador > 1) return false;
        somador += checador;
    }
    if(somador == 4) return true;
}

int retornaSituacaoJogada(char jogadaJogador[]){
    if(jogadaJogador == "#") return 0;
    else if(jogadaJogador == "?") return 1;
    else if(jogadaJogador == "!") return 2;
    
    else if(verificaJogada(jogadaJogador)) return 3;
    else return 4;
}

void fazJogada(){}
int verificaAcertosPreto(char jogadaJogador[], char jogadaSorteada[]){

}

int verificaAcertosBrancos(char jogadaJogador[], char jogadaSorteada[]){

}

void imprimeRelatorio(char jogadas[NUM_CHANCES][NUM_STRING]){
    printf("--------------------------------------------\n");
    printf("%s%+30s%+13s\n", "|", "RELATORIO JOGADAS", "|");
    printf("--------------------------------------------\n");
    for(int i = 0; i < NUM_CHANCES; i++){
       printf("%-2s%+8s %d   -->   %-4s%+19s\n", "|", "Jogada", i+1, jogadas[i], "|");     
    }
    printf("--------------------------------------------\n");
}

void recebeJogada(char jogadaJogador[]){
    printf("Digite a sua jogada: ");
    scanf("%s", &jogadaJogador);
}

void partida(){}
void jogo(){}


int main(){
    setlocale(LC_ALL, "portuguese");
    printf("%d", retornaSituacaoJogada("VART"));
    return 0;
}