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
		void setLetra(char letra);
		void setPonto(Ponto ponto);
		void setAscii(int ascii);
		void setTipo_M_m(int tipo_M_m);
		char getLetra();
		Ponto getPonto();
		int getascii();
		int getTipo_M_m();
		bool operator!=(char letra);
		bool operator!=(Letra letra);
};

