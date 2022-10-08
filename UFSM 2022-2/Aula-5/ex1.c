#include <stdio.h>
#include <time.h>

#define HORA 3600
#define HORAS 24

int main(){

    long t = time(0);
    int dia, dia_hoje;


    dia = (HORAS * HORA);

    /*Lógica: considerei apenas sábado e domingo como final de semana
      Se o 0 começa em uma quinta feira, sua divisão de resto vale 0,
      a sexta vale 1, sabado 2 e domingo 3, logo, só consideramos fim
      de semana se tempo, que será convertido em dias, quando dividido
      por 7 reste 2 ou 3. Por ser uma divisão inteira, quando conver-
      termos para dia, os segundo excedentes serão excluídos*/

    dia_hoje = t/dia;

    if(dia_hoje % 7 == 2 || dia_hoje % 7 == 3){
        printf("Fim de semana");
    }else{
        printf("Não é fim de semana");
    }
    return 0;
}
