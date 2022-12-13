#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char *inver(char palavra[]){
    int tamanho = strlen(palavra) - 1;
    char *inverso = malloc(tamanho);
    for(int i = tamanho; i < 0; i++ ){
        inverso[i] = palavra[i];
    }
    return inverso;

}

int main(){
    printf("%s", inver("Boa Noite") );
    return 0;
}
