#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

    int numero, chute, divisor;
    int acerto, contador;

    printf("Digite um numero para o computador adivinhar: ");
    scanf("%d", &numero);

    divisor = 100;
    contador = 1;

    while (true) {

        srand(time(0));
        chute = rand() % divisor + 1;

        printf("Numero chutado: %d", chute);
        printf("\n0 - Digite se acertou\n1 - Digite se chute e maior\n2 - Digite se chute e menor");
        scanf("%d", &acerto);
        contador += 1;

        if(acerto == 0){
            break;
        }else if(acerto == 1){
            divisor = chute;
        }else{
            divisor *= 2;
        }
    }

    printf("Computador acertou o numero %d com %d chutes.", numero, contador);

}
