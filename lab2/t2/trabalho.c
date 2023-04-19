/*
    Laboratório de Programação 2
    Trabalho 2 -> Alocação Dinâmica de Vetores e Matrizes
    Aluno -> Davi Janisch Maia
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>


#define T_STR_CIDADES 20 //Tamanho da string para cidades

struct municipio
{
    char* nome;
    int populacao;
    int** dados; //matriz de dados -> dia / novos_caso / óbitos
};
typedef struct municipio Municipio;

// Função auxiliar de impressão de linha
void linha(char caract, int i){
    for(i; i>0; i--){
        printf("%c", caract);
    }
    printf("\n");
}

//Função de boas vindas do programa
void apresentacao(){
    linha('-', 30);
    printf("Seja bem vindo(a) ao programa!\n");
    linha('-', 30);
}

/*
    Essa função permite usar uma mensagem
    para solicitar a entrada de ponteiro
    de inteiro
*/
void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);

}

void ler_string(char *mensagem, char **str) {
    printf("%s", mensagem);
    getchar();

    char buffer[T_STR_CIDADES];
    fgets(buffer, T_STR_CIDADES, stdin);
    // Remover o caractere de nova linha no final da string
    buffer[strcspn(buffer, "\n")] = '\0';

    // Alocar memória suficiente para armazenar a string
    *str = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(*str, buffer);
}

/*
    As duas proximas funções são usadas para armazenar de forma dinâmica
    os argumentos da estrutura Municipio, anteriormente definida dinami-
    camente. Uso malloc para nome (dentro de ler_string) e o array dados. 
*/
void cadastroMunicipio(Municipio *_municipio, int y){
    linha('-', 30);
    ler_string("Digite o nome da cidade: ", &_municipio->nome);
    ler_int("Digite a populacao da cidade:", &_municipio->populacao);  
    _municipio->dados = (int**) malloc(y * sizeof(int*));
    for(int j = 0; j < y; j++){
        _municipio->dados[j] = (int*) malloc(3 * sizeof(int));
        linha('-', 30);
        printf("Cadastro do dia %d:\n", j+1);
        _municipio->dados[j][0] = j;
        ler_int("Numero de novos casos: ", &_municipio->dados[j][1]);
        ler_int("Numero de novos obitos: ", &_municipio->dados[j][2]);
    }
    linha('-', 30);

}

void cadastroMunicipios(Municipio *_municipios, int n, int y){
    for(int i = 0; i < n; i++){
        printf("\nCadastro do municipio de numero %d: \n", i+1);
        cadastroMunicipio(&_municipios[i], y);
    }
}

/*
    Função auxiliar para gerar um valor sobre 100k.
    Usa-se a população total e o número de óbitos
    ou confirmados como argumentos.
*/
float calculoCemMil(int populacao, int casoOuObito){
    float pop, cOo;
    pop = (float) populacao;
    cOo = (float) casoOuObito;
    return (cOo * 100000)/ pop;
}

/*
    Nesta função há a impressão dos dados gerados dentro da função mesmo,
    sem o seu armazenamento em memória ou vetores externos. Usa-se dados
    previamente salvos para gerar esses que serão os outputs.
*/
void imprimirLinhaCidade(Municipio _municipio, int y, int n){
    int totalCasos = 0, totalObitos = 0;
    int novosCasos =  _municipio.dados[y-1][1];
    int novosObitos = _municipio.dados[y-1][2];
    for(int i = 0; i < y; i++){
        totalCasos +=  _municipio.dados[i][1];
        totalObitos +=  _municipio.dados[i][2];
    }
    float incidencia = calculoCemMil(_municipio.populacao, totalCasos);
    float mortalidade = calculoCemMil(_municipio.populacao, totalObitos);
    printf("| %2d | %-20s | %-12d | %-18d | %-24.2f | %-6d | %-13d | %-24.2f |\n", n, _municipio.nome,  totalCasos, novosCasos,
    incidencia, totalObitos, novosObitos, mortalidade);
}

// Essa função imprime cidade por cidade usando a função anterior
void imprimirLinhasCidade(Municipio *_municipios, int n, int y){
    linha('-', 144);
    printf("|    | %-20s | %-12s | %-18s | %-24s | %-6s | %-13s | %-24s |\n", 
    "Muncipio", "Confirmados", "Novos Confirmados", "Incidencia /100 mil hab",
    "Obitos", "Novos Obitos", "Mortalidade /100 mil hab");
    linha('-', 144);
    for(int j = 0; j < n; j++){
        imprimirLinhaCidade(_municipios[j], y, j+1);
    }
    linha('-', 144);
}

/*
    Esse função segue a mesma lógica das duas funções que imprimem
    os resultados no console, porém, ela salva dentro do arquivo
    chamdo "relatorio.txt" a tabela gerada
*/
void salvaEmArquivo(Municipio *_municipios, int n, int y){
    FILE *file = fopen("relatorio.txt", "w");
    if (!file) {
        return;
    }
    fprintf(file, "|    | %-20s | %-12s | %-18s | %-24s | %-6s | %-13s | %-24s |\n", 
    "Muncipio", "Confirmados", "Novos Confirmados", "Incidencia /100 mil hab",
    "Obitos", "Novos Obitos", "Mortalidade /100 mil hab");
    for(int i = 0; i < n; i++){
        int totalCasos = 0, totalObitos = 0;
        int novosCasos =  _municipios[i].dados[y-1][1];
        int novosObitos = _municipios[i].dados[y-1][2];
        for(int i = 0; i < y; i++){
            totalCasos +=  _municipios[i].dados[i][1];
            totalObitos +=  _municipios[i].dados[i][2];
        }
        float incidencia = calculoCemMil(_municipios[i].populacao, totalCasos);
        float mortalidade = calculoCemMil(_municipios[i].populacao, totalObitos);
        fprintf(file, "| %2d | %-20s | %-12d | %-18d | %-24.2f | %-6d | %-13d | %-24.2f |\n", i, _municipios[i].nome,  totalCasos, novosCasos,
        incidencia, totalObitos, novosObitos, mortalidade);
    }
    fclose(file);
}

/*
    Dentro dessa função chama-se a entrada e saída de dados, respecitivamente,
    além disso, há a opção do usuário salvar o relatorio em um arquivo. 
*/
void subprograma(Municipio *_municipios, int n, int y){
    int verificador = 0;

    //Função para dar as entradas de dados
    cadastroMunicipios(_municipios, n, y);
    imprimirLinhasCidade(_municipios, n, y);

    printf("\nDeseja salvar o relatorio em um arquivo?[Digite 1] ");
    scanf("%d", &verificador);
    if(verificador == 1){
        salvaEmArquivo(_municipios, n, y);
        printf("\nRelatorio salvo em relatorio.txt");
    }

}

void programa(){
    int n, y;

    //Início do programa, chamando quantidade de dias e de cidades
    apresentacao();
    ler_int("Digite a quantidade de cidades que deseja cadastrar: ", &n);
    ler_int("Digite a quantidade de dias que deseja cadastrar: ", &y);
    linha('-', 30);

    //Declaração do vetor alocado de maneira dinâmica
    Municipio* municipios = (Municipio*) malloc(n * sizeof(Municipio));

    //Chamando a função principal do programa
    subprograma(municipios, n, y);

    // Liberando a memória dos espaços alocados dinamicamente
    for(int i = 0; i < n; i++){
        free(municipios[i].nome);
        for(int j = 0; j < y; j++){
            free(municipios[i].dados[j]);
        }
        free(municipios[i].dados);
    }
    free(municipios);
}

int main(){
    //Deixando a linguagem em português, para aceitar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");
    programa();
    return 0;
}