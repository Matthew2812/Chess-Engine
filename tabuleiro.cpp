#include <iostream>
#include "tabuleiro.h"
#define TAM 89

Tabuleiro::Tabuleiro(char t[]){
  tab = t;
}

void Tabuleiro::imprimeTabuleiro() {
  int aux;
  for(int i = 0; i < TAM; i++) {
    aux = tab[i] - 48;
    if(tab[i] == 0)
      break;
    else if(0 <= aux && aux <= 8 && tab[i-1] != '/') {
      for(int j = i; j < i+aux; j++) {
        std::cout << ". ";
      }
    }
    else if(tab[i] != '/') {
      std::cout << tab[i] << ' ';

    }
    else
      std::cout << std::endl;
  }
}

char* Tabuleiro::getTab() {
  return tab;
}