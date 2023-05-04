#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_STR 30

typedef struct {
    int matricula;
    char *nome;
    float nota1;
    float nota2;
    float media;
} aluno_t;

