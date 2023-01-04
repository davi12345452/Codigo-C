#include <stdio.h>

void cor_fundo(int vermelho, int verde, int azul){
    // envia códigos de escape ANSI para limpar a tela e alterar a cor de fundo
    printf("\e[2J\e[48;2;%d;%d;%dm", vermelho, verde, azul);
    fflush(stdout); // força o envio da saída para o terminal
}

int main(){
    cor_fundo(255, 0, 0); // altera a cor de fundo para vermelho
    printf("\e[0m"); // volta à cor padrão
    return 0;
}
