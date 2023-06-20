#ifndef FILA_H
#define FILA_H

typedef struct {
    int id;
    int tempoChegada;
    int tempoExecucao;
    char *tipo;
} Processo;

typedef struct node {
    Processo* processo;
    struct node* prox;
} Node;

typedef struct {
    Node* frente;
    Node* tras;
} Fila;

Fila* criarFila();
void enfileirar(Fila* fila, Processo* processo);
Processo* desenfileirar(Fila* fila);
int filaVazia(Fila* fila);
void imprimirFila(Fila* fila);
void destruirFila(Fila* fila);

#endif