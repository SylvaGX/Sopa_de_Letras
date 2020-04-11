#include "Palavra.h"

Palavra::Palavra() {
	this->orientacao = -1;
	this->estado = -1;
	this->pIni = Ponto(-1, -1);
}

Palavra::Palavra(string palavra, int orientacao, int estado, Ponto pIni) {
	this->palavra = palavra;
	this->orientacao = orientacao;
	this->estado = estado;
	this->pIni = pIni;
}

Palavra::~Palavra() {
}

void Palavra::setOrientacao(int orientacao) {
	this->orientacao = orientacao;
}

void Palavra::setEstado(int estado) {
	this->estado = estado;
}

void Palavra::setPonto(Ponto pIni) {
	this->pIni = pIni;
}

void Palavra::showPalavra() {
	for (size_t i = 0; i < this->getPalavra().size(); i++) {
		cout << this->getPalavra()[i];
	}
}

void Palavra::setPalavra(string str) {
	this->palavra = str;
}

string Palavra::pedirpalavra() {
	string pedir;
	cout << "Qual é a palavra que queres advinhar?\n->";
	cin >> pedir;
	return pedir;
}

size_t Palavra::size() {
	return (palavra.size());
}

bool Palavra::operator==(string str2) {
	return (this->getPalavra() == str2);
}

bool Palavra::operator<(Palavra str) {
	return (this->getPalavra() < str.getPalavra());
}

bool Palavra::operator>(Palavra str) {
	return (this->getPalavra() > str.getPalavra());
}
