#pragma once
#include "Tabuleiro.h"
#include "Jogador.h"

class Jogo {
	private:
		Tabuleiro *tabuleiro;
		Jogador *jogador;
	public:
		Jogo();
		Jogo(Tabuleiro *tabuleiro, Jogador *jogador);
		virtual ~Jogo();
		void iniciarJogo();
		void init(); //função do jogo
		Tabuleiro* getTabuleiro();
		Jogador* getJogador();
};

