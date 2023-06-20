#include "processo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Processo *criarProcesso(char *id, Tipo tipo, int tempoChegada, int tempoExec) {
  Processo *processo = malloc(sizeof(Processo));
  if (!processo) {
    fprintf(stderr, "Erro na alocação de memória!\n");
    exit(EXIT_FAILURE);
  }
  strcpy(processo->id, id);
  processo->tipo = tipo;
  processo->tempoChegada = tempoChegada;
  processo->tempoExecucao = tempoExec;
  return processo;
}

void destruirProcesso(Processo *processo) { free(processo); }