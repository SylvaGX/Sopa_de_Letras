#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include "Jogador.h"
#include "Letra.h"
#include "Palavra.h"

using namespace std;

class Tabuleiro {
	private:
		vector<vector<Letra>> matrizLetras;
		size_t DimX;
		size_t DimY;
		int nPalavras;
		vector<Palavra> palavras;
		vector<Palavra> guessWords;
		bool GetPossibilities(vector<Palavra>::iterator p, vector<pair<int, pair<int, int>>> &opcoes, int x, int y);
	public:
		Tabuleiro();
		Tabuleiro(vector<vector<Letra>> matrizLetras, size_t DimX, size_t DimY, int nPalavras, vector<Palavra> palavras);
		virtual ~Tabuleiro();
		void Draw();
		void setDimX(size_t DimX);
		void setDimY(size_t DimY);
		void set_nPalavras(int nPalavras);
		void setMatrizLetras(vector<vector<Letra>> matrizLetras);
		void setPalavras(vector<Palavra> palavras);
		size_t getDimX() { return DimX; };
		size_t getDimY() { return DimY; };
		vector<vector<Letra>> getMatrizLetras();
		vector<Palavra> getPalavras();
		void showPalavras();
		bool loadPalavras();
		void GenerarMatriz();
		void CountSpaceMatriz(vector<int>& X, vector<int>& Y);
		bool PutM(vector<Palavra>::iterator &p, vector<int> X, vector<int> Y);
		bool PutDiag(vector<Palavra>::iterator p);
		void SelectPalavras();
		string VerificarPalavra(string str, Jogador &jog);
		void Save(ofstream& os);
		void Read(ifstream& is);
};

