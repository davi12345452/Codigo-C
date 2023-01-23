/*
Trabalho 2
Davi Jansich Maia
SI 1 2022/2
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


/*
    As duas funções a seguir foram retiradas da aula.
*/
double fat(int n)
{
    double f = 1;
    double valor = n;
    for (int i=0; i<n; i++) {
    f *= valor;
    valor--;
    }
    return f;
}


double xnan(double x, int n)
{
    double p = 1;
    for (int i=0; i<n; i++) {
        p *= x;
    }
    return p;
}

/*
    Função que calcula e^x
*/

double enax(double x)
{   double soma = 1, valor;
    int expoente = 1;

    while(true){
        valor = xnan(x, expoente) / fat(expoente);
        soma += valor;
        if(valor < 1e-7){
            break;
        }
        expoente += 1;
    }
    return soma;
}

/*
    Função que calcula ln((x+1))
*/
double ln_xmais1(double x)
{
    double soma = 0, valor;
    int expoente = 2;
    soma += x;

    while(true){

        valor = xnan(x, expoente)/expoente;

        if(expoente % 2 == 1){
            soma += valor;
        }else{
            soma -= valor;
        }

        expoente++;

        if(valor < 1e-7){
            break;
        }
    }

    return soma;
}

/*
    Função fornecida pelo professor que calcula ln(x)
*/

double ln(double x)
{
    int n=0;
    double y=x;
    while (y>1.35) {
        y/=2;
        n++;
    }
    while (y<0.65) {
        y*=2;
        n--;
    }
    double ln2 = ln_xmais1(0.5)+ln_xmais1(1.0/3.0);
    return ln_xmais1(y-1) + n*ln2;
}

/*
    Função que calcula x^y a partir de e^(y * ln(x))
*/
double xnay(double x, double y)
{
    double valor, expoenteEnax;
    expoenteEnax = y * ln(x);
    valor = enax(expoenteEnax);
    return valor;
}

/*
    Função main fornecida pelo professor, somente incorporei os testes.
*/
int main(void)
{
    double a = 19.42;
    double rc = xnay(a, 1.0/3.0);
    double b = rc*rc*rc;
    printf("%lf deve ser parecido com %lf\n", a, b);
    /*
        Teste das funções intermediárias enax, ln_xmais1 e xnay
    */
    printf("e^4 => %lf = %lf\n",exp(4), enax(4));
    printf("ln(1 + 0.3) => %lf = %lf\n",log(1.3), ln_xmais1(0.3));
    printf("8^3 => %lf = %lf\n",pow(8, 3), xnay(8, 3));
    return 0;
}
