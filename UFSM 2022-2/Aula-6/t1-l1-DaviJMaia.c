/*
Trabalho 1
Davi Jansich Maia
SI 1 2022/2
*/

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

/* Neste program, o usuario escolhe um numero e o computador tenta adivinhar
   usando a funcao rand(), a cada tentativa ele devolve o numero ao usuario,
   que deve dizer se acertou, ou se o numero e maior ou menor. No fim, o pro-
   grama devolve quantas tentativas foram necessarias ate acertar o numero. */


int randEntre(max, min){

    /*
        Essa funcao recebe duas variaveis, um valor maximo e um valor minimo,
        devolvendo um numero dentro do intervalo entre os dois, sem contar pa-
        os dois mesmos. Devolve
    */

    int valor;
    valor = rand() % (max - min) + min;
    return valor;

}


int main(){

    int acerto; // Declara??o Vari?veis de entrada
    int chute, divisor_max, divisor_min = 0; // Declaracao Variaveis Intermediarias
    int contador; // Declaracao Variavel de saida

    divisor_max = 100; //Atribui 100 ao divisor maximo do rand, logo os valores serao de 0 a 99
    contador = 0; //Contador de chances que o computador demora para acertar

    printf("Pense em um numero, o computador ira tentar adivinhar...");

    srand(time(0)); //Gera uma nova cadeia de numeros aleatoios

    while (true) {

        chute = randEntre(divisor_max, divisor_min);

        /*
          Layout de entrada e saida. Computador da como saida o numero que chutou, enquanto o
          usuarioindica se esta ou nao certo.
        */

        printf("\nNumero chutado: %d", chute);
        printf("\n0 - Digite se acertou\n1 - Digite se chute e maior\n2 - Digite se chute e menor");
        scanf("%d", &acerto);
        contador += 1; // Contador de chances para acertar

        /*Logica do programa: se chutou igual, cabe ao usuario indicar e o laco acaba.
          Se o chute for maior, o divisor maximo passa a ser esse valor
          Se o chute for menor, o divisor manimo passa a ser esse valor e o somador tambem.
        */

        if(acerto == 0){
            break;
        }else if(acerto == 1){
            divisor_max = chute - 1;
        }else{
            divisor_min = chute + 1;
        }
    }

    printf("\nComputador acertou o numero com %d chutes.\n", contador); //Saida do programa com o numero e as chances usadas

}
