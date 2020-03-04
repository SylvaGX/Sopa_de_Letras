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

void Palavra::setOrientacao(int orientacao) {
	this->orientacao = orientacao;
}

void Palavra::setEstado(int estado) {
	this->estado = estado;
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

bool Palavra::operator==(Palavra str2) {
	int p = 0;
	if (this->getPalavra().size() == str2.getPalavra().size()) {
		p = 1;
		for (int i = 0; (i < str2.getPalavra().size()) && p; i++) {
			if (this->getPalavra()[i] != str2.getPalavra()[i]) {
				p = 0;
			}
		}
	}
	return p;
}
