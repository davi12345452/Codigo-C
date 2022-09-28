#include <stdio.h>

int main(){

    int idade;
    char nome[10];

    printf("Nome: ");
    scanf("%s", &nome);

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Meu nome e %s e tenho %d anos", nome, idade);
    return 0;
}
