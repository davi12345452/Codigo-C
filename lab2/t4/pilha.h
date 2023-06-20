#ifndef PILHA_H
#define PILHA_H

#include "fila.h"

typedef struct {
    Processo* processo;
    struct pilhaNode* prox;
} PilhaNode;

typedef struct {
    PilhaNode* topo;
} Pilha;

Pilha* criarPilha();
void empilhar(Pilha* pilha, Processo* processo);
Processo* desempilhar(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void imprimirPilha(Pilha* pilha);
void destruirPilha(Pilha* pilha);

#endif