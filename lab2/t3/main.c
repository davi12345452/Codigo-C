#include "lista.h"
#include "menu.h"
#include <stdio.h>

// Aqui estou chamando as função definidas em lista.h e menu.h para
// executar o programa

int main() {
  ListaConsultas *listaConsultas = criarListaConsultas(); // Crie a lista de Consultas
  ListaMedicos *listaMedicos = criarListaMedicos();
  ListaPacientes *listaPacientes = criarListaPacientes();
  menu(listaConsultas, listaMedicos, listaPacientes); // Chama o programa em si
  destruirListaConsultas(listaConsultas); // Libera a memória alocada em lista
  destruirListaMedicos(listaMedicos);
  destruirListaPacientes(listaPacientes);
  return 0;
}
