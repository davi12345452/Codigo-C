#include <stdio.h>

typedef struct {
    int matricula;
    char nome[30];
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

    printf("%d", num_alunos);

    if(n < num_alunos) return -1;

    for(int i = 0; i < num_alunos; i++){
        fscanf(file, "%d %s %f %f", &alunos[i].matricula, &alunos[i].nome,
                                     &alunos[i].nota1, &alunos[i].nota2);
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
        fprintf(file, "%d %s %.1f %.1f %.1f\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
    }

    fclose(file);
}

void calcula_medias(int n, aluno_t alunos[n]){
    for(int i = 0; i < n; i++){
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2;
    }
}

int main() {
    char *nome_do_arquivo1 = "notas.txt";
    char *nome_do_arquivo2 = "notasFinal.txt";
    aluno_t alunos[30];

    int n = le_arq(30, alunos, nome_do_arquivo1);
    if(n < 0){
        printf("ERRO NA LEITURA DO ARQUIVO");
        return 0;
    }

    calcula_medias(n, alunos);
    grava_arq(n, alunos, nome_do_arquivo2);

    free(alunos);
    return 0;
}
