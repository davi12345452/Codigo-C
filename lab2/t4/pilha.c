#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha* pilha, Processo* processo) {
    PilhaNode* novoNode = (PilhaNode*)malloc(sizeof(PilhaNode));
    novoNode->processo = processo;
    novoNode->prox = pilha->topo;
    pilha->topo = novoNode;
}

Processo* desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha))
        return NULL;
    
    PilhaNode* nodeRemovido = pilha->topo;
    Processo* processo = nodeRemovido->processo;
    
    pilha->topo = pilha->topo->prox;
    free(nodeRemovido);
    
    return processo;
}

int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void imprimirPilha(Pilha* pilha) {
    PilhaNode* atual = pilha->topo;
    while (atual != NULL) {
        printf("P%d ", atual->processo->id);
        atual = atual->prox;
    }
    printf("\n");
}

void destruirPilha(Pilha* pilha) {
    PilhaNode* atual = pilha->topo;
    while (atual != NULL) {
        PilhaNode* prox = atual->prox;
        free(atual->processo);
        free(atual);
        atual = prox;
    }
    free(pilha);
}