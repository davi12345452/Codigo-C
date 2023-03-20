#include <stdio.h>

typedef struct {
    int matricula;
    float nota1;
    float nota2;
    float media;
} aluno_t;

int le_arq(int n, aluno_t alunos[n], char *nome_do_arquivo) {
    FILE *file = fopen(nome_do_arquivo, "r");
    if (!file) {
        return -1;
    }

    int num_alunos;
    fscanf(file, "%d", &num_alunos);

    if (num_alunos != n) {
        fclose(file);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %f %f", &alunos[i].matricula, &alunos[i].nota1, &alunos[i].nota2);
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

void calcula_medias(int n, aluno_t alunos[n]) {
    for (int i = 0; i < n; i++) {
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2;
    }
}

int main() {
    char *nome_do_arquivo = "notas.txt";
    int n = 15;
    aluno_t alunos[n];

    int num_alunos = le_arq(n, alunos, nome_do_arquivo);
    if (num_alunos == -1) {
        printf("Erro ao ler o arquivo.\n");
        return 1;
    }

    calcula_medias(n, alunos);
    grava_arq(n, alunos, nome_do_arquivo);

    return 0;
}
