#ifndef CHESS_H
#define CHESS_H

bool casaInicial(char peca, char *jogada, std::string jogador);

bool jogadaPossivel(char *jogada, std::string jogador);

void criaTabuleiro(char tabuleiro[][9]);

void imprimeTabuleiro(char tabuleiro[][9]);

int movimentos(char *jogada, char tabuleiro[][9], std::string jogador);

int movimentoPeao(bool inicial, char *jogada, char tabuleiro, int casa_atual, std::string jogador);

#endif