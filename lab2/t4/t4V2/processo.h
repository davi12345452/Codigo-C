#ifndef PROCESSO_H
#define PROCESSO_H

// Aqui está definido o que é um processo, sendo usado em filas e pilhas
// pelo programa

typedef enum { USUARIO, SISTEMA } Tipo;

typedef struct {
  char id[10];
  int tempoChegada;
  int tempoExecucao;
  Tipo tipo;
} Processo;

// Funções básicas, uma de criar uma variável do tipo Processo e uma para destruir
Processo *criarProcesso(char *id, Tipo tipo, int tempoChegada, int tempoExec);
void destruirProcesso(Processo *processo);

#endif