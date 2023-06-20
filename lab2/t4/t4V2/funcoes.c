#include "funcoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Essa função será usada para imprimir na tela o que há na pilha e lista, durante a execução do programa
static void printFilaPilha(Fila* fila, Pilha* pilha){
    printf("Conteúdo da Fila: ");
    printFila(fila);
    printf("Conteúdo da Pilha: ");
    printPilha(pilha);
    printf("\n");
}

// Função que move processos da fila pra pilha
static void moverProcessosParaPilha(Fila* fila, Pilha* pilha){
    while(!filaVazia(fila)){
        Processo* proc = desenfileirar(fila);
        empilhar(pilha, proc);
    }
}

// Função que move processos da pilha pra fila
static void moverProcessosParaFila(Fila* fila, Pilha* pilha){
    while(!pilhaVazia(pilha)){
        Processo* proc = desempilhar(pilha);
        enfileirar(fila, proc);
    }
}

// Função booleana que identifica se há ou não processo de sistema na fila
static bool temProcessoDeSistema(Fila* fila) {
    FilaNode* temp = fila->front;
    while(temp) {
        if(temp->processo->tipo == SISTEMA)
            return true;
        temp = temp->next;
    }
    return false;
}

// Função que executa um processo, ou seja, o processo é retirado da fila e movido para
// uma fila dos executados, que será usado para exibir a sequência de processos. 
static Processo* executarProcesso(Processo* proc, int TP, Fila* execucao){
    Processo* proc_executado = criarProcesso(proc->id, proc->tipo, proc->tempoChegada, proc->tempoExecucao <= TP ? proc->tempoExecucao : TP);
    enfileirar(execucao, proc_executado);
    printf("\nExecutando processo %s(%d)\n", proc->id, proc_executado->tempoExecucao);
    if(proc->tempoExecucao > TP){
        proc->tempoExecucao -= TP;
        return proc;  
    } else {
        free(proc);
        return NULL;
    }
}

// Funções declaradas para main:

// Função que imprime a sequência de processos, através da fila de executados
void imprimirExecucao(Fila* execucao){
    printf("\nOrdem de execucao:\n");
    while(!filaVazia(execucao)){
        Processo* proc = desenfileirar(execucao);
        printf("%s(%d), ", proc->id, proc->tempoExecucao);
        free(proc);
    }
    printf("\n");
}

// Escalonador em si, função principal de todo programa
void executarProcessos(Fila* fila, Pilha* pilha, Fila* execucao, int TP) {
    printFilaPilha(fila, pilha);
    while (!filaVazia(fila) || !pilhaVazia(pilha)) {
        if (temProcessoDeSistema(fila)) {
            Processo* proc = desenfileirar(fila);
            while (proc != NULL && proc->tipo == USUARIO) {
                empilhar(pilha, proc);
                proc = desenfileirar(fila);
            }
            if (proc != NULL && proc->tipo == SISTEMA) {
                proc = executarProcesso(proc, TP, execucao);
                printFilaPilha(fila, pilha);  // imprime o estado das filas e pilhas após a execução
                if(proc != NULL)
                    enfileirar(fila, proc);
            }
        } else {
            moverProcessosParaFila(fila, pilha);
            printFilaPilha(fila, pilha);
            Processo* proc = desenfileirar(fila);
            while (proc != NULL) {
                proc = executarProcesso(proc, TP, execucao);
                printFilaPilha(fila, pilha);  // imprime o estado das filas e pilhas após a execução
                if(proc != NULL)
                    enfileirar(fila, proc);
                proc = desenfileirar(fila);
            }
        }
    }
}

// Função para entrada de dados pelo usuário
void cadastrarProcessos(Fila* fila) {
    int numProcessos;
    printf("Digite o número de processos a serem cadastrados: ");
    scanf("%d", &numProcessos);
    for (int i = 0; i < numProcessos; i++) {
        char id[10];
        int tipo;
        int tempoChegada;
        int tempoExec;
        printf("Digite o ID do processo %d: ", i+1);
        scanf("%s", id);
        printf("Digite o tipo do processo %d (1 para USUARIO, 2 para SISTEMA): ", i+1);
        scanf("%d", &tipo);
        printf("Digite o tempo de chegada do processo %d: ", i+1);
        scanf("%d", &tempoChegada);
        printf("Digite o tempo de execução do processo %d: ", i+1);
        scanf("%d", &tempoExec);

        Tipo procTipo;
        if (tipo == 1) {
            procTipo = USUARIO;
        } else if (tipo == 2) {
            procTipo = SISTEMA;
        } else {
            printf("Tipo de processo inválido.\n");
            continue;
        }
        printf("\n");
        enfileirar(fila, criarProcesso(id, procTipo, tempoChegada, tempoExec));
    }
}