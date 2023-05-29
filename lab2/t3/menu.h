#ifndef MENU_H
#define MENU_H

/*
  É necessário incluir lista.h pois menu.h define a função do programa, o qual
  utiliza uma estrutura definida em lista.h como único argumento
*/

#include "lista.h"

// Funções do menu

void menu(ListaConsultas *listaConsultas, ListaMedicos *listaMedicos,  ListaPacientes *listaPacientes);

#endif