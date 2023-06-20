#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha *criarPilha() {
  Pilha *pilha = malloc(sizeof(Pilha));
  if (!pilha) {
    fprintf(stderr, "Erro na alocação de memória!\n");
    exit(EXIT_FAILURE);
  }
  pilha->top = NULL;
  return pilha;
}

void empilhar(Pilha *pilha, Processo *processo) {
  PilhaNode *newNode = malloc(sizeof(PilhaNode));
  if (!newNode) {
    fprintf(stderr, "Erro na alocação de memória!\n");
    exit(EXIT_FAILURE);
  }
  newNode->processo = processo;
  newNode->next = pilha->top;
  pilha->top = newNode;
}

void destruirPilha(Pilha *pilha) {
  PilhaNode *temp = pilha->top;
  while (temp) {
    PilhaNode *next = temp->next;
    free(temp);
    temp = next;
  }
  free(pilha);
}

Processo *desempilhar(Pilha *pilha) {
  if (pilha->top == NULL)
    return NULL;

  PilhaNode *temp = pilha->top;
  Processo *processo = temp->processo;
  pilha->top = pilha->top->next;

  free(temp);
  return processo;
}

int pilhaVazia(Pilha *pilha) { return pilha->top == NULL; }

void printPilha(Pilha *pilha) {
  if (pilhaVazia(pilha)) {
    printf("Pilha esta vazia!\n");
  } else {
    PilhaNode *temp = pilha->top;
    while (temp != NULL) {
      printf("Processo ID: %s (Execução: %d)\n", temp->processo->id,
             temp->processo->tempoExecucao);
      temp = temp->next;
    }
  }
}



