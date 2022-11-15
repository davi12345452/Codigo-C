#include <stdio.h>
#include <string.h>


/*
1 - Percorre array e verifica somente os algarismos, sem repetir
2 - Percorre novamente o array e guarda termos repetidos
3 - Percorre array de termos repetidos e ve quem mais se repetiu
*/

int moda(int n, int v[n]){
    int max, valor;
    int conta[100]={0};
    for(int i = 0; i < n; i++){
        valor = v[i];
        conta[valor]++;
    }

    max = 0;
    for(int i = 0; i < n; i++){
        if(conta[i]> conta[max]){
            max = i;
        }
    }
    return max;
}

int main(){
    int _moda;
    int vetor[20] = {2, 2, 2, 4, 3, 1, 5, 6, 4, 2};
    _moda = moda(20, vetor);
    printf("Mode: %d", _moda);
}
