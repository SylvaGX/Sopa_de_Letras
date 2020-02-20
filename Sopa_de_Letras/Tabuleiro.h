#pragma once
#include <vector>
#include <fstream>

using namespace std;

class Tabuleiro {
	private:
		vector<vector<char>> tabuleiro;
		int DimX;
		int DimY;
		int nPalavras;
		vector<vector<char>> palavras;
	public:
		Tabuleiro();
		Tabuleiro(vector<vector<char>> m_tabuleiro, int m_DimX, int m_DimY, vector<vector<char>> m_palavras);
		virtual ~Tabuleiro();
		void Draw();
		void Save(ofstream& os);
		void Read(ifstream& is);
};

