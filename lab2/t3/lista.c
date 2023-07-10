#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Função para criar a lista de consultas e alocar memória à ela.*/
 
ListaConsultas *criarListaConsultas() {
  ListaConsultas *lista = (ListaConsultas *)malloc(sizeof(ListaConsultas));
  lista->primeiro = NULL;
  return lista;
}

/* Função para limpar o espaço alocado à lista de consultas*/
 
void destruirListaConsultas(ListaConsultas *lista) {
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    Consulta *prox = atual->prox;
    free(atual);
    atual = prox;
  }
  free(lista);
}

/* Função para criar a lista de pacientes e alocar memória à ela.*/
 
ListaPacientes *criarListaPacientes() {
  ListaPacientes *lista = (ListaPacientes *)malloc(sizeof(ListaPacientes));
  lista->primeiro = NULL;
  return lista;
}

/* Função para limpar o espaço alocado à lista de pacientes*/
 
void destruirListaPacientes(ListaPacientes *lista) {
  PacienteNode *atual = lista->primeiro;
  while (atual != NULL) {
    PacienteNode *prox = atual->prox;
    free(atual);
    atual = prox;
  }
  free(lista);
}

/* Função para criar a lista de médicos e alocar memória à ela.*/
 
ListaMedicos *criarListaMedicos() {
  ListaMedicos *lista = (ListaMedicos *)malloc(sizeof(ListaMedicos));
  lista->primeiro = NULL;
  return lista;
}

/* Função para limpar o espaço alocado à lista de médicos*/
 
void destruirListaMedicos(ListaMedicos *lista) {
  MedicoNode *atual = lista->primeiro;
  while (atual != NULL) {
    MedicoNode *prox = atual->prox;
    free(atual);
    atual = prox;
  }
  free(lista);
}

/*
  Função para buscar um paciente, através de um CPF, na lista de pacientes.
  Caso não encontre, devolve NULL. 
*/
 
Paciente *buscarPaciente(ListaPacientes *lista, char *cpf) {
  PacienteNode *atual = lista->primeiro;
  while (atual != NULL) {
    if (strncmp(atual->paciente.cpf, cpf, sizeof(atual->paciente.cpf)) == 0) {
      return &(atual->paciente);
    }
    atual = atual->prox;
  }
  return NULL;
}

/*
  Função para buscar um médico, através de um CRM, na lista de médicos.
  Caso não encontre, devolve NULL. 
*/
 
Medico *buscarMedico(ListaMedicos *lista, char *crm) {
  MedicoNode *atual = lista->primeiro;
  while (atual != NULL) {
    if (strcmp(atual->medico.crm, crm) == 0) {
      return &(atual->medico);
    }
    atual = atual->prox;
  }
  return NULL;
}

/*
  Função para cadastrar um paciente na lista de pacientes. Recebe CPF, Nome e telefone como
  entradas. Caso já haja algum paciente com mesmo CPF, não há cadastro. 
*/
 
void cadastrarPaciente(ListaPacientes *lista, char *cpf, char *nome, char *telefone) {
  // Verificar se o CPF já está cadastrado
  if(buscarPaciente(lista, cpf) != NULL) {
      printf("CPF já cadastrado.\n");
      return;
  }

  PacienteNode *novoNode = (PacienteNode *)malloc(sizeof(PacienteNode));
  if (novoNode == NULL) {
    printf("Erro na alocação de memória.\n");
    return;
  }
  
  strncpy(novoNode->paciente.cpf, cpf, sizeof(novoNode->paciente.cpf));
  strncpy(novoNode->paciente.nome, nome, sizeof(novoNode->paciente.nome));
  strncpy(novoNode->paciente.telefone, telefone, sizeof(novoNode->paciente.telefone));
  
  // Coloca o finalizador de string no último caractere, caso os inputs sejam maiores que o buffer
  novoNode->paciente.cpf[sizeof(novoNode->paciente.cpf) - 1] = '\0';
  novoNode->paciente.nome[sizeof(novoNode->paciente.nome) - 1] = '\0';
  novoNode->paciente.telefone[sizeof(novoNode->paciente.telefone) - 1] = '\0';
  
  novoNode->prox = lista->primeiro;
  lista->primeiro = novoNode;
  
  printf("Paciente cadastrado com sucesso.\n");
}

/*
  Função para cadastrar um médico na lista de médicos. Recebe CRM, nome, especilidade e telefone como
  entradas. Caso já haja algum médico com mesmo CRM, não há cadastro. 
*/
 
void cadastrarMedico(ListaMedicos *lista, char *crm, char *nome, char *especialidade, char *telefone) {
  // Verificar se o CRM já está cadastrado
  MedicoNode *atual = lista->primeiro;
  while (atual != NULL) {
    if (strcmp(atual->medico.crm, crm) == 0) {
      printf("CRM já cadastrado.\n");
      return; 
    }
    atual = atual->prox;
  }

  
  MedicoNode *novoNode = (MedicoNode *)malloc(sizeof(MedicoNode));
  strcpy(novoNode->medico.crm, crm);
  strcpy(novoNode->medico.nome, nome);
  strcpy(novoNode->medico.especialidade, especialidade);
  strcpy(novoNode->medico.telefone, telefone);
  novoNode->prox = lista->primeiro;
  lista->primeiro = novoNode;
  printf("Médico cadastrado com sucesso.\n");
}

/*
  Essa foi a função auxiliar para ver se o paciente teria conflito com o horário da consulta
*/
 
int pacienteTemConsultaNoHorario(ListaConsultas *lista, Paciente *paciente, DataHora dataHora) {
  int horario = dataHora.hora * 60 + dataHora.minuto;
  
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    int horarioConsulta = atual->dataHora.hora * 60 + atual->dataHora.minuto;
    int fimConsulta = horarioConsulta + 30; // Duração fixa de 30 minutos para cada consulta

    // Verifica se há conflito de horário com outra consulta do paciente
    if (strcmp(atual->paciente->cpf, paciente->cpf) == 0 &&
        atual->dataHora.dia == dataHora.dia &&
        atual->dataHora.mes == dataHora.mes &&
        atual->dataHora.ano == dataHora.ano &&
        horario >= horarioConsulta && horario < fimConsulta) {
      return 1; 
    }

    atual = atual->prox;
  }

  return 0; 
}

/*
  Essa função ficou um pouco complexa. Primeiro verifica se está dentro do horário de atendimento. Optei por 30
  minutos mais cedo no final, pois considerei uma consulta com esse tempo. Depois converti para minutos e fiz análise, junto
  de uma função auxiliar abaixo, se o médico tinha algum consulta que conflitava e se o paciente também tinha alguma que conflitava
*/
 
int horarioLivre(ListaConsultas *lista, Medico *medico, DataHora dataHora, Paciente *paciente) {
  int horario = dataHora.hora * 60 + dataHora.minuto;
  /*
    Aqui há um detalhe importante, não entendi perfeitamente se podem ser marcadas
    até 12h e 18h ou se realizar as consultas até esse horário. Se for consultar,
    basta retirar 30 minutos, ou seja, só poderia marcar até as 11:30 e a tarde até
    as 17:30. Deixei comentado isso no If. Essa parte busca ver se está de acordo
    com o horário de atendimento. 
  */
  if (!((horario >= 8*60 && horario <= 12*60/*-30*/) || (horario >= 14*60 && horario <= 18*60/*-30*/))) {
    return 0; // Horário fora do horário de atendimento do médico
  }

  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    // Verifica se o médico já possui uma consulta no mesmo horário
    if (strcmp(atual->medico->crm, medico->crm) == 0 &&
        atual->dataHora.dia == dataHora.dia &&
        atual->dataHora.mes == dataHora.mes &&
        atual->dataHora.ano == dataHora.ano) {

      int duracaoConsulta = 30; // Duração fixa de 30 minutos para cada consulta
      int horarioConsulta = atual->dataHora.hora * 60 + atual->dataHora.minuto;
      int fimConsulta = horarioConsulta + duracaoConsulta;

      // Verifica se há conflito de horário com outra consulta do mesmo médico
      if (horario >= horarioConsulta && horario < fimConsulta) {
        return 0; 
      }
    }

    atual = atual->prox;
  }
  
  // Verifica se o paciente já possui uma consulta no mesmo horário
  if (pacienteTemConsultaNoHorario(lista,  paciente, dataHora)) {
    return 0; 
  }

  return 1; 
}


/*
  Essa função permite ao médico acrescentar uma descrição na estrutura Consulta, que está dentro da lista de Consultas;
  Nessa função, ao acrescentar a descrição, o status muda para executado, marcado como 1, mas nas funções de exibição é
  devolvido EXECUTADO. 
*/
 
void adicionarDescricaoConsulta(ListaConsultas *lista, char *cpf, char *crm,  DataHora dataHora, char *descricao) {
  Consulta *atual = lista->primeiro;

  while (atual != NULL) {
    // Verifica se as entradas são válidas
    if (strcmp(atual->paciente->cpf, cpf) == 0 &&
        strcmp(atual->medico->crm, crm) == 0 &&
        atual->dataHora.dia == dataHora.dia &&
        atual->dataHora.mes == dataHora.mes &&
        atual->dataHora.ano == dataHora.ano &&
        atual->dataHora.hora == dataHora.hora &&
        atual->dataHora.minuto == dataHora.minuto) {
      
      strncpy(atual->descricao, descricao, sizeof(atual->descricao) - 1);
      atual->descricao[sizeof(atual->descricao) - 1] =  '\0'; 
      atual->status = 1;

      return;
    }

    atual = atual->prox;
  }

  
  printf("Consulta não encontrada para o paciente de CPF %s, médico de CRM %s e data/horário especificados.\n", cpf, crm);
}

/*
  Essa é outra função um pouco complexa. Aqui utilizamos as funções de busca, para achar o paciente e médico por CRM e CPF,
  caso não estejam cadastrados, já da um erro. Após isso, verifica-se se há conflito de horário com a data dada como entra-
  da pelo usuário. Caso esteja tudo certo, executa e marca uma consulta. 
*/
 
void agendarConsulta(ListaConsultas *lista, ListaPacientes *listaPacientes, ListaMedicos *listaMedicos, char *cpf, char *crm, DataHora dataHora, char *convenio) {
  Paciente *paciente = buscarPaciente(listaPacientes, cpf);
  Medico *medico = buscarMedico(listaMedicos, crm);
  // Verifica se existem
  if (paciente == NULL || medico == NULL) {
    printf("Paciente ou médico não encontrado.\n");
    return;
  }
  // Verifica conflito de horário
  if (!horarioLivre(lista, medico, dataHora, paciente)) {
    printf("Horário Indisponível\n");
    return;
  }

  Consulta *novaConsulta = (Consulta *)malloc(sizeof(Consulta));
  novaConsulta->paciente = paciente;
  novaConsulta->medico = medico;
  novaConsulta->dataHora = dataHora;
  strcpy(novaConsulta->convenio, convenio);
  novaConsulta->status = 0; // Agendada
  strcpy(novaConsulta->descricao, "");

  novaConsulta->prox = lista->primeiro;
  lista->primeiro = novaConsulta;
  printf("Consulta marcada com sucesso!\n");
}

/*
  Essa função exclui uma consulta da lista
*/
 
void desmarcarConsulta(ListaConsultas *lista, char *cpf, DataHora dataHora) {
  Consulta *anterior = NULL;
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    if (strcmp(atual->paciente->cpf, cpf) == 0 &&
        atual->dataHora.dia == dataHora.dia &&
        atual->dataHora.mes == dataHora.mes &&
        atual->dataHora.ano == dataHora.ano &&
        atual->dataHora.hora == dataHora.hora &&
        atual->dataHora.minuto == dataHora.minuto) {
      if (anterior == NULL) {
        lista->primeiro = atual->prox;
      } else {
        anterior->prox = atual->prox;
      }
      free(atual);
      printf("Consulta desmarcada com sucesso.\n");
      return;
    }
    anterior = atual;
    atual = atual->prox;
  }
  printf("Consulta não encontrada.\n");
}

/*
  Essa função imprime todas as consultas existentes. 
*/
 
void listarConsultas(ListaConsultas *lista) {
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    printf("\n-------------------------------------");
    printf("\nPaciente: %s", atual->paciente->nome);
    printf("\nMédico: %s", atual->medico->nome);
    printf("\nData/Hora: %02d/%02d/%04d %02d:%02d", atual->dataHora.dia,
           atual->dataHora.mes, atual->dataHora.ano, atual->dataHora.hora,
           atual->dataHora.minuto);
    printf("\nConvênio: %s", atual->convenio);
    printf("\nStatus: %s", atual->status ? "Executada" : "Agendada");
    printf("\nDescrição: %s", atual->descricao);
    printf("\n-------------------------------------");
    atual = atual->prox;
  }
}

/*
  Essa função imprime todas as consultas de um dia específico
*/
 
void listarConsultasDia(ListaConsultas *lista, int dia, int mes, int ano) {
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    if (atual->dataHora.dia == dia && atual->dataHora.mes == mes &&
        atual->dataHora.ano == ano) {
      printf("\n-------------------------------------");
      printf("\nPaciente: %s", atual->paciente->nome);
      printf("\nMédico: %s", atual->medico->nome);
      printf("\nData/Hora: %02d/%02d/%04d %02d:%02d", atual->dataHora.dia,
             atual->dataHora.mes, atual->dataHora.ano, atual->dataHora.hora,
             atual->dataHora.minuto);
      printf("\nConvênio: %s", atual->convenio);
      printf("\nStatus: %s", atual->status ? "Executada" : "Agendada");
      printf("\nDescrição: %s", atual->descricao);
      printf("\n-------------------------------------");
    }
    atual = atual->prox;
  }
}

/*
  Essa função imprime as consultas de um CPF específico. 
*/
 
void listarConsultasPaciente(ListaConsultas *lista, char *cpf) {
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    if (strcmp(atual->paciente->cpf, cpf) == 0) {
      printf("\n-------------------------------------");
      printf("\nMédico: %s", atual->medico->nome);
      printf("\nData/Hora: %02d/%02d/%04d %02d:%02d", atual->dataHora.dia,
             atual->dataHora.mes, atual->dataHora.ano, atual->dataHora.hora,
             atual->dataHora.minuto);
      printf("\nConvênio: %s", atual->convenio);
      printf("\nStatus: %s", atual->status ? "Executada" : "Agendada");
      printf("\nDescrição: %s", atual->descricao);
      printf("\n-------------------------------------");
    }
    atual = atual->prox;
  }
}

/*
  Essa função devolve a descrição dada pelo médico em uma especifica consulta
*/
 
void listarDescricaoConsulta(ListaConsultas *lista, char *cpf, DataHora dataHora) {
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    if (strcmp(atual->paciente->cpf, cpf) == 0 &&
        atual->dataHora.dia == dataHora.dia &&
        atual->dataHora.mes == dataHora.mes &&
        atual->dataHora.ano == dataHora.ano &&
        atual->dataHora.hora == dataHora.hora &&
        atual->dataHora.minuto == dataHora.minuto) {
      printf("-------------------------------------\n");
      printf("Descrição da consulta:\n");
      printf("%s", atual->descricao);
      printf("-------------------------------------\n");
      return;
    }
    atual = atual->prox;
  }
  printf("Consulta não encontrada.\n");
}

/*
  Essa função devolve todas a conssultas por uma certa especialidade e determinado mês
*/
 
void listarConsultasEspecialidadeMes(ListaConsultas *lista, char *especialidade, int mes, int ano) {
  Consulta *atual = lista->primeiro;
  while (atual != NULL) {
    if (strcmp(atual->medico->especialidade, especialidade) == 0 &&
        atual->dataHora.mes == mes && atual->dataHora.ano == ano) {
      printf("\n-------------------------------------");
      printf("\nPaciente: %s", atual->paciente->nome);
      printf("\nMédico: %s", atual->medico->nome);
      printf("\nData/Hora: %02d/%02d/%04d %02d:%02d", atual->dataHora.dia,
             atual->dataHora.mes, atual->dataHora.ano, atual->dataHora.hora,
             atual->dataHora.minuto);
      printf("\nConvênio: %s", atual->convenio);
      printf("\nStatus: %s", atual->status ? "Executada" : "Agendada");
      printf("\nDescrição: %s", atual->descricao);
      printf("\n-------------------------------------");
    }
    atual = atual->prox;
  }
}

/* Essa função devolve uma lista de paciente que se consultou o consultará com médico específico.*/
 
void listarPacientesPorMedico(ListaConsultas *lista, char *crm) {
  Consulta *atual = lista->primeiro;
  Paciente *ultimoPaciente = NULL;

  while (atual != NULL) {
    if (strcmp(atual->medico->crm, crm) == 0) {
      printf("-------------------------------------\n");
      printf("Lista de Pacientes: \n");
      if (ultimoPaciente == NULL ||
          strcmp(atual->paciente->cpf, ultimoPaciente->cpf) != 0) {
        printf("Paciente: %s\n", atual->paciente->nome);
        ultimoPaciente = atual->paciente;
      }
    }
    atual = atual->prox;
  }
}
