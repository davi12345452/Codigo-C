/*
Trabalho 2
Davi Jansich Maia
SI 1 2022/2
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


/*
    Fun??o retirada da aula, devolve true quando ? primo e false quando n?o ?.
*/
bool primo(int x)
{
  if (x < 2) return false;
  for (int n = 2; n < x; n++) {
    if (x%n == 0) return false;
  }
  return true;
}

/*
    Fun??o que recebe um valor inicial e um final de um intervalo,
    devolvendo o numero de n?meros primos dentro deste. Fa?o uso da
    fun??o antes declarada para identificar um n?mero primo.
*/

int primoPorIntervalo(int intervalo_i, int intervalo_f){
    int i, numPrimos = 0;
    for(i = intervalo_i; i <= intervalo_f; i++){
        if(primo(i)){
            numPrimos += 1;
        }
    }
    return numPrimos;
}

/// não implementou as funções pedidas
int main(){
    //Idioma portugu?s, entende os acentos e caracteres especiais
    setlocale(LC_ALL, "Portuguese");

    //Declara??o das vari?veis
    int intervalos, tamanho, i;
    int intervalo_i, intervalo_f;
    int saidaIntervInicial, saidaIntervFinal, saidaPrimos;

    //Interface explicativa do programa
    printf("\t\tBem vindos ao programa\n");
    printf("Este programa recebe de entrada uma quantidade de intervalos\n");
    printf("e um tamannho, devolvendo o intervalo que possui menos n?meros primos\n");

    //Interface com comandos de entrada
    printf("\nDigite a quantidade de intervalos: ");
    scanf("%d", &intervalos);
    printf("Digite o tamanho dos intervalos: ");
    scanf("%d", &tamanho);

    //Atribui??es de valores
    intervalo_i = 1;
    intervalo_f = tamanho;
    saidaPrimos = tamanho + 1; //Valor grande para que o programa n?o d? bug.


    /*
        Principal: dentro deste loop for, passamos por cada intervalo que
        o usu?rio digitou. A quantidade de repeti??es ? a mesma que a quan-
        tidade de intervalos. Caso dentro de um intervalo exista menos pri-
        mos que no intervalo que at? o momento era o que tinha menos, o
        programa atribui a este novo intervalo o n?mero de primo dele e,
        o seu in?cio e fim do intervalo ?s vari?veis de sa?da. A cada loop
        os intervalos recebem o valor tamanho para verificarem um novo
        intervalo.
    */
    for(i = 1; i <= intervalos; i++){
        if(primoPorIntervalo(intervalo_i, intervalo_f) < saidaPrimos){
            saidaPrimos = primoPorIntervalo(intervalo_i, intervalo_f);
            saidaIntervInicial = intervalo_i;
            saidaIntervFinal = intervalo_f;
        }
        intervalo_i += tamanho;
        intervalo_f += tamanho;
    }

    //Imprime as sa?da do programa.
    printf("\nIntervalo: %d ao %d\nN?mero de primos: %d\n", saidaIntervInicial, saidaIntervFinal, saidaPrimos);

    return 0;
}
