   // lista.h
   #ifndef _LISTA_H_
   #define _LISTA_H_
   #include <stdbool.h>
   
   typedef struct _lista *Lista;
   
   Lista lista_cria(int cap);
   void lista_destroi(Lista l);
   
   // retorna o número de dados atualmente na lista l
   int lista_num_elem(Lista l);
   
   // coloca em *pd o dado na posição pos da lista l, retorna false se não ok (e não coloca nada em *pd)
   bool lista_dado(Lista l, int pos, dado_t *pd);
   
   // insere d na posicao pos da lista l, retorna true se ok
   bool lista_insere(Lista l, int pos, dado_t d);
   
   // remove o dado na posição pos da lista l, retorna true se ok
   bool lista_remove(Lista l, int pos);
   #endif //_LISTA_H_