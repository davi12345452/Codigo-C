#include <stdio.h>

/*
Lê 2 números entre 0 e 10, que representam as notas de um aluno, e mais dois números, que representam os pesos de cada nota. Se a
média ponderada das notas for pelo menos 7, informa que o aluno está aprovado. Se não for, lê mais um número, que é a nota do exame.
Se a média entre o exame e a média anterior for pelo menos 5, informa que o aluno está aprovado. Senão, informa que o aluno reprovou.
*/

int main(){
    float n_1, n_2, exame;
    float p_1, p_2;
    float media, media_exame;

    printf("\nDigite a nota 1 e seu peso em porcentagem: ");
    scanf("%f%f", &n_1, &p_1);

    printf("\nDigite a nota 2 e seu peso em porcentagem: ");
    scanf("%f%f", &n_2, &p_2);

    p_1 = p_1/100;
    p_2 = p_2/100;

    media = ((n_1 * p_1) + (n_2 + p_2))/2;

    if(media >= 7){
        printf("\nAPROVADO");
    }else{
        printf("\nQual sua nota no exame? ");
        scanf("%f", &exame);

        media_exame = (media + exame)/2;
        if(media_exame >= 5){
            printf("\nAPROVADO");
        }else{
            printf("REPROVADO");
        }
    }

    return 0;

}
