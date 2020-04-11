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
		void init(); //função que inicializa o jog
		Tabuleiro* getTabuleiro();
		Jogador* getJogador();
		void loop();//loop do jogo
		void SaveGame();
		void LoadGame();
};

