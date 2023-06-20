#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

// Função para criar um novo processo
Processo* criarProcesso(int id, int tempoChegada, int tempoExecucao, char* tipo) {
    Processo* processo = (Processo*)malloc(sizeof(Processo));
    processo->id = id;
    processo->tempoChegada = tempoChegada;
    processo->tempoExecucao = tempoExecucao;
    processo->tipo = (char*)malloc((strlen(tipo) + 1) * sizeof(char));
    strcpy(processo->tipo, tipo);
    return processo;
}

// Função para escalonar os processos
void escalonarProcessos(Fila* fila, Pilha* pilha, int TP) {
    Fila* sequenciaExecucao = criarFila();

    while (!filaVazia(fila)) {
        // Executar processos de sistema
        while (!filaVazia(fila) && strcmp(fila->frente->processo->tipo, "sistema") == 0) {
            Processo* processo = desenfileirar(fila);
            printf("Executando processo de sistema: P%d (%d)\n", processo->id, TP);
            processo->tempoExecucao -= TP;
            if (processo->tempoExecucao > 0) {
                printf("Processo P%d continua em execução, volta para o final da fila\n", processo->id);
                enfileirar(fila, processo);
            } else {
                printf("Processo P%d finalizado\n", processo->id);
                free(processo->tipo);
                free(processo);
            }
        }

        if (filaVazia(fila)) {
            printf("\nTodos os processos foram executados.\n");
            break;
        }

        // Executar processos de usuário
        Processo* processo = desenfileirar(fila);
        printf("Empilhando processo de usuário: P%d\n", processo->id);

        if (strcmp(processo->tipo, "usuario") == 0) {
            if (pilhaVazia(pilha)) {
                empilhar(pilha, processo);
                processo = NULL;
            } else {
                printf("Processo P%d continua em execução, volta para o final da fila\n", processo->id);
                enfileirar(fila, processo);
                processo = NULL;
            }
        }

        if (processo != NULL) {
            processo->tempoExecucao -= TP;
            if (processo->tempoExecucao > 0) {
                printf("Processo P%d continua em execução, volta para o final da fila\n", processo->id);
                enfileirar(fila, processo);
            } else {
                printf("Processo P%d finalizado\n", processo->id);
                free(processo->tipo);
                free(processo);
            }
        }

        printf("Conteúdo da fila: ");
        imprimirFila(fila);
        printf("Conteúdo da pilha: ");
        imprimirPilha(pilha);
        printf("\n");

        if (processo != NULL) {
            enfileirar(sequenciaExecucao, processo);
        }
    }

    printf("\nOrdem de execução dos processos:\n");
    while (!filaVazia(sequenciaExecucao)) {
        Processo* processo = desenfileirar(sequenciaExecucao);
        printf("P%d (%d)\n", processo->id, TP);
        free(processo);
    }

    destruirFila(sequenciaExecucao);
}

int main() {
    Fila* fila = criarFila();
    Pilha* pilha = criarPilha();
    int TP;

    char id[10], tipo[10];
    int tempoChegada, tempoExecucao;
    // Obter informações dos processos
    while (1) {
        printf("Informe o id do processo ('sair' para encerrar): ");
        scanf("%s", id);
        if (strcmp(id, "sair") == 0)
            break;
        
        printf("Informe o tempo de chegada do processo: ");
        scanf("%d", &tempoChegada);
        
        printf("Informe o tempo de execucao do processo: ");
        scanf("%d", &tempoExecucao);
        
        printf("Informe o tipo do processo (usuario ou sistema): ");
        scanf("%s", tipo);
        
        Processo* processo = criarProcesso(atoi(id), tempoChegada, tempoExecucao, tipo);
        enfileirar(fila, processo);
    }
    
    printf("Informe o tempo fixo do processador (TP): ");
    scanf("%d", &TP);
    
    printf("\nIniciando escalonamento...\n\n");
    
    escalonarProcessos(fila, pilha, TP);
    
    destruirFila(fila);
    destruirPilha(pilha);
    
    return 0;
}