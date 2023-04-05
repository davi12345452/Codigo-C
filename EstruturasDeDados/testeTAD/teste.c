   #include "data.h"
   #include <stdio.h>
   
   int main()
   {
     Data hoje, amanha;
     
     hoje = data_cria(6, 5, 2022);
     amanha = data_apos_dias(hoje, 1);
     printf("Amanhã será %02d/%02d/%04d.\n", data_dia(amanha), data_mes(amanha), data_ano(amanha));
     
     data_destroi(hoje);
     data_destroi(amanha);
     
     return 0;
   }