/* Este programa calcula e imprime o salário bruto a ser recebido por um
funcionário no mês*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    int filhos, horas;//Declaração da variável com os parâmetros
    float vhora; //Declaração da variável com os parâmetros
     //Declaração da variável com os parâmetros
    float salario; //Declaração da variável com o resultado
    printf("Numero de horas trabalhadas no mes:\n");
    scanf("%d",&horas);
    printf("Indique o seu salario por horas trabalhadas:\n");//Deixei apenas a variável "vhora" como float por não precisar ser necessariamente um número inteiro
    scanf("%f",&vhora);
    printf("Indique o número de filhos que voce possui com menos de 14 anos:\n");
    scanf("%d",&filhos);
    salario =(horas * vhora + filhos * 50);//Usei 50 reais como salário família
    printf("O seu salario no mes foi:%1.2f R$",salario); //Usei o 1.2f para deixar apenas duas casas decimais
    return(0);
}
