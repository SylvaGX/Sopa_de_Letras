#include "Tabuleiro.h"

Tabuleiro::Tabuleiro() {
	DimX = 0;
	DimY = 0;
	nPalavras = 0;
}

Tabuleiro::Tabuleiro(vector<vector<Letra>> matrizLetras, size_t DimX, size_t DimY, int nPalavras, vector<Palavra> palavras) {
	this->matrizLetras = matrizLetras;
	this->DimX = DimX;
	this->DimY = DimY;
	this->nPalavras = nPalavras;
	this->palavras = palavras;
}

Tabuleiro::~Tabuleiro() {
}

void Tabuleiro::newTabuleiro() {
	string p = "";
	system("CLS");
	cout << "Digite as dimenções da matriz:\n";
	cout << "Digite as linhas\n-> ";
	getline(cin, p);
	while (!is_numeric(p)) {
		Ponto::gotoxy(2, 2);
		for (size_t i = 0; i < p.length(); i++) {
			cout << " ";
		}
		Ponto::gotoxy(0, 1);
		cout << "Digite as linhas\n-> ";
		getline(cin, p);
	}
	this->DimY = stoul(p);
	p = "";
	cout << "Digite as colunas\n-> ";
	getline(cin, p);
	while (!is_numeric(p)) {
		Ponto::gotoxy(2, 4);
		for (size_t i = 0; i < p.length(); i++) {
			cout << " ";
		}
		Ponto::gotoxy(0, 3);
		cout << "Digite as colunas\n-> ";
		getline(cin, p);
	}
	this->DimX = stoul(p);
	//ler o ficheiro das palavras
	this->nPalavras = -1;
}

void Tabuleiro::Draw() {
	//Desenhar o tabuleiro ---- Tiago
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 0;
	if (DimY > 99) {
		k = 2;
	}
	else if (DimY > 9) {
		k = 1;
	}
	for (int i = 0; i < k+2; i++) {
		cout << " ";
	}
	for (size_t i = 0; i < DimX*2; i++)
		cout << "_";
	cout << endl;
	for (size_t i = 0; i < this->DimY; i++) {
		if (i < 9 && k == 2) {
			cout << "  ";
		}
		else if ((i < 99 && k == 2) || (i < 9 && k == 1)) {
			cout << " ";
		}
		cout << i + 1 << "|";
		for (size_t j = 0; j < this->DimX; j++) {
			if (this->matrizLetras[i][j].getBold() && this->matrizLetras[i][j].getCor()) {
				SetConsoleTextAttribute(hndl, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << this->matrizLetras[i][j].getLetra();
				SetConsoleTextAttribute(hndl, 7);
				cout << " ";
			}
			else {
				cout << this->matrizLetras[i][j].getLetra() << " ";
			}
		}
		cout << "|\n";
	}
	for (int i = 0; i < k + 2; i++) {
		cout << " ";
	}
	for (size_t i = 0; i < DimX*2; i++)
		cout << "_";
	cout << endl;
}

void Tabuleiro::setDimX(size_t DimX) {
	this->DimX = DimX;
}

void Tabuleiro::setDimY(size_t DimY) {
	this->DimY = DimY;
}

void Tabuleiro::setNpalavras(int nPalavras) {
	this->nPalavras = nPalavras;
}

void Tabuleiro::setMatrizLetras(vector<vector<Letra>> matrizLetras) {
	this->matrizLetras = matrizLetras;
}

void Tabuleiro::setPalavras(vector<Palavra> palavras) {
	this->palavras = palavras;
}

void Tabuleiro::setCategoria(string categoria) {
	this->categoria = categoria;
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
	bool err = false;
	if (is) {
		vector<pair<streampos, string>> cat;
		string aux;
		bool c = false;
		while (!is.eof()) {
			getline(is, aux);
			if (aux != "") {
				if (c) {
					if (aux.size() > 1 && aux[0] == '/' && aux[1] == '#') {
						c = false;
					}
					else if (aux[0] == '#') {
						//erro ao ler o ficheiro. Formato não reconhecido
						err = true;
					}
				}
				else {
					if (aux[0] == '#') {
						cat.push_back(make_pair(is.tellg(), aux.substr(1)));
						c = true;
					}
				}
			}
		}
		if (!c) {
			size_t i = 0;
			size_t r = 0;
			r = rand() % cat.size();
			categoria = cat.at(r).second;
			is.seekg(cat.at(r).first);
			aux = "";
			getline(is, aux);
			while (aux != "/#") {
				while (i < aux.length()) {
					if (aux[i] == ' ') {
						aux.erase(i, 1);
					}
					else {
						i++;
					}
				}
				if (Letra::getTipo_M_m() == 0) {
					transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
				}
				else {
					transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
				}
				Palavra::CheckWordAccents(aux);
				this->palavras.push_back(Palavra(aux, -1, 0, Ponto(-1, -1)));
				i = 0;
				getline(is, aux);
			}
			unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
			std::shuffle(this->palavras.begin(), this->palavras.end(), default_random_engine(seed));
		}
		else {
			err = true;
		}
	}
	return err;
}

void Tabuleiro::GenerarMatriz(Jogador* j) {
	this->matrizLetras = vector<vector<Letra> >(DimY, vector<Letra>(DimX));
	int r = 0;
	int M_m = 0;
	
	if (Letra::getTipo_M_m() == 1) {
		M_m = 97;
	}
	else {
		M_m = 65;
	}

	for (size_t i = 0; i < this->DimY; i++) {
		for (size_t j = 0; j < this->DimX; j++) {
				this->matrizLetras[i][j] = Letra(' ', Ponto((int)j, (int)i), 32, 0, 0);
		}
	}

	SelectPalavras(j);
	
	char aux;
	for (size_t i = 0; i < this->DimY; i++) {
		for (size_t j = 0; j < this->DimX; j++) {
			if (this->matrizLetras[i][j].getLetra() == ' ') {
				r = M_m + (rand() % 26);
				aux = (char) r;
				this->matrizLetras[i][j].setLetra(aux);
				this->matrizLetras[i][j].setAscii(r);
				this->matrizLetras[i][j].setPonto(Ponto(j, i));
			}
		}
	}
}

void Tabuleiro::CountSpaceMatriz(vector<int>& X, vector<int>& Y) {
	int countSpace = 0;
	bool stop = false;
	int y = 0;
	int x = 0;
	for (size_t i = 0; i < Y.size(); i++) {
		y = Y[i];
		for (size_t j = 0; j < DimX && !stop; j++) {
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
		for (size_t j = 0; j < DimY && !stop; j++) {
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

bool Tabuleiro::GetPossibilities(vector<Palavra>::iterator p, vector<pair<int, pair<int, int>>> &opcoes, int x, int y, Jogador* n) {
	bool inseriu = false;
	int strlen = (int)p->size();
	size_t j = 0;
	if (x == -1 && y != -1) {// ver na Horizontal
		int maxlen = (int)DimX - (strlen - 1);
		if(dynamic_cast<Principiante*>(n)){
			bool H = true;
			for (int i = 0; i < maxlen; i++) {
				for (j = 0; j < strlen && H ; j++) {
					if (p->getPalavra()[j] != this->matrizLetras[y][i + j].getLetra() && this->matrizLetras[y][i + j].getLetra() != ' ') {
						H = false;
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
					
				}
				H = true;
			}
		}
		else {
			bool H = true;
			bool HR = true;
			for (int i = 0; i < maxlen; i++) {
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
	}
	else if(y == -1 && x != -1){//ver na Vertical
		int maxlen = (int)DimY - (strlen - 1);
		if (dynamic_cast<Principiante*>(n)) {
			bool V = true;
			for (int i = 0; i < maxlen; i++) {
				for (j = 0; j < strlen && V; j++) {
					if (p->getPalavra()[j] != this->matrizLetras[i + j][x].getLetra() && this->matrizLetras[i + j][x].getLetra() != ' ') {
						V = false;
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
				}
				V = true;
			}
		}
		else {
			bool V = true;
			bool VR = true;
			for (int i = 0; i < maxlen; i++) {
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
	}
	else {
		int numDiagY = 0;
		int numDiagX = 0;
		if (DimX < DimY) {
			numDiagY = (int)(DimY - DimX);
		}
		else if(DimY < DimX){
			numDiagX = (int)(DimX - DimY);
		}
		size_t l = 0;
		int maxlen = 0;
		size_t i = 0;
		bool DP = true;
		bool DPR = true;
		bool DS = true;
		bool DSR = true;
		while (DimY + numDiagY > 4 && DimY + numDiagY >= strlen) {
			if (numDiagY >= 0) {
				maxlen = (int)min(DimY, DimX) - (strlen - 1);
			}
			else {
				maxlen = (int)min(DimY, DimX) + numDiagY - (strlen - 1);
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
						if (p->getPalavra()[(strlen - 1) - j] != this->matrizLetras[l + k + j][i + k + j].getLetra() && this->matrizLetras[l + k + j][i + k + j].getLetra() != ' ') {
							DPR = false;
						}
						if (p->getPalavra()[j] != this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() && this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() != ' ') {
							DS = false;
						}
						if (p->getPalavra()[(strlen - 1) - j] != this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() && this->matrizLetras[l + k + j][DimX - 1 - i - k - j].getLetra() != ' ') {
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
				numDiagX = (int)(DimX - DimY);
			}
		}
	}
	return inseriu;
}

bool Tabuleiro::PutM(vector<Palavra>::iterator &p, vector<int> X, vector<int> Y, Jogador* j) {
	//0 - esquerda_direita, 1 - direita_esquerda, 2 - cima_baixo, 3 - baixo_cima.
	//serve para saber a posição dos pontos.
	//segundo pair<y, x>
	vector<pair<int, pair<int, int>>> opcoes;
	int x = 0;
	int y = 0;
	bool ok = false;
	if (!Y.empty()) {
		for (vector<int>::iterator i = Y.begin(); i != Y.end(); i++) {
			if (GetPossibilities(p, opcoes, -1, (*i), j)) {
				ok = true;
			}
		}
	}
	else if(!X.empty()){
		for (vector<int>::iterator i = X.begin(); i != X.end(); i++) {
			if (GetPossibilities(p, opcoes, (*i), -1, j)) {
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
					laux = Letra((*p).getPalavra()[i], Ponto(x + i, y), (int)(*p).getPalavra()[i], 0, 0);
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
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x + i, y), (int)(*p).getPalavra()[l - i - 1], 0, 0);
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
					laux = Letra((*p).getPalavra()[i], Ponto(x, y + i), (int)(*p).getPalavra()[i], 0, 0);
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
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x, y + i), (int)(*p).getPalavra()[l - i - 1], 0, 0);
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
	if (GetPossibilities(p, opcoes, -1, -1, nullptr)) {
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
				for (int i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[i], Ponto(x + i, y + i), (int)(*p).getPalavra()[i], 0, 0);
					this->matrizLetras[y + i][x + i] = laux;
				}
				break;
			}
			case 5:{//Diagonal Principal Baixo - Cima
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(5);
				p->setPonto(Ponto((x + (int)p->getPalavra().size() - 1), (y + (int)p->getPalavra().size() - 1)));
				for (int i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x + i, y + i), (int)(*p).getPalavra()[l - i - 1], 0, 0);
					this->matrizLetras[y + i][x + i] = laux;
				}
				break;
			}
			case 6:{//Diagonal Secudária Cima - Baixo
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(6);
				p->setPonto(Ponto(x, y));
				for (int i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[i], Ponto(x - i, y + i), (int)(*p).getPalavra()[i], 0, 0);
					this->matrizLetras[y + i][x - i] = laux;
				}
				break;
			}
			case 7:{//Diagonal Secudária Baixo - Cima
				Letra laux = Letra();
				p->setEstado(0);
				p->setOrientacao(7);
				p->setPonto(Ponto((x - (p->getPalavra().size() - 1)), (y + p->getPalavra().size() - 1)));
				for (int i = 0; i < l; i++) {
					laux = Letra((*p).getPalavra()[l - i - 1], Ponto(x - i, y + i), (int)(*p).getPalavra()[l - i - 1], 0, 0);
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

int partition(vector<Palavra>& p, int left, int right) {
	int pivotIndex = left + (right - left) / 2;
	Palavra pivotValue = p[pivotIndex];
	int i = left, j = right;
	while (i <= j) {
		while (p[i] < pivotValue) {
			i++;
		}
		while (p[j] > pivotValue) {
			j--;
		}
		if (i <= j) {
			swap(p[i], p[j]);
			i++;
			j--;
		}
	}
	return i;
}

void quicksort(vector<Palavra>& p, int left, int right) {
	if (left < right) {
		int pivotIndex = partition(p, left, right);
		quicksort(p, left, pivotIndex - 1);
		quicksort(p, pivotIndex, right);
	}
}

void Tabuleiro::SelectPalavras(Jogador* j){
	srand((unsigned)time(nullptr));
	int dir = 0;
	vector<Palavra> auxPal;
	vector<int> X(DimX);//palavras possiveis na posição respetiva(Horizontal)
	vector<int> Y(DimY);//palavras possiveis na posição respetiva(Vertical)
	iota(X.begin(), X.end(), 0);
	iota(Y.begin(), Y.end(), 0);
	j->adquirirPontos();
	if (dynamic_cast<Principiante*>(j)) {
		for (vector<Palavra>::iterator i = this->palavras.begin(); i != this->palavras.end(); i++) {
			if (i->size() <= max(DimX, DimY)) {
				if (i->size() <= DimY && i->size() <= DimX) {
					if (!X.empty() && !Y.empty()) {//Ou Vertical ou Horizontal
						dir = rand() % 2;
						if (dir == 0) {//Horizontal
							if (PutM(i, X, vector<int>(0), j)) {
								auxPal.push_back((*i));
							}
							else {//Vertical
								if (PutM(i, vector<int>(0), Y,j)) {
									auxPal.push_back((*i));
								}
							}
						}
						else if (dir == 1) {//Vertical
							if (PutM(i, vector<int>(0), Y, j)) {
								auxPal.push_back((*i));
							}
							else {//Horizontal
								if (PutM(i, X, vector<int>(0), j)) {
									auxPal.push_back((*i));
								}
							}
						}
					}
					else if (!X.empty()) {//Horizontal
						if (PutM(i, X, vector<int>(0), j)) {
							auxPal.push_back((*i));
						}
					}
					else if (!Y.empty()) {//Vertical
						if (PutM(i, vector<int>(0), Y, j)) {
							auxPal.push_back((*i));
						}
					}
				}
				else if (i->size() <= DimY) {
					if (!Y.empty()) {//Vertical
						if (PutM(i, vector<int>(0), Y, j)) {
							auxPal.push_back((*i));
						}

					}
					else if (i->size() <= DimX) {
						if (!X.empty()) {//Horizontal
							if (PutM(i, X, vector<int>(0), j)) {
								auxPal.push_back((*i));
							}
						}
					}
					CountSpaceMatriz(X, Y);
				}
			}
		}
	}
	else {
		for (vector<Palavra>::iterator i = this->palavras.begin(); i != this->palavras.end(); i++) {
			if (i->size() <= max(DimX, DimY)) {
				if (i->size() <= DimY && i->size() <= DimX) {
					if (!X.empty() && !Y.empty()) {//Ou Vertical ou Horizontal ou Diagonal
						dir = rand() % 3;
						if (dir == 0) {//Horizontal
							if (PutM(i, X, vector<int>(0), j)) {
								auxPal.push_back((*i));
							}
							else {//Ou Vertical ou Diagonal
								dir = rand() % 2;
								if (dir == 0) {//Vertical
									if (PutM(i, vector<int>(0), Y, j)) {
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
									else {//Vertical
										if (PutM(i, vector<int>(0), Y, j)) {
											auxPal.push_back((*i));
										}
									}
								}
							}
						}
						else if (dir == 1) {//Horizontal
							if (PutM(i, vector<int>(0), Y, j)) {
								auxPal.push_back((*i));
							}
							else {//Ou Vertical ou Diagonal
								dir = rand() % 2;
								if (dir == 0) {//Vertical
									if (PutM(i, X, vector<int>(0), j)) {
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
										if (PutM(i, X, vector<int>(0), j)) {
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
									if (PutM(i, X, vector<int>(0), j)) {
										auxPal.push_back((*i));
									}
									else {
										if (PutM(i, vector<int>(0), Y, j)) {
											auxPal.push_back((*i));
										}
									}
								}
								else {//Horizontal
									if (PutM(i, vector<int>(0), Y, j)) {
										auxPal.push_back((*i));
									}
									else {
										if (PutM(i, X, vector<int>(0), j)) {
											auxPal.push_back((*i));
										}
									}
								}
							}
						}
					}
					else if (!X.empty()) {//Ou Vertical ou Diagonal
						dir = rand() % 2;
						if (dir == 0) {//Vertical
							if (PutM(i, X, vector<int>(0), j)) {
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
								if (PutM(i, X, vector<int>(0), j)) {
									auxPal.push_back((*i));
								}
							}
						}
					}
					else if (!Y.empty()) {//Ou Horizontal ou Diagonal
						dir = rand() % 2;
						if (dir == 0) {//Horizontal
							if (PutM(i, vector<int>(0), Y, j)) {
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
								if (PutM(i, vector<int>(0), Y, j)) {
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
				else if (i->size() <= DimY) {
					if (!Y.empty()) {//Ou Horizontal ou Diagonal
						dir = rand() % 2;
						if (dir == 0) {//Horizontal
							if (PutM(i, vector<int>(0), Y, j)) {
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
								if (PutM(i, vector<int>(0), Y, j)) {
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
							if (PutM(i, X, vector<int>(0), j)) {
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
								if (PutM(i, X, vector<int>(0), j)) {
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
	}
	quicksort(auxPal, 0, (int)auxPal.size()-1);
	this->setPalavras(auxPal);
	setNpalavras((int)auxPal.size());
}

int Tabuleiro::VerificarPalavra(string str, Jogador& jog) {
	int sms = 0;
	if (!str.empty() && !is_numeric(str)) {
		pair<size_t, size_t> i; // X, Y
		int mid = 0;
		int low = 0;
		int high = (int)this->palavras.size() - 1;
		size_t strlen = 0;
		size_t x = 0, y = 0;
		while (low <= high) {

			mid = low + (high - low) / 2;

			if (this->palavras[mid].getPalavra() == str) {
				i = Ponto::AskPonto(DimY);
				if (i.first - 1 >= 0 && i.second - 1 >= 0) {
					i.first--;
					i.second--;
					switch (this->palavras[mid].getOrientacao()) {
						case 0://HE-HD
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first >= x && i.first <= x + (strlen - 1)) && (i.second == y)) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y][x + i].setBold(1);
									this->matrizLetras[y][x + i].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
						case 1://HD-HE
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first <= x && i.first >= x - (strlen - 1)) && (i.second == y)) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y][x - i].setBold(1);
									this->matrizLetras[y][x - i].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
						case 2://VC - VB
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first == x) && (i.second >= y && i.second <= y + (strlen - 1))) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y + i][x].setBold(1);
									this->matrizLetras[y + i][x].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
						case 3://VB-VC
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first == x) && (i.second <= y && i.second >= y - (strlen - 1))) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y - i][x].setBold(1);
									this->matrizLetras[y - i][x].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
						case 4://D1C - D1B
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first >= x && i.first <= x + (strlen - 1)) && (i.second == (y + (i.first - x)))) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y + i][x + i].setBold(1);
									this->matrizLetras[y + i][x + i].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
						case 5://D1B-D1C
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first <= x && i.first >= x - (strlen - 1)) && (i.second == (y - (x - i.first)))) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y - i][x - i].setBold(1);
									this->matrizLetras[y - i][x - i].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
						case 6://D2C-D2B
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first <= x && i.first >= x - (strlen - 1)) && (i.second == (y + (x - i.first)))) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y + i][x - i].setBold(1);
									this->matrizLetras[y + i][x - i].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
						case 7://D2B-D2C
							x = (size_t)this->palavras[mid].getPonto().Get_x();
							y = (size_t)this->palavras[mid].getPonto().Get_y();
							strlen = this->palavras[mid].size();
							if ((i.first >= x && i.first <= x + (strlen - 1)) && (i.second == (y - (i.first - x)))) {
								for (size_t i = 0; i < strlen; i++) {
									this->matrizLetras[y - i][x + i].setBold(1);
									this->matrizLetras[y - i][x + i].setCor(1);
								}
								sms = 1;
								this->palavras[mid].setEstado(1);
								this->guessWords.push_back((this->palavras[mid]));
								this->palavras.erase(this->palavras.begin() + mid);
								low = -1;
								high = -2;
								jog++;
							}
							else {
								sms = 4;
								low = -1;
								high = -2;
							}
							break;
					}
				}
				else {
					sms = 5;
				}
			}
			else if (str < this->palavras[mid].getPalavra()) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		if (low != -1 && high != -2 && !this->palavras.empty()) {
			vector<Palavra>::iterator ptr;
			for (ptr = this->guessWords.begin(); ptr != this->guessWords.end(); ptr++) {
				if (str == ptr->getPalavra()) {
					break;
				}
			}
			if (ptr == this->guessWords.end()) {
				sms = 2;
			}
			else {
				sms = 3;
			}
		}
	}
	else sms = 0;
	return sms;
}

void Tabuleiro::Save(ofstream& os) {
	os << getDimX() << "\n" << getDimY() << "\n";
	for (size_t i = 0; i < getDimY(); i++) {
		for (size_t j = 0; j < getDimX(); j++) {
			getMatrizLetras()[i][j].Save(os);
			os << "\n";
		}
	}
	os << Letra::getTipo_M_m() << endl;
	os << getPalavras().size() << endl;
	for (size_t i = 0; i < getPalavras().size(); i++) {
		getPalavras()[i].Save(os);
		os << "\n";
	}
	os << getGuessWords().size() << endl;
	for (size_t i = 0; i < getGuessWords().size(); i++) {
		getGuessWords()[i].Save(os);
		os << "\n";
	}
	os << getCategoria();
}

bool Tabuleiro::Load(ifstream& is) {
	bool sms = 1;
	int n = 0;
	string t = "";
	getline(is, t);
	if (is_numeric(t)) {
		setDimX(stoi(t));
		getline(is, t);
		if (is_numeric(t)) {
			setDimY(stoi(t));
			n = getDimX() * getDimY();
			this->matrizLetras = vector<vector<Letra> >(DimY, vector<Letra>(DimX));
			Letra *Laux;
			for (size_t i = 0; i < n && sms; i++) {
				Laux = new Letra;
				if (Laux->Load(is)) {
					this->matrizLetras[Laux->getPonto().Get_y()][Laux->getPonto().Get_x()] = (*Laux);
				}
				else
					sms = 0;
				delete Laux;
			}
			getline(is, t);
			Letra::setTipo_M_m(stoi(t));
			getline(is, t);
			if (is_numeric(t) && sms) {
				n = stoi(t);
				Palavra *Paux;
				for (size_t i = 0; i < n && sms; i++) {
					Paux = new Palavra;
					if (Paux->Load(is)) {
						this->palavras.push_back(*Paux);
					}
					else
						sms = 0;
					delete Paux;
				}
				getline(is, t);
				if (is_numeric(t) && sms ) {
					n = stoi(t);
					Palavra* Paux;
					for (size_t i = 0; i < n && sms; i++) {
						Paux = new Palavra;
						if (Paux->Load(is)) {
							this->guessWords.push_back(*Paux);
						}
						else
							sms = 0;
						delete Paux;
					}
					if (sms) {
						getline(is, t);
						setCategoria(t);
					}
				}
				else
					sms = 0;
			}
			else
				sms = 0;
		}
		else
			sms = 0;
	}
	else
		sms = 0;
	return sms;
}
