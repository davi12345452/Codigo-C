#ifndef FUNCOES_H
#define FUNCOES_H

#include "fila.h"
#include "pilha.h"

/*
    Nos arquivos funcoes, julguei a melhor opcao para organizar o código.
    Aqui há o funcionamento do escalonador. 
*/
// Essa função imprime a sequencia final de processos realizados
void imprimirExecucao(Fila* execucao);
// Essa funçao é o escalonador em si
void executarProcessos(Fila* fila, Pilha* pilha, Fila* execucao, int TP);
// Essa função é a de entrada de dados
void cadastrarProcessos(Fila* fila);

#endif