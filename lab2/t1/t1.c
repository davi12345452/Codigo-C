// Davi Janisch Maia
// Lab2 - Trabalho 1

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

//Constante para tamanho de string dos char[] com tamanho 80, sem contar o \0
#define T_STRING 81

struct pessoa {
int codigo;
char nome[T_STRING];
char endereco[T_STRING];
float peso;
int altura;
char sexo;
float salario;
};

typedef struct pessoa Pessoa;


// Função que lê um inteiro e salva em um local da memória
void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);
}

// Função que lê um número de ponto flutuante e e salva em
// um local da memória
void ler_float(char *mensagem, float *valor) {
    printf("%s", mensagem);
    scanf("%f", valor);
}

// Função que transforma um valor minúsculo e maiúsculo
// Verifica se é ou maiúculo e, caso não for, o transforma.
// Verifica de acordo com o ASCII do caracter -> StackOverflow
char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Função que verifica se um char digitado é uma das duas opções disponíveis. Caso
// não for, entra em um loop até o usuário digitar corretamente. Pode ser digitado
// tanto minúsculo, quanto maiúculo.
void ler_char(char *mensagem, char *valor, char caract1, char caract2) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    scanf("%c", valor);

    // Converter para maiúsculo
    *valor = to_upper(*valor);

    while (*valor != to_upper(caract1) && *valor != to_upper(caract2)) {
        printf("Entrada inválida. Digite %c ou %c: ", to_upper(caract1), to_upper(caract2));
        getchar(); // Limpar buffer do teclado
        scanf("%c", valor);

        // Converter para maiúsculo
        *valor = to_upper(*valor);
    }
}


void ler_string(char *mensagem, char *str) {

    printf("%s", mensagem);
    getchar();
    fgets(str, T_STRING, stdin);
    // Remover o caractere de nova linha no final da string
    /*
        Ao usar o fgets, caso haja espaço para mais caracteres e se clicar enter para enviar
        ele vai colocar o \n dentro da string. Precisei tirar para ajudar na formatação do re-
        latório.
    */
    str[strcspn(str, "\n")] = '\0';

}


// Função que gera uma linha com tamanho vezes e formada pelo caracter c
void imprimeLinha(char c, int vezes){
    printf("\n");
    for(int i = 0; i < vezes; i++){
        printf("%c", c);
    }
}

// Função que imprime um header para um relatório, o usuário só passa a frase desejada
void imprimeHeaderRelatorio(char *frase){
    imprimeLinha('-', 50);
    printf("\n|  %-46s|", frase);
    imprimeLinha('-', 50);
}


//Função que recebe os dados de entrada das pessoas usando as funções
//auxiliares previamente declaradas
void recebeDadosEntrada(int tamanhoV, Pessoa vetor[tamanhoV]){
    imprimeLinha('*', 40);
    printf("\n\tCADASTRO DE PESSOAS\n");
    printf("Obs.: Use ',' ao invés de '.' para nú-\nmeros com ponto flutuante(float)!");
    for(int i = 0; i < tamanhoV; i++){
        imprimeLinha('-', 40);
        printf("\n\tCadastro da pessoa %d:", i+1);
        imprimeLinha('-', 40);
        ler_int("\nDigite o código: ", &vetor[i].codigo);
        ler_string("Digite o nome: ", vetor[i].nome);
        ler_float("Digite o peso(kg): ", &vetor[i].peso);
        ler_string("Digite o endereço: ", vetor[i].endereco);
        ler_int("Digite a altura(cm): ", &vetor[i].altura);
        ler_char("Digite o sexo(F/M): ", &vetor[i].sexo, 'f', 'm');
        ler_float("Digite o salário(R$/mês): ", &vetor[i].salario);
    }
    imprimeLinha('-', 40);
}

// Função que gera um relatório com todas as pessoas cadastradas
void mostraDados(int tamanhoV, Pessoa pessoas[tamanhoV]){
    imprimeHeaderRelatorio("       DADOS DE PESSOAS CADASTRADAS");
    for (int i = 0; i < tamanhoV; i++) {
        printf("\n|              Pessoa número %-2d                  |", i + 1);
        imprimeLinha('-', 50);
        printf("\n| Código:     %-d \n", pessoas[i].codigo);
        printf("| Nome:       %-s \n", pessoas[i].nome);
        printf("| Peso(kg):   %-.2f \n", pessoas[i].peso);
        printf("| Endereço:   %-s \n", pessoas[i].endereco);
        printf("| Altura(cm): %-d \n", pessoas[i].altura);
        printf("| Sexo:       %-c \n", pessoas[i].sexo);
        printf("| Salário:    R$%-.2f ", pessoas[i].salario);
        imprimeLinha('-', 50);
    }

};

// Função que calcula e exibe a media salarial dos homens cadastrados
void mediaSalariosHomens(int tamanhoV, Pessoa pessoas[tamanhoV]){
    float somaSalario = 0, mediaSalarial = 0;
    int quantHomens = 0;

    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].sexo == 'M'){
            somaSalario+= pessoas[i].salario;
            quantHomens+= 1;
        }
    }
    mediaSalarial = somaSalario / (float) quantHomens;
    imprimeHeaderRelatorio("Relatório Salarial Homens:");
    printf("\n| Media salarial: %.2f", mediaSalarial);
    imprimeLinha('-', 50);

};

// Função que calcula a média do peso das mulheres cadastradas

float mediaPesosMulheres(int tamanhoV, Pessoa pessoas[tamanhoV]){
    float somaPeso = 0, mediaPeso;
    int quantMulheres = 0;

    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].sexo == 'F'){
            somaPeso += pessoas[i].peso;
            quantMulheres += 1;
        }
    }
    if(quantMulheres == 0) return 0; // Para quando não há cadastro de mulheres
    mediaPeso = somaPeso / (float) quantMulheres;
    return mediaPeso;
};

// Função que gera um relatório dizendo o peso médio das mulheres cadastradas

void relatorioMediaPesoMulheres(float mediaPeso){
    imprimeHeaderRelatorio("Relatório Peso Mulheres:");
    printf("\n| Media de peso: %.2f", mediaPeso);
    imprimeLinha('-', 50);
}

// Função que calcula e devolve em um relatório, o IMC das pessoas cadastradas

void mostrarIMC(int tamanhoV, Pessoa pessoas[tamanhoV]){
    float imc, peso, altura;
    imprimeHeaderRelatorio("Relatório IMCs das pessoas:");
    for(int i = 0; i < tamanhoV; i++){
       altura = (float) pessoas[i].altura *0.01;
       peso = pessoas[i].peso;
       imc = peso/(altura * altura);
       printf("\n| IMC Pessoa %-2d: %-2.2f", i+1, imc);
    }
    imprimeLinha('-', 50);
};

// Função que calcula a pessoa mais alta e devolve um relatório com seu nome

void pessoaMaisAlta(int tamanhoV, Pessoa pessoas[tamanhoV]){
    char nomePessoaMaisAlta[T_STRING];
    int maiorAltura = INT_MIN;
    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].altura > maiorAltura){
            maiorAltura = pessoas[i].altura;
            for(int j = 0; j < T_STRING; j++){
                nomePessoaMaisAlta[j] = pessoas[i].nome[j];
            }
        }
    }

    imprimeHeaderRelatorio("Relatório Pessoa mais Alta:");
    printf("\n| Nome pessoa mais alta: %s", nomePessoaMaisAlta);
    imprimeLinha('-', 50);
};

// Função que calcula a pessoa com altura mais baixa e devolve um relatório com seu código

void pessoaMaisBaixa(int tamanhoV, Pessoa pessoas[tamanhoV]){
    int alturaMaisBaixa = INT_MAX, codigo;
    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].altura < alturaMaisBaixa){
            alturaMaisBaixa = pessoas[i].altura;
            codigo = pessoas[i].codigo;
        }
    }

    imprimeHeaderRelatorio("Relatório Pessoa mais Baixa:");
    printf("\n| Código pessoa mais baixa: %d", codigo);
    imprimeLinha('-', 50);
};


// Função que calcula o salário médio, após isso, registra quantas pessoas
// recebem acima desse valor e gera um relatório.

void numPesSalarioAcimaMedia(int tamanhoV, Pessoa pessoas[tamanhoV]){
    float soma = 0, media;
    int quantAcimaMedia = 0;
    for(int i = 0; i < tamanhoV; i++){
        soma += pessoas[i].salario;
    }
    media = soma / (float)tamanhoV;
    for(int j = 0; j < tamanhoV; j++){
        if(pessoas[j].salario > media){
            quantAcimaMedia += 1;
        }
    }
    imprimeHeaderRelatorio("Relatório Salário acima da Média:");
    printf("\n| Quantidade de pessoas: %d", quantAcimaMedia);
    imprimeLinha('-', 50);
};


// Função que recebe um peso médio e gera um relatório mostrando quantas mulheres
// estão abaixo do peso médio das mulheres cadastradas

void mulheresAbaixoDaMediaPeso(float mediaPeso, int tamanhoV, Pessoa pessoas[tamanhoV]){
    int quant = 0;
    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].sexo == 'F' && pessoas[i].peso < mediaPeso){
            quant += 1;
        }
    }
    imprimeHeaderRelatorio("Relatório Mulheres abaixo da Média de peso:");
    printf("\n| Quantidade de mulheres abaixo da média: %d", quant);
    imprimeLinha('-', 50);
}

// Função que busca e gera um relatório das pessoas cadastradas que recebem menos de
// 1000 reais de salário. Devolve-se o número de cadastro, nome e endereço.

void menosDeMilSalario(int tamanhoV, Pessoa pessoas[tamanhoV]){
    imprimeHeaderRelatorio("Relatório pessoas com salário < 1000:");
    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].salario < 1000){
            printf("\n| Pessoa cadastrada número %d: ", i+1);
            printf("\n| Nome: %s", pessoas[i].nome);
            printf("\n| Endereço: %s", pessoas[i].endereco);
            imprimeLinha('-', 50);
        }else{
            printf("\n| Nenhuma pessoa encontrada!");
            imprimeLinha('-', 50);
        }

    }

}

// Função de exibição das opções para o menu de relatórios.

void explicacaoMenu(){
    printf("\nSelecione o relatório desejado:\n");
    printf("1. Mostrar Dados\n");
    printf("2. Média de Peso das Mulheres\n");
    printf("3. Média de Salários dos Homens\n");
    printf("4. Mostrar IMC\n");
    printf("5. Nome da Pessoa Mais Alta\n");
    printf("6. Código da Pessoa Mais Baixa\n");
    printf("7. Pessoas com Salário Acima da Média\n");
    printf("8. Pessoas com Salário < R$ 1000\n");
    printf("9. Mulheres Abaixo da Média de Peso\n");
    printf("0. Sair\n");
    printf("Opção: ");

}

// Função que gera os relatórios de acordo com o desejo do usuário

void menuRelatorios(int tamanhoV, Pessoa pessoas[tamanhoV]){
    int opcao;
    char continuar;
    // Cálculo do peso medio de mulheres para ser usado em relatórios abaixo
    float mediaPeso = mediaPesosMulheres(tamanhoV, pessoas);

    do {
        explicacaoMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostraDados(tamanhoV, pessoas);
                break;
            case 2:
                relatorioMediaPesoMulheres(mediaPeso);
                break;
            case 3:
                mediaSalariosHomens(tamanhoV, pessoas);
                break;
            case 4:
                mostrarIMC(tamanhoV, pessoas);
                break;
            case 5:
                pessoaMaisAlta(tamanhoV, pessoas);
                break;
            case 6:
                pessoaMaisBaixa(tamanhoV, pessoas);
                break;
            case 7:
                numPesSalarioAcimaMedia(tamanhoV, pessoas);
                break;
            case 8:
                menosDeMilSalario(tamanhoV, pessoas);
                break;
            case 9:
                mulheresAbaixoDaMediaPeso(mediaPeso, tamanhoV, pessoas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

        // Aqui reaproveita-se a função ler_char, quando o usuário indica se deseja ou não continuar
        if (opcao != 0) {
            ler_char("\nDeseja continuar? (S/N): ", &continuar, 'S', 'N');
        }
    } while (opcao != 0 && continuar == 'S');
}




int main(){

    //Deixando a linguagem em português, para aceitar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    // DEFINA AQUI A QUANTIDADE DE PESSOAS A SEREM CADASTRADAS:
    int tamanhoVetor = 1;

    Pessoa *vetorPessoas[tamanhoVetor];

    // DADOS DE ENTRADA:
    recebeDadosEntrada(tamanhoVetor, &vetorPessoas);

    // DADOS DE SAÍDA:
    menuRelatorios(tamanhoVetor, vetorPessoas);

    return 0;
}
