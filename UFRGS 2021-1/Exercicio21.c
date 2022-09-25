/*
Esse programa recebe um nome de empresa, devolvendo a sua quantidade anual de venda. Além de indicar a mais
vendida entre N empresas. Após isso, o programa zera a quantidade mensal da empresa mais vendida, exibindo
um relatorio com a quantidade total e o valor faturado, além de outro relatório exibindo a venda mensal de
cada empresa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ZERO 0 //Constante zero, com valor 0, para ser usada no programa
#define N 6 // Constante com o número de empresas que podem ser cadastradas
#define T 20 //Constante com tamanho dos nomes das empresas
#define MESES 12 //Constante com a quantidade de meses
#define UM 1 //Constante com valor 1
#define VALOR_MAXIMO_QUANTIDADE 10000 //Constante com quantidade maxima por mes de vendas de acoes
#define VALOR_MAXIMO_VALOR 100.00 //Constante com valor unitario maximo por ação

int main()
{
    char string_acoes[N][T] = {"Gerdau", "Petrobras", "Lojas Renner", "Vivo", "Vale", "Metalsinos"}, leitura[T]; //Definição da matriz de string com nome das empresas
    int vendas[N][MESES], quantidade_vendida[N] = {ZERO}; //Declaração das matrizes inteiras
    int i, j, verificador, booleano, mais_vendida, c_mais_vendida; //Declaração das variaveis de entrada e intermediárias
    float valor_unitario[N], valor_total[N]; //Declaração das matrizes float


    /*
    Atribuindo valores aleatorios ao valor unitário e as vendas mensais
    */

    srand(time(ZERO)); //Gera uma nova cadeia de números aleatórios
    for (i = ZERO; i < N; i++)
    {
        valor_unitario[i] = (float) (rand() / (double) RAND_MAX * (VALOR_MAXIMO_VALOR + UM)); //Atribui um preço aleatório à ação
        for(j = ZERO; j < MESES; j++)
            vendas[i][j]  = (int) (rand() / (double) RAND_MAX * (VALOR_MAXIMO_QUANTIDADE + UM)); //Atribui uma quantidade mensal aleatória para cada mes de cada ação
    }


    /*
    Atribuindo valores a quantidade total e ao valor total
    */

    for (i = ZERO; i < N; i++)
    {
        for(j = ZERO; j < MESES; j++)
            quantidade_vendida[i] += vendas[i][j]; //Calcula a quantidade anual vendida por cada ação

        valor_total[i] = valor_unitario[i]*quantidade_vendida[i]; //Calcula o valor anual arrecadado pela venda de cada ação
    }


    /*
    Definindo a ação mais vendida
    */

    mais_vendida = quantidade_vendida[ZERO]; //Atribui o primeiro valor a mais vendida
    c_mais_vendida = ZERO; //Atribui o primeiro codigo a mais vendida
    for (i = ZERO; i < N; i++) //Comando de repetição vai atribuir a quantidade da mais vendida, além do código
    {
        if(quantidade_vendida[i] > mais_vendida)
        {
            mais_vendida = quantidade_vendida[i];
            c_mais_vendida = i;
        }
    }

    /*
    Funcionamento do código
    */


    printf("\nPossuimos %d acoes para a visualizacao da quantidade vendida:\n", N);
    for (i = ZERO; i < N; i++)
        printf("%s  ", string_acoes[i]); //Mostra as acoes disponiveis
    puts("\n\nDigite o nome da acao que deseja vizualizar:\n");
    gets(leitura); //Le a ação preterida pelo usuário

    system("cls"); //Limpa a tela

    for (i = ZERO; i < N; i++)
    {
        verificador = strcmp(leitura, string_acoes[i]); //Verifica se a ação lida esta entre as disponiveis
        if (verificador == ZERO) //Caso a acao lida esteja entre as disponiveis
        {
            booleano = UM; //Comando lógico para caso a ação digitada esteja certa
            printf("\nO codigo da acao %s e: %d\n", string_acoes[i], i); //Exibe o codigo da ação digitada
            printf("\nO total de vendas de %s em 12 meses foi: %d\n", leitura, quantidade_vendida[i]); //Exibe a quantidade anual de vendas da ação digitada
            break; //Encerra o comando de repetição
        }
        else
            booleano = ZERO; //Comando lógico para caso a ação digitada esteja errada
    }

    if (booleano == ZERO) //Se a ação digitada estiver errada
    {
        printf("\n-1\n");
        printf("\nVoce digitou uma empresa invalida.\n");
    }

    printf("\nA acao mais vendida foi %s, com %d unidades comercializadas.\n\n", string_acoes[c_mais_vendida], mais_vendida); //Exibe a ação mais vendida no ano
    for (i = ZERO; i < MESES; i++) //Comando de repetição que zera a quantidade mensal e anual da ação mais vendida
        vendas[c_mais_vendida][i] = ZERO;
    quantidade_vendida[c_mais_vendida] = ZERO;


    /*
    Tabela de vendas:
    */

    printf("\nRELATORIO DE VENDAS DO ANO\n");
    printf("%-20s%-20s%-20s%-20s\n", "Codigo da Acao", "Nome da Acao", "Quantidade", "Total Faturado");
    for (i = ZERO; i < N; i++)
        printf("%-20d%-20s%-20dR$ %-17.2f\n", i, string_acoes[i], quantidade_vendida[i], valor_total[i]);


    /*
    Tabela de venda mensal
    */

    printf("\nRELATORIO DE VENDAS MENSAIS:\n");
    for (i = ZERO; i < N; i++)
        printf("%-20s", string_acoes[i]);
    printf("\n");
    for (j = ZERO; j < MESES; j++)
    {
        for (i = ZERO; i < N; i++)
            printf("%-20d", vendas[i][j]);
        printf("\n");
    }

    return(ZERO); //Encerra o programa
}
