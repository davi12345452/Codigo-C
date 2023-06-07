#include <stdio.h>
#include "fila.h"

int main() {
    Fila* fila = criarFila();
    Pilha* pilha = criarPilha();
    int TP;

    // Leitura dos processos
    printf("Digite os processos (id, tempo de chegada, tempo de execucao, tipo):\n");
    char id[10], tipo[10];
    int chegada, execucao;
    do {
        scanf("%s %d %d %s", id, &chegada, &execucao, tipo);
        if (strcmp(id, "fim") == 0) {
            break;
        }
        Processo* processo = criarProcesso(id, chegada, execucao, tipo);
        enfileirar(fila, processo);
    } while (1);

    // Leitura do TP
    printf("Digite o tempo fixo que o processo pode ficar no processador: ");
    scanf("%d", &TP);

    printf("Procurando por processo de sistema:\n");

    while (!filaVazia(fila)) {
        Processo* processo = desenfileirar(fila);
        if (strcmp(processo->tipo, "sistema") == 0) {
            printf("Achou %s, que e processo de sistema. Executa %s (%d)\n", processo->id, processo->id, TP);
            free(processo);
            while (!pilhaVazia(pilha)) {
                Processo* processoAux = desempilhar(pilha);
                enfileirar(fila, processoAux);
                printf("Recoloca %s na fila\n", processoAux->id);
            }
        } else {
            printf("Conteudo da pilha: ");
            imprimirPilha(pilha);
            empilhar(pilha, processo);
        }
    }

    printf("Fila vazia. Processa os processos restantes na pilha:\n");
    while (!pilhaVazia(pilha)) {
        Processo* processo = desempilhar(pilha);
        printf("Processa %s (%d)\n", processo->id, TP);
        free(processo);
    }

    liberarPilha(pilha);
    liberarFila(fila);

    return 0;
}
