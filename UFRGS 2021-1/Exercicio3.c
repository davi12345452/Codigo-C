/*
Programa que calcula o peso total de uma carga de celulares e webcams */

#include <stdio.h>
int main(void)
{
   int ncelular, nwebcam;
   float ecelular, ewebcam;
   float pesototal;
   printf("Indique a quantidade de celulares:\n");
   scanf("%d",&ncelular);
   printf("Indique a quantidade de Webcams:\n");
   scanf("%d",&nwebcam);
   printf("Indique o peso da embalagem do Celular em grams:\n");
   scanf("%f",&ecelular);
   printf("Indique o peso da embalagem da Webcam em gramas:\n");
   scanf("%f",&ewebcam);
   pesototal=(ncelular*100)+(nwebcam*45)+(ncelular*ecelular)+(nwebcam*ewebcam);
   printf("O peso total da carga e:%1.6g gramas\n",pesototal);
   return(0);
}

