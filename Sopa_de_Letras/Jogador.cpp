#include "Jogador.h"

Jogador::Jogador() {
	this->nome = "Sem nome";
	this->idade = -1;
	this->pontos = 0;
}

Jogador::Jogador(string nome, int idade, int pontos) {
	this->nome = nome;
	this->idade = idade;
	this->pontos = pontos;
}

Jogador::~Jogador() {
}

void Jogador::setJogador(string nome, int idade) {
	this->nome = nome;
	this->idade = idade;
}

void Jogador::setNome(string nome) {
	this->nome = nome;
}

void Jogador::setIdade(int idade) {
	this->idade = idade;
}

void Jogador::operator++(int pontos) {
	
}
