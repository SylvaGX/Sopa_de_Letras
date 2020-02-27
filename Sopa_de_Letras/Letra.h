#pragma once
#include "Ponto.h"

class Letra {
	private:
		char letra;
		Ponto ponto;
		int ascii;
		int tipo_M_m; // 0- Maiscula, 1 - minuscula
	public:
		Letra();
		Letra(char m_letra, Ponto m_ponto, int m_ascii, int m_tipo_M_m);
		virtual ~Letra();
		char getLetra();
		Ponto getPonto();
		int getascii();
		int getTipo_M_m();
};

