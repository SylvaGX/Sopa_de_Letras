#pragma once
#include <vector>
#include "Letra.h"

class Palavra {
	private:
		vector<Letra> palavra;
		int orientacao; // 0 - Horizontal, 1 - vertical, 2 - diagonal
		int estado; //0 - N descoberto, 1 - Descoberta
	public:
		Palavra();
		Palavra(vector<Letra> m_palavra, int m_orientacao, int m_estado);
		virtual ~Palavra();
		void setOrientacao(int orientacao);
		void setEstado(int estado);
		vector<Letra> getPalavra();
		int getOrientacao();
		int getEstado();
		bool operator== (Palavra str2);
};

