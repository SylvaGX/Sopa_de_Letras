#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include "Letra.h"
#include "Palavra.h"

using namespace std;

class Tabuleiro {
	private:
		vector<vector<Letra>> matrizLetras;
		int DimX;
		int DimY;
		int nPalavras;
		vector<Palavra> palavras;
		bool GetPossibilities(vector<Palavra>::iterator p, vector<pair<int, pair<int, int>>> &opcoes, int x, int y);
	public:
		Tabuleiro();
		Tabuleiro(vector<vector<Letra>> matrizLetras, int DimX, int DimY, int nPalavras, vector<Palavra> palavras);
		virtual ~Tabuleiro();
		void Draw();
		void setDimX(int DimX);
		void setDimY(int DimY);
		void set_nPalavras(int nPalavras);
		void setMatrizLetras(vector<vector<Letra>> matrizLetras);
		void setPalavras(vector<Palavra> palavras);
		vector<vector<Letra>> getMatrizLetras();
		vector<Palavra> getPalavras();
		void showPalavras();
		bool loadPalavras();
		void GenerarMatriz();
		void CountSpaceMatriz(vector<int>& X, vector<int>& Y);
		bool PutM(vector<Palavra>::iterator &p, vector<int> X, vector<int> Y);
		bool PutDiag(vector<Palavra>::iterator p);
		void SelectPalavras();
		void Save(ofstream& os);
		void Read(ifstream& is);
};

