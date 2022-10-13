/*
Trabalho 1
Davi Jansich Maia
SI 1 2022/2
*/

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

/* Neste program, o usuário escolhe um número e o computador tenta adivinhar
   usando a função rand(), a cada tentativa ele devolve o número ao usuário,
   que deve dizer se acertou, ou se o número é maior ou menor. No fim, o pro-
   grama devolve quantas tentativas foram necessárias até acertar o número. */

int main(){

    int numero, acerto; // Declaração Variáveis de entrada
    int chute, divisor_max, divisor_min = 0; // Declaração Variáveis Intermediárias
    int contador, somador; // Declaração Variável de saída

    printf("Digite um numero para o computador adivinhar: ");
    scanf("%d", &numero); //Entrada do número que desejamos que o computador adivinhe

    divisor_max = 100; //Atribui 100 ao divisor máximo do rand, logo os valores serão de 0 a 99
    contador = 0; //Contador de chances que o computador demora para acertar
    somador = 1; //Valor atribuído após o resto da divisão com os divisores e o rand

    while (true) {

        /*
          Programa irá gerar números aleatórios de acordo com uma lógica. Esses valores
          deverão estar dentro de um intervalo que começa no somador e tem tamanho da
          diferença do divisor máximo com o divisor mínimo. Por exemplo, se max = 30, min =
          20 e somador = 20, logo teremos um intervalo de 20 a 30 para o computador chutar
        */

        srand(time(0)); //Gera uma nova cadeia de números aleatórios
        chute = rand() % (divisor_max - divisor_min)+ somador;

        /*
          Layout de entrada e saída. Computador da como saída o número que chutou, enquanto o
          usuária indica se está ou não certo.
        */

        printf("Numero chutado: %d", chute);
        printf("\n0 - Digite se acertou\n1 - Digite se chute e maior\n2 - Digite se chute e menor");
        scanf("%d", &acerto);
        contador += 1; // Contador de chances para acertar

        /*Lógica do programa: se chutou igual, cabe ao usuário indicar e o laço acaba.
          Se o chute for maior, o divisor máximo passa a ser esse valor
          Se o chute for menor, o divisor mínimo passa a ser esse valor e o somador também.
        */

        if(acerto == 0){
            break;
        }else if(acerto == 1){
            divisor_max = chute;
        }else{
            divisor_min = chute;
            somador = chute;
        }
    }

    printf("\nComputador acertou o numero %d com %d chutes.\n", numero, contador); //Saída do programa com o número e as chances usadas

}
