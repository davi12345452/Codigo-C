#include <stdio.h>
#include <math.h>

int main(){

    float altura, peso;
    float imc;

    printf("\nIndique sua altura em m: ");
    scanf("%f", &altura);

    printf("\nIndique seu peso em kg: ");
    scanf("%f", &peso);

    imc = (peso/pow(altura, 2));

    if(imc < 18.5) {
        printf("\nSeu imc e %f, voce esta abaixo do peso ideal\n", imc);
    }else if(imc < 24.9) {
        printf("\nSeu imc e %f, voce esta normal\n", imc);
    }else if(imc < 29.9){
        printf("\nSeu imc e %f, voce esta em sobrepeso\n", imc);
    }else if(imc < 39.9){
        printf("\nSeu imc e %f, voce esta em obesidade\n", imc);
    }else{
        printf("\nSeu imc e %f, voce esta em obesidade grave\n", imc);
    }
    return 0;
}
