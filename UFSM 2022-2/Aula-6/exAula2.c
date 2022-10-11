#include <stdio.h>
#include <stdbool.h>

int main(){
    int cont, somador, numero;
    int verificador;
    float media;

    somador = 0;
    cont = 0;

    while(true){
        printf("\nDigite um numero: ");
        scanf("%d", &numero);

        somador += numero;
        cont += 1;

        printf("Deseja parar?(Digite 1 se sim)");
        scanf("%d", &verificador);

        if(verificador == 1){
            break;
        }
    }

    media = somador / cont;

    printf("A media dos valores digitados e: %f", media);
    return 0;
}
