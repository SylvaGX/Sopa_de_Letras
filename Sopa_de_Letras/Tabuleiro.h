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
		Tabuleiro(vector<vector<Letra>> matrizLetras, int DimX, int DimY, int nPalavras, vector<string> palavras);
		virtual ~Tabuleiro();
		void Draw();
		void setDimX(int DimX);
		void setDimY(int DimY);
		void set_nPalavras(int nPalavras);
		void setMatrizLetras(vector<vector<Letra>> matrizLetras);
		void setPalavras(vector<string> palavras);
		vector<vector<Letra>> getMatrizLetras();
		vector<string> getPalavras();
		void GenerarMatriz();
		void Save(ofstream& os);
		void Read(ifstream& is);
};

