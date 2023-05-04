#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//cd "c:\Users\davij\Documents\GitHub\exercicios C\Codigo-C\EstruturasDeDados\t2\" ; if ($?) { gcc str.c t2.c -o t2 } ; if ($?) { .\t2 }
//cd "c:\Users\davij\Documents\GitHub\exercicios C\Codigo-C\EstruturasDeDados\t2\" ; if ($?) { gcc -DTESTE -o t2 t2.c str.c  } ; if ($?) { .\t2 }
int main(){
    //set_locale(LC_ALL, "portuguese");
    Str string;
    int teste;
    string = str_cria("Ola");
    teste = str_tam(string);
    printf("%d", teste);
    return 0;
}



