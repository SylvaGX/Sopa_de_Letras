#include "Palavra.h"

Palavra::Palavra() {
	this->orientacao = -1;
	this->estado = -1;
	this->Ponto_ini = Ponto(-1, -1);
	this->Ponto_ini = Ponto(-1, -1);
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

void Palavra::showPalavra() {
	for (size_t i = 0; i < this->getPalavra().size(); i++) {
		cout << this->getPalavra()[i].getLetra();
	}
	cout << endl;
}

void Palavra::setPalavra(string str) {
	int strl = str.length();
	this->palavra.resize(strl);
	for (int i = 0; i < strl; i++) {
		this->palavra[i] = Letra(str[i], Ponto(-1,-1), (int)str[i], verificaTipo(str[i]));
	}
}

int Palavra::verificaTipo(char c) {
	return ((c >= 'a') && (c <= 'z')) ? 1 : ((c >= 'A') && (c <= 'Z')) ? 0 : -1;
}

int Palavra::size() {
	return (palavra.size());
}

bool Palavra::operator==(string str2) {
	int p = 0;
	if (this->getPalavra().size() == str2.length()) {
		p = 1;
		for (size_t i = 0; (i < str2.length()) && p; i++) {
			if (this->getPalavra()[i] != str2[i]) {
				p = 0;
			}
		}
	}
	return p;
}
