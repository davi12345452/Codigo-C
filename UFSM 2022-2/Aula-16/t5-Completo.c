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
    Função que gera uma linha para apresentação do jogo
*/

void linha(){
    printf("%s\n", "---------------------------------------------------");
}
/*
    Função que explica o jogo
*/
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

/*
    Função que checa se o jogador realizou uma jogada válida. Para ser válida,
    a jogada deve ter cores aceitas pelo jogo e não pode repetir cores nas jo-
    gadas. Se tudo estiver certo, ela devolve true, senão false.
*/
bool checaJogada(char jogada[], char cores[]){
    int somador = 0, checador;
    //Se a jogador tiver mais ou menos que 4 letras, é falsa
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
        //Este if checa se o usuário digitou uma cor mais de uma vez
        if(checador > 1){
            return false;
        }
        somador += checador; //Se estiver certo, checado será 0 ou 1, se der mais que 1 a função ja terá acabado
    }
    if(somador == N_JOGADAS){
        return true;
    }else{
        return false;
    }
}

/*
    Função que gera a explicação do jogo, recebe uma entrada, verifica se é válida e a
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
            printf("Você fez uma jogada inválida\n");
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


