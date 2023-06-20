#ifndef FILA_H
#define FILA_H

#include "processo.h"


// Estruturas para criar uma fila 

typedef struct filanode {
  Processo *processo;
  struct FilaNode *next;
} FilaNode;

typedef struct fila {
  FilaNode *front;
  FilaNode *rear;
} Fila;


// Funções para manipular as filas: criar, destruir...

Fila *criarFila();
void destruirFila(Fila *fila);
void enfileirar(Fila *fila, Processo *processo);
Processo *desenfileirar(Fila *fila);
int filaVazia(Fila *fila);
void printFila(Fila *fila);

#endif