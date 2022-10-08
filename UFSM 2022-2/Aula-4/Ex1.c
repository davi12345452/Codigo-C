#include <stdio.h>

/*
L� 2 n�meros entre 0 e 10, que representam as notas de um aluno, e mais dois n�meros, que representam os pesos de cada nota. Se a
m�dia ponderada das notas for pelo menos 7, informa que o aluno est� aprovado. Se n�o for, l� mais um n�mero, que � a nota do exame.
Se a m�dia entre o exame e a m�dia anterior for pelo menos 5, informa que o aluno est� aprovado. Sen�o, informa que o aluno reprovou.
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
