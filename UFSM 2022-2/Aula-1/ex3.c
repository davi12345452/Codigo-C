#include <stdio.h>

/*
Fa�a um programa para calcular e imprimir o valor de um litro de suco de laranja. Esse programa deve inicializar uma
vari�vel com o custo de um quilo de laranja (20), outra com a quantidade de suco, em ml, extra�vel de um quilo (800),
outra com o custo da m�o de obra mais lucro para produzir um litro de suco (14).
*/

int main(){

    int v_laranja = 20;
    int q_suco = 800;
    int custo_lucro = 14;

    int valor_final;

    valor_final = v_laranja * 1000 / q_suco + custo_lucro;

    printf("Valor do litro de suco: R$ %d", valor_final);

    return 0;
}
