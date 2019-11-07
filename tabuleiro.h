#ifndef CHESS_H
#define CHESS_H

class Tabuleiro {
  private:
    char *tab;

  public:
    Tabuleiro(char t[]);
    void imprimeTabuleiro();
    char* getTab();
};

#endif