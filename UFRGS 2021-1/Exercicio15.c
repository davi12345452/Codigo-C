/*
Este programa ele oferta 4 tipos de ações, com quantidade e valores, cabe ao usuário escolher um código
de ação e uma quantidade, no final, caso haja estoque e a operação seja efetuada, cabe ao usuário escolher
se quer fazer mais compras ou não (Ele pode comprar infinitamente, desde que haja estoque). No final, o
programa exibe um relatório mostrando a quantidade vendida e o valor total arrecadado.
*/

#include <stdio.h>
#include <stdlib.h>


#define P_GERDAU 14.0 //Constante preço unitário da ação GERDAU
#define P_PETROBRAS 2.5 //Constante preço unitário da ação PETROBRAS
#define P_LOJASRENNER 1.2 //Constante preço unitário da ação LOJASRENNER
#define P_VIVO 2.2 //Constante preço unitário da ação VIVO


#define Q_INICIAL_VIVO 500 //Constante valor da quantidade incial de ações Vivo
#define Q_INICIAL_GERDAU 10000 //Constante valor da quantidade incial de ações Gerdau
#define Q_INICIAL_PETROBRAS 2000 //Constante valor da quantidade incial de ações Petrobras
#define Q_INICIAL_LOJASRENNER 5000 //Constante valor da quantidade incial de ações Lojas Renner
#define ZERO 0 //Constante valor 0


#define C_GERDAU 1 //Constante código de Gerdau
#define C_PETROBRAS 2 //Constante código de Petrobras
#define C_LOJASRENNER 3 //Constante código de Lojas Renner
#define C_VIVO 4 //Constante código de Grendene

#define PEDIDOS 5 //Constante usada no FOR
#define NUMERO_UM 1 //Constante do número 1
#define NUMERO_QUATRO 4 //Constante do número 4



int main()
{
    int codigo, quantidade, pedidos; //Declaração das variáveis de entrada INT
    int e_vivo, e_gerdau, e_petrobras, e_lojasrenner; //Declaração das variáveis intermediárias e de saída INT
    int quantidade_total, q_gerdau, q_petrobras, q_lojasrenner, q_vivo; //Declaração das variáveis intermediárias e de saída INT
    float valor, valor_gerdau, valor_petrobras, valor_lojasrenner, valor_vivo, preco_por_pedido; //Declaração das variáveis intermediárias e de saída FLOAT
    int verificacao; //Declaração de variável de entrada


    valor = ZERO; //Valor inicial arrecado é ZERO
    pedidos = NUMERO_UM; //Atribuição de 1 à variável pedidos
    quantidade_total = ZERO; //Atribuição de 0 à variável quantidade_total

    e_vivo = Q_INICIAL_VIVO; //Atribuição do número de ações VIVO disponíveis
    e_gerdau = Q_INICIAL_GERDAU; //Atribuição do número de ações GERDAU disponíveis
    e_petrobras = Q_INICIAL_PETROBRAS; //Atribuição do número de ações PETROBRAS disponíveis
    e_lojasrenner = Q_INICIAL_LOJASRENNER; //Atribuição do número de ações LOJAS RENNER disponíveis

    q_gerdau = ZERO; //Atribuição do valor 0 á variável q_gerdau
    q_petrobras = ZERO; //Atribuição do valor 0 á variável q_petrobras
    q_lojasrenner = ZERO; //Atribuição do valor 0 á variável q_lojasrenner
    q_vivo = ZERO; //Atribuição do valor 0 á variável q_vivo

    while(verificacao == ZERO) //Executar enquanto o usuário manter a condição no final de cada laço
    {
        preco_por_pedido = ZERO; //Zerar a cada laço, principalmente para uso quando estoque é 0.
        /*
        TABELA QUE APRESENTA AS AÇÕES, SEUS RESPECTIVOS CODIGOS E VALORES, ALÉM DA QUANTIDADE DISPONÍVEL
        */
        printf("\n-------------------------------------------------");
        printf("\n|%30s%2d%16s\n", "PEDIDO NUMERO ", pedidos, "|");
        printf("-------------------------------------------------");
        printf("\n|%-10s|%-12s|%-10s|%-12s|\n", "CODIGO", "OPCAO", "DISPONIVEL", "VALOR");
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_GERDAU, "Gerdau", e_gerdau, P_GERDAU);
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_PETROBRAS, "Petrobras", e_petrobras, P_PETROBRAS);
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_LOJASRENNER, "Lojas Renner", e_lojasrenner, P_LOJASRENNER);
        printf("|%-10d|%-12s|%-10d|R$%-10.2f|\n", C_VIVO, "Vivo", e_vivo, P_VIVO);
        printf("-------------------------------------------------");


        printf("\nDigite o codigo valido da acao que deseje comprar: ");
        scanf("%d",&codigo);//Ler o codigo da ação desejada

        printf("\nDigite a quantidade desejada de acoes: ");
        scanf("%d",&quantidade); //Ler a quantidade desejada



        switch(codigo) //Comando de seleção múltipla para o codigo digitado pelo usuário
        {

        case C_GERDAU:

            if (e_gerdau == ZERO) //Condição para quando não há estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de GERDAU\n\n"); //Exibe mensagem de que não há estoque
                break; //Encerra o switch, não computando compra
            }

            while(quantidade > e_gerdau) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes.\n", e_gerdau); //Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_gerdau += quantidade; //Adiciona quantidade na variável de quantidade vendida de Gerdau
            e_gerdau -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_gerdau += (P_GERDAU * quantidade); //Adiciona ao valor arrecadado em GERDAU a multiplicação da quantidade selecionada e o valor unitário da ação
            preco_por_pedido = (P_GERDAU * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        case C_PETROBRAS:

            if (e_petrobras == ZERO) //Condição para quando não há estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de PETROBRAS\n\n"); //Exibe mensagem de que não há estoque
                break; //Encerra o switch, não computando compra
            }

            while(quantidade > e_petrobras) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_petrobras);//Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_petrobras += quantidade; //Adiciona quantidade na variável de quantidade vendida de Petrobras
            e_petrobras -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_petrobras += (P_PETROBRAS*quantidade); //Adiciona ao valor arrecadado em PETROBRAS a multiplicação da quantidade selecionada e o valor unitário da ação
            preco_por_pedido = (P_PETROBRAS * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        case C_LOJASRENNER:

            if (e_lojasrenner == ZERO) //Condição para quando não há estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de LOJAS RENNER\n\n"); //Exibe mensagem de que não há estoque
                break; //Encerra o switch, não computando compra
            }

            while (quantidade > e_lojasrenner) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_lojasrenner);//Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_lojasrenner += quantidade; //Adiciona quantidade na variável de quantidade vendida de Lojas Renner
            e_lojasrenner -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_lojasrenner += (P_LOJASRENNER*quantidade); //Adiciona ao valor arrecadado em LOJAS RENNER a multiplicação da quantidade selecionada e o valor unitário da ação
            preco_por_pedido = (P_LOJASRENNER * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        case C_VIVO:

            if (e_vivo == ZERO) //Condição para quando não há estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de VIVO\n\n"); //Exibe mensagem de que não há estoque
                break; //Encerra o switch, não computando compra
            }

            while (quantidade > e_vivo) //Comando de repetição para o cliente colocar a quantidade novamente caso escolha uma indisponível
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_vivo);//Mensagem de erro caso a quantidade desejada esteja indisponível
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_vivo += quantidade; //Adiciona quantidade na variável de quantidade vendida de Vivo
            e_vivo -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_vivo += (P_VIVO*quantidade); //Adiciona ao valor arrecadado em VIVO a multiplicação da quantidade selecionada e o valor unitário da ação
            preco_por_pedido = (P_VIVO * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        default:

            system("cls"); //Limpa a tela
            printf("\nERRO, VOCE DIGITOU UM CODIGO INVALIDO.\n\n"); //Mensagem de erro caso seja um código inválido
            break;//Encerra o SWITCH

        }

        system("cls"); //Limpa a tela para aparecer a nota do pedido e a varificação de continuidade.

        /*
        O print abaixo mostra qual era o pedido, exibindo o código da ação, a quantidade e o valor a se pagar.
        */

        printf("\n\t PEDIDO NUMERO %d\n\nCODIGO: %d\nQUANTIDADE: %d\nVALOR: R$%.2f\n\n", pedidos, codigo, quantidade, preco_por_pedido);

        quantidade_total += quantidade; //Adiciona a quantidade do pedido à quantidade total para o calculo da media das vendas
        pedidos = pedidos + NUMERO_UM; //Para identificar cada um dos pedidos

        printf("Digite 0 caso queira continuar comprando, ou 1, caso queira encerrar a compra: ");
        scanf("%d", &verificacao); //Verifica se a pessoa quer ou não continuar com o pedido.


    }


    system("cls"); //Limpa a tela para a tabela do stock market
    valor += valor_gerdau; //Atribuição do valor de GERDAU vendidas para o geral
    valor += valor_petrobras; //Atribuição do valor de PETROBRAS vendidas para o geral
    valor += valor_lojasrenner; //Atribuição do valor de LOJAS RENNER vendidas para o geral
    valor += valor_vivo; //Atribuição do valor de VIVO vendidas para o geral

    /*
    TABELA DE EXIBIÇÃO DO RELATORIO DE VENDAS DO DIA
    */
    printf("\nRELATORIO DE VENDAS DO DIA\n");
    printf("%-16s%-17s%-14s\n", "Acao", "Quantidade", "Total faturado");
    /*
    Parte da tabela que exibe as quantidades e o valor especifico comprados por empresa
    */
    printf("%-16s%10d%9s  %-9.2f\n", "Gerdau", q_gerdau,"R$", valor_gerdau); //Linha da tabela com dados da Gerdau
    printf("%-16s%10d%9s  %-9.2f\n", "Petrobras", q_petrobras, "R$", valor_petrobras); //Linha da tabela com dados da Petrobras
    printf("%-16s%10d%9s  %-9.2f\n", "Lojas Renner", q_lojasrenner, "R$", valor_lojasrenner); //Linha da tabela com dados das Lojas Renner
    printf("%-16s%10d%9s  %-9.2f\n", "Vivo", q_vivo, "R$", valor_vivo); //Linha da tabela com dados da Vivo
    /*
    Parte da tabela que exibe o total arrecado com vendas
    */
    printf("%-26s%9s  %-9.2f\n", "TOTAL DE VENDAS DO DIA", "R$", valor);


    return(0); //Encerra o programa
}
