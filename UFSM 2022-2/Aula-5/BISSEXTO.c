#include <stdio.h>

int main(){
    int ano;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    if(ano % 400 == 0){
        printf("E ano bissexto");
    }else {
        if((ano % 4 == 0) && !(ano % 100 == 0)){
            printf("E ano bissexto");
        }else {
            printf("Nao e bissexto");
        }
    }

    return 0;
}
