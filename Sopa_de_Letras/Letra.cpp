#include "Letra.h"

Letra::Letra() {
	this->letra = '-';
	this->ascii = -1;
	this->tipo_M_m = -1;
}

Letra::Letra(char m_letra, Ponto m_ponto, int m_ascii, int m_tipo_M_m) {
	this->letra = m_letra;
	this->ponto = m_ponto;
	this->ascii = m_ascii;
	this->tipo_M_m = m_tipo_M_m;
}

Letra::~Letra() {
}

char Letra::getLetra() {
	return this->letra;
}

Ponto Letra::getPonto() {
	return this->ponto;
}

int Letra::getascii() {
	return this->ascii;
}

int Letra::getTipo_M_m() {
	return this->tipo_M_m;
}