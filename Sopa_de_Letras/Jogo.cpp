#include <iostream>
#include "Jogo.h"

using namespace std;

Jogo::Jogo(){
	this->jogador = NULL;
	this->tabuleiro = NULL;
}

Jogo::~Jogo() {
}

//Loop do jogo
void Jogo::loop() {
	int j = 0;
	int l = 1;
	while (l) {
		this->tabuleiro->Draw();
		cout << "1-Tentar acertar a palavra\n2-Save do jogo\n0-Sair\n";
		cin >> j;
		switch (j) {
			case 1:{
				string ask = Palavra::pedirpalavra();
				this->getTabuleiro()->VerificarPalavra(ask);
				//system("CLS");
				break;
			}
			case 2:{
				break;
			}
			case 0:{
				l = 0;
				break;
			}
		}
	}
}
//verificar as palavras(vetor)(pesquisa binaria)
Tabuleiro* Jogo::getTabuleiro() {
	return this->tabuleiro;
}

Jogador* Jogo::getJogador() {
	return this->jogador;
}

void Jogo::init() {
	this->jogador = new Jogador();
	this->tabuleiro = new Tabuleiro();
	Letra::setTipo_M_m(Letra::generateM_m());
	this->tabuleiro->loadPalavras();
	this->tabuleiro->GenerarMatriz();
}

void Jogo::SaveGame() {
}

void Jogo::LoadGame() {
}
