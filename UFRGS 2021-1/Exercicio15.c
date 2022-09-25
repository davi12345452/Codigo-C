/*
Este programa ele oferta 4 tipos de a��es, com quantidade e valores, cabe ao usu�rio escolher um c�digo
de a��o e uma quantidade, no final, caso haja estoque e a opera��o seja efetuada, cabe ao usu�rio escolher
se quer fazer mais compras ou n�o (Ele pode comprar infinitamente, desde que haja estoque). No final, o
programa exibe um relat�rio mostrando a quantidade vendida e o valor total arrecadado.
*/

#include <stdio.h>
#include <stdlib.h>


#define P_GERDAU 14.0 //Constante pre�o unit�rio da a��o GERDAU
#define P_PETROBRAS 2.5 //Constante pre�o unit�rio da a��o PETROBRAS
#define P_LOJASRENNER 1.2 //Constante pre�o unit�rio da a��o LOJASRENNER
#define P_VIVO 2.2 //Constante pre�o unit�rio da a��o VIVO


#define Q_INICIAL_VIVO 500 //Constante valor da quantidade incial de a��es Vivo
#define Q_INICIAL_GERDAU 10000 //Constante valor da quantidade incial de a��es Gerdau
#define Q_INICIAL_PETROBRAS 2000 //Constante valor da quantidade incial de a��es Petrobras
#define Q_INICIAL_LOJASRENNER 5000 //Constante valor da quantidade incial de a��es Lojas Renner
#define ZERO 0 //Constante valor 0


#define C_GERDAU 1 //Constante c�digo de Gerdau
#define C_PETROBRAS 2 //Constante c�digo de Petrobras
#define C_LOJASRENNER 3 //Constante c�digo de Lojas Renner
#define C_VIVO 4 //Constante c�digo de Grendene

#define PEDIDOS 5 //Constante usada no FOR
#define NUMERO_UM 1 //Constante do n�mero 1
#define NUMERO_QUATRO 4 //Constante do n�mero 4



int main()
{
    int codigo, quantidade, pedidos; //Declara��o das vari�veis de entrada INT
    int e_vivo, e_gerdau, e_petrobras, e_lojasrenner; //Declara��o das vari�veis intermedi�rias e de sa�da INT
    int quantidade_total, q_gerdau, q_petrobras, q_lojasrenner, q_vivo; //Declara��o das vari�veis intermedi�rias e de sa�da INT
    float valor, valor_gerdau, valor_petrobras, valor_lojasrenner, valor_vivo, preco_por_pedido; //Declara��o das vari�veis intermedi�rias e de sa�da FLOAT
    int verificacao; //Declara��o de vari�vel de entrada


    valor = ZERO; //Valor inicial arrecado � ZERO
    pedidos = NUMERO_UM; //Atribui��o de 1 � vari�vel pedidos
    quantidade_total = ZERO; //Atribui��o de 0 � vari�vel quantidade_total

    e_vivo = Q_INICIAL_VIVO; //Atribui��o do n�mero de a��es VIVO dispon�veis
    e_gerdau = Q_INICIAL_GERDAU; //Atribui��o do n�mero de a��es GERDAU dispon�veis
    e_petrobras = Q_INICIAL_PETROBRAS; //Atribui��o do n�mero de a��es PETROBRAS dispon�veis
    e_lojasrenner = Q_INICIAL_LOJASRENNER; //Atribui��o do n�mero de a��es LOJAS RENNER dispon�veis

    q_gerdau = ZERO; //Atribui��o do valor 0 � vari�vel q_gerdau
    q_petrobras = ZERO; //Atribui��o do valor 0 � vari�vel q_petrobras
    q_lojasrenner = ZERO; //Atribui��o do valor 0 � vari�vel q_lojasrenner
    q_vivo = ZERO; //Atribui��o do valor 0 � vari�vel q_vivo

    while(verificacao == ZERO) //Executar enquanto o usu�rio manter a condi��o no final de cada la�o
    {
        preco_por_pedido = ZERO; //Zerar a cada la�o, principalmente para uso quando estoque � 0.
        /*
        TABELA QUE APRESENTA AS A��ES, SEUS RESPECTIVOS CODIGOS E VALORES, AL�M DA QUANTIDADE DISPON�VEL
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
        scanf("%d",&codigo);//Ler o codigo da a��o desejada

        printf("\nDigite a quantidade desejada de acoes: ");
        scanf("%d",&quantidade); //Ler a quantidade desejada



        switch(codigo) //Comando de sele��o m�ltipla para o codigo digitado pelo usu�rio
        {

        case C_GERDAU:

            if (e_gerdau == ZERO) //Condi��o para quando n�o h� estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de GERDAU\n\n"); //Exibe mensagem de que n�o h� estoque
                break; //Encerra o switch, n�o computando compra
            }

            while(quantidade > e_gerdau) //Comando de repeti��o para o cliente colocar a quantidade novamente caso escolha uma indispon�vel
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes.\n", e_gerdau); //Mensagem de erro caso a quantidade desejada esteja indispon�vel
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_gerdau += quantidade; //Adiciona quantidade na vari�vel de quantidade vendida de Gerdau
            e_gerdau -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_gerdau += (P_GERDAU * quantidade); //Adiciona ao valor arrecadado em GERDAU a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
            preco_por_pedido = (P_GERDAU * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        case C_PETROBRAS:

            if (e_petrobras == ZERO) //Condi��o para quando n�o h� estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de PETROBRAS\n\n"); //Exibe mensagem de que n�o h� estoque
                break; //Encerra o switch, n�o computando compra
            }

            while(quantidade > e_petrobras) //Comando de repeti��o para o cliente colocar a quantidade novamente caso escolha uma indispon�vel
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_petrobras);//Mensagem de erro caso a quantidade desejada esteja indispon�vel
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_petrobras += quantidade; //Adiciona quantidade na vari�vel de quantidade vendida de Petrobras
            e_petrobras -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_petrobras += (P_PETROBRAS*quantidade); //Adiciona ao valor arrecadado em PETROBRAS a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
            preco_por_pedido = (P_PETROBRAS * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        case C_LOJASRENNER:

            if (e_lojasrenner == ZERO) //Condi��o para quando n�o h� estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de LOJAS RENNER\n\n"); //Exibe mensagem de que n�o h� estoque
                break; //Encerra o switch, n�o computando compra
            }

            while (quantidade > e_lojasrenner) //Comando de repeti��o para o cliente colocar a quantidade novamente caso escolha uma indispon�vel
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_lojasrenner);//Mensagem de erro caso a quantidade desejada esteja indispon�vel
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_lojasrenner += quantidade; //Adiciona quantidade na vari�vel de quantidade vendida de Lojas Renner
            e_lojasrenner -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_lojasrenner += (P_LOJASRENNER*quantidade); //Adiciona ao valor arrecadado em LOJAS RENNER a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
            preco_por_pedido = (P_LOJASRENNER * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        case C_VIVO:

            if (e_vivo == ZERO) //Condi��o para quando n�o h� estoque
            {
                system("cls");
                printf("\nNao ha estoque suficiente de VIVO\n\n"); //Exibe mensagem de que n�o h� estoque
                break; //Encerra o switch, n�o computando compra
            }

            while (quantidade > e_vivo) //Comando de repeti��o para o cliente colocar a quantidade novamente caso escolha uma indispon�vel
            {
                printf("\nERRO, a quantidade disponivel e de %d acoes\n ", e_vivo);//Mensagem de erro caso a quantidade desejada esteja indispon�vel
                printf("Digite novamente a quantidade desejada: ");
                scanf("%d", &quantidade);
            }

            q_vivo += quantidade; //Adiciona quantidade na vari�vel de quantidade vendida de Vivo
            e_vivo -= quantidade; //Subtrai a quantidade desejada do estoque
            valor_vivo += (P_VIVO*quantidade); //Adiciona ao valor arrecadado em VIVO a multiplica��o da quantidade selecionada e o valor unit�rio da a��o
            preco_por_pedido = (P_VIVO * quantidade); //Valor a ser imprimido na nota do pedido
            break; //Encerra o SWITCH



        default:

            system("cls"); //Limpa a tela
            printf("\nERRO, VOCE DIGITOU UM CODIGO INVALIDO.\n\n"); //Mensagem de erro caso seja um c�digo inv�lido
            break;//Encerra o SWITCH

        }

        system("cls"); //Limpa a tela para aparecer a nota do pedido e a varifica��o de continuidade.

        /*
        O print abaixo mostra qual era o pedido, exibindo o c�digo da a��o, a quantidade e o valor a se pagar.
        */

        printf("\n\t PEDIDO NUMERO %d\n\nCODIGO: %d\nQUANTIDADE: %d\nVALOR: R$%.2f\n\n", pedidos, codigo, quantidade, preco_por_pedido);

        quantidade_total += quantidade; //Adiciona a quantidade do pedido � quantidade total para o calculo da media das vendas
        pedidos = pedidos + NUMERO_UM; //Para identificar cada um dos pedidos

        printf("Digite 0 caso queira continuar comprando, ou 1, caso queira encerrar a compra: ");
        scanf("%d", &verificacao); //Verifica se a pessoa quer ou n�o continuar com o pedido.


    }


    system("cls"); //Limpa a tela para a tabela do stock market
    valor += valor_gerdau; //Atribui��o do valor de GERDAU vendidas para o geral
    valor += valor_petrobras; //Atribui��o do valor de PETROBRAS vendidas para o geral
    valor += valor_lojasrenner; //Atribui��o do valor de LOJAS RENNER vendidas para o geral
    valor += valor_vivo; //Atribui��o do valor de VIVO vendidas para o geral

    /*
    TABELA DE EXIBI��O DO RELATORIO DE VENDAS DO DIA
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
