/*
Este programa cria codigos, quantidades e precos para 4 acoes de forma aleatoria em toda execu��o,
cabe ao usu�rio executar pedidos de compra at� o valor exceder 10 mil reais.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMAC 4 //Tamanho dos arranjos
#define ZERO 0 //Constante 0
#define UM 1 //Constante 1
#define DOIS 2 //Constante 2
#define TRES 3 //Constante 3

#define MAX_CODIGO 50 //Valor maximo do codigo a ser gerado
#define MAX_INICIAL 10000 //Valor maximo da quantidade a ser gerada
#define MAX_PRECO 100.00 //Valor maximo do preco a ser gerado
#define FINAL_DO_LACO 10000.00 //Valor do final do laco

int main()
{
    int codigo[NUMAC], qtade_inicial[NUMAC], qtade_vendida[NUMAC] = {ZERO}; //Declara��o dos arranjos usados de forma intermedi�ria e de sa�da
    float preco[NUMAC], valor_total, valor, valor_unitario[NUMAC] = {ZERO}; //Declara��o dos arranjos e vari�veis usadas de forma intermedi�ria e de sa�da
    int i, pedido_c, pedido_q, marcador, mais_vendida, maior; //Declara��o das vari�veis int de entrada e sa�da.

    srand(time(ZERO)); //Gera uma nova cadeia de n�meros aleat�rios

    for (i = ZERO; i < NUMAC; i++) //Comando de repeti��o que gera valores aleat�rios para codigo, quantidade e preco
    {
        codigo[i] = (int) (rand() / (double) RAND_MAX * (MAX_CODIGO + 1)); //Cria um codigo aleatorio de 0 a 50
        qtade_inicial[i] =(int) (rand() / (double) RAND_MAX * (MAX_INICIAL + 1)); //Cria uma quantidade aleatoria de 0 a 10000
        preco[i] = (float) (rand() / (double) RAND_MAX * (MAX_PRECO + 1)); //Cria um preco aleatorio de 0 a 100
    }

    i = ZERO; //i vale 0
    marcador = ZERO; //marcador vale 0

    while(valor_total < FINAL_DO_LACO) //La�o de execu��o da venda
    {
        i++; //i usado para identificar o pedido

        /*
        Tabela que exibe a quantidade disponivel, o valor e o codigo da a��o.
        Ela usa os termos de arranjos para preenche-la
        */
        printf("\n%25s%d\n", "PEDIDO ", i);
        printf("\n%-15s%-15s%-15s\n", "CodigoAcao", "Estoque", "Valor(R$)");
        printf("\n%-3s%-10d%-5s%-10d%-5s%-10.2f", " ", codigo[ZERO], " ", qtade_inicial[ZERO], " ", preco[ZERO] );
        printf("\n%-3s%-10d%-5s%-10d%-5s%-10.2f", " ", codigo[UM], " ", qtade_inicial[UM], " ", preco[UM] );
        printf("\n%-3s%-10d%-5s%-10d%-5s%-10.2f", " ", codigo[DOIS], " ", qtade_inicial[DOIS], " ", preco[DOIS] );
        printf("\n%-3s%-10d%-5s%-10d%-5s%-10.2f\n", " ", codigo[TRES], " ", qtade_inicial[TRES], " ", preco[TRES] );

        printf("\nDigite o codigo da acao que deseja comprar: ");
        scanf("%d", &pedido_c); //Recebe o codigo de compra desejada
        printf("\nDigite a quantidade de acoes que deseja comprar: ");
        scanf("%d", &pedido_q); //Recebe a quantidade de compra desejada

        /*
        Sequ�ncia de comandos condicionais para identificar a vari�vel marcador
        que vai ser usada na identifica��o e altera��o de valores que est�o den-
        tro de arranjos
        */
        if(pedido_c == codigo[ZERO])
            marcador = ZERO;
        else
        {
            if(pedido_c == codigo[UM])
                marcador = UM;
            else
            {
                if(pedido_c == codigo[DOIS])
                    marcador = DOIS;
                else
                    marcador = TRES;
            }

        }
        /*
        Comandos para quando codigo e quantidade est�o adequados
        */
        if( pedido_q <= qtade_inicial && pedido_c == codigo[marcador])
        {
            valor = pedido_q * preco[marcador]; //Calcula o valor do pedido
            qtade_inicial[marcador] -= pedido_q; //Diminui da quantidade total a quantidade do pedido
            qtade_vendida[marcador] += pedido_q; //Adiciona a quantidade do pedido � quantidade vendida
            valor_total += valor; //Atribui o valor do pedido ao valor total
            valor_unitario[marcador] += valor; //Atribui o valor do pedido ao valor total de venda da a�ao
            system("cls"); //Limpa a tela
            printf("\tPedido %d\nCodigo: %d\nQuantidade: %d\nValor a pagar: R$%.2f\n\n", i, pedido_c, pedido_q, valor); //Dados do pedido
        }
        /*
        Comandos quando o codigo ou a quantidade n�o est�o adequados
        */
        else
        {
            system("cls"); //Limpa a tela
            printf("Faca novamente o pedido, voce escolheu um codigo ou quantidade nao disponivel\n"); //Mensagem de erro
        }
    }
    /*
    Definindo a a��o que mais foi vendida em quantidade
    */
    maior = qtade_vendida[ZERO];
    for(i = ZERO; i <= TRES; i++)
        if(qtade_vendida[i] > maior)
        {
            maior = qtade_vendida[i];
            mais_vendida = i;
        }
    /*
    Tabela final contendo a quantidade comprada, valor total por a��o, e valor total,
    al�m da a��o mais comprada em quantidade
    */
    printf("RELATORIO DE VENDAS DO DIA\n");
    printf("%-20s%-15s%-15s\n", "Codigo da Acao", "Quantidade", "Total Faturado");
    for(i = ZERO; i <= TRES; i++)//Comando repetitivo para formar a tabela
    {
        if (qtade_vendida[i] > ZERO)//Para n�o mostrar quando n�o houve a��o comprada
            printf("%-20d%-15dR$ %-13.2f\n", codigo[i], qtade_vendida[i], valor_unitario[i]);
    }
    printf("\n\n%-35sR$ %-13.2f\n", "TOTAL DE VENDAS DO DIA", valor_total);
    printf("\n%-43s%d\n\n", "CODIGO DA ACAO MAIS VENDIDA", codigo[mais_vendida]);



    return(ZERO);//Encerra a fun��o

}
