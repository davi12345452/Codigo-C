#ifndef PILHA_H
#define PILHA_H

#include "processo.h"

// Estruturas para criar uma pilha 

typedef struct pilhaNode {
  Processo *processo;
  struct PilhaNode *next;
} PilhaNode;

typedef struct pilha {
  PilhaNode *top;
} Pilha;


// Aqui abaixo estão as funções principais de manipulação de pilha
Pilha *criarPilha();
void destruirPilha(Pilha *pilha);
void empilhar(Pilha *pilha, Processo *processo);
Processo *desempilhar(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
void printPilha(Pilha *pilha);

#endif