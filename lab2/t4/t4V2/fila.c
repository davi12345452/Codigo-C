#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila *criarFila() {
  Fila *fila = malloc(sizeof(Fila));
  if (!fila) {
    fprintf(stderr, "Erro na alocação de memória!\n");
    exit(EXIT_FAILURE);
  }
  fila->front = fila->rear = NULL;
  return fila;
}

void enfileirar(Fila *fila, Processo *processo) {
  FilaNode *newNode = malloc(sizeof(FilaNode));
  if (!newNode) {
    fprintf(stderr, "Erro na alocação de memória!\n");
    exit(EXIT_FAILURE);
  }
  newNode->processo = processo;
  newNode->next = NULL;
  if (fila->rear == NULL) {
    fila->front = fila->rear = newNode;
    return;
  }
  fila->rear->next = newNode;
  fila->rear = newNode;
}

void destruirFila(Fila *fila) {
  FilaNode *temp = fila->front;
  while (temp) {
    FilaNode *next = temp->next;
    free(temp);
    temp = next;
  }
  free(fila);
}

Processo *desenfileirar(Fila *fila) {
  if (fila->front == NULL)
    return NULL;

  FilaNode *temp = fila->front;
  Processo *processo = temp->processo;
  fila->front = fila->front->next;

  if (fila->front == NULL)
    fila->rear = NULL;

  free(temp);
  return processo;
}

int filaVazia(Fila *fila) { return fila->front == NULL; }

void printFila(Fila *fila) {
  if (filaVazia(fila)) {
    printf("Fila esta vazia!\n");
  } else {
    FilaNode *temp = fila->front;
    while (temp != NULL) {
      printf("Processo ID: %s (Execução: %d)\n", temp->processo->id,
             temp->processo->tempoExecucao);
      temp = temp->next;
    }
  }
}




