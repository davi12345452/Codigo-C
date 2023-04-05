#ifndef _DATA_H_ 
// para evitar a inclusão múltipla deste arquivo
#define _DATA_H_
   
   // o tipo de dados Data
   typedef struct _data *Data;
   
   // criação de uma data
   Data data_cria(int dia, int mes, int ano);
   
   // destruição de uma data
   void data_destroi(Data d);
   
   // obtenção do dia da data
   int data_dia(Data d);
   
   // obtenção do mês da data
   int data_mes(Data d);
   
   // obtenção do ano da data
   int data_ano(Data d);
   
   // cálculo do número de dias entre duas datas
   int data_dias_ate(Data d1, Data d2);
   
   // obtenção de uma data a tantos dias de distância da outra
   Data data_apos_dias(Data d, int dias);
   
   #ifdef TESTE
   void data_teste(void);
   #endif
   
#endif  // _DATA_H_