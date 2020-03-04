#pragma once
#include "Tabuleiro.h"
#include "Jogador.h"

class Jogo {
	private:
		Tabuleiro *tabuleiro;
		Jogador *jogador;
	public:
		Jogo();
		virtual ~Jogo();
		void init(); //fun��o do jogo
		Tabuleiro* getTabuleiro();
		Jogador* getJogador();
		void NewGame();
		void SaveGame();
		void LoadGame();
};

