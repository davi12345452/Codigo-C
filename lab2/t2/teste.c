#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct para os municípios
struct municipio
{
    char* nome;
    int populacao;
    int** dados; //matriz de dados
};
typedef struct municipio Municipio;

// Função para criar um novo município
Municipio* criarMunicipio(char* nome, int populacao, int linhas) {
    Municipio* municipio = (Municipio*) malloc(sizeof(Municipio));
    municipio->nome = (char*) malloc(strlen(nome)+1);
    strcpy(municipio->nome, nome);
    municipio->populacao = populacao;
    municipio->dados = (int**) malloc(linhas*sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        municipio->dados[i] = (int*) malloc(3*sizeof(int));
    }
    return municipio;
}

// Função para destruir um município
void destruirMunicipio(Municipio* municipio, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(municipio->dados[i]);
    }
    free(municipio->dados);
    free(municipio->nome);
    free(municipio);
}

// Função para buscar um município no vetor de municípios
Municipio* buscarMunicipio(Municipio** municipios, int tamanho, char* nome) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(municipios[i]->nome, nome) == 0) {
            return municipios[i];
        }
    }
    return NULL;
}

// Função para inserir um novo município no vetor de municípios
void inserirMunicipio(Municipio** municipios, int* tamanho, int linhas) {
    char nome[100];
    int populacao;
    printf("Digite o nome do municipio: ");
    scanf("%s", nome);
    printf("Digite a populacao do municipio: ");
    scanf("%d", &populacao);
    Municipio* municipio = criarMunicipio(nome, populacao, linhas);
    municipios[*tamanho] = municipio;
    (*tamanho)++;
}

// Função para preencher a matriz de dados de um município
void preencherDados(Municipio* municipio, int linhas) {
    printf("Digite os dados para cada dia:\n");
    for (int i = 0; i < linhas; i++) {
        int dia, casos, obitos;
        printf("Dia %d:\n", i+1);
        printf("  Casos confirmados: ");
        scanf("%d", &casos);
        printf("  Obitos: ");
        scanf("%d", &obitos);
        municipio->dados[i][0] = i+1;
        municipio->dados[i][1] = casos;
        municipio->dados[i][2] = obitos;
    }
}

// Função para gerar os dados epidemiológicos gerais de um município
void gerarDadosGerais(Municipio* municipio, int linhas) {
    int totalConfirmados = 0;
    int novosConfirmados = municipio->dados[linhas-1][1] - municipio->dados[linhas-2][1];
    float incidencia = (float) municipio->dados[linhas-1][1] / municipio->populacao * 100000;
    int totalObitos = 0;
    int novosObitos = municipio->dados[linhas-1][2] - municipio->dados[linhas-2][2];
    float mortalidade = (float) municipio->dados[linhas-1][2] / municipio->populacao * 100000;

    for (int i = 0; i < linhas; i++) {
        totalConfirmados += municipio->dados[i][1];
        totalObitos += municipio->dados[i][2];
    }

    printf("Dados epidemiologicos gerais para o municipio de %s:\n", municipio->nome);
    printf("  Total de casos confirmados: %d\n", totalConfirmados);
    printf("  Novos casos confirmados (ultimo dia): %d\n", novosConfirmados);
    printf("  Incidencia por 100 mil habitantes: %.2f\n", incidencia);
    printf("  Total de obitos: %d\n", totalObitos);
    printf("  Novos obitos (ultimo dia): %d\n", novosObitos);
    printf("  Mortalidade por 100 mil habitantes: %.2f\n", mortalidade);    

}

// Função principal
int main() {
    int tamanho = 0;
    int linhas = 0;
    printf("Digite o numero de municipios: ");
    scanf("%d", &tamanho);
    printf("Digite o numero de dias: ");
    scanf("%d", &linhas);

    Municipio** municipios = (Municipio**) malloc(tamanho*sizeof(Municipio*));

    for (int i = 0; i < tamanho; i++) {
        inserirMunicipio(municipios, &tamanho, linhas);
        preencherDados(municipios[i], linhas);
    }

    for (int i = 0; i < tamanho; i++) {
        gerarDadosGerais(municipios[i], linhas);
    }

    for (int i = 0; i < tamanho; i++) {
        destruirMunicipio(municipios[i], linhas);
    }
    free(municipios);

    return 0;
}