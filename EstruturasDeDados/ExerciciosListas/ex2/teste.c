#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Execução: if ($?) { gcc lista.c  teste.c -o teste } ; if ($?) { .\teste }

int main(){
    Lista lista;
    lista = lista_cria(5);
    printf("Ola mundo");
    return 0;
}
