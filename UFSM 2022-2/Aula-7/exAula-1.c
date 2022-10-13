#include <stdio.h>

int main(){

    int i, n;

    printf("Escreve o limite: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        if(i % 3 == 0 && i % 5 != 0){
            printf("\nPA");
        }else if(i % 5 == 0 && i % 3 != 0){
            printf("\nPUM");
        }else if (i % 3 == 0 && i % 5 == 0){
            printf("\nPAPUM");
        }else{
            printf("\n%d", i);
        }
    }

    return 0;
}
