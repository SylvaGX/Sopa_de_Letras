#include "Jogo.h"

Jogo::Jogo() {
}

Jogo::Jogo(Tabuleiro m_tabuleiro, Jogador m_jogador) {
	tabuleiro = m_tabuleiro;
	jogador = m_jogador;
}

Jogo::~Jogo() {
}

Tabuleiro Jogo::getTabuleiro() {
	return tabuleiro;
}

Jogador Jogo::getJogador() {
	return jogador;
}
