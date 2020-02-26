#pragma once
#include <vector>
#include <fstream>
#include "Letra.h"

using namespace std;

class Tabuleiro {
	private:
		vector<vector<Letra>> matrizLetras;
		int DimX;
		int DimY;
		int nPalavras;
		vector<string> palavras;
	public:
		Tabuleiro();
		Tabuleiro(vector<vector<Letra>> m_matrizLetras, int m_DimX, int m_DimY, int m_nPalavras, vector<string> m_palavras);
		virtual ~Tabuleiro();
		void Draw();
		void Save(ofstream& os);
		void Read(ifstream& is);
};

