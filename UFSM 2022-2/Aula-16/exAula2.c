#include <stdbool.h>
#include <stdio.h>

bool verificaPalindromo(char frase[]){
    int tamanho = strlen(frase);
    for(int i = 0; i< tamanho; i++){
        if(frase[0] != frase[tamanho-1-i]){
            return false;
        }
    return true;
    }
}

int main(){

    bool verficia1 = verificaPalindromo("atacato");
    if(verficia1){
        printf("Oi");
    }
    return 0;
}
