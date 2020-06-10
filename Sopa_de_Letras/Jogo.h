#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Tabuleiro.h"
#include "Jogador.h"

class Jogo {
	private:
		Tabuleiro *tabuleiro;
		Jogador *jogador;
		string namefile;
	public:
		Jogo();
		~Jogo();
		bool init(); //função que inicializa o jogador
		Tabuleiro* getTabuleiro();
		Jogador* getJogador();
		void loop();//loop do jogo
		int Save();
		void Load();
};

