#include <stdio.h>

typedef struct {
    int matricula;
    float nota1;
    float nota2;
    float media;
} aluno_t;

int le_arq(aluno_t **alunos, char *nome_do_arquivo) {
    FILE *file = fopen(nome_do_arquivo, "r");
    if (!file) {
        return -1;
    }

    int num_alunos;
    fscanf(file, "%d", &num_alunos);

    *alunos = (aluno_t *)malloc(num_alunos * sizeof(aluno_t));
    if (!*alunos) {
        fclose(file);
        return -1;
    }

    for (int i = 0; i < num_alunos; i++) {
        fscanf(file, "%d %f %f", &(*alunos)[i].matricula, &(*alunos)[i].nota1, &(*alunos)[i].nota2);
        (*alunos)[i].media = ((*alunos)[i].nota1 + (*alunos)[i].nota2) / 2;
    }

    fclose(file);
    return num_alunos;
}

void grava_arq(int n, aluno_t alunos[n], char *nome_do_arquivo) {
    FILE *file = fopen(nome_do_arquivo, "w");
    if (!file) {
        return;
    }

    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %.1f %.1f %.1f\n", alunos[i].matricula, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
    }

    fclose(file);
}

int main() {
    char *nome_do_arquivo = "notas.txt";
    aluno_t *alunos;

    int num_alunos = le_arq(&alunos, nome_do_arquivo);
    if (num_alunos == -1) {
        printf("Erro ao ler o arquivo.\n");
        return 1;
    }

    grava_arq(num_alunos, alunos, nome_do_arquivo);

    free(alunos);
    return 0;
}

