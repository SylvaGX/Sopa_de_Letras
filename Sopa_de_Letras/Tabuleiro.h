#pragma once
#include "Main.h"
#include "Jogador.h"
#include "Letra.h"
#include "Palavra.h"

class Tabuleiro {
	private:
		vector<vector<Letra>> matrizLetras;
		size_t DimX;
		size_t DimY;
		int nPalavras;
		vector<Palavra> palavras;
		vector<Palavra> guessWords;
		string categoria;
		bool GetPossibilities(vector<Palavra>::iterator p, vector<pair<int, pair<int, int>>> &opcoes, int x, int y, Jogador* j);
	public:
		Tabuleiro();
		Tabuleiro(vector<vector<Letra>> matrizLetras, size_t DimX, size_t DimY, int nPalavras, vector<Palavra> palavras);
		virtual ~Tabuleiro();
		void newTabuleiro();
		void Draw();
		void setDimX(size_t DimX);
		void setDimY(size_t DimY);
		void setNpalavras(int nPalavras);
		void setMatrizLetras(vector<vector<Letra>> matrizLetras);
		void setPalavras(vector<Palavra> palavras);
		void setCategoria(string categoria);
		size_t getDimX() { return DimX; };
		size_t getDimY() { return DimY; };
		string getCategoria() {return categoria;};
		vector<vector<Letra>> getMatrizLetras();
		vector<Palavra> getPalavras();
		vector<Palavra> getGuessWords() { return this->guessWords; };
		void showPalavras();
		bool loadPalavras();
		void GenerarMatriz(Jogador* j);
		void CountSpaceMatriz(vector<int>& X, vector<int>& Y);
		bool PutM(vector<Palavra>::iterator &p, vector<int> X, vector<int> Y,Jogador* j);
		bool PutDiag(vector<Palavra>::iterator p);
		void SelectPalavras(Jogador* j);
		int VerificarPalavra(string str, Jogador &jog);
		void Save(ofstream& os);
		bool Load(ifstream& is);
};

