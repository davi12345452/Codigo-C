#include <stdio.h>

int main(){

    int ano_atual, ano_nasc;

    printf("Ano atual: ");
    scanf("%d", &ano_atual);

    printf("Ano nascimento: ");
    scanf("%d", &ano_nasc);

    printf("Idade: %d", ano_atual-ano_nasc);
    return 0;
}
