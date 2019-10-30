#include <iostream>
#include <cmath>
#include "chess.h"

int main() {
  //Matriz do tabuleiro
  char tabuleiro[9][9];
  char jogada[4];
  std::string jogador = "Brancas";
  int contador_movimentos = 0;
  int movimento_invalido = 0;

  criaTabuleiro(tabuleiro);
  while (true){

    if (std::fmod(contador_movimentos, 2) == 0)
      jogador = "Brancas";
    else
      jogador = "Negras";

    std::cout << "Contador de Jogadas: " << contador_movimentos;
    std::cout << "\nMovimento das " << jogador << std::endl;
    std::cin >> jogada;

    contador_movimentos++;
    movimento_invalido = movimentos(jogada, tabuleiro, jogador);

    if(movimento_invalido == -1){
      std::cout << "Movimento inválido" << std::endl;
      contador_movimentos--;
    }

    imprimeTabuleiro(tabuleiro);
  }
}