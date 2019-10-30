#include <iostream>
#include <random>
#include <cmath>
#include "chess.h"

//Transformar tudo em classe

//Caractere para cada peça e casa
char peao = 'P';
char cavalo = 'C';
char bispo = 'B';
char torre = 'T';
char dama = 'D';
char rei = 'R';
char casa = '.';

//Pontuações de cada peça
short int pont_peao = 1;
short int pont_cavalo = 3;
short int pont_bispo = 4;
short int pont_torre = 5;
short int pont_dama = 9;
short int pont_rei = 900;

bool casaInicial(char peca, char *jogada, std::string jogador){
  if(peca == peao){
    if(jogador == "Brancas")
      return jogada[1] == 2? true : false;
    else
      return jogada[1] == 7? true : false;
  }
  return true;
}

bool jogadaPossivel(char *jogada, std::string jogador){
  if(jogador == "Brancas"){
    int mov = abs(jogada[3] - jogada[1]);
    if(mov < 3 && mov > 0)
      return true;
    return false;
  
  } else {
    int mov = abs(jogada[1] - jogada[3]);
    if(mov < 3 && mov > 0)
      return true;
    return false;
  }
}

void criaTabuleiro(char tabuleiro[][9]){
  char end_letras = 'a';
    char end_numero = '8';
  
    for (int i = 1; i < 9; i++){
        tabuleiro[i][0] = end_numero;
        tabuleiro[0][i] = end_letras;
        end_numero--;
        end_letras++;
    }
    for (int i = 1; i < 9; i++){
        tabuleiro[2][i] = tabuleiro[7][i] = 'P';
    }
    
    for (int i = 3; i < 7; i++){
        for (int j = 1; j < 9; j++){
            tabuleiro[i][j] = '.';
        }
    }
    
    tabuleiro[1][1] = tabuleiro[1][8] = tabuleiro[8][1] = tabuleiro[8][8] = torre;
    tabuleiro[1][2] = tabuleiro[1][7] = tabuleiro[8][2] = tabuleiro[8][7] = cavalo;
    tabuleiro[1][3] = tabuleiro[1][6] = tabuleiro[8][3] = tabuleiro[8][6] = bispo;
    tabuleiro[1][4] = tabuleiro[8][4] = dama;
    tabuleiro[1][5] = tabuleiro[8][5] = rei;

    imprimeTabuleiro(tabuleiro);
}

void imprimeTabuleiro(char tabuleiro[][9]){
  tabuleiro[0][0] = '/';
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      std::cout << tabuleiro[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

int movimentoPeao(bool inicial, char *jogada, char tabuleiro[][9], int casa_atual, std::string jogador){

  bool possivel = jogadaPossivel(jogada, jogador);

  if(!possivel)
    return -1;

  int tam = sizeof(tabuleiro[0])/sizeof(tabuleiro[0][0]);
  int linha_prox = tam - jogada[3]; 
  int diferenca = tam - jogada[0];
  int coluna_prox = tam - diferenca;
}

int movimentos(char *jogada, char tabuleiro[][9], std::string jogador){
  bool inicial;
  int jogada_possivel;
  char ascii_atual = toupper(jogada[0]);
  int casa_atual = ascii_atual - 64;
  switch (tabuleiro[57 - jogada[1]][casa_atual]){
    case 'P':
      inicial = casaInicial(peao, jogada, jogador);
      jogada_possivel = movimentoPeao(inicial, jogada, tabuleiro, casa_atual, jogador);
      break;
  }
  return jogada_possivel;
}