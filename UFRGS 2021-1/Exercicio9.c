/* Este programa ele oferta 4 tipos de ações, com quantidades e preços ja definidos, cabendo ao usuários escolher uma ou duas delas
e comprar a quantidade que desejar até chegar ao total do estoque. */

#include <stdio.h>
#include <stdlib.h>


#define P_GERDAU 4.0 //Constante preço unitário da ação GERDAU
#define P_PETROBRAS 22.5 //Constante preço unitário da ação PETROBRAS
#define P_LOJASRENNER 2.5 //Constante preço unitário da ação LOJASRENNER
#define P_GRENDENE 1.2 //Constante preço unitário da ação GRENDENE


#define Q_INICIAL_GRENDENE 500 //Constante valor da quantidade incial de ações Grendene
#define Q_INICIAL_GERDAU 2000 //Constante valor da quantidade incial de ações Gerdau
#define Q_INICIAL_PETROBRAS 5000 //Constante valor da quantidade incial de ações Petrobras
#define Q_INICIAL_LOJASRENNER 4500 //Constante valor da quantidade incial de ações Lojas Renner
#define ZERO 0 //Constante valor 0


#define C_GERDAU 1 //Constante código de Gerdau
#define C_PETROBRAS 2 //Constante código de Petrobras
#define C_LOJASRENNER 3 //Constante código de Lojas Renner
#define C_GRENDENE 4 //Constante código de Grendene

#define PEDIDOS 5
#define


int main()
{
    int codigo, quantidade, pedidos; //Declaração das variáveis de entrada
    int q_grendene, q_gerdau, q_petrobras, q_lojasrenner; //Declaração das variáveis intermediárias e de saída
    float valor, valor_gerdau, valor_petrobras, valor_lojasrenner, valor_grendene; //Declaração das variáveis intermediárias e de saída


    valor = ZERO; //Valor inicial arrecado é ZERO
    q_grendene = Q_INICIAL_GRENDENE; //Atribuição do número de ações GRENDENE disponíveis
    q_gerdau = Q_INICIAL_GERDAU; //Atribuição do número de ações GERDAU disponíveis
    q_petrobras = Q_INICIAL_PETROBRAS; //Atribuição do número de ações PETROBRAS disponíveis
    q_lojasrenner = Q_INICIAL_LOJASRENNER; //Atribuição do número de ações LOJAS RENNER disponíveis
    pedidos = ZERO;

    /*
    TABELA QUE APRESENTA AS AÇÕES, SEUS RESPECTIVOS CODIGOS E VALORES, ALÉM DA QUANTIDADE DISPONÍVEL
    */


    printf("Seja bem vindo! Voce podera comprar de 1 a 2\ndas opcoes listadas abaixo, podendo escolher a\nquantidade que quiser, desde que a quantidade\nesteja disponivel.\n");

    printf("\n|%-10s|%-12s|%-10s|%-12s|\n", "CODIGO", "OPCAO", "DISPONIVEL", "VALOR");
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_GERDAU, "Gerdau", q_gerdau, P_GERDAU);
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_PETROBRAS, "Petrobras", q_petrobras, P_PETROBRAS);
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_LOJASRENNER, "Lojas Renner", q_lojasrenner, P_LOJASRENNER);
    printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_GRENDENE, "Grendene", q_grendene, P_GRENDENE);


    printf("\nDigite o codigo da acao que deseje comprar: ");
    scanf("%d",&codigo);//Ler o codigo da ação desejada

    printf("\nDigite a quantidade desejada de acoes: ");
    scanf("%d",&quantidade); //Ler a quantidade desejada


    for (pedidos; pedidos < PEDIDOS; pedidos++)
    {
        switch(codigo) //Comando de seleção múltipla para o codigo digitado pelo usuário
        {
        case C_GERDAU:
            if (quantidade < Q_INICIAL_GERDAU) //Condição dentro da quantidade disponível de ações GERDAU
            {
                q_gerdau -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_gerdau += (P_GERDAU*quantidade); //Adiciona ao valor arrecadado em GERDAU a multiplicação da quantidade selecionada e o valor unitário da ação
                printf("\nVoce comprou %d acoes da GERDAU, o valor a pagar e: R$%.2f.", quantidade, valor_gerdau); //Exibe a quantidade de ações compradas e o valor total da operação
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_gerdau); //Mensagem de erro caso a quantidade desejada esteja indisponível
                break; //Encerra o SWITCH
            }
        case C_PETROBRAS:
            if (quantidade < Q_INICIAL_PETROBRAS) //Condição fora da quantidade disponível de ações PETROBRAS
            {
                q_petrobras -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_petrobras += (P_PETROBRAS*quantidade); //Adiciona ao valor arrecadado em PETROBRAS a multiplicação da quantidade selecionada e o valor unitário da ação
                printf("\nVoce comprou %d acoes da PETROBRAS, o valor a pagar e: R$%.2f.", quantidade, valor_petrobras); //Exibe a quantidade de ações compradas e o valor total da operação
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_petrobras); //Mensagem de erro caso a quantidade desejada esteja indisponível
                break; //Encerra o SWITCH
            }
        case C_LOJASRENNER:
            if (quantidade < Q_INICIAL_LOJASRENNER) //Condição fora da quantidade disponível de ações LOJAS RENNER
            {
                q_lojasrenner -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_lojasrenner += (P_LOJASRENNER*quantidade); //Adiciona ao valor arrecadado em LOJAS RENNER a multiplicação da quantidade selecionada e o valor unitário da ação
                printf("\nVoce comprou %d acoes das LOJAS RENNER, o valor a pagar e: R$%.2f.", quantidade, valor_lojasrenner); //Exibe a quantidade de ações compradas e o valor total da operação
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_lojasrenner); //Mensagem de erro caso a quantidade desejada esteja indisponível
                break; //Encerra o SWITCH
            }
        case C_GRENDENE:
            if (quantidade < Q_INICIAL_GRENDENE) //Condição fora da quantidade disponível de ações GRENDENE
            {
                q_grendene -= quantidade; //Subtrai a quantidade desejada do estoque
                valor_grendene += (P_GRENDENE*quantidade); //Adiciona ao valor arrecadado em GRENDENE a multiplicação da quantidade selecionada e o valor unitário da ação
                printf("\nVoce comprou %d acoes da GRENDENE, o valor a pagar e: R$%.2f.", quantidade, valor_grendene); //Exibe a quantidade de ações compradas e o valor total da operação
                break; //Encerra o SWITCH
            }
            else
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes ", q_grendene); //Mensagem de erro caso a quantidade desejada esteja indisponível
                break; //Encerra o SWITCH
            }
        default:
            printf("\nERRO, VOCE DIGITOU UM CODIGO INVALIDO.");
            break;
            pedido = pedido -
        }
    }


    valor += valor_gerdau; //Atribuição do valor de GERDAU vendidas para o geral
    valor += valor_petrobras; //Atribuição do valor de PETROBRAS vendidas para o geral
    valor += valor_lojasrenner; //Atribuição do valor de LOJAS RENNER vendidas para o geral
    valor += valor_grendene; //Atribuição do valor de GRENDENE vendidas para o geral

    /*
    TABELA DE RELATÓRIO DE VENDAS DO DIA
    */

    printf("\n\n*\t STOCK MARKET\T*\n");
    printf("\n%-3s%-15s%-15s%-15s*", "Empresa", "Lotes vendidos", "Total faturado");
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Gerdau", (Q_INICIAL_GERDAU - q_gerdau), valor_gerdau); //Exibe a quantidade vendida de GERDAU e o valor arrecadado
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Petrobras", (Q_INICIAL_PETROBRAS - q_petrobras), valor_petrobras); //Exibe a quantidade vendida de PETROBRAS e o valor arrecadado
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Lojas Renner", (Q_INICIAL_LOJASRENNER - q_lojasrenner), valor_lojasrenner); //Exibe a quantidade vendida de LOJAS RENNER e o valor arrecadado
    printf("\n%-3s%-15s%-15dR$%-15.2f*", "Grendene", (Q_INICIAL_GRENDENE - q_grendene), valor_grendene); //Exibe a quantidade vendida de GRENDENE e o valor arrecadado


    return(0); //Encerra o programa
}


