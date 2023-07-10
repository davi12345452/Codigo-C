#ifndef LISTA_H
#define LISTA_H

// Definição das estruturas de dados

// Estrutura para definir um horário

typedef struct {
  int dia;
  int mes;
  int ano;
  int hora;
  int minuto;
} DataHora;

// Estrutura para definir o paciente

typedef struct {
  char cpf[12];
  char nome[50];
  char telefone[15];
} Paciente;

// Estrutura para definir o médico

typedef struct {
  char crm[10];
  char nome[50];
  char especialidade[50];
  char telefone[15];
} Medico;

// Estrutura para definir a consulta. Utiliza estruturas de médico, paciente e
// horário. Além de aplicar o conceito de encadeamento de listas.

typedef struct _consulta{
  Paciente *paciente;
  Medico *medico;
  DataHora dataHora;
  char convenio[50];
  int status;
  char descricao[100];
  struct _consulta *prox;
} Consulta;

// Estrutura que define uma lista encadeada de estrutura Consulta

typedef struct {
  Consulta *primeiro;
} ListaConsultas;

// Estruturas para criar listas de pacientes e médicos

typedef struct PacienteNode {
  Paciente paciente;
  struct PacienteNode *prox;
} PacienteNode;

typedef struct {
  PacienteNode *primeiro;
} ListaPacientes;

typedef struct MedicoNode {
  Medico medico;
  struct MedicoNode *prox;
} MedicoNode;

typedef struct {
  MedicoNode *primeiro;
} ListaMedicos;

// Funções para manipulação das listas

ListaConsultas *criarListaConsultas();
void destruirListaConsultas(ListaConsultas *lista);

ListaPacientes *criarListaPacientes();
void destruirListaPacientes(ListaPacientes *lista);

ListaMedicos *criarListaMedicos();
void destruirListaMedicos(ListaMedicos *lista);

Paciente *buscarPaciente(ListaPacientes *lista, char *cpf);
Medico *buscarMedico(ListaMedicos *lista, char *crm);

void cadastrarPaciente(ListaPacientes *lista, char *cpf, char *nome,
                       char *telefone);
void cadastrarMedico(ListaMedicos *lista, char *crm, char *nome,
                     char *especialidade, char *telefone);

int horarioLivre(ListaConsultas *lista, Medico *medico, DataHora dataHora, Paciente *paciente);
void adicionarDescricaoConsulta(ListaConsultas *lista, char *cpf, char *crm,
                                DataHora dataHora, char *descricao);
void agendarConsulta(ListaConsultas *lista, ListaPacientes *listaPacientes,
                     ListaMedicos *listaMedicos, char *cpf, char *crm,
                     DataHora dataHora, char *convenio);
void desmarcarConsulta(ListaConsultas *lista, char *cpf, DataHora dataHora);

void listarConsultas(ListaConsultas *lista);
void listarConsultasDia(ListaConsultas *lista, int dia, int mes, int ano);
void listarConsultasPaciente(ListaConsultas *lista, char *cpf);
void listarDescricaoConsulta(ListaConsultas *lista, char *cpf,
                             DataHora dataHora);
void listarConsultasEspecialidadeMes(ListaConsultas *lista, char *especialidade,
                                     int mes, int ano);
void listarPacientesPorMedico(ListaConsultas *lista, char *crm);

#endif
