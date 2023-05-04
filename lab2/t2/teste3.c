/*
    Laboratório de Programação 2
    Trabalho 2 -> Alocação Dinâmica de Vetores e Matrizes
    Aluno -> Davi Janisch Maia
*/

/*
    Usuário vai fornecer cidades, população e quantidade de dia, assim
    como confirmados e mortes no dia por cidade. A partir disso
    o programa deve usar alocação dinâmica para guardar essas
    informações e devolver por município o total de confirmados,
    total de novos casos (último dia cadastrado), total de óbitos,
    total de novos óbitos (útlimo dia cadastrado) e a mortalidade
    por 100k habitantes
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>


#define T_STR_CIDADES 20

struct municipio
{
    char* nome;
    int populacao;
    int** dados; //matriz de dados -> dia / novos_caso / óbitos
};
typedef struct municipio Municipio;

void linha(char caract, int i){
    for(i; i>0; i--){
        printf("%c", caract);
    }
    printf("\n");
}

void apresentacao(){
    linha('-', 30);
    printf("Seja bem vindo(a) ao programa!\n");
    linha('-', 30);
}

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

float calculoCemMil(int populacao, int casoOuObito){
    float pop, cOo;
    pop = (float) populacao;
    cOo = (float) casoOuObito;
    return (cOo * 100000)/ pop;
}

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

int desejaGerarRelatorio(int verificador){
    printf("Selecione o que voce deseja: \n1 - Exibir relatorio no console\n2 - Salvar relatorio em arquivo\n3 - Os dois anteriores");
    while(true){
        printf("\nDigite sua opcao (1/2/3):");
        scanf("%d", &verificador);
        if(verificador == 1 || verificador == 2 || verificador == 3){
            break;
        }
        printf("Voce digitou uma opcao invalida!");
    }
}



void programa(){
    int n, y, verificador = 0;

    apresentacao();
    ler_int("Digite a quantidade de cidades que deseja cadastrar: ", &n);
    ler_int("Digite a quantidade de dias que deseja cadastrar: ", &y);
    linha('-', 30);

    Municipio* municipios = (Municipio*) malloc(n * sizeof(Municipio));

    cadastroMunicipios(municipios, n, y);
    desejaGerarRelatorio(verificador);

    if(verificador == 1){
        imprimirLinhasCidade(municipios, n, y);
    }
    else if(verificador == 2){}
    else{
        imprimirLinhasCidade(municipios, n, y);
    }

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
