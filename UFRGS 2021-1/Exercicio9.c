/* Este programa ele oferta 4 tipos de a��es, com quantidades e pre�os ja definidos, cabendo ao usu�rios escolher uma ou duas delas
e comprar a quantidade que desejar at� chegar ao total do estoque. */

#include <stdio.h>
#include <stdlib.h>


#define P_GERDAU 4.0 //Constante pre�o unit�rio da a��o GERDAU
#define P_PETROBRAS 22.5 //Constante pre�o unit�rio da a��o PETROBRAS
#define P_LOJASRENNER 2.5 //Constante pre�o unit�rio da a��o LOJASRENNER
#define P_GRENDENE 1.2 //Constante pre�o unit�rio da a��o GRENDENE


#define Q_INICIAL_GRENDENE 500 //Constante valor da quantidade incial de a��es Grendene
#define Q_INICIAL_GERDAU 2000 //Constante valor da quantidade incial de a��es Gerdau
#define Q_INICIAL_PETROBRAS 5000 //Constante valor da quantidade incial de a��es Petrobras
#define Q_INICIAL_LOJASRENNER 4500 //Constante valor da quantidade incial de a��es Lojas Renner
#define ZERO 0 //Constante valor 0


#define C_GERDAU 1 //Constante c�digo de Gerdau
#define C_PETROBRAS 2 //Constante c�digo de Petrobras
#define C_LOJASRENNER 3 //Constante c�digo de Lojas Renner
#define C_GRENDENE 4 //Constante c�digo de Grendene

#define PEDIDOS 5
#define


int main()
{
    int codigo, quantidade, pedidos; //Declara��o das vari�veis de entrada
    int q_grendene, q_gerdau, q_petrobras, q_lojasrenner; //Declara��o das vari�veis intermedi�rias e de sa�da
    float valor, valor_gerdau, valor_petrobras, valor_lojasrenner, valor_grendene; //Declara��o das vari�veis intermedi�rias e de sa�da


    valor = ZERO; //Valor inicial arrecado � ZERO
    q_grendene = Q_INICIAL_GRENDENE; //Atribui��o do n�mero de a��es GRENDENE dispon�veis
    q_gerdau = Q_INICIAL_GERDAU; //Atribui��o do n�mero de a��es GERDAU dispon�veis
    q_petrobras = Q_INICIAL_PETROBRAS; //Atribui��o do n�mero de a��es PETROBRAS dispon�veis
    q_lojasrenner = Q_INICIAL_LOJASRENNER; //Atribui��o do n�mero de a��es LOJAS RENNER dispon�veis
    pedidos = ZERO;

    /*
    TABELA QUE APRESENTA AS A��ES, SEUS RESPECTIVOS CODIGOS E VALORES, AL�M DA QUANTIDADE DISPON�VEL
    */


    printf("Seja bem vindo! Voce podera comprar de 1 a 2\ndas opcoes listadas abaixo, podendo escolher a\nquantidade que quiser, desde que a quantidade\nesteja disponivel.\n");

    printf("\n|%-10s|%-12s|%-10s|%-12s|\n", "CODIGO", "OPCAO", "DISPONIVEL", "VALOR");
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_GERDAU, "Gerdau", q_gerdau, P_GERDAU);
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_PETROBRAS, "Petrobras", q_petrobras, P_PETROBRAS);
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_LOJASRENNER, "Lojas Renner", q_lojasrenner, P_LOJASRENNER);
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_GRENDENE, "Grendene", q_grendene, P_GRENDENE);


    printf("\nDigite o codigo da acao que deseje comprar: ");
    scanf("%d",&codigo);//Ler o codigo da a��o desejada

    printf("\nDigite a quantidade desejada de acoes: ");
    scanf("%d",&quantidade); //Ler a quantidade desejada


    for (pedidos; pedidos < PEDIDOS; pedidos++)
    {
        switch(codigo) //Comando de sele��o m�ltipla para o codigo digitado pelo usu�rio
        {
        case C_GERDAU:
            if (quantidade < Q_INICIAL_GERDAU) //Condi��o dentro da quantidade dispon�vel de a��es GERDAU
            {
                q_gerdau -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_gerdau += (P_GERDAU*quantidade); //Adiciona ao valor arrecadado em GERDAU a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
                printf("\nVoce comprou %d acoes da GERDAU, o valor a pagar e: R$%.2f.", quantidade, valor_gerdau); //Exibe a quantidade de a��es compradas e o valor total da opera��o
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_gerdau); //Mensagem de erro caso a quantidade desejada esteja indispon�vel
                break; //Encerra o SWITCH
            }
        case C_PETROBRAS:
            if (quantidade < Q_INICIAL_PETROBRAS) //Condi��o fora da quantidade dispon�vel de a��es PETROBRAS
            {
                q_petrobras -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_petrobras += (P_PETROBRAS*quantidade); //Adiciona ao valor arrecadado em PETROBRAS a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
                printf("\nVoce comprou %d acoes da PETROBRAS, o valor a pagar e: R$%.2f.", quantidade, valor_petrobras); //Exibe a quantidade de a��es compradas e o valor total da opera��o
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_petrobras); //Mensagem de erro caso a quantidade desejada esteja indispon�vel
                break; //Encerra o SWITCH
            }
        case C_LOJASRENNER:
            if (quantidade < Q_INICIAL_LOJASRENNER) //Condi��o fora da quantidade dispon�vel de a��es LOJAS RENNER
            {
                q_lojasrenner -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_lojasrenner += (P_LOJASRENNER*quantidade); //Adiciona ao valor arrecadado em LOJAS RENNER a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
                printf("\nVoce comprou %d acoes das LOJAS RENNER, o valor a pagar e: R$%.2f.", quantidade, valor_lojasrenner); //Exibe a quantidade de a��es compradas e o valor total da opera��o
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_lojasrenner); //Mensagem de erro caso a quantidade desejada esteja indispon�vel
                break; //Encerra o SWITCH
            }
        case C_GRENDENE:
            if (quantidade < Q_INICIAL_GRENDENE) //Condi��o fora da quantidade dispon�vel de a��es GRENDENE
            {
                q_grendene -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_grendene += (P_GRENDENE*quantidade); //Adiciona ao valor arrecadado em GRENDENE a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
                printf("\nVoce comprou %d acoes da GRENDENE, o valor a pagar e: R$%.2f.", quantidade, valor_grendene); //Exibe a quantidade de a��es compradas e o valor total da opera��o
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_grendene); //Mensagem de erro caso a quantidade desejada esteja indispon�vel
                break; //Encerra o SWITCH
            }
        default:
            printf("\nERRO, VOCE DIGITOU UM CODIGO INVALIDO.");
            break;
            pedido = pedido -
        }
    }


    valor += valor_gerdau; //Atribui��o do valor de GERDAU vendidas para o geral
    valor += valor_petrobras; //Atribui��o do valor de PETROBRAS vendidas para o geral
    valor += valor_lojasrenner; //Atribui��o do valor de LOJAS RENNER vendidas para o geral
    valor += valor_grendene; //Atribui��o do valor de GRENDENE vendidas para o geral

    /*
    TABELA DE RELAT�RIO DE VENDAS DO DIA
    */

    printf("\n\n*\t STOCK MARKET\T*\n");
    printf("\n%-3s%-15s%-15s%-15s*", "Empresa", "Lotes vendidos", "Total faturado");
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Gerdau", (Q_INICIAL_GERDAU - q_gerdau), valor_gerdau); //Exibe a quantidade vendida de GERDAU e o valor arrecadado
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Petrobras", (Q_INICIAL_PETROBRAS - q_petrobras), valor_petrobras); //Exibe a quantidade vendida de PETROBRAS e o valor arrecadado
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Lojas Renner", (Q_INICIAL_LOJASRENNER - q_lojasrenner), valor_lojasrenner); //Exibe a quantidade vendida de LOJAS RENNER e o valor arrecadado
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Grendene", (Q_INICIAL_GRENDENE - q_grendene), valor_grendene); //Exibe a quantidade vendida de GRENDENE e o valor arrecadado


    return(0); //Encerra o programa
}


