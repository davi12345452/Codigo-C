#include "data.h"
#include <stdbool.h>
#include <stdlib.h>
   
   typedef struct _data {
     int dia;
     int mes;
     int ano;
   } data;
   
   #ifdef TESTE
   #include <assert.h>
   void data_teste(void)
   {
     Data d1;
     d1 = data_cria(29,2,2023);
     assert(d1 == NULL);
     d1 = data_cria(27,3,2023);
     assert(d1 != NULL);
     assert(data_dia(d1) == 27);
     assert(data_mes(d1) == 3);
     assert(data_ano(d1) == 2023);
     Data d2;
     d2 = data_apos_dias(d1,10);
     assert(d2 != NULL);
     assert(data_dia(d2) == 6);
     assert(data_mes(d2) == 4);
     assert(data_ano(d2) == 2023);
     assert(data_dias_ate(d1, d2) == 10);
     assert(data_dias_ate(d2, d1) == -10);
     data_destroi(d1);
     data_destroi(d2);
     // ... outros testes
   }
   #endif // TESTE
   
   // função auxiliar que retorna true se for data válida
   static bool data_ok(int d, int m, int a)
   {
     // testes para ver se d/m/a constituem uma data válida
     // ...
     return true; // ou nao
   }
   
   Data data_cria(int dia, int mes, int ano)
   {
     if (!data_ok(dia, mes, ano)) return NULL;
     Data d = malloc(sizeof(data));
     if (d != NULL) {
       d->dia = dia;
       d->mes = mes;
       d->ano = ano;
     }
     return d;
   }
   
   // destruição de uma data
   void data_destroi(Data d)
   {
     free(d);
   }
   
   // obtenção do dia da data
   int data_dia(Data d)
   {
     return d->dia;
   }
   
   // obtenção do mês da data
   int data_mes(Data d)
   {
     return d->mes;
   }
   
   // obtenção do ano da data
   int data_ano(Data d)
   {
     return d->ano;
   }
   
   // cálculo do número de dias entre duas datas
   int data_dias_ate(Data d1, Data d2)
   {
     if (d1->mes == d2->mes && d1->ano == d2->ano) {
       return d2->dia - d1->dia;
     }
     // ...
   }
   
   // obtenção de uma data a tantos dias de distância da outra
   Data data_apos_dias(Data d, int dias)
   {
     return data_cria(d->dia + dias, d->mes, d->ano); // talvez necessite refinamentos
   }