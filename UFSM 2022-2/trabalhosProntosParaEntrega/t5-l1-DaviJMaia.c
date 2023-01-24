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
#include <ctype.h>

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

/* Essa função imprime a tabela de cores para o usuário*/

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

/* Essa função imprime as cores jogadas pelo usuário e seu resultado, os quadrados pretos e brancos*/
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
    printf("\nQue pena, espero que tenha se divertido, ate!\n");
}

/*
    Demais funções do programa, com a lógica do jogo.
*/

/* Essa função é feita para receber uma jogada, ja descartado as entradas 
   de caracteres especiais, devolvendo true se é válida e false se não.*/
bool verificaJogada(char jogadaJogador[]){
    int somador = 0, checador;
    if(strlen(jogadaJogador) != 4) return false;
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

/* Essa função retorna 0 caso queira sair, 1 para imprimir
   tabela de cores, 2 para ver as jogas, 3 se é válida e 
   4 se for uma jogada inválida. Esses número serão usados
   na função partid.*/
int retornaSituacaoJogada(char jogadaJogador[]){
    if(strncmp(jogadaJogador, "#", 1) == 0) return 0;
    else if(strncmp(jogadaJogador, "?", 1) == 0) return 1;
    else if(strncmp(jogadaJogador, "!", 1) == 0) return 2;
    else if(verificaJogada(jogadaJogador)) return 3;
    else return 4;
}

/* Devolve os acertos de quadrado preto*/
int verificaAcertosPreto(char jogadaJogador[], char jogadaSorteada[]){
    int acertosPreto = 0;
    for(int i = 0; i < 4; i++){
        if(jogadaJogador[i] == jogadaSorteada[i]){
            acertosPreto++;
        }
    }
    return acertosPreto;
}

/* Devolve os acertos do quadrado branco*/
int verificaAcertosBrancos(char jogadaJogador[], char jogadaSorteada[]){
    int brancos = 0;
    int pretos = verificaAcertosPreto(jogadaJogador, jogadaSorteada);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(jogadaJogador[i] == jogadaSorteada[j]) brancos++;
        }
    }
    return brancos - pretos;
}

/* Imprime as jogadas do usuário na partida*/
void imprimeRelatorio(char jogadas[NUM_CHANCES][NUM_STRING]){
    printf("--------------------------------------------\n");
    printf("%s%+30s%+13s\n", "|", "RELATORIO JOGADAS", "|");
    printf("--------------------------------------------\n");
    for(int i = 0; i < NUM_CHANCES; i++){
       printf("%-2s%+8s %d   -->   %-4s%+19s\n", "|", "Jogada", i+1, jogadas[i], "|");     
    }
    printf("--------------------------------------------\n");
}

/* Função que le a jogada e a transforma totalmente em maiúscula*/
void recebeJogada(char jogadaJogador[]){
    printf("\nDigite a sua jogada: ");
    scanf("%s", jogadaJogador);

    for(int i = 0; i < 4; i++){
        jogadaJogador[i] = toupper(jogadaJogador[i]);
    }
}

/* As próximas duas funcoes fazem o sorteio de uma jogada.
   A funcao bool verifica se a letra já foi sorteada ou nao,
   permitindo a funcao void, principal, entrar em um loop ate
   que ache um simbolo valido para a jogada.*/

bool letraRepetida(char letra, char jogadaSorteada[], int i){
    for(int j = 0; j < i; j++){
        if(letra == jogadaSorteada[j]){
            return true;
        }
    }
    return false;
}

void sorteiaJogada(char jogadaSorteada[]){
    char letraSorteada;
    srand(time(0));

    for(int i = 0; i < 4; i++){
        letraSorteada = SIMBOLOS[rand()%7];
        while(letraRepetida(letraSorteada, jogadaSorteada, i)){
            letraSorteada = SIMBOLOS[rand()%7];
        }
        jogadaSorteada[i] = letraSorteada;
    }
    jogadaSorteada[4] = '\0';
}

/* Função que cria uma partida, usando as funções anteriores*/
void partida(){
    char jogadaJogador[5]; 
    char jogadaSorteada[5];
    int cont = 0;
    char tabela[NUM_CHANCES][NUM_STRING];
    memset(tabela, '\0', sizeof(tabela));
    sorteiaJogada(jogadaSorteada);
    do{
        recebeJogada(jogadaJogador);
        if(retornaSituacaoJogada(jogadaJogador) == 0) break;
        else if(retornaSituacaoJogada(jogadaJogador) == 1) tabelaDeCores();
        else if(retornaSituacaoJogada(jogadaJogador) == 2) imprimeRelatorio(tabela);
        else if(retornaSituacaoJogada(jogadaJogador) == 4) printf("Jogada Invalida.");
        else{
            strcpy(tabela[cont], jogadaJogador);
            cont++;
            imprimeResulatadoCores(jogadaJogador, verificaAcertosPreto(jogadaJogador, jogadaSorteada), verificaAcertosBrancos(jogadaJogador, jogadaSorteada));
            if(strcmp(jogadaJogador, jogadaSorteada) == 0){
                printf("Parabens, voce venceu na rodada %d", cont);
                break;
            }
        }
    }while(cont < NUM_CHANCES);
}

/* Coloca a partida em um loop infinito, o usuário pode jogar quanto quiser*/
void jogo(){
    int decisao;
    apresentacao();
    while(true){
        partida();
        printf("\nVoce deseja jogar mais uma partida? [Sim: 1/Nao: 0] ");
        scanf("%d", &decisao);
        if(decisao == 0) break;
    }
    despedida();
}


int main(){
    setlocale(LC_ALL, "portuguese");
    jogo();
    return 0;
}