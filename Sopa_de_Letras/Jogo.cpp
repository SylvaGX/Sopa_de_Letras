#include "Jogo.h"

Jogo::Jogo() {
	this->tabuleiro = NULL;
	this->jogador = NULL;
}

Jogo::Jogo(Tabuleiro *tabuleiro, Jogador *jogador) {
	this->tabuleiro = tabuleiro;
	this->jogador = jogador;
}

Jogo::~Jogo() {
	delete tabuleiro;
	delete jogador;
}

void Jogo::iniciarJogo() {
	//pedir a dimensão do tabuleiro
	int dimX = 20, dimY = 20;
	//iniciar o tabuleiro
	this->tabuleiro = new Tabuleiro;

	//pedir as infomarções do jogador
	//iniciar o jogador
}

void Jogo::init() {
}

Tabuleiro* Jogo::getTabuleiro() {
	return this->tabuleiro;
}

Jogador* Jogo::getJogador() {
	return this->jogador;
}
