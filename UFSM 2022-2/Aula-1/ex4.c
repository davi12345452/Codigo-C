#include <stdio.h>

/*Faça um programa para calcular o valor necessário para encher o tanque inicialmente vazio*/

int main(){

    float t_tanque = 333.00;
    float v_litro = 6.66;

    float valor;

    valor = t_tanque * v_litro;

    printf("Valor para encher tanque: R$%.2f", valor);
    return 0;
}
