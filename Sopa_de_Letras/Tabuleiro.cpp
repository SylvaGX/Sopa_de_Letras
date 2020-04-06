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
	for (int i = 0; i < DimX*2; i++)
		cout << "_";
	cout << endl;
	for (int i = 0; i < this->DimY; i++) {
		cout << "|";
		for (int j = 0; j < this->DimX; j++) {
			cout << this->matrizLetras[i][j].getLetra() << " ";
		}
		cout << "|\n";
	}
	cout << " ";
	for (int i = 0; i < DimX*2; i++)
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

bool Tabuleiro::GetPossibilities(vector<Palavra>::iterator p, vector<pair<int, pair<int, int>>> &opcoes, int x, int y) {
	bool inseriu = false;
	size_t strlen = p->size();
	size_t j = 0;
	if (x == -1 && y != -1) {// ver na Horizontal
		size_t maxlen = DimX - (strlen - 1);
		bool H = true;
		bool HR = true;
		//palavra direita
		for (size_t i = 0; i < maxlen; i++) {
			for (j = 0; j < strlen && (H || HR); j++) {
				if (p->getPalavra()[j] != this->matrizLetras[y][i + j].getLetra() && this->matrizLetras[y][i + j].getLetra() != ' ') {
					H = false;
				}
				if (p->getPalavra()[strlen - 1 - j] != this->matrizLetras[y][i + j].getLetra() && this->matrizLetras[y][i + j].getLetra() != ' ') {
					HR = false;
				}
			}
			if (j == strlen) {
				if (H) {
					//inserir a palavra nas opcoes
					//push_back(make_pair(direção,make_pair(y, x)))
					opcoes.push_back(make_pair(0, make_pair(y, i)));
					if (!inseriu)
						inseriu = true;
				}
				if (HR) {
					//inserir a palavra nas opcoes
					//push_back(make_pair(direção,make_pair(y, x)))
					opcoes.push_back(make_pair(1, make_pair(y, i)));
					if (!inseriu)
						inseriu = true;
				}
			}
			H = true;
			HR = true;
		}
	}
	else if(y == -1 && x != -1){//ver na Vertical
		size_t maxlen = DimY - (strlen - 1);
		bool V = true;
		bool VR = true;
		//palavra direita
		for (size_t i = 0; i < maxlen; i++) {
			for (j = 0; j < strlen && (V || VR); j++) {
				if (p->getPalavra()[j] != this->matrizLetras[i + j][x].getLetra() && this->matrizLetras[i + j][x].getLetra() != ' ') {
					V = false;
				}
				if (p->getPalavra()[strlen - 1 - j] != this->matrizLetras[i + j][x].getLetra() && this->matrizLetras[i + j][x].getLetra() != ' ') {
					VR = false;
				}
			}
			if (j == strlen) {
				if (V) {
					//inserir a palavra nas opcoes
					//push_back(make_pair(direção,make_pair(y, x)))
					opcoes.push_back(make_pair(2, make_pair(i, x)));
					if (!inseriu)
						inseriu = true;
				}
				if (VR) {
					//inserir a palavra nas opcoes
					//push_back(make_pair(direção,make_pair(y, x)))
					opcoes.push_back(make_pair(3, make_pair(i, x)));
					if (!inseriu)
						inseriu = true;
				}
			}
			V = true;
			VR = true;
		}
	}
	else {
		int numDiagY = 0;
		int numDiagX = 0;
		if (DimX < DimY) {
			numDiagY = DimY - DimX;
		}
		else if(DimY < DimX){
			numDiagX = DimX - DimY;
		}
		int l = 0;
		int maxlen = 0;
		int i = 0;
		bool DP = true;
		bool DPR = true;
		bool DS = true;
		bool DSR = true;
		while (DimY + numDiagY > 4 && DimY + numDiagY >= strlen) {
			if (numDiagY >= 0) {
				maxlen = min(DimY, DimX) - (strlen - 1);
			}
			else {
				maxlen = min(DimY, DimX) + numDiagY - (strlen - 1);
			}
			while (DimX + numDiagX > 4 && DimX + numDiagX >= strlen) {
				if (numDiagX >= 0) {
					maxlen -= (strlen - 1);
				}
				else {
					maxlen += numDiagX - (strlen - 1);
				}
				for (int k = 0; k < maxlen; k++) {
					for (j = 0; j < strlen && (DP || DPR || DS || DSR); j++) {
						if (p->getPalavra()[j] != this->matrizLetras[l + k + j][i + k + j].getLetra() && this->matrizLetras[l + k + j][i + k + j].getLetra() != ' ') {
							DP = false;
						}
						if (p->getPalavra()[strlen - 1 - j] != this->matrizLetras[l + k + j][i + k + j].getLetra() && this->matrizLetras[l + k + j][i + k + j].getLetra() != ' ') {
							DPR = false;
						}
						if (p->getPalavra()[j] != this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() && this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() != ' ') {
							DS = false;
						}
						if (p->getPalavra()[strlen - 1 - j] != this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() && this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() != ' ') {
							DSR = false;
						}
					}
					if (j == strlen) {
						if (DP) {//Diagonal Principal Cima-Baixo
							//inserir a palavra nas opcoes
							//push_back(make_pair(direção,make_pair(y, x)))
							opcoes.push_back(make_pair(4, make_pair(l + k, i + k)));
							if (!inseriu)
								inseriu = true;
						}
						if (DPR) {//Diagonal Principal Baixo-Cima
							//inserir a palavra nas opcoes
							//push_back(make_pair(direção,make_pair(y, x)))
							opcoes.push_back(make_pair(5, make_pair(l + k, i + k)));
							if (!inseriu)
								inseriu = true;
						}
						if (DS) {//Diagonal Secundária Cima-Baixo
							//inserir a palavra nas opcoes
							//push_back(make_pair(direção,make_pair(y, x)))
							opcoes.push_back(make_pair(6, make_pair(l + k, DimX - 1 - i - k)));
							if (!inseriu)
								inseriu = true;
						}
						if (DSR) {//Diagonal Secundária Baixo-Cima
							//inserir a palavra nas opcoes
							//push_back(make_pair(direção,make_pair(y, x)))
							opcoes.push_back(make_pair(7, make_pair(l + k, DimX - 1 - i - k)));
							if (!inseriu)
								inseriu = true;
						}
					}
					DP = true;
					DPR = true;
					DS = true;
					DSR = true;
				}
				i++;
				numDiagX--;
			}
			l++;
			i = 0;
			numDiagY--;
			if (DimX < DimY) {
				numDiagX = 0;
			}
			else if (DimY < DimX) {
				numDiagX = DimX - DimY;
			}
		}
	}
	return inseriu;
}

/*
			 y
			 ^
* * * *  * *  |
* * * *  * *  |
* * * *  * *  |
* * * *  * *  |
* * * *  * * -|---------------->X

* * * * * *
  * * * * * *
	* * * * * *
	  * * * * * *

	  * * * * * *
	* * * * * *
  * * * * * *
* * * * * *

*/

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
			if (GetPossibilities(p, opcoes, -1, (*i))) {
				ok = true;
			}
		}
	}
	else if(!X.empty()){
		for (vector<int>::iterator i = X.begin(); i != X.end(); i++) {
			if (GetPossibilities(p, opcoes, (*i), -1)) {
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

bool Tabuleiro::PutDiag(vector<Palavra>::iterator p) {
	vector<pair<int, pair<int, int>>> opcoes;
	int x = 0;
	int y = 0;
	bool ok = false;
	if (GetPossibilities(p, opcoes, -1, -1)) {
		ok = true;
	}
	if (ok) {
		size_t r = rand() % opcoes.size();
		int o = opcoes.at(r).first;// pega na orientação da opção escolhida
		int x = opcoes.at(r).second.second;// pega no x da opção escolhida
		int y = opcoes.at(r).second.first;// pega no y da opção escolhida
		size_t l = p->getPalavra().size();
		switch (o) {
			case 4:{//Diagonal Principal Cima - Baixo
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(4);
				p->setPonto(Ponto(x, y));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[i], Ponto(x + i, y + i), (int)(*p).getPalavra()[i], Letra::verificaTipo((*p).getPalavra()[i]));
					this->matrizLetras[y + i][x + i] = laux;
				}
				break;
			}
			case 5:{//Diagonal Principal Baixo - Cima
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(5);
				p->setPonto(Ponto((x + p->getPalavra().size() - 1), (y + p->getPalavra().size() - 1)));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x + i, y + i), (int)(*p).getPalavra()[l - i - 1], Letra::verificaTipo((*p).getPalavra()[l - i - 1]));
					this->matrizLetras[y + i][x + i] = laux;
				}
				break;
			}
			case 6:{//Diagonal Secudária Cima - Baixo
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(6);
				p->setPonto(Ponto(x, y));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[i], Ponto(x - i, y + i), (int)(*p).getPalavra()[i], Letra::verificaTipo((*p).getPalavra()[i]));
					this->matrizLetras[y + i][x - i] = laux;
				}
				break;
			}
			case 7:{//Diagonal Principal Baixo - Cima
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(7);
				p->setPonto(Ponto((x - p->getPalavra().size() - 1), (y + p->getPalavra().size() - 1)));
				for (size_t i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x - i, y + i), (int)(*p).getPalavra()[l - i - 1], Letra::verificaTipo((*p).getPalavra()[l - i - 1]));
					this->matrizLetras[y + i][x - i] = laux;
				}
				break;
			}
			default:
				ok = false;
		}
	}
	return ok;
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
			if (i->size() <= DimY && i->size() <= DimX) {
				if (!X.empty() && !Y.empty()) {//Ou Vertical ou Horizontal ou Diagonal
					dir = rand() % 3;
					if (dir == 0) {//Vertical
						if (PutM(i, X, vector<int>(0))) {
							auxPal.push_back((*i));
						}
						else {//Ou Horizontal ou Diagonal
							dir = rand() % 2;
							if (dir == 0) {//Horizontal
								if (PutM(i, vector<int>(0), Y)) {
									auxPal.push_back((*i));
								}
								else {
									if (PutDiag(i)) {
										auxPal.push_back((*i));
									}
								}
							}
							else {//Diagonal
								if (PutDiag(i)) {
									auxPal.push_back((*i));
								}
								else {
									if (PutM(i, vector<int>(0), Y)) {
										auxPal.push_back((*i));
									}
								}
							}
						}
					}
					else if (dir == 1) {//Horizontal
						if (PutM(i, vector<int>(0), Y)) {
							auxPal.push_back((*i));
						}
						else {//Ou Vertical ou Diagonal
							dir = rand() % 2;
							if (dir == 0) {//Vertical
								if (PutM(i, X, vector<int>(0))) {
									auxPal.push_back((*i));
								}
								else {
									if (PutDiag(i)) {
										auxPal.push_back((*i));
									}
								}
							}
							else {//Diagonal
								if (PutDiag(i)) {
									auxPal.push_back((*i));
								}
								else {
									if (PutM(i, X, vector<int>(0))) {
										auxPal.push_back((*i));
									}
								}
							}
						}
					}
					else {//Diagonal
						if (PutDiag(i)) {
							auxPal.push_back((*i));
						}
						else {
							dir = rand() % 2;
							if (dir == 0) {//Vertical
								if (PutM(i, X, vector<int>(0))) {
									auxPal.push_back((*i));
								}
								else {
									if (PutM(i, vector<int>(0), Y)) {
										auxPal.push_back((*i));
									}
								}
							}
							else {//Horizontal
								if (PutM(i, vector<int>(0), Y)) {
									auxPal.push_back((*i));
								}
								else {
									if (PutM(i, X, vector<int>(0))) {
										auxPal.push_back((*i));
									}
								}
							}
						}
					}
				}
				else if(!X.empty()){//Ou Vertical ou Diagonal
					dir = rand() % 2;
					if (dir == 0) {//Vertical
						if (PutM(i, X, vector<int>(0))) {
							auxPal.push_back((*i));
						}
						else {
							if (PutDiag(i)) {
								auxPal.push_back((*i));
							}
						}
					}
					else {//Diagonal
						if (PutDiag(i)) {
							auxPal.push_back((*i));
						}
						else {
							if (PutM(i, X, vector<int>(0))) {
								auxPal.push_back((*i));
							}
						}
					}
				}
				else if(!Y.empty()){//Ou Horizontal ou Diagonal
					dir = rand() % 2;
					if (dir == 0) {//Horizontal
						if (PutM(i, vector<int>(0), Y)) {
							auxPal.push_back((*i));
						}
						else {
							if (PutDiag(i)) {
								auxPal.push_back((*i));
							}
						}
					}
					else {//Diagonal
						if (PutDiag(i)) {
							auxPal.push_back((*i));
						}
						else {
							if (PutM(i, vector<int>(0), Y)) {
								auxPal.push_back((*i));
							}
						}
					}
				}
				else {
					if (PutDiag(i)) {
						auxPal.push_back((*i));
					}
				}
			}
			else if(i->size() <= DimY){
				if (!Y.empty()) {//Ou Horizontal ou Diagonal
					dir = rand() % 2;
					if (dir == 0) {//Horizontal
						if (PutM(i, vector<int>(0), Y)) {
							auxPal.push_back((*i));
						}
						else {
							if (PutDiag(i)) {
								auxPal.push_back((*i));
							}
						}
					}
					else {//Diagonal
						if (PutDiag(i)) {
							auxPal.push_back((*i));
						}
						else {
							if (PutM(i, vector<int>(0), Y)) {
								auxPal.push_back((*i));
							}
						}
					}
				}
				else {//Diagonal
					if (PutDiag(i)) {
						auxPal.push_back((*i));
					}
				}
			}
			else {
				if (!X.empty()) {//Ou Vertical ou Diagonal
					dir = rand() % 2;
					if (dir == 0) {//Vertical
						if (PutM(i, X, vector<int>(0))) {
							auxPal.push_back((*i));
						}
						else {
							if (PutDiag(i)) {
								auxPal.push_back((*i));
							}
						}
					}
					else {//Diagonal
						if (PutDiag(i)) {
							auxPal.push_back((*i));
						}
						else {
							if (PutM(i, X, vector<int>(0))) {
								auxPal.push_back((*i));
							}
						}
					}
				}
				else {//Diagonal
					if (PutDiag(i)) {
						auxPal.push_back((*i));
					}
				}
			}
			CountSpaceMatriz(X, Y);
		}
	}
	this->setPalavras(auxPal);
}

void Tabuleiro::Save(ofstream& os) {
}

void Tabuleiro::Read(ifstream& is) {
}
