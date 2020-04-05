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
void Jogo::init() {
	this->tabuleiro->Draw();
	this->tabuleiro->showPalavras();
	cout << this->jogador;
	cout << this->jogador->GetPontos() << endl;
	(*(this->jogador))++;
	cout << this->jogador->GetPontos() << endl;
}

Tabuleiro* Jogo::getTabuleiro() {
	return this->tabuleiro;
}

Jogador* Jogo::getJogador() {
	return this->jogador;
}

void Jogo::NewGame() {
	this->jogador = new Jogador();
	this->tabuleiro = new Tabuleiro();
	this->tabuleiro->loadPalavras();
	this->tabuleiro->GenerarMatriz();
}

void Jogo::SaveGame() {
}

void Jogo::LoadGame() {
}
