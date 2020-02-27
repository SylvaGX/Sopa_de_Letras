#include "Palavra.h"

Palavra::Palavra() {
	this->orientacao = -1;
	this->estado = -1;
}

Palavra::Palavra(vector<Letra> m_palavra, int m_orientacao, int m_estado) {
	this->palavra = m_palavra;
	this->orientacao = m_orientacao;
	this->estado = m_estado;
}

Palavra::~Palavra() {
}

vector<Letra> Palavra::getPalavra() {
	return this->palavra;
}

int Palavra::getOrientacao() {
	return this->orientacao;
}

int Palavra::getEstado() {
	return this->estado;
}
