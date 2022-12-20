// T5 - Davi Jansich Maia

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define CHANCES 10
#define N_JOGADAS 4
#define N_CORES 7

/*
    Fun��o que gera uma linha para apresenta��o do jogo
*/

void linha(){
    printf("%s\n", "---------------------------------------------------");
}
/*
    Fun��o que explica o jogo
*/
void explicaJogo(){
    linha();
    printf("%15s%s\n"," ", "Bem vindo ao MasterMind!");
    linha();
    printf("%s\n", "Observa��o: cada jogada � feita com 4 letras\nmai�sculas, n�o pode usar outras letras sen�o\nas fornecidas nem repetir letra alguma.");
    linha();
    printf("%+30s\n", "JOGADAS");
    printf("V -> Verde\nA -> Amarelo\nR -> Roxo\nT -> Vermelho\nE -> Azul\nL -> Laranja\nC -> Cinza\n");
    linha();
}

/*
    Fun��o que checa se o jogador realizou uma jogada v�lida. Para ser v�lida,
    a jogada deve ter cores aceitas pelo jogo e n�o pode repetir cores nas jo-
    gadas. Se tudo estiver certo, ela devolve true, sen�o false.
*/
bool checaJogada(char jogada[], char cores[]){
    int somador = 0, checador;
    //Se a jogador tiver mais ou menos que 4 letras, � falsa
    if(strlen(jogada) != N_JOGADAS){
        return false;
    }
    for(int i = 0; i < N_CORES; i++){
        checador = 0;
        for(int j = 0; j < N_JOGADAS; j++){
            if(jogada[j] == cores[i]){
                checador += 1;
            }
        }
        //Este if checa se o usu�rio digitou uma cor mais de uma vez
        if(checador > 1){
            return false;
        }
        somador += checador; //Se estiver certo, checado ser� 0 ou 1, se der mais que 1 a fun��o ja ter� acabado
    }
    if(somador == N_JOGADAS){
        return true;
    }else{
        return false;
    }
}

/*
    Fun��o que gera a explica��o do jogo, recebe uma entrada, verifica se � v�lida e a
    retorna ela.
*/
char * recebeJogada(char cores[]){
    char jogadaDoJogador[N_JOGADAS], jogadaCorrigida[N_JOGADAS];
    while(true){
        printf("\Sua jogada: ");
        scanf("%s", &jogadaDoJogador);
        strcat(jogadaCorrigida, strupr(jogadaDoJogador));
        if(checaJogada(jogadaCorrigida, cores)){
            break;
        }else{
            linha();
            printf("Voc� fez uma jogada inv�lida\n");
            linha();
        }
    }
    return jogadaDoJogador;
}

void jogo(char cores[]){
    int chances = CHANCES;
    char jogada[N_JOGADAS];
    explicaJogo();

}
int main(){
    setlocale(LC_ALL, "Portuguese");
    char simboloCores[] = "VARTELC";
    recebeJogada(simboloCores);
    /*
    V -> Verde
    A -> Amarelo
    R -> Roxo
    T -> Vermelho
    E -> Azul
    L -> Laranja
    C -> Cinza
    */
    explicaJogo();
    return 0;
}


