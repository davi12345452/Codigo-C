#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool primo(num){
    int i, contador = 0;
    for(i = 1; i <= num; i++){
        if(num % i == 0){
            contador += 1;
        }
    }

    if(contador == 2){
        return true;
    }else{
        return false;
    }
}

int proximoPrimo(num){
    int proximoPrimo;
    proximoPrimo = num;

    while(true){
        proximoPrimo += 1;
        if(primo(proximoPrimo) == true){
            return proximoPrimo;
        }
    }
}

int main(){

    int numero, primoSeguinte;
    while(true){
        printf("\nDigite um numero primo: ");
        scanf("%d", &numero);
        if(primo(numero) == true){
            break;
        }else{
            printf("\nVoce nao digitou um numero primo, digite novamente...");
        }
    }

    primoSeguinte = proximoPrimo(numero);
    printf("\nO proximo primo e: %d", primoSeguinte);
    return 0;
}
