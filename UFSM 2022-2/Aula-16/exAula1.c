#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int verifica(char palavra[]){
    char vogais[] = {"aeiouAEIOU"};
    int somador;
    for(int i = 0; i < strlen(palavra); i++){
        for(int k = 0; k < 10; k++){
            if(palavra[i] == vogais[k]){
                somador++;
            }
        }
    }
    return somador;

}
int main(){
    printf("%d", verifica("Ola"));
    return 0;
}
