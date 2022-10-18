#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_entre(min, max){

    int valor;
    valor = rand() % (max - min) + min + 1;
    return valor;

}

int quadrado(num){

    int valor;
    valor = num * num;
    return num;

}


int main(){

    srand(time(0));
    printf("%d", rand_entre(10, 16));
    return 0;

}
