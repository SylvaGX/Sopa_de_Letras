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

void Tabuleiro::SelectPalavras(){
	vector<Palavra> auxP;
	vector<int> vert(DimX, 0);
	vector<int> horz(DimY, 0);
	time_t t;
	srand(time(&t));
	int dir = 0;
	for (vector<Palavra>::iterator i = this->palavras.begin(); i != this->palavras.end(); i++) {
		dir = rand() % 2;
		if (dir == 0) { // Vertical
			if (i->size() <= DimX) { //Por na vertical se menor do que DimX
				if (!all_of(horz.begin(), horz.end(), [horz](int x) {return x == 1; })) {
					//Verificar se tem palavras na posição que vou inserir a palavra
					for (size_t i = 0; i < horz.size(); i++) {

					}
				}
				else if(i->size() <= DimY) {//senão meter na horizontal ou diagonal

				}
			}
			else if(i->size() <= DimY) {//Senão por na horizontal ou diagonal se menor do que DimY
				//Se DimY < DimX decidir na horizontal ou diagonal
				
			}
			//não por a palavra
		}
		else if (dir == 1) { // Horizontal
			if (i->size() <= DimY) {//Por na horizontal se menor do que DimY

			}
			else if (i->size() <= DimX) {//Senão por na vertical ou diagonal se menor do que DimX
				//Se DimX < DimY decidir na vertical ou diagonal
			}
		}
		else { //Diagonal
			/*
			Ver se a palavra cabe na diagonal
			if (this->palavras[i].size() <=	min(DimX,DimY)) {
				Diagonal
			}
			senao escolher entre diagonal ou vertical
			*/
		}
		auxP.push_back(*i);
		palavras.erase(i);
		i--;//Andar para o elemento anterior porque foi apagado o elemento 
	}
	this->palavras = auxP;
}

/*

* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *

*/

void Tabuleiro::Save(ofstream& os) {
}

void Tabuleiro::Read(ifstream& is) {
}
