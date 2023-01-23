/*
Trabalho 2
Davi Jansich Maia
SI 1 2022/2
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


void apresentacao(){
    //Interface explicativa do programa
    printf("\t\tBem vindos ao programa\n");
    printf("Este programa recebe de entrada uma quantidade de intervalos\n");
    printf("e um tamannho, devolvendo o intervalo que possui menos n?meros primos\n");
}

/*
    Função retirada da aula, devolve true quando é primo e false quando não é.
*/
bool primo(int x)
{
  if (x < 2) return false;
  for (int n = 2; n < x; n++) {
    if (x%n == 0) return false;
  }
  return true;
}

// Função que conta o número de primos dado um inicio e fim de intervalo
int conta_primos(int inicio, int fim){
    int contador = 0;
    for(int i = inicio; i <= fim; i++){
        if(primo(i)) contador++;
    }
    return contador;
}

// Função que conta o número de primos por um intervalo
int conta_primos_por_intervalo(int tamanho, int ordem){
    int inicio = (ordem - 1) * tamanho + 1;
    int fim = ordem * tamanho;
    return conta_primos(inicio, fim);
}

// Função que imprime o número de primos por um dado intervalo
void imprime_primos_intervalos(int tamanho, int num_intervalos) {
    int qtd_primos = conta_primos_por_intervalo(tamanho, num_intervalos);
    printf("Intervalo %d-%d: %d primos\n", (num_intervalos - 1) * tamanho + 1, num_intervalos * tamanho, qtd_primos);
}

// Função que devolve o intevalo com menor número de primos
int intervalo_menor_numero_primos(int tamanho, int num_intervalos) {
    int menor_num_primos = INT_MAX;
    int intervalo_menor_num_primos = -1;
    for (int i = 1; i <= num_intervalos; i++) {
        int qtd_primos = conta_primos_por_intervalo(tamanho, i);
        if (qtd_primos < menor_num_primos) {
            menor_num_primos = qtd_primos;
            intervalo_menor_num_primos = i - 1;
        }
    }
    return intervalo_menor_num_primos;
}

int main(){
    //Idioma português, entende os acentos e caracteres especiais
    setlocale(LC_ALL, "Portuguese");

    //Declaração das variáveis
    int intervalos, tamanho;

    apresentacao();

    //Interface com comandos de entrada
    printf("\nDigite a quantidade de intervalos: ");
    scanf("%d", &intervalos);
    printf("Digite o tamanho dos intervalos: ");
    scanf("%d", &tamanho);

    int intarvalorComMenosPrimos = intervalo_menor_numero_primos(tamanho, intervalos);
    imprime_primos_intervalos(tamanho, intarvalorComMenosPrimos + 1);

    return 0;
}
