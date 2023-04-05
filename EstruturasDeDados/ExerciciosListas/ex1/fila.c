// fila.c
#include "fila.h"
#include <assert.h>

typedef struct _fila {
  int cap;
  int num;
  dado_t *vet;
} fila;

Fila fila_cria(int cap)
{
  // aloca memória para o descritor
  Fila f = malloc(sizeof(fila));
  if (f == NULL) return NULL;
  // aloca memória para os dados
  f->vet = malloc(cap * sizeof(dado_t));
  if (f->vet == NULL) {
    free(f);
    return NULL;
  }
  f->cap = cap;
  f->num = 0;
  return f;
}

void fila_destroi(Fila f)
{
  // libera a memória dos dados e do descritor
  free(f->vet);
  free(f);
}

// Retorna se está ou não vazia
bool fila_vazia(Fila f)
{
  return f->num == 0;
}

// Retorna se está ou não cheia
bool fila_cheia(Fila f)
{
  return f->num == f->cap;
}

// Lista inicia no 0
dado_t fila_inicio(Fila f)
{
    // Assert funciona mais ou menos como o require, porém sem retornar mensagem
    // indicando o erro. 
  assert(!fila_vazia(f)); // Verifica se está ou não vazia para seguir o código
  return f->vet[0];
}

// Aqui estamos removendo o primeiro elemento e deslocando a lista para a esquerda
dado_t fila_remove(Fila f)
{
  assert(!fila_vazia(f));
  dado_t valor = f->vet[0];
  for (int i = 0; i < f->num - 1; i++) {
    f->vet[i] = f->vet[i+1];
  }
  f->num--;
  return valor;
}

// Aqui estamos adicionando f ao final da lista
void fila_insere(Fila f, dado_t d)
{
  assert(!fila_cheia(f));
  f->vet[f->num++] = d;
}
