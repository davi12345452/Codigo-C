#include <stdio.h>

int main(){

    int kg_laranja, custo_lucro, q_suco;
    int valor_final;

    printf("Custo do kg de laranja em R$: ");
    scanf("%d", &kg_laranja);

    printf("Quantidade de suco em 1kg de laranja em ml: ");
    scanf("%d", &q_suco);

    printf("Custo da mão de obra, mais lucro em 1 litro de suco em R$: ");
    scanf("%d", &custo_lucro);

    valor_final = kg_laranja * 1000 / q_suco + custo_lucro;

    printf("Valor final: R$%d", valor_final);

    return 0;
}
