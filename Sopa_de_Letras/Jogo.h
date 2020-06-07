#pragma once
#include "Main.h"
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
		string getNameFile() { return namefile; };
		void setNameFile(string namefile);
		Jogador* perdirDificuldade();
		void loop();//loop do jogo
		int Save();
		bool Load(ifstream& is);
};

