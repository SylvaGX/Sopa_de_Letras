#pragma once
#include "Ponto.h"

class Letra {
	private:
		char letra;
		Ponto ponto;
		int ascii;
		static int tipo_M_m; // 0- Maiscula, 1 - Minuscula
		int bold; //0 - nao, 1 - sim
		int cor;//0 - branco, 1 - verde
	public:
		Letra();
		Letra(char m_letra, Ponto m_ponto, int m_ascii, int m_tipo_M_m);
		virtual ~Letra();
		void setLetra(char letra);
		void setPonto(Ponto ponto);
		void setAscii(int ascii);
		void setBold(int bold);
		void setCor(int cor);
		static void setTipo_M_m(int tipo_M_m);
		char getLetra() { return this->letra; };
		Ponto getPonto() { return this->ponto; };
		int getAscii() { return this->ascii; };
		int getBold() { return this->bold; };
		int getCor() { return this->cor; };
		static int toAscii(char c) { return ((int)c); };
		static int getTipo_M_m() { return tipo_M_m; };
		static int verificaTipo(char c);
		bool operator!=(char letra);
		bool operator!=(Letra letra);
};

