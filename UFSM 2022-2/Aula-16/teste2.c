#include <stdio.h>

void cor_fundo(int vermelho, int verde, int azul){
    // envia c�digos de escape ANSI para limpar a tela e alterar a cor de fundo
    printf("\e[2J\e[48;2;%d;%d;%dm", vermelho, verde, azul);
    fflush(stdout); // for�a o envio da sa�da para o terminal
}

int main(){
    cor_fundo(255, 0, 0); // altera a cor de fundo para vermelho
    printf("\e[0m"); // volta � cor padr�o
    return 0;
}
