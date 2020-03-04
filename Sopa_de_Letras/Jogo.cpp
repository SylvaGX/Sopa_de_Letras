#include <iostream>
#include "Jogo.h"

using namespace std;

Jogo::Jogo(){
	this->jogador = NULL;
	this->tabuleiro = NULL;
}

Jogo::~Jogo() {
}

void Jogo::init() {
	this->tabuleiro->Draw();
	cout << this->jogador->GetNome() << endl;
	cout << this->jogador->GetIdade() << endl;
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
	this->tabuleiro->setDimX(20);
	this->tabuleiro->setDimY(20);
	this->tabuleiro->GenerarMatriz();
}

void Jogo::SaveGame() {
}

void Jogo::LoadGame() {
}
