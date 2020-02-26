#include "Tabuleiro.h"

Tabuleiro::Tabuleiro() {
	DimX = -1;
	DimY = -1;
	nPalavras = -1;
}

Tabuleiro::Tabuleiro(vector<vector<Letra>> m_matrizLetras, int m_DimX, int m_DimY, int m_nPalavras, vector<string> m_palavras) {
	matrizLetras = m_matrizLetras;
	DimX = m_DimX;
	DimY = m_DimY;
	palavras = m_palavras;
}

Tabuleiro::~Tabuleiro() {
}

void Tabuleiro::Draw() {
}

void Tabuleiro::Save(ofstream& os) {
}

void Tabuleiro::Read(ifstream& is) {
}
