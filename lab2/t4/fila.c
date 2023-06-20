#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

void enfileirar(Fila* fila, Processo* processo) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->processo = processo;
    novoNode->prox = NULL;
    
    if (filaVazia(fila)) {
        fila->frente = novoNode;
        fila->tras = novoNode;
    } else {
        fila->tras->prox = novoNode;
        fila->tras = novoNode;
    }
}

Processo* desenfileirar(Fila* fila) {
    if (filaVazia(fila))
        return NULL;
    
    Node* nodeRemovido = fila->frente;
    Processo* processo = nodeRemovido->processo;
    
    fila->frente = fila->frente->prox;
    if (fila->frente == NULL)
        fila->tras = NULL;
    
    free(nodeRemovido);
    return processo;
}

int filaVazia(Fila* fila) {
    return (fila->frente == NULL);
}

void imprimirFila(Fila* fila) {
    Node* atual = fila->frente;
    while (atual != NULL) {
        printf("P%d ", atual->processo->id);
        atual = atual->prox;
    }
    printf("\n");
}

void destruirFila(Fila* fila) {
    Node* atual = fila->frente;
    while (atual != NULL) {
        Node* prox = atual->prox;
        free(atual->processo);
        free(atual);
        atual = prox;
    }
    free(fila);
}

