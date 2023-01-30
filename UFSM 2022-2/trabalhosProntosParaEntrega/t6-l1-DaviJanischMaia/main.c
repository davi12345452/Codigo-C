// Programa de exemplo de uso de tela.h e tela.c
//
// Necessita os arquivos exemplo.c (este), tela.h, tela.c e DejaVuSans.ttf
// Necessita ter instalado a biblioteca allegro5
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o exemplo exemplo.c tela.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "tela.h"

#define LARGURA 500
#define ALTURA 600

typedef struct coordenada {
  float x1;
  float y1;
  float x2;
  float y2;
} coordenada;

typedef struct rodada {
  int jogada[4];
  int cont;
  bool enviar;
  bool pronto;
} rodada;

typedef struct jogador{
  int pontuacao;
  char nick[5];
} jogador;

typedef struct partida {
  int jogadas[9][4];
  int contador;
  int secret[4];
  coordenada cliques[10];
  bool desistiu;
  int pretosBrancos[9][2];
  jogador player;
  bool ganhou;
} partida;

typedef struct jogo{
  jogador ultimoElemento;
  jogador top5[5];
  bool encerrarPartida;
} jogo;

void desenhaTemp(rodada *rodada, partida *estado){
  int xi = 10, xf = 40, yi = 10 , yf = 40;
  int ident = estado->contador;
  int ident2 = rodada->cont;
  // Para imprimir corretamente
  yi += ident * 40;
  yf += ident * 40;
  if(ident2 != 0){
    for(int i = 0; i < ident2; i++){
      // Problema de segmention:
      tela_retangulo(xi, yi, xf, yf, 0, rodada->jogada[i], rodada->jogada[i]);
      xi += 40;
      xf += 40;
    }
  }
}

void desenha_linhas(partida *estado, int yi, int yf, int cont){
  int xi = 10; int xf = 40;
  for(int i = 0; i < 4; i++){
    tela_retangulo(xi, yi, xf, yf, 0, estado->jogadas[cont][i], estado->jogadas[cont][i]);
    xi += 40;
    xf += 40;
    
  }
  xi += 100;
  xf += 100;
  for(int i = 0; i < estado->pretosBrancos[cont][0]; i++){
    tela_retangulo(xi, yi, xf, yf, 1, branco, preto);
    xi += 40;
    xf += 40;
  }
  for(int i = 0; i < estado->pretosBrancos[cont][1]; i++){
    tela_retangulo(xi, yi, xf, yf, 1, branco, branco);
    xi += 35;
    xf += 35;
  }
}

void desenha_jogadas(partida *estado){
  int yi = 10, yf = 40;
  for(int i = 0; i < estado->contador; i++){
    desenha_linhas(estado, yi, yf, i);
    yi += 40;
    yf += 40;
  }
  
}
void desenha_opcoes(partida *estado){
  float yi = 401, yf = 461, xi = 10, xf = 70;
  for(int i = 0; i < 7; i++){
    coordenada opcao;
    tela_retangulo(xi, yi, xf, yf, 1, preto, i);
    opcao.x1 = xi;
    opcao.x2 = xf;
    opcao.y1 = yi;
    opcao.y2 = yf;
    estado->cliques[i] = opcao;
    xi += 70;
    xf += 70;
  }
}
  
void desenha_botoes(partida *estado){
  char nomes[3][9] = {"Enviar", "Apagar", "Desistir"};
  float yi = 497, yf = 547, xi = 80, xf = 180;
  for(int i = 0; i < 3; i++){
    coordenada botao;
    tela_retangulo(xi, yi, xf, yf, 1, branco, transparente);
    tela_texto((xi+xf)/2, (yf+yi)/2, 20, branco, nomes[i]);
    botao.x1 = xi;
    botao.x2 = xf;
    botao.y1 = yi;
    botao.y2 = yf;
    // referencia dos botões
    estado->cliques[i+7] = botao;
    xi += 120;
    xf += 120;
  }
}

void draw_game(partida *estado){
  int margemLinhas = 20;
  tela_retangulo(0, 0, LARGURA, ALTURA, 1, preto, transparente);
  desenha_jogadas(estado);
  tela_linha(margemLinhas, 391, LARGURA-margemLinhas, 392, 1, branco);
  desenha_opcoes(estado);
  tela_linha(margemLinhas, 471, LARGURA-margemLinhas, 472, 1, branco);
  desenha_botoes(estado);
}

int retorna_click(partida *estado){
  float x = tela_rato_x_clique();
  float y = tela_rato_y_clique();
  for(int i = 0; i < 10; i++){
    if(x > estado->cliques[i].x1 && x < estado->cliques[i].x2 && y > estado->cliques[i].y1 && y < estado->cliques[i].y2) return i;
  }
}

void sorteiaSecret(partida *estado){
  srand(time(0));
  int num;
  for(int i = 0; i < 4; i++){
    do {
      num = rand() % 7;
      for(int j = 0; j < i; j++){
        if(estado->secret[j] == num){
          num = -1;
          break;
        }
      }
    } while (num == -1);
    estado->secret[i] = num;
  }
}

void adicionaPretBran(partida *estado) {
  int cont = estado->contador;
  int brancos = 0, pretos = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (estado->jogadas[cont][i] == estado->secret[j]) {
        if (i == j) pretos++;
        else brancos++;
      }
    }
  }
  estado->pretosBrancos[cont][0] = pretos;
  estado->pretosBrancos[cont][1] = brancos;
}


void incrementaJogada(int jogada, rodada *rodada){
  bool verificador = true;
  if(rodada->cont == 0) {
    rodada->jogada[0] = jogada;
    rodada->cont++;
    }
  else{
    for(int i = 0; i < rodada->cont; i++){
      if(jogada == rodada->jogada[i]){
        verificador = false;
        break;
      }
    }
    if(verificador){
      if(!rodada->pronto){
        rodada->jogada[rodada->cont] = jogada;
        rodada->cont ++;
      }
    }
  }
  if(rodada -> cont == 4) rodada->pronto = true;
  else rodada->pronto = false;
}

void verificaJogada(rodada *rodada, partida *estado, int clique){
  if(clique >= 0 && clique <= 6) incrementaJogada(clique, rodada);
  else if(clique == 7) {
    if(rodada->cont == 4) rodada->enviar = true;
  }
  else if(clique == 8) {
    if(rodada->cont > 0){
    rodada->jogada[rodada->cont] = 10;
    rodada->cont --;
    }
  }
  else if(clique == 9){
    estado->desistiu = true;
  }
}

void rodadaDoJogo(partida *estado){
  rodada rodada;
  int estadoContador = estado->contador;
  rodada.enviar = false;
  rodada.pronto = false;
  rodada.cont = 0;
  while(true){
    draw_game(estado);
    desenhaTemp(&rodada, estado);
    tela_circulo(tela_rato_x(), tela_rato_y(), 2, 2, branco, branco);
    if(tela_rato_clicado()){
      int clique = retorna_click(estado);
      verificaJogada(&rodada, estado, clique);
      if(estado->desistiu) break;
      if(rodada.enviar && rodada.pronto){
        for(int i = 0; i < 4; i++){
          estado->jogadas[estadoContador][i] = rodada.jogada[i];
        }
        break;
      }
    }
    tela_atualiza();
  } 
}

void verificaSeGanhou(partida *estado){
  bool verifica = true;
  for(int i = 0; i < 4; i++){
    if(estado->jogadas[estado->contador][i] != estado->secret[i]){
      verifica = false;
      break;
    }
  }
  estado->ganhou = verifica;
}

void calculaPontuacao(partida *estado, jogo *estadoJogo){
  int bonus = 9 - estado->contador;
  for(int i = 0; i <= estado->contador; i++){
    estado->player.pontuacao += estado->pretosBrancos[i][0] * 5 * bonus;
    estado->player.pontuacao += estado->pretosBrancos[i][1] * 3 * bonus;
  }
}

void leNickname(partida *estado, jogo *estadoJogo){
  bool enviar = false;
  char nickname[5] = "\0";
  int contador = 0;
  while(!enviar){
    tela_retangulo(10, 10, LARGURA, ALTURA, 1, branco, transparente);
    tela_texto(150, 100, 15, branco, "Digite seu nick(4 letras): ");
    tela_texto(270, 100, 15, branco, nickname);
    char tecla = tela_tecla();
    if(tecla != '\0'){
      if(tecla == '\n' && contador == 4) enviar = true;
      else{
        if(contador < 4){
        nickname[contador] = tecla;
        contador++;
        }
      }
    }
    tela_atualiza();
  }
  for(int i = 0; i < 4; i++){
    estado->player.nick[i] = nickname[i];
  }
  estado->player.nick[4] = '\0'; 
}

void partidaDoJogo(jogo *estadoJogo){
  partida estado;
  estado.desistiu = false;
  estado.contador = 0;
  estado.player.pontuacao = 0;
  sorteiaSecret(&estado);
  do{
    rodadaDoJogo(&estado);
    adicionaPretBran(&estado);
    verificaSeGanhou(&estado);
    if(estado.ganhou) break;
    if(estado.desistiu) break;
    estado.contador++;
  }while(estado.contador < 9);
  if(!estado.desistiu) {
    calculaPontuacao(&estado, estadoJogo);
    leNickname(&estado, estadoJogo);
    estadoJogo->ultimoElemento = estado.player;
  }
  
}

void abreArquivo(jogo *estadoJogo){
  FILE *file = fopen("scores.txt", "r");
  if (file == NULL) {
    printf("Não foi possível abrir o arquivo");
    exit(1);
  }
  int n;
  for (int i = 0; i < 5; i++) {
    n = fscanf(file, "%s %d\n", estadoJogo->top5[i].nick, &estadoJogo->top5[i].pontuacao);
    if (n != 2) {
      printf("Erro na leitura do arquivo");
      exit(1);
    }
  }

  fclose(file);
}

void acrescentaTop5(jogo *estadoJogo){
  int controlador = -1;
  jogador temp[5];

  for(int i = 0; i < 5; i++){
    if(estadoJogo->top5[i].pontuacao < estadoJogo->ultimoElemento.pontuacao){
      controlador = i;
      break;
    }
    temp[i] = estadoJogo->top5[i];
  }

  if(controlador != -1){
    temp[controlador] = estadoJogo->ultimoElemento;
    for(int i = controlador + 1; i < 5; i++){
      temp[i] = estadoJogo->top5[i-1];
    }
  }
  for(int i = 0; i < 5; i++){
    estadoJogo->top5[i] = temp[i];
  }
}

void escreveArquivo(jogo *estadoJogo){
  FILE *file = fopen("scores.txt", "w");
  if (file == NULL) {
    printf("Não foi possível abrir o arquivo");
    exit(1);
  }
  for (int i = 0; i < 5; i++) {
    fprintf(file, "%s %d\n", estadoJogo->top5[i].nick, estadoJogo->top5[i].pontuacao);
  }

  fclose(file);
}

void processaArquivos(jogo *estadoJogo){
  abreArquivo(estadoJogo);
  acrescentaTop5(estadoJogo);
  escreveArquivo(estadoJogo);
}

void fimDePartida(jogo *estadoJogo){
  int x, y;
  while(true){
    tela_circulo(tela_rato_x(), tela_rato_y(), 2, 2, branco, branco);
    tela_retangulo(10, 10, LARGURA, ALTURA, 1, branco, transparente);
    tela_retangulo(100, 50, 400, 350, 1, branco, transparente);
    tela_texto(250, 70, 20, branco, "TOP 5 Pontuações");
    tela_texto(200, 120, 15, branco, "Nickname");
    tela_texto(300, 120, 15, branco, "Pontos");
    for(int i = 0; i < 5; i++){
      char bufferPontos[5];
      char bufferPosicao[2];
      tela_texto(200, 160+(30*i), 13, branco, estadoJogo->top5[i].nick);
      sprintf(bufferPontos, "%d", estadoJogo->top5[i].pontuacao);
      tela_texto(300, 160+(30*i), 13, branco, bufferPontos);
      sprintf(bufferPosicao, "%d", i + 1);
      tela_texto(130, 160+(30*i), 13, branco, bufferPosicao);
    }
    tela_texto(250, 400, 20, branco, "Deseja jogar outra partida?");
    tela_retangulo(100, 450, 200, 500, 1, branco, transparente);
    tela_texto(150, 475, 15, branco, "SIM");
    tela_retangulo(300, 450, 400, 500, 1, branco, transparente);
    tela_texto(350, 475, 15, branco, "NÃO");
    if(tela_rato_clicado()){
      x = tela_rato_x_clique();
      y = tela_rato_y_clique();
    }
    if(x >= 100 && x <= 200 && y >= 450 && y<= 500) break;
    if(x >= 300 && x <= 400 && y >= 450 && y<= 500){
      estadoJogo->encerrarPartida = true;
      break;
    }
    tela_atualiza();
  }
}
  
void jogoMain(){
  jogo estadoJogo;
  estadoJogo.ultimoElemento.pontuacao = 0;
  tela_inicio(LARGURA, ALTURA, "Mastermind Davi J Maia");
  while(true){
    estadoJogo.encerrarPartida = false;
    partidaDoJogo(&estadoJogo);
    processaArquivos(&estadoJogo);
    fimDePartida(&estadoJogo);
    if(estadoJogo.encerrarPartida) break;
  }
  tela_fim();
}


int main(void){
  jogoMain();
  return 0;
}