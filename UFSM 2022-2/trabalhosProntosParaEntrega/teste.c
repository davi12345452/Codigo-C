#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool verificaRepetida(char string[], int posicao, char letra){
    if(posicao == 0) return true;
    for(int i = 0; i < posicao, i++){
        if(string[i] == letra) return false;
    }
    return true;
}

void sorteiaJogada(char jogadaSorteada[]){
    char letras[8] = "ABCDEFG\0";
    char letraSorteada;
    srand(time(0));
    for(int i = 0; i < 4; i++){
        letraSorteada = letras[rand()%7];
    }
    jogadaSorteada[4] = '\0';
}

void imprime(){
    char string[5];
    sorteiaJogada(string);
    printf("%s", string);
}

int main(){
    imprime();
    return 0;
}