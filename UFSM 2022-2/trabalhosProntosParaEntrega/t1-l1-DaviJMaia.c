/*
Trabalho 1
Davi Jansich Maia
SI 1 2022/2
*/

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

/* Neste program, o usu?rio escolhe um n?mero e o computador tenta adivinhar
   usando a fun??o rand(), a cada tentativa ele devolve o n?mero ao usu?rio,
   que deve dizer se acertou, ou se o n?mero ? maior ou menor. No fim, o pro-
   grama devolve quantas tentativas foram necess?rias at? acertar o n?mero. */

int main(){

    int numero, acerto; // Declara??o Vari?veis de entrada
    int chute, divisor_max, divisor_min = 0; // Declara??o Vari?veis Intermedi?rias
    int contador, somador; // Declara??o Vari?vel de sa?da

/// se o programa vai adivinhar o que o usuário pensou, não deveria perguntar
///   o número pensado
    printf("Digite um numero para o computador adivinhar: ");
    scanf("%d", &numero); //Entrada do n?mero que desejamos que o computador adivinhe

    divisor_max = 100; //Atribui 100 ao divisor m?ximo do rand, logo os valores ser?o de 0 a 99
    contador = 0; //Contador de chances que o computador demora para acertar
    somador = 1; //Valor atribu?do ap?s o resto da divis?o com os divisores e o rand

    while (true) {

        /*
          Programa ir? gerar n?meros aleat?rios de acordo com uma l?gica. Esses valores
          dever?o estar dentro de um intervalo que come?a no somador e tem tamanho da
          diferen?a do divisor m?ximo com o divisor m?nimo. Por exemplo, se max = 30, min =
          20 e somador = 20, logo teremos um intervalo de 20 a 30 para o computador chutar
        */

/// só deveria gerar uma cadeia. se usa esse comando uma só vez no programa.
        srand(time(0)); //Gera uma nova cadeia de n?meros aleat?rios
/// se os valores de divisor_max e min forem 7 e 4, os valores possíveis para
///   o número do usuário são 5 ou 6. o cálculo abaixo será rand%3+4, que pode
///   dar 4, 5 ou 6.
        chute = rand() % (divisor_max - divisor_min)+ somador;

        /*
          Layout de entrada e sa?da. Computador da como sa?da o n?mero que chutou, enquanto o
          usu?ria indica se est? ou n?o certo.
        */

        printf("Numero chutado: %d", chute);
        printf("\n0 - Digite se acertou\n1 - Digite se chute e maior\n2 - Digite se chute e menor");
        scanf("%d", &acerto);
        contador += 1; // Contador de chances para acertar

        /*L?gica do programa: se chutou igual, cabe ao usu?rio indicar e o la?o acaba.
          Se o chute for maior, o divisor m?ximo passa a ser esse valor
          Se o chute for menor, o divisor m?nimo passa a ser esse valor e o somador tamb?m.
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

    printf("\nComputador acertou o numero %d com %d chutes.\n", numero, contador); //Sa?da do programa com o n?mero e as chances usadas

}
