/* Este programa calcula e imprime o sal�rio bruto a ser recebido por um
funcion�rio no m�s*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    int filhos, horas;//Declara��o da vari�vel com os par�metros
    float vhora; //Declara��o da vari�vel com os par�metros
     //Declara��o da vari�vel com os par�metros
    float salario; //Declara��o da vari�vel com o resultado
    printf("Numero de horas trabalhadas no mes:\n");
    scanf("%d",&horas);
    printf("Indique o seu salario por horas trabalhadas:\n");//Deixei apenas a vari�vel "vhora" como float por n�o precisar ser necessariamente um n�mero inteiro
    scanf("%f",&vhora);
    printf("Indique o n�mero de filhos que voce possui com menos de 14 anos:\n");
    scanf("%d",&filhos);
    salario =(horas * vhora + filhos * 50);//Usei 50 reais como sal�rio fam�lia
    printf("O seu salario no mes foi:%1.2f R$",salario); //Usei o 1.2f para deixar apenas duas casas decimais
    return(0);
}
