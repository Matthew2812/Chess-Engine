#include <iostream>
#include <cmath>
#include "tabuleiro.h"
#define MAX 80

int main() {
  char t[MAX] = "Xabcdefgh/8tcbdrbct/7pppppppp/68/58/48/38/2PPPPPPPP/1TCBDRBCT";
  Tabuleiro tabuleiro(t);
  tabuleiro.imprimeTabuleiro();
}