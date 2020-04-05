#include "Tabuleiro.h"

using namespace std;

bool is_digit(const char value) { return isdigit(value); }
bool is_numeric(const string& value) { return all_of(value.begin(), value.end(), is_digit); }

Tabuleiro::Tabuleiro() {
	cout << "Digite as dimenções da matriz\n-> ";
	cin >> this->DimY >> this->DimX;
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
	cout << " ";
	for (int i = 0; i < DimX; i++)
		cout << "_";
	cout << endl;
	for (int i = 0; i < this->DimY; i++) {
		cout << "|";
		for (int j = 0; j < this->DimX; j++) {
			cout << this->matrizLetras[i][j].getLetra();
		}
		cout << "|\n";
	}
	cout << " ";
	for (int i = 0; i < DimX; i++)
		cout << "_";
	cout << endl;
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
	cout << "Size: " << this->getPalavras().size() << endl;
	for (size_t i = 0; i < this->getPalavras().size(); i++) {
		this->getPalavras()[i].showPalavra();
		cout << " " << this->getPalavras()[i].getPonto();
		cout << endl;
	}
}

bool Tabuleiro::loadPalavras() {
	ifstream is;
	is.open("words.txt");
	srand((unsigned)time(nullptr));
	int r = rand() % 2;
	if (is) {
		string aux;
		while (!is.eof()) {
			getline(is, aux);
			size_t i = 0;
			while (i < aux.length()) {
				if (aux[i] == ' ') {
					aux.erase(i, 1);
				}
				else {
					i++;
				}
			}
			if (r) {
				transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
			}
			else {
				transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
			}
			this->palavras.push_back(Palavra(aux, -1, 0, Ponto(-1, -1)));
		}
	}
	unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(this->palavras.begin(), this->palavras.end(), default_random_engine(seed));
	return false;
}

void Tabuleiro::GenerarMatriz() {
	this->matrizLetras = vector<vector<Letra> >(DimY, vector<Letra>(DimX));
	int r = 0;
	for (int i = 0; i < this->DimY; i++) {
		for (int j = 0; j < this->DimX; j++) {
				this->matrizLetras[i][j] = Letra(' ', Ponto(i, j), 32, -1);
		}
	}
	SelectPalavras();
}

bool Tabuleiro::GetSpace(vector<Palavra>::iterator p, vector<pair<int, pair<int, int>>> &opcoes, int x, int y) {
	bool inseriu = false;
	size_t strlen = p->size();
	size_t j = 0;
	if (x == -1) {// ver na Horizontal
		size_t maxlen = DimX - (strlen - 1);
		//palavra direita
		for (size_t i = 0; i < maxlen; i++) {
			for (j = 0; j < strlen; j++) {
				if (p->getPalavra()[j] != this->matrizLetras[y][i + j].getLetra() && this->matrizLetras[y][i + j] != ' ') {
					break;
				}
			}
			if (j == strlen) {
				//inserir a palavra nas opcoes
				//push_back(make_pair(direção,make_pair(y, x)))
				opcoes.push_back(make_pair(0, make_pair(y, i)));
				if (!inseriu)
					inseriu = true;
			}
		}
		j = 0;
		//palavra ao contrario
		for (size_t i = 0; i < maxlen; i++) {
			for (j = 0; j < strlen; j++) {
				if (p->getPalavra()[strlen - 1 - j] != this->matrizLetras[y][i + j].getLetra() && this->matrizLetras[y][i + j] != ' ') {
					break;
				}
			}
			if (j == strlen) {
				//inserir a palavra nas opcoes
				//push_back(make_pair(direção,make_pair(y, x)))
				opcoes.push_back(make_pair(1, make_pair(y, i)));
				if (!inseriu)
					inseriu = true;
			}
		}
	}
	else {//ver na Vertical
		size_t maxlen = DimY - (strlen - 1);
		//palavra direita
		for (size_t i = 0; i < maxlen; i++) {
			for (j = 0; j < strlen; j++) {
				if (p->getPalavra()[j] != this->matrizLetras[i + j][x].getLetra() && this->matrizLetras[i + j][x] != ' ') {
					break;
				}
			}
			if (j == strlen) {
				//inserir a palavra nas opcoes
				//push_back(make_pair(direção,make_pair(y, x)))
				opcoes.push_back(make_pair(2, make_pair(i, x)));
				if (!inseriu)
					inseriu = true;
			}
		}
		j = 0;
		//palavra ao contrario
		for (size_t i = 0; i < maxlen; i++) {
			for (j = 0; j < strlen; j++) {
				if (p->getPalavra()[strlen - 1 - j] != this->matrizLetras[i + j][x].getLetra() && this->matrizLetras[i + j][x] != ' ') {
					break;
				}
			}
			if (j == strlen) {
				//inserir a palavra nas opcoes
				//push_back(make_pair(direção,make_pair(y, x)))
				opcoes.push_back(make_pair(3, make_pair(i, x)));
				if (!inseriu)
					inseriu = true;
			}
		}
	}
	return inseriu;
}


bool Tabuleiro::PutM(vector<Palavra>::iterator &p, vector<int> X, vector<int> Y) {
	//0 - esquerda_direita, 1 - direita_esquerda, 2 - cima_baixo, 3 - baixo_cima.
	//serve para saber a posição dos pontos.
	//segundo pair<y, x>
	vector<pair<int, pair<int, int>>> opcoes;
	int x = 0;
	int y = 0;
	bool ok = false;
	if (!Y.empty()) {
		for (vector<int>::iterator i = Y.begin(); i != Y.end(); i++) {
			if (GetSpace(p, opcoes, -1, (*i))) {
				ok = true;
			}
		}
	}
	else if(!X.empty()){
		for (vector<int>::iterator i = X.begin(); i != X.end(); i++) {
			if (GetSpace(p, opcoes, (*i), -1)) {
				ok = true;
			}
		}
	}
	if (ok) {
		size_t r = rand() % opcoes.size();
		int o = opcoes.at(r).first;// pega na orientação da opção escolhida
		int x = opcoes.at(r).second.second;// pega no x da opção escolhida
		int y = opcoes.at(r).second.first;// pega no y da opção escolhida
		size_t l = p->getPalavra().size();
		switch (o) {
			case 0:{
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(0);
				p->setPonto(Ponto(x, y));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[i], Ponto(x + i, y), (int)(*p).getPalavra()[i], Letra::verificaTipo((*p).getPalavra()[i]));
					this->matrizLetras[y][x + i] = laux;
				}
				break;
			}
			case 1:{
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(1);
				p->setPonto(Ponto((x + p->getPalavra().size() - 1), y));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x + i, y), (int)(*p).getPalavra()[l - i - 1], Letra::verificaTipo((*p).getPalavra()[l - i - 1]));
					this->matrizLetras[y][x + i] = laux;
				}
				break;
			}
			case 2:{
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(2);
				p->setPonto(Ponto(x, y));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[i], Ponto(x, y + i), (int)(*p).getPalavra()[i], Letra::verificaTipo((*p).getPalavra()[i]));
					this->matrizLetras[y + i][x] = laux;
				}
				break;
			}
			case 3:{
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(3);
				p->setPonto(Ponto(x, (y + p->getPalavra().size() - 1)));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x, y + i), (int)(*p).getPalavra()[l - i - 1], Letra::verificaTipo((*p).getPalavra()[l - i - 1]));
					this->matrizLetras[y + i][x] = laux;
				}
				break;
			}
			default:
				ok = false;
		}
	}
	return ok;
}

void Tabuleiro::CountSpaceMatriz(vector<int>& X, vector<int>& Y) {
	int countSpace = 0;
	bool stop = false;
	int y = 0;
	int x = 0;
	for (size_t i = 0; i < Y.size(); i++) {
		y = Y[i];
		for (int j = 0; j < DimX && !stop; j++) {
			if (this->matrizLetras[y][j].getLetra() == ' ') {
				countSpace++;
			}
			else {
				if (countSpace >= 5) {
					stop = true;
				}
				else {
					countSpace = 0;
				}
			}
		}
		if (countSpace < 5) {
			Y.erase(Y.begin() + i);
		}
		stop = false;
		countSpace = 0;
	}
	for (size_t i = 0; i < X.size(); i++) {
		x = X[i];
		for (int j = 0; j < DimY && !stop; j++) {
			if (this->matrizLetras[j][x].getLetra() == ' ') {
				countSpace++;
			}
			else {
				if (countSpace >= 5) {
					stop = true;
				}
				else {
					countSpace = 0;
				}
			}
		}
		if (countSpace < 5) {
			X.erase(X.begin() + i);
		}
		stop = false;
		countSpace = 0;
	}
}

void Tabuleiro::SelectPalavras(){
	srand((unsigned)time(nullptr));
	int dir = 0;
	vector<Palavra> auxPal;
	vector<int> X(DimX);//palavras possiveis na posição respetiva(Vertical)
	vector<int> Y(DimY);//palavras possiveis na posição respetiva(Horizontal)
	iota(X.begin(), X.end(), 0);
	iota(Y.begin(), Y.end(), 0);
	for (vector<Palavra>::iterator i = this->palavras.begin(); i != this->palavras.end(); i++) {
		if (i->size() <= max(DimX, DimY)) {
			dir = rand() % 2;
			if (dir == 0) {// Vertical
				if (i->size() <= DimY) {
					if (PutM(i, X, vector<int>(0))) {
						auxPal.push_back((*i));
					}
				}
				else {//Horizontal ou Diagonal
					if (i->size() <= DimX) {
						if (PutM(i, vector<int>(0), Y)) {
							auxPal.push_back((*i));
						}
					}
				}
			}
			else if(dir == 1) {//Horizontal
				if (i->size() <= DimX) {
					if (PutM(i, vector<int>(0), Y)) {
						auxPal.push_back((*i));
					}
				}
				else {//Vertical ou Diagonal
					if (i->size() <= DimY) {
						if (PutM(i, X, vector<int>(0))) {
							auxPal.push_back((*i));
						}
					}
				}
			}
			else {//Diagonal

			}
			CountSpaceMatriz(X, Y);
		}
	}
	this->setPalavras(auxPal);
}

/*
			 y
			 ^
* * * * * *  |
* * * * * *  |
* * * * * *  |
* * * * * *  |
* * * * * * -|---------------->X

* * * * * *
  * * * * * *
    * * * * * *
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
