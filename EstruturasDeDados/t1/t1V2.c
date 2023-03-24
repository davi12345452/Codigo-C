#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char *nome;
    float nota1;
    float nota2;
    float media;
} aluno_t;

int le_arq(aluno_t **alunos, char *nome_do_arquivo) {
    int num_alunos;
    FILE *file = fopen(nome_do_arquivo, "r");

    if (!file) {
        return -1;
    }
    if(fscanf(file, "%d", &num_alunos) != 1){
        return -1;
    }

    *alunos = (aluno_t *) malloc(num_alunos * sizeof(aluno_t));

    for(int i = 0; i < num_alunos; i++){
        char temp_nome[30];
        fscanf(file, "%d %s %f %f", &((*alunos)[i].matricula), temp_nome,
                                     &((*alunos)[i].nota1), &((*alunos)[i].nota2));

        (*alunos)[i].nome = (char *) malloc((strlen(temp_nome) + 1) * sizeof(char));
        strcpy((*alunos)[i].nome, temp_nome);

        /*
            Para evitar a leitura de uma terceira nota, fica-se fazendo
            a leitura até o final da linha ou até o final do arquivo (EOF).
            Assim, o loop vai lendo os dados, mas sem armazená-los, acabando
            quando inicia-se uma nova linha, ou quando o arquivo acaba.
        */
        int c;
        while ((c = fgetc(file)) != '\n' && c != EOF) {}
    }
    fclose(file);

    return num_alunos;
}

void grava_arq(int n, aluno_t *alunos, char *nome_do_arquivo) {
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
    char *nome_do_arquivo = "notasFinal.txt";

    aluno_t *alunos;

    int n = le_arq(&alunos, nome_do_arquivo);
    if(n < 0){
        printf("ERRO NA LEITURA DO ARQUIVO");
        return 0;
    }

    calcula_medias(n, alunos);
    grava_arq(n, alunos, nome_do_arquivo);

    // Aqui estou liberando a alocação de memória dos nomes
    // e da struct.
    for (int i = 0; i < n; i++) {
        free(alunos[i].nome);
    }
    free(alunos);
    return 0;
}
