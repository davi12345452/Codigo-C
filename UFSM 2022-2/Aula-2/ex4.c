#include <stdio.h>

int main (){
    float t_tanque, v_diesel;

    printf("Valor do diesel em R$: ");
    scanf("%f", &v_diesel);

    printf("Capacidade do tanque em litros: ");
    scanf("%f", &t_tanque);

    printf("Valor a pagar pelo tanque cheio: R$%.2f", v_diesel*t_tanque);

    return 0;
}
