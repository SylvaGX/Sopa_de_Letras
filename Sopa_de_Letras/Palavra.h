#pragma once
#include <iostream>
#include <locale>
#include <algorithm>
#include <string>
#include <vector>
#include "Letra.h"

using namespace std;

class Palavra {
	private:
		string palavra;
		int orientacao; // 0 - HE-HD, 1 - HD-HE, 2 - VC-VB, 3 - VB-VC, 4 - D1C-D1B, 5 - D1B-D1C, 6 - D2C-D2B, 7 - D2B-D2C
		int estado; //0 - N descoberto, 1 - Descoberta
		Ponto pIni;
	public:
		Palavra();
		Palavra(string m_palavra, int m_orientacao, int m_estado, Ponto pIni);
		virtual ~Palavra();
		void setOrientacao(int orientacao);
		void setEstado(int estado);
		void setPonto(Ponto pIni);
		string getPalavra() { return palavra; };
		int getOrientacao() { return orientacao; };
		int getEstado() { return estado; };
		Ponto getPonto() { return pIni; };
		void showPalavra();
		void setPalavra(string str);
		static string pedirpalavra(size_t DimX, size_t DimY);
		static void CheckWordAccents(string &str);
		size_t size();
		bool operator== (string str2);
		bool operator<(Palavra str);
		bool operator>(Palavra str);
};

