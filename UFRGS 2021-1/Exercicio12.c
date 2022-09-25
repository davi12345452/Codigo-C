/*
Fazer um programa que calcule o resultado final das eleições para a presidência de um clube,
sabendo-se que irão votar um numero desconhecido de membros. São 3 chapas concorrendo e os
eleitores votam indicando o numero (inteiro) da chapa escolhida.  No inicio da votação não
sabe quantos associados vao aparecer para votar.
*/

#include <stdio.h>
#include <stdlib.h>
#define CHAPA_UM 1 //constante do código da chapa 1
#define CHAPA_DOIS 2 //constante do código da chapa 2
#define CHAPA_TRES 3 // constante do código da chapa 3
#define VOTO_BRANCO 0 // constante do código do voto em branco
#define NUMERO_UM 1 // Constante 1 para não misturar com a constante do código chapa 1
#define NUMERO_ZERO 0 // Constante 0 para não misturar com a constante do código chapa 1


int main ()
{
    int chapa_um, chapa_dois, chapa_tres, chapa_nulo, chapa_branco; //Declaração das variáveis de saída
    int booleano, voto, cadastro; //Declaração das variáveis intermediárias e de entrada

    booleano = NUMERO_UM; //Atribuição do valor 1 à variável "booleano"
    chapa_um = NUMERO_ZERO; //Atribuição do valor 0 à variável "chapa_um"
    chapa_dois = NUMERO_ZERO; //Atribuição do valor 0 à variável "chapa_dois"
    chapa_tres = NUMERO_ZERO; //Atribuição do valor 0 à variável "chapa_tres"
    chapa_nulo = NUMERO_ZERO; //Atribuição do valor 0 à variável "chapa_nulo"
    chapa_branco = NUMERO_ZERO; //Atribuição do valor 0 à variável "chapa_branco"


    while (booleano) //Início da estrutura de repetição While, com booleano = 1 como condição de repetição
    {
        /*
        Tabela que exibe os tipos de votos e seus respectivos códigos
        */
        printf("\nSEJAM BEM VINDOS A VOTACAO!\n\n");
        printf("|%-25s|%-21s|\n", "Para...", "Digite codigo");
        printf("|%-25s|%-21d|\n", "Votar CHAPA 1", CHAPA_UM);
        printf("|%-25s|%-21d|\n", "Votar CHAPA 2", CHAPA_DOIS);
        printf("|%-25s|%-21d|\n", "Votar CHAPA 3", CHAPA_TRES);
        printf("|%-25s|%-21d|\n", "Votar EM BRANCO", VOTO_BRANCO);
        printf("|%-25s|%-21s|\n", "Votar NULO", "Qualquer outro numero");

        printf("\nDIGITE AQUI O SEU VOTO: ");
        scanf("%d", &voto);//Leitura do voto escolhido pelo usuário

        /*
        Estrutura condicional que busca atribuir os votos e acumulá-los
        nas variáveis específicas de cada tipo de voto
        */
        switch(voto)
        {
        case VOTO_BRANCO: // Caso voto = 0
            chapa_branco = chapa_branco + NUMERO_UM;//Atribuir mais um à variável chapa_branco
            break; //Encerra a estrutura condicional
        case CHAPA_UM: // Caso voto = 1
            chapa_um = chapa_um + NUMERO_UM;//Atribuir mais um à variável chapa_um
            break; //Encerra a estrutura condicional
        case CHAPA_DOIS: // Caso voto = 2
            chapa_dois = chapa_dois + NUMERO_UM;//Atribuir mais um à variável chapa_dois
            break; //Encerra a estrutura condicional
        case CHAPA_TRES: // Caso voto = 3
            chapa_tres = chapa_tres + NUMERO_UM;//Atribuir mais um à variável chapa_tres
            break; //Encerra a estrutura condicional
        default: // Caso voto for diferente de 0, 1, 2 e 3
            chapa_nulo = chapa_nulo + NUMERO_UM; //Atribuir mais um à variável chapa_nulo
            break; //Encerra a estrutura condicional
        }

        system("cls"); //Limpa a tela
        printf("\nDigite 0 caso queira encerrar o programa, ou outro numero se quiser cadastrar mais votos:  ");
        scanf("%d", &cadastro); //Leitura da variável cadastro que será usada para continuar ou para o While
        system("cls"); //Limpa a tela

        if (cadastro == NUMERO_ZERO) //Estrutura condicional caso cadastro seja igual a 0
            booleano = NUMERO_ZERO; //Atribuição de 0 à variável "booleano", o que encerra o comando de repetição While(booleano)


    }

    /*
    Tabela do resultado da eleição, exibe os apenas o tipo de voto
    e a quantidade de votos recebidas
    */
    printf("\t RESULTADO DA VOTACAO:\n\n");
    printf("|%-20s|%-20s|\n", "Tipo de voto", "Quantidade de votos");
    printf("|%-20s|%-20d|\n", "Chapa 1", chapa_um);
    printf("|%-20s|%-20d|\n", "Chapa 2", chapa_dois);
    printf("|%-20s|%-20d|\n", "Chapa 3", chapa_tres);
    printf("|%-20s|%-20d|\n", "Votos em Branco", chapa_branco);
    printf("|%-20s|%-20d|\n", "Votos Nulos", chapa_nulo);


    if ((chapa_um > chapa_dois) && (chapa_um > chapa_tres)) //Condição para chapa 1 vencedora
    {
        if (chapa_um > (chapa_dois + chapa_tres)) //Condição para chapa 1 vencdora no primeiro turno
            printf("\nA chapa 1 ganhou no primeiro turno");
        else //Condição para chapa 1 vencedora, porém necessita de segundo turno
            printf("\nSera necessario um segundo turno");
    }
    else
    {
        if ((chapa_dois > chapa_um) && (chapa_dois > chapa_tres))//Condição para chapa 2 vencedora
        {
            if (chapa_dois > (chapa_um + chapa_tres))//Condição para chapa 2 vencdora no primeiro turno
                printf("\nA chapa 2 ganhou no primeiro turno");
            else//Condição para chapa 2 vencedora, porém necessita de segundo turno
                printf("\nSera necessario um segundo turno");
        }
        else
        {
            if ((chapa_tres > chapa_dois) && (chapa_tres > chapa_um))//Condição para chapa 3 vencedora
            {
                if (chapa_tres > (chapa_dois + chapa_um))//Condição para chapa 3 vencdora no primeiro turno
                    printf("\nA chapa 3 ganhou no primeiro turno");
                else //Condição para chapa 3 vencedora, porém necessita de segundo turno
                    printf("\nSera necessario um segundo turno");
            }
            else //Condição caso haja empate entre duas ou entre as tres chapas
                printf("\nHouve um empate\n");

        }


    }
    return(0);//Encerra o programa
}
