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


#define T_STR_CIDADES 50

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
    printf("Seja bem vindo ao programa!");
    linha('*', 10);
}

void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);

}

void ler_string(char *mensagem, char *str) {

    printf("%s", mensagem);
    getchar();
    fgets(str, T_STR_CIDADES, stdin);
    // Remover o caractere de nova linha no final da string
    /*
        Ao usar o fgets, caso haja espaço para mais caracteres e se clicar enter para enviar
        ele vai colocar o \n dentro da string. Precisei tirar para ajudar na formatação do re-
        latório.
    */
    str[strcspn(str, "\n")] = '\0';

}

void cadastroMunicipio(Municipio _municipio, int y){
    linha('-', 20);
    ler_string("Digite o nome da cidade: ", &_municipio.nome);
    ler_int("Digite a população da cidade:", &_municipio.populacao);
    _municipio.dados = (int**) malloc(y * sizeof(int*));
    for(int j = 1; j <= y; j++){
        _municipio.dados[j] = (int*) malloc(3 * sizeof(int));
        printf("Cadastro do dia %d:\n", j);
        _municipio.dados[j][0] = j;
        ler_int("Número de novos casos: ", &_municipio.dados[j][1]);
        ler_int("Número de novos óbitos: ", &_municipio.dados[j][2]);
    }

}

void cadastroMunicipios(Municipio *_municipios, int n, int y){
    for(int i = 1; i <= n; i++){
        printf("Cadastro do município de número %d: ", i);
        cadastroMunicipio(_municipios[i], y);
    }
}

void programa(){
    int n, y;
    apresentacao();
    ler_int("Digite a quantidade de cidades que deseja cadastrar: ", &n);
    ler_int("Digite a quantidade de dias que deseja cadastrar: ", &y);
    Municipio* municipios = (Municipio*) malloc(n * sizeof(Municipio));
    linha('-', 10);
    printf("%d, %d", n, y);
    cadastroMunicipios(municipios, n, y);
}

int main(){
    //Deixando a linguagem em português, para aceitar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");
    programa();
    return 0;
}