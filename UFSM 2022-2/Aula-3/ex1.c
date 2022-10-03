#include <stdio.h>

int main(){

    float cateto_a, cateto_b, area;

    printf("\nValor do cateto A: ");
    scanf("%f", &cateto_a);

    printf("\nValor do cateto B: ");
    scanf("%f", &cateto_b);

    area = cateto_a * cateto_b / 2;

    printf("\nValor da area: %.2f", area);
    return 0;
}
