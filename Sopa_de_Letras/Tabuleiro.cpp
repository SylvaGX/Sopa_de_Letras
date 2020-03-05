#include "Tabuleiro.h"

using namespace std;

bool is_digit(const char value) { return isdigit(value); }
bool is_numeric(const string& value) { return all_of(value.begin(), value.end(), is_digit); }

Tabuleiro::Tabuleiro() {
	cout << "Digite as dimenções da matriz\n-> ";
	cin >> this->DimX >> this->DimY;
	//ler o ficheiro das palavras
	this->nPalavras = -1;
}

Tabuleiro::Tabuleiro(vector<vector<Letra>> matrizLetras, int DimX, int DimY, int nPalavras, vector<Palavra> palavras) {
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
	for (int i = 0; i < this->DimX; i++) {
		for (int j = 0; j < this->DimY; j++) {
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

void Tabuleiro::setPalavras(vector<Palavra> palavras) {
	this->palavras = palavras;
}

vector<vector<Letra>> Tabuleiro::getMatrizLetras() {
	return this->matrizLetras;
}

vector<Palavra> Tabuleiro::getPalavras() {
	return this->palavras;
}

void Tabuleiro::showPalavras() {
	for (size_t i = 0; i < this->getPalavras().size(); i++) {
		this->getPalavras()[i].showPalavra();
	}
}

bool Tabuleiro::loadPalavras() {
	ifstream is;
	is.open("words.txt");
	if (is) {
		int n = 0;
		int i = 0;
		string aux;
		getline(is, aux);
		if (is_numeric(aux)) {
			n = stoi(aux);
			aux = "";
			this->palavras.resize(n);
			while (is && (i < n)) {
				getline(is, aux);
				this->palavras[i].setPalavra(aux);
				i++;
			}
		}
	}
	return false;
}

void Tabuleiro::GenerarMatriz() {
	srand(time(NULL));
	this->matrizLetras = vector<vector<Letra> >(DimX, vector<Letra>(DimY));
	int r = 0;
	for (int i = 0; i < this->DimX; i++) {
		for (int j = 0; j < this->DimY; j++) {
			r = rand() % 26 + 65;
			this->matrizLetras[i][j] = Letra((char) r, Ponto(i, j), r, 1);
		}
	}
}

void Tabuleiro::Save(ofstream& os) {
}

void Tabuleiro::Read(ifstream& is) {
}
