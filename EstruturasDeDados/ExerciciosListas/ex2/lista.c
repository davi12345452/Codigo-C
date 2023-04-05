   // lista.c
   #include "lista.h"
   #include <stdio.h>
   #include <stdlib.h>

   typedef double dado_t;

   typedef struct _lista {
     int cap;
     int num;
     dado_t *vet;
   } lista;
   
   Lista lista_cria(int cap)
   {
     // aloca memória para o descritor da lista
     Lista l = malloc(sizeof(lista));
     if (l == NULL) return NULL;
     // aloca memória para os dados da lista
     l->vet = malloc(cap * sizeof(dado_t));
     if (l->vet == NULL) {
       free(l);
       return NULL;
     }
     l->cap = cap;
     l->num = 0;
     return l;
   }
   
   void lista_destroi(Lista l)
   {
     // libera a memória dos dados e do descritor
     free(l->vet);
     free(l);
   }
   
   int lista_num_elem(Lista l)
   {
     // essa é fácil, o número de elementos tá no descritor
     return l->num;
   }
   
   bool lista_dado(Lista l, int pos, dado_t *pd)
   {
     // vê se existe alguém nessa pos
     if (pos < 0 || pos >= l->num) {
       return false;
     }
     *pd = l->vet[pos];
     return true;
   }
   
   bool lista_insere(Lista l, int pos, dado_t d)
   {
     // vê se inserção não é possível
     if (pos < 0 || pos > l->num || l->num >= l->cap) {
       return false;
     }
     // desloca dados para gerar espaço (movimenta as posições desde pos até o final da lista para a direita)
     // movimenta de trás pra diante para nao sobrescrever
     for (int i = l->num - 1; i > pos; i--) {
       l->vet[i] = l->vet[i-1];
     }
     // em vez do for, daria para usar uma função de movimentação de memória:
     // memmove(&l->vet[pos+1], &l->vet[pos], (l->num - pos)*sizeof(dado_t));
     // coloca o novo dado na posição e incrementa o número de dados
     l->vet[pos] = d;
     l->num++;
     return true;
   }
   
   bool lista_remove(Lista l, int pos)
   {
     // vê se existe alguém nessa pos
     if (pos < 0 || pos >= l->num) {
       return false;
     }
     // movimenta os dados após o removido
     for (int i = pos; i < l->num-1; i++) {
       l->vet[i] = l->vet[i+1];
     }
     l->num--;
     return true;
   }