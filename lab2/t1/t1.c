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


// Fun��o que l� um inteiro e salva em um local da mem�ria
void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);
}

// Fun��o que l� um n�mero de ponto flutuante e e salva em
// um local da mem�ria
void ler_float(char *mensagem, float *valor) {
    printf("%s", mensagem);
    scanf("%f", valor);
}

// Fun��o que transforma um valor min�sculo e mai�sculo
// Verifica se � ou mai�culo e, caso n�o for, o transforma.
// Verifica de acordo com o ASCII do caracter -> StackOverflow
char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Fun��o que verifica se um char digitado � uma das duas op��es dispon�veis. Caso
// n�o for, entra em um loop at� o usu�rio digitar corretamente. Pode ser digitado
// tanto min�sculo, quanto mai�culo.
void ler_char(char *mensagem, char *valor, char caract1, char caract2) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    scanf("%c", valor);

    // Converter para mai�sculo
    *valor = to_upper(*valor);

    while (*valor != to_upper(caract1) && *valor != to_upper(caract2)) {
        printf("Entrada inv�lida. Digite %c ou %c: ", to_upper(caract1), to_upper(caract2));
        getchar(); // Limpar buffer do teclado
        scanf("%c", valor);

        // Converter para mai�sculo
        *valor = to_upper(*valor);
    }
}


void ler_string(char *mensagem, char *str) {

    printf("%s", mensagem);
    getchar();
    fgets(str + 1, T_STRING - 1, stdin);
    // Remover o caractere de nova linha no final da string
    /*
        Ao usar o fgets, caso haja espa�o para mais caracteres e se clicar enter para enviar
        ele vai colocar o \n dentro da string. Precisei tirar para ajudar na formata��o do re-
        lat�rio.
    */
    str[strcspn(str, "\n")] = '\0';

}

void imprimeLinha(char c, int vezes){
    printf("\n");
    for(int i = 0; i < vezes; i++){
        printf("%c", c);
    }
}

void imprimeHeaderRelatorio(char *frase){
    imprimeLinha('-', 50);
    printf("\n|  %-46s|", frase);
    imprimeLinha('-', 50);
}


//Fun��o que recebe os dados de entrada das pessoas
void recebeDadosEntrada(int tamanhoV, Pessoa vetor[tamanhoV]){
    printf("***************************************");
    printf("\n\tCADASTRO DE PESSOAS\n");
    printf("Obs.: Use ',' ao inv�s de '.' para n�-\nmeros com ponto flutuante(float)!\n");
    for(int i = 0; i < tamanhoV; i++){
        printf("---------------------------------------");
        printf("\n\tCadastro da pessoa %d:\n", i+1);
        printf("---------------------------------------");
        ler_int("\nDigite o c�digo: ", &vetor[i].codigo);
        ler_string("Digite o nome: ", vetor[i].nome);
        ler_string("Digite o endere�o: ", vetor[i].endereco);
        ler_float("Digite o peso(kg): ", &vetor[i].peso);
        ler_int("Digite a altura(cm): ", &vetor[i].altura);
        ler_char("Digite o sexo(F/M): ", &vetor[i].sexo, 'f', 'm');
        ler_float("Digite o sal�rio(R$/m�s): ", &vetor[i].salario);
    }
    printf("---------------------------------------\n");
}

void mostraDados(int tamanhoV, Pessoa pessoas[tamanhoV]){
    printf("\n**************************************************");
    printf("\n*         DADOS DE PESSOAS CADASTRADAS           *\n");
    for (int i = 0; i < tamanhoV; i++) {
        printf("--------------------------------------------------\n");
        printf("|              Pessoa n�mero %-2d                  |\n", i + 1);
        printf("--------------------------------------------------\n");
        printf("| C�digo:     %-34d |\n", pessoas[i].codigo);
        printf("| Nome:       %-34s |\n", pessoas[i].nome);
        printf("| Endere�o:   %-34s |\n", pessoas[i].endereco);
        printf("| Peso(kg):   %-34.2f |\n", pessoas[i].peso);
        printf("| Altura(cm): %-34d |\n", pessoas[i].altura);
        printf("| Sexo:       %-34c |\n", pessoas[i].sexo);
        printf("| Sal�rio:    R$%-32.2f |\n", pessoas[i].salario);
    }
    printf("--------------------------------------------------\n");
};

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
    imprimeHeaderRelatorio("Relat�rio Salarial Homens:");
    printf("\n| Media salarial: %.2f", mediaSalarial);
    imprimeLinha('-', 50);

};

// Fun��o que calcula a m�dia do peso das mulheres cadastradas

float mediaPesosMulheres(int tamanhoV, Pessoa pessoas[tamanhoV]){
    float somaPeso = 0, mediaPeso;
    int quantMulheres = 0;

    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].sexo == 'F'){
            somaPeso += pessoas[i].peso;
            quantMulheres += 1;
        }
    }
    if(quantMulheres == 0) return 0; // Para quando n�o h� cadastro de mulheres
    mediaPeso = somaPeso / (float) quantMulheres;
    return mediaPeso;
};

// Fun��o que devolve a media do peso das mulheres cadastradas

void relatorioMediaPesoMulheres(float mediaPeso){
    imprimeHeaderRelatorio("Relat�rio Peso Mulheres:");
    printf("\n| Media de peso: %.2f", mediaPeso);
    imprimeLinha('-', 50);
}

// Fun��o que calcula e devolve o IMC das pessoas cadastradas

void mostrarIMC(int tamanhoV, Pessoa pessoas[tamanhoV]){
    float imc, peso, altura;
    imprimeHeaderRelatorio("Relat�rio IMCs das pessoas:");
    for(int i = 0; i < tamanhoV; i++){
       altura = (float) pessoas[i].altura *0.01;
       peso = pessoas[i].peso;
       imc = peso/(altura * altura);
       printf("\n| IMC Pessoa %-2d: %-2.2f", i+1, imc);
    }
    imprimeLinha('-', 50);
};

// Fun��o que calcula a pessoa mais alta e devolve seu nome

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

    imprimeHeaderRelatorio("Relat�rio Pessoa mais Alta:");
    printf("\n| Nome pessoa mais alta: %s", nomePessoaMaisAlta);
    imprimeLinha('-', 50);
};

// Fun��o que calcula a pessoa com altura mais baixa e devolve seu c�digo

void pessoaMaisBaixa(int tamanhoV, Pessoa pessoas[tamanhoV]){
    int alturaMaisBaixa = INT_MAX, codigo;
    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].altura < alturaMaisBaixa){
            alturaMaisBaixa = pessoas[i].altura;
            codigo = pessoas[i].codigo;
        }
    }

    imprimeHeaderRelatorio("Relat�rio Pessoa mais Baixa:");
    printf("\n| C�digo pessoa mais baixa: %d", codigo);
    imprimeLinha('-', 50);
};


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
    imprimeHeaderRelatorio("Relat�rio Sal�rio acima da M�dia:");
    printf("\n| Quantidade de pessoas: %d", quantAcimaMedia);
    imprimeLinha('-', 50);
};


void mulheresAbaixoDaMediaPeso(float mediaPeso, int tamanhoV, Pessoa pessoas[tamanhoV]){
    int quant = 0;
    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].sexo == 'F' && pessoas[i].peso < mediaPeso){
            quant += 1;
        }
    }
    imprimeHeaderRelatorio("Relat�rio Mulheres abaixo da M�dia de peso:");
    printf("\n| Quantidade de mulheres abaixo da m�dia: %d", quant);
    imprimeLinha('-', 50);
}

void menosDeMilSalario(int tamanhoV, Pessoa pessoas[tamanhoV]){
    imprimeHeaderRelatorio("Relat�rio pessoas com sal�rio < 1000:");
    for(int i = 0; i < tamanhoV; i++){
        if(pessoas[i].salario < 1000){
            printf("\n| Pessoa cadastrada n�mero %d: ", i+1);
            printf("\n| Nome: %s", pessoas[i].nome);
            printf("\n| Endere�o: %s", pessoas[i].endereco);
            imprimeLinha('-', 50);
        }else{
            printf("\n| Nenhuma pessoa encontrada!");
            imprimeLinha('-', 50);
        }

    }

}

void explicacaoMenu(){
    printf("\nSelecione o relat�rio desejado:\n");
    printf("1. Mostrar Dados\n");
    printf("2. M�dia de Peso das Mulheres\n");
    printf("3. M�dia de Sal�rios dos Homens\n");
    printf("4. Mostrar IMC\n");
    printf("5. Nome da Pessoa Mais Alta\n");
    printf("6. C�digo da Pessoa Mais Baixa\n");
    printf("7. Pessoas com Sal�rio Acima da M�dia\n");
    printf("8. Pessoas com Sal�rio < R$ 1000\n");
    printf("9. Mulheres Abaixo da M�dia de Peso\n");
    printf("0. Sair\n");
    printf("Op��o: ");

}

void menuRelatorios(int tamanhoV, Pessoa pessoas[tamanhoV]){
    int opcao;
    char continuar;
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
                printf("Op��o inv�lida.\n");
                break;
        }

        if (opcao != 0) {
            ler_char("\nDeseja continuar? (S/N): ", &continuar, 'S', 'N');
        }
    } while (opcao != 0 && continuar == 'S');
}




int main(){
    //Vari�vel para definir a quantidade de pessoas a serem computadas
    int tamanhoVetor = 1;
    Pessoa vetorPessoas[tamanhoVetor];

    //Deixando a linguagem em portugu�s, para aceitar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    recebeDadosEntrada(tamanhoVetor, vetorPessoas);
    menuRelatorios(tamanhoVetor, vetorPessoas);

    return 0;
}
