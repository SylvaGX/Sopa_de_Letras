#include <iostream>
#include <vector>
#include <time.h>
#include "Tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro() {
	this->DimX = -1;
	this->DimY = -1;
	this->nPalavras = -1;
}

Tabuleiro::Tabuleiro(vector<vector<Letra>> matrizLetras, int DimX, int DimY, int nPalavras, vector<string> palavras) {
	this->matrizLetras = matrizLetras;
	this->DimX = DimX;
	this->DimY = DimY;
	this->nPalavras = nPalavras;
	this->palavras = palavras;
}

Tabuleiro::~Tabuleiro() {
}

void Tabuleiro::Draw() {
	//Desenhar o tabuleiro ---- Tiago
	for (int i = 0; i < this->DimY; i++) {
		for (int j = 0; j < this->DimX; j++) {
			cout << this->matrizLetras[i][j].getLetra()<<" ";
		}
		cout << endl;
	}
}

void Tabuleiro::setDimX(int DimX) {
	this->DimX = DimX;
}

void Tabuleiro::setDimY(int DimY) {
	this->DimY = DimY;
}

void Tabuleiro::set_nPalavras(int nPalavras) {
	this->nPalavras = nPalavras;
}

void Tabuleiro::setMatrizLetras(vector<vector<Letra>> matrizLetras) {
	this->matrizLetras = matrizLetras;
}

void Tabuleiro::setPalavras(vector<string> palavras) {
	this->palavras = palavras;
}

vector<vector<Letra>> Tabuleiro::getMatrizLetras() {
	return this->matrizLetras;
}

vector<string> Tabuleiro::getPalavras() {
	return this->palavras;
}

void Tabuleiro::GenerarMatriz() {
	srand(time(NULL));
	this->matrizLetras.resize(DimX, vector<Letra>(DimY));
	int r = 0;
	for (int i = 0; i < this->DimY; i++) {
		for (int j = 0; j < this->DimX; j++) {
			r = rand() % 26 + 65;
			this->matrizLetras[i][j] = Letra((char) r, Ponto(i, j), r, 1);
		}
	}
}

void Tabuleiro::Save(ofstream& os) {
}

void Tabuleiro::Read(ifstream& is) {
}
