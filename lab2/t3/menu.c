#include "menu.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*
  Essa função serve apenas para exibir um menu de orientação ao usuário.
*/

void exibirMenu() {
  printf("---------------------------------------------------\n");
  printf("Sistema de Agendamento de Consultas\n");
  printf("---------------------------------------------------\n");
  printf("1.  Cadastrar Paciente\n");
  printf("2.  Cadastrar Médico\n");
  printf("3.  Agendar Consulta\n");
  printf("4.  Desmarcar Consulta\n");
  printf("5.  Adicionar Descrição à consulta completa\n");
  printf("6.  Listar Paciente Cadastrados\n");
  printf("7.  Listar Médicos Cadastrados\n");
  printf("8.  Listar Consultas\n");
  printf("9.  Listar Consultas de um Dia\n");
  printf("10. Listar Consultas de um Paciente\n");
  printf("11. Listar Descrição de uma Consulta\n");
  printf("12. Listar Consultas por Especialidade e Mês\n");
  printf("13. Listar Pacientes por Médico\n");
  printf("0.  Sair\n");
  printf("---------------------------------------------------\n");
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para cadastrar um paciente no
  programa.
*/

void _cadastrarPaciente(ListaPacientes *lista) {
  char cpf[12];
  char nome[100];
  char telefone[15];

  printf("Digite o CPF do paciente: ");
  scanf("%s", cpf);
  printf("Digite o nome do paciente: ");
  getchar();
  fgets(nome, 100, stdin);
  printf("Digite o telefone do paciente: ");
  scanf("%s", telefone);

  cadastrarPaciente(lista, cpf, nome, telefone);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para cadastrar um médico no
  programa.
*/

void _cadastrarMedico(ListaMedicos *lista) {
  char crm[10];
  char nome[100];
  char especialidade[50];
  char telefone[15];

  printf("Digite o CRM do médico: ");
  scanf("%s", crm);
  printf("Digite o nome do médico: ");
  getchar();
  fgets(nome, 100, stdin);
  printf("Digite a especialidade do médico: ");
  fgets(especialidade, 50, stdin);
  printf("Digite o telefone do médico: ");
  scanf("%s", telefone);

  cadastrarMedico(lista, crm, nome, especialidade, telefone);
}

/*
  Nessa função, exibe-se a lista de médicos cadastrados no programa. 
*/

void _listarMedicos(ListaMedicos *lista) {
  MedicoNode *atual = lista->primeiro;

  printf("----- Médicos Cadastrados -----\n");

  while (atual != NULL) {
    printf("CRM: %s\n", atual->medico.crm);
    printf("Nome: %s", atual->medico.nome);
    printf("Especialidade: %s", atual->medico.especialidade);
    printf("Telefone: %s\n", atual->medico.telefone);
    printf("-------------------------------------\n");

    atual = atual->prox;
  }

  if (lista->primeiro == NULL) {
    printf("Nenhum médico cadastrado.\n");
  }
}

/*
  Nessa função, exibe-se a lista de pacientes cadastrados no programa. 
*/

void _listarPacientes(ListaPacientes *lista) {
  PacienteNode *atual = lista->primeiro;

  printf("----- Pacientes Cadastrados -----\n");

  while (atual != NULL) {
    printf("CPF: %s\n", atual->paciente.cpf);
    printf("Nome: %s", atual->paciente.nome);
    printf("Telefone: %s\n", atual->paciente.telefone);
    printf("-------------------------------------\n");

    atual = atual->prox;
  }

  if (lista->primeiro == NULL) {
    printf("Nenhum paciente cadastrado.\n");
  }
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para o usuário marcar uma consulta.
  Além disso, a função verifica se a data dada é válida, não com os horário do médico, mas
  logicamente, como, não existe mês 13, hora 25...
*/

void _agendarConsulta(ListaConsultas *lista, ListaMedicos *listaM,  ListaPacientes *listaP) {
  char cpf[12];
  char crm[10];
  int dia, mes, ano, hora, minuto;
  char convenio[50];

  printf("Digite o CPF do paciente: ");
  scanf("%s", cpf);
  printf("Digite o CRM do médico: ");
  scanf("%s", crm);
  printf("Digite a data da consulta (DD MM AAAA): ");
  scanf("%d %d %d", &dia, &mes, &ano);
  printf("Digite o horário da consulta (HH MM): ");
  scanf("%d %d", &hora, &minuto);
  printf("Digite o convênio: ");
  getchar();
  fgets(convenio, 50, stdin);

  if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0) {
    printf("Data inválida!\n");
    return;
  }

  if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59) {
    printf("Horário inválido!\n");
    return;
  }

  DataHora dataHora;
  dataHora.dia = dia;
  dataHora.mes = mes;
  dataHora.ano = ano;
  dataHora.hora = hora;
  dataHora.minuto = minuto;

  agendarConsulta(lista, listaP, listaM, cpf, crm, dataHora, convenio);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para o médico poder
  acrescentar sua descrição da consulta, depois de realizada. Na lista.h, a
  função aqui utilizada, alterará o status para EXECUTADA após realizado esse
  processo com êxito.
*/
void _adicionarDescricao(ListaConsultas *lista) {
  char cpf[12], crm[10], descricao[100];
  int dia, mes, ano, hora, minuto;

  printf("Digite o CPF do paciente: ");
  scanf("%s", cpf);
  printf("Digite o CRM do médico: ");
  scanf("%s", crm);
  printf("Digite a data da consulta (DD MM AAAA): ");
  scanf("%d %d %d", &dia, &mes, &ano);
  printf("Digite o horário da consulta (HH MM): ");
  scanf("%d %d", &hora, &minuto);
  printf("Descreva a consulta: ");
  getchar();
  fgets(descricao, 100, stdin);

  DataHora dataHora;
  dataHora.dia = dia;
  dataHora.mes = mes;
  dataHora.ano = ano;
  dataHora.hora = hora;
  dataHora.minuto = minuto;

  adicionarDescricaoConsulta(lista, cpf, crm, dataHora, descricao);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para o usuário poder
  desmarcar uma consulta. Ele fornece seus dados, os quais utilizou para marcar
  e desmarca ela. 
*/

void _desmarcarConsulta(ListaConsultas *lista) {
  char cpf[12];
  int dia, mes, ano, hora, minuto;

  printf("Digite o CPF do paciente: ");
  scanf("%s", cpf);
  printf("Digite a data da consulta (DD MM AAAA): ");
  scanf("%d %d %d", &dia, &mes, &ano);
  printf("Digite o horário da consulta (HH MM): ");
  scanf("%d %d", &hora, &minuto);

  DataHora dataHora;
  dataHora.dia = dia;
  dataHora.mes = mes;
  dataHora.ano = ano;
  dataHora.hora = hora;
  dataHora.minuto = minuto;

  desmarcarConsulta(lista, cpf, dataHora);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para exibir todas
  as consultas cadastradas no programa.
*/

void _listarConsultas(ListaConsultas *lista) {
  printf("Listagem de Consultas\n");
  listarConsultas(lista);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para exibir todas
  as consultas cadastradas para um dia específico.
*/

void _listarConsultasDia(ListaConsultas *lista) {
  int dia, mes, ano;

  printf("Digite a data (DD MM AAAA): ");
  scanf("%d %d %d", &dia, &mes, &ano);

  printf("Listagem de Consultas do Dia\n");
  listarConsultasDia(lista, dia, mes, ano);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para exibir todas as
  consultadas cadastradas por paciente, utilizando CPF de entrada
*/

void _listarConsultasPaciente(ListaConsultas *lista) {
  char cpf[12];

  printf("Digite o CPF do paciente: ");
  scanf("%s", cpf);

  printf("Listagem de Consultas do Paciente CPF %s:", cpf);
  listarConsultasPaciente(lista, cpf);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para exibir as descrições de uma
  determinada consulta. Usa-se o CPF do paciente e a data da consulta para chamar.
*/

void _listarDescricaoConsulta(ListaConsultas *lista) {
  char cpf[12];
  int dia, mes, ano, hora, minuto;

  printf("Digite o CPF do paciente: ");
  scanf("%s", cpf);
  printf("Digite a data da consulta (DD MM AAAA): ");
  scanf("%d %d %d", &dia, &mes, &ano);
  printf("Digite o horário da consulta (HH MM): ");
  scanf("%d %d", &hora, &minuto);

  DataHora dataHora;
  dataHora.dia = dia;
  dataHora.mes = mes;
  dataHora.ano = ano;
  dataHora.hora = hora;
  dataHora.minuto = minuto;

  printf("Descrição da Consulta\n");
  listarDescricaoConsulta(lista, cpf, dataHora);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para exibir as consultas
  de uma determinada especiliadade em uma data específica
*/

void _listarConsultasEspecialidadeMes(ListaConsultas *lista) {
  char especialidade[50];
  int mes, ano;

  printf("Digite a especialidade: ");
  getchar();
  fgets(especialidade, 50, stdin);
  printf("Digite o mês e o ano (MM AAAA): ");
  scanf("%d %d", &mes, &ano);

  printf("Listagem de Consultas por Especialidade e Mês\n");
  listarConsultasEspecialidadeMes(lista, especialidade, mes, ano);
}

/*
  Essa função é a UI, que utiliza uma função de lista.h para exibir os 
  pacientes de um médico, chamado por seu CRM
*/

void _listarPacientesPorMedico(ListaConsultas *lista) {
  char crm[10];

  printf("Digite o CRM do médico: ");
  scanf("%s", crm);

  printf("Listagem de Pacientes por Médico\n");
  listarPacientesPorMedico(lista, crm);
}

/*
  Acabei deixando comentado, porém é uma função para limpar a tela, para lembrar
  os dados que utilizei nos testes, mantive desligado, mas pode rodá-la, que fun-
  ciona.
*/

void limparConsole() {
#ifdef _WIN32
  system("cls"); //Win
#else
  system(
      "clear"); //Linux
#endif
}

/*
  Função final, onde o programa será iniciado pelo usuário
*/

void menu(ListaConsultas *listaConsultas, ListaMedicos *listaMedicos,  ListaPacientes *listaPacientes) {
  int opcao;

  do {
    exibirMenu();
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    printf("---------------------------------------------------\n");
    // limparConsole(); // Deixe desabilitada a função. Mas pode usar
    // tranquilamente.

    switch (opcao) {
    case 1:
      _cadastrarPaciente(listaPacientes);
      break;
    case 2:
      _cadastrarMedico(listaMedicos);
      break;
    case 3:
      _agendarConsulta(listaConsultas, listaMedicos, listaPacientes);
      break;
    case 4:
      _desmarcarConsulta(listaConsultas);
      break;
    case 5:
      _adicionarDescricao(listaConsultas);
      break;
    case 6:
      _listarPacientes(listaPacientes);
      break;
    case 7:
      _listarMedicos(listaMedicos);
      break;
    case 8:
      _listarConsultas(listaConsultas);
      break;
    case 9:
      _listarConsultasDia(listaConsultas);
      break;
    case 10:
      _listarConsultasPaciente(listaConsultas);
      break;
    case 11:
      _listarDescricaoConsulta(listaConsultas);
      break;
    case 12:
      _listarConsultasEspecialidadeMes(listaConsultas);
      break;
    case 13:
      _listarPacientesPorMedico(listaConsultas);
      break;
    case 0:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }

    printf("\n");
  } while (opcao != 0);
}