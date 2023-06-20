#include <stdio.h>

#include "fila.h"
#include "pilha.h"
#include "processo.h"
#include "funcoes.h"


/*
    Aqui chama-se o programa, criando filas e pilhas, usando funções definidas
    nos outros arquivos. A lógica de execução do programa está em funcoes.c, porém
    há bastante utilização dos outros arquivos. O programa permite criar quantos
    processos quiser, devolvendo o que há na fila e pilha a cada execucao. No final,
    há a exibição da sequência de processos dessa maneira P2 (X)... 
*/

int main() {
    int TP = 20; // Pode alterar o TP conforme o desejo. 
    Fila* fila = criarFila();
    Pilha* pilha = criarPilha();
    Fila* execucao = criarFila();

    cadastrarProcessos(fila);
    executarProcessos(fila, pilha, execucao, TP);
    imprimirExecucao(execucao);

    destruirFila(fila);
    destruirPilha(pilha);
    destruirFila(execucao);

    return 0;
}
