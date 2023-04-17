/*
    Laboratório de Programação 2
    Trabalho 2 -> Alocação Dinâmica de Vetores e Matrizes
    Aluno -> Davi Janisch Maia
*/

/*
    Usuário vai fornecer cidades, população e quantidade de dia, assim
    como confirmados e mortes no dia por cidade. A partir disso
    o programa deve usar alocação dinâmica para guardar essas
    informações e devolver por município o total de confirmados, 
    total de novos casos (último dia cadastrado), total de óbitos,
    total de novos óbitos (útlimo dia cadastrado) e a mortalidade
    por 100k habitantes
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define T_STR_CIDADES 50

struct municipio
{
    char* nome;
    int populacao;
    int** dados; //matriz de dados -> dia / novos_caso / óbitos
};
typedef struct municipio Municipio;

