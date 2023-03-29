#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int matricula;
    char *nome;
    float nota1;
    float nota2;
    float media;
} aluno_t;


char *lerStringEntreAspas(FILE *arq){
    char *str = (char *) malloc(31 * sizeof(char));
    int pos = 0;
    int c;

    // Encontra a primeira aspa
    while ((c = fgetc(arq)) != EOF && c != '\"') {}

    // Se n�o encontrou a primeira aspa, retorna NULL
    if (c != '\"') {
        free(str);
        return NULL;
    }

    bool encontrarAspaFinal = false;
    // L� os caracteres entre as aspas at� atingir o limite de 30 ou encontrar a segunda aspa
    while ((c = fgetc(arq)) != EOF) {
        if (c == '\"') {
            encontrarAspaFinal = true;
            break;
        }
        if (pos < 30) {
            str[pos++] = (char)c;
        }
    }

    // Se n�o encontrou a segunda aspa, retorna NULL
    if (!encontrarAspaFinal) {
        free(str);
        return NULL;
    }

    str[pos] = '\0';
    return str;
}

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

    /*
        Preciso mudar a l�gica da string, precisa estar entre "" no arquvio txt, logo,
        preciso criar uma fun��o especial para identificar a primeira aspa e a partir
        dela gravar os caracteres da string, ou seja, ela vai gravar at� achar a outra
        aspa, ou quando atingir o espa�o, 30.
    */

    for(int i = 0; i < num_alunos; i++){
        fscanf(file, "%d", &((*alunos)[i].matricula));

        (*alunos)[i].nome = lerStringEntreAspas(file);
        if (!(*alunos)[i].nome) {
            return -1;
        }

        fscanf(file, "%f %f", &((*alunos)[i].nota1), &((*alunos)[i].nota2));

        int c;
        while ((c = fgetc(file)) != '\n' && c != EOF) {}
    }

        /*
            Para evitar a leitura de uma terceira nota, fica-se fazendo
            a leitura at� o final da linha ou at� o final do arquivo (EOF).
            Assim, o loop vai lendo os dados, mas sem armazen�-los, acabando
            quando inicia-se uma nova linha, ou quando o arquivo acaba.
        */

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
    // N�o precisa passar &aluno pois n�o h� modifica��o do ponteiro
    grava_arq(n, alunos, nome_do_arquivo);

    // Aqui estou liberando a aloca��o de mem�ria dos nomes
    // e da struct.
    for (int i = 0; i < n; i++) {
        free(alunos[i].nome);
    }
    free(alunos);
    return 0;
}
