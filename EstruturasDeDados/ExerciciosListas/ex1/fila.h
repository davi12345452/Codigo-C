   // fila.h
   #ifndef _FILA_H_
   #define _FILA_H_
   #include <stdbool.h>
   
   typedef struct _fila *Fila;
   
   Fila fila_cria(int cap);
   void fila_destroi(Fila p);
   
   // diz se a fila está vazia
   bool fila_vazia(Fila p);
   
   // diz se a fila está cheia
   bool fila_cheia(Fila p);
   
   // retorna o dado no topo da fila, sem remover
   dado_t fila_topo(Fila p);
   
   // remove o dado no topo da fila e retorna ele
   dado_t fila_remove(Fila p);
   
   // insere d na fila
   void fila_insere(Fila p, dado_t d);

   #endif //_FILA_H_