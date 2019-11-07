#ifndef PEAO_H
#define PEAO_H
#include "tabuleiro.h"

class Peao {
  private:
    char peao;
    bool cor;
  
  public:
    Peao(bool c);
    bool casaInicial();
    bool jogadaPossivel();
    int movimentos();
    int movimentoPeao();
};

#endif