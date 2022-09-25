/*
Este programa ele oferta 4 tipos de ações, com quantidades e preços ja definidos, podendo fazer 5 pedidos diferentes.
*/

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

#define PEDIDOS 5 //Constante usada no FOR
#define NUMERO_UM 1 //Constante do número 1



int main()
{
    int codigo, quantidade, pedidos; //Declaração das variáveis de entrada INT
    int e_grendene, e_gerdau, e_petrobras, e_lojasrenner; //Declaração das variáveis intermediárias e de saída INT
    int quantidade_total, q_gerdau, q_petrobras, q_lojasrenner, q_grendene; //Declaração das variáveis intermediárias e de saída INT
    float valor, valor_gerdau, valor_petrobras, valor_lojasrenner, valor_grendene, media; //Declaração das variáveis intermediárias e de saída FLOAT


    valor = ZERO; //Valor inicial arrecado é ZERO
    pedidos = NUMERO_UM; //Atribuição de 1 à variável pedidos
    quantidade_total = ZERO; //Atribuição de 0 à variável quantidade_total

    e_grendene = Q_INICIAL_GRENDENE; //Atribuição do número de ações GRENDENE disponíveis
    e_gerdau = Q_INICIAL_GERDAU; //Atribuição do número de ações GERDAU disponíveis
    e_petrobras = Q_INICIAL_PETROBRAS; //Atribuição do número de ações PETROBRAS disponíveis
    e_lojasrenner = Q_INICIAL_LOJASRENNER; //Atribuição do número de ações LOJAS RENNER disponíveis

    q_gerdau = ZERO; //Atribuição do valor 0 á variável q_gerdau
    q_petrobras = ZERO; //Atribuição do valor 0 á variável q_petrobras
    q_lojasrenner = ZERO; //Atribuição do valor 0 á variável q_lojasrenner
    q_grendene = ZERO; //Atribuição do valor 0 á variável q_grendene

    for (pedidos; pedidos <= PEDIDOS; pedidos++)
    {
        /*
        TABELA QUE APRESENTA AS AÇÕES, SEUS RESPECTIVOS CODIGOS E VALORES, ALÉM DA QUANTIDADE DISPONÍVEL
        */
        printf("-------------------------------------------------");
        printf("\n|%30s%2d%16s\n", "PEDIDO NUMERO ", pedidos, "|");
        printf("-------------------------------------------------");
        printf("\n|%-10s|%-12s|%-10s|%-12s|\n", "CODIGO", "OPCAO", "DISPONIVEL", "VALOR");
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_GERDAU, "Gerdau", e_gerdau, P_GERDAU);
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_PETROBRAS, "Petrobras", e_petrobras, P_PETROBRAS);
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_LOJASRENNER, "Lojas Renner", e_lojasrenner, P_LOJASRENNER);
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_GRENDENE, "Grendene", e_grendene, P_GRENDENE);
        printf("-------------------------------------------------");

        printf("\nDigite o codigo da acao que deseje comprar: ");
        scanf("%d",&codigo);//Ler o codigo da ação desejada

        printf("\nDigite a quantidade desejada de acoes: ");
        scanf("%d",&quantidade); //Ler a quantidade desejada



        switch(codigo) //Comando de seleção múltipla para o codigo digitado pelo usuário
        {

        case C_GERDAU:


            while(quantidade > e_gerdau) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes.\n", e_gerdau); //Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            system("cls");
            q_gerdau += quantidade; //Adiciona quantidade na variável de quantidade vendida de Gerdau
            e_gerdau -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_gerdau += (P_GERDAU*quantidade); //Adiciona ao valor arrecadado em GERDAU a multiplicação da quantidade selecionada e o valor unitário da ação
            printf("\nVoce comprou %d acoes da GERDAU, o valor a pagar e: R$%.2f.\n\n", quantidade, (P_GERDAU*quantidade)); //Exibe a quantidade de ações compradas e o valor total da operação

            break; //Encerra o SWITCH



        case C_PETROBRAS:


            while(quantidade > e_petrobras) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_petrobras);//Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            system("cls");
            q_petrobras += quantidade; //Adiciona quantidade na variável de quantidade vendida de Petrobras
            e_petrobras -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_petrobras += (P_PETROBRAS*quantidade); //Adiciona ao valor arrecadado em PETROBRAS a multiplicação da quantidade selecionada e o valor unitário da ação
            printf("\nVoce comprou %d acoes da PETROBRAS, o valor a pagar e: R$%.2f.\n\n", quantidade, (P_PETROBRAS*quantidade)); //Exibe a quantidade de ações compradas e o valor total da operação
            break; //Encerra o SWITCH



        case C_LOJASRENNER:


            while (quantidade > e_lojasrenner) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_lojasrenner);//Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            system("cls");
            q_lojasrenner += quantidade; //Adiciona quantidade na variável de quantidade vendida de Lojas Renner
            e_lojasrenner -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_lojasrenner += (P_LOJASRENNER*quantidade); //Adiciona ao valor arrecadado em LOJAS RENNER a multiplicação da quantidade selecionada e o valor unitário da ação
            printf("\nVoce comprou %d acoes das LOJAS RENNER, o valor a pagar e: R$%.2f.\n\n", quantidade, (P_LOJASRENNER*quantidade)); //Exibe a quantidade de ações compradas e o valor total da operação
            break; //Encerra o SWITCH



        case C_GRENDENE:


            while (quantidade > e_grendene) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_lojasrenner);//Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            system("cls");
            q_grendene += quantidade; //Adiciona quantidade na variável de quantidade vendida de Grendene
            e_grendene -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_grendene += (P_GRENDENE*quantidade); //Adiciona ao valor arrecadado em GRENDENE a multiplicação da quantidade selecionada e o valor unitário da ação
            printf("\nVoce comprou %d acoes da GRENDENE, o valor a pagar e: R$%.2f.\n\n", quantidade, (P_GRENDENE*quantidade)); //Exibe a quantidade de ações compradas e o valor total da operação
            break; //Encerra o SWITCH



        default:

            system("cls"); //Limpa a tela
            printf("\nERRO, VOCE DIGITOU UM CODIGO INVALIDO.\n\n"); //Mensagem de erro caso seja um código inválido
            break;//Encerra o SWITCH

        }
        quantidade_total += quantidade; //Adiciona a quantidade do pedido à quantidade total para o calculo da media das vendas

    }
    system("cls"); //Limpa a tela para a tabela do stock market
    valor += valor_gerdau; //Atribuição do valor de GERDAU vendidas para o geral
    valor += valor_petrobras; //Atribuição do valor de PETROBRAS vendidas para o geral
    valor += valor_lojasrenner; //Atribuição do valor de LOJAS RENNER vendidas para o geral
    valor += valor_grendene; //Atribuição do valor de GRENDENE vendidas para o geral

    media = valor/quantidade_total;//calcula a media paga por ação

    /*
    TABELA DE EXIBIÇÃO DO STOCK MARKET
    */
    printf("-------------------------------------------------------\n");
    printf("%-21s%s%22s\n", "|", "STOCK MARKET", "|");
    printf("-------------------------------------------------------\n");
    printf("%-4s%-12s%-18s%-17s%4s\n", "|", "Empresa", "Lotes vendidos", "Total faturado", "|");
    printf("%-27s%28s\n", "|", "|");

    /*
    Parte da tabela que exibe as quantidades e o valor especifico comprados por empresa
    */
    printf("%-5s%-15s%10d%10s  %-9.2f%4s\n", "|", "1.GERDAU", q_gerdau,"R$", valor_gerdau, "|"); //Linha da tabela com dados da Gerdau
    printf("%-5s%-15s%10d%10s  %-9.2f%4s\n", "|", "2.PETROBRAS", q_petrobras, "R$", valor_petrobras, "|"); //Linha da tabela com dados da Petrobras
    printf("%-5s%-15s%10d%10s  %-9.2f%4s\n", "|", "3.LOJAS RENNER", q_lojasrenner, "R$", valor_lojasrenner, "|"); //Linha da tabela com dados das Lojas Renner
    printf("%-5s%-15s%10d%10s  %-9.2f%4s\n", "|", "4.GRENDENE", q_grendene, "R$", valor_grendene, "|"); //Linha da tabela com dados da Grendene
    /*
    Parte da tabela que exibe o total arrecado com vendas, além da media paga por ação
    */
    printf("-------------------------------------------------------\n");
    printf("%-5s%-26s%10s  %-9.2f%3s\n", "|", "TOTAL DE VENDAS DO DIA", "R$", valor, "|");
    printf("%-5s%-26s%10s  %-9.2f%3s\n", "|", "MEDIA DAS VENDAS", "R$", media, "|");
    printf("-------------------------------------------------------\n");

    return(0); //Encerra o programa
}
