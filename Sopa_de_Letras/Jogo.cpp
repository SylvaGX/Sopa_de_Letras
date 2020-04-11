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
	this->tabuleiro->Draw();
	int j = 0;
	int l = 1;
	while (l) {
		cout << "1-Tentar acertar a palavra\n2-Save do jogo\n3-Sair\n";
		cin >> j;
		switch (j) {
			case 1:{
				string ask = Palavra::pedirpalavra();
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
