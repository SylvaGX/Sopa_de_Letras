#pragma once
#include "Tabuleiro.h"
#include "Jogador.h"

class Jogo {
	private:
		Tabuleiro tabuleiro;
		Jogador jogador;
	public:
		Jogo();
		Jogo(Tabuleiro m_tabuleiro, Jogador m_jogador);
		virtual ~Jogo();
		Tabuleiro getTabuleiro();
		Jogador getJogador();
};

