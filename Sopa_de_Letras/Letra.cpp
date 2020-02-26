#include "Letra.h"

Letra::Letra() {
	letra = '-';
	ascii = -1;
	tipo_M_m = -1;
}

Letra::Letra(char m_letra, Ponto m_ponto, int m_ascii, int m_tipo_M_m) {
	letra = m_letra;
	ponto = m_ponto;
	ascii = m_ascii;
	tipo_M_m = m_tipo_M_m;
}

Letra::~Letra() {
}

char Letra::getLetra() {
	return letra;
}

Ponto Letra::getPonto() {
	return ponto;
}

int Letra::getascii() {
	return ascii;
}

int Letra::getTipo_M_m() {
	return tipo_M_m;
}
