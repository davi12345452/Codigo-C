#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
char SIMBOLOS[8] = "VARTELC\0";
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




void imprime(){
    char string[5];
    sorteiaJogada(string);
    printf("%s", string);
}

int main(){
    imprime();
    return 0;
}