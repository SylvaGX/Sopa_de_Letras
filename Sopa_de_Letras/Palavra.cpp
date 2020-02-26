#include "Palavra.h"

Palavra::Palavra() {
	orientacao = -1;
	estado = -1;
}

Palavra::Palavra(vector<Letra> m_palavra, int m_orientacao, int m_estado) {
	palavra = m_palavra;
	orientacao = m_orientacao;
	estado = m_estado;
}

Palavra::~Palavra() {
}

vector<Letra> Palavra::getPalavra() {
	return palavra;
}

int Palavra::getOrientacao() {
	return orientacao;
}

int Palavra::getEstado() {
	return estado;
}
