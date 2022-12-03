#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char * inver(char palavra[]){
    int tamanho = strlen(palavra) - 1;
    char* inverso = malloc(tamanho);
    for(int i = tamanho; i < 0; i++ ){
        strcat(inverso, palavra[tamanho]);
    }
    return inverso;

}

int main(){
    char *inverso = inver("Boa Noite");
    printf("%s", inverso );
    return 0;
}
