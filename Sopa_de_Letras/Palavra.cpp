#include "Palavra.h"

Palavra::Palavra() {
	this->orientacao = -1;
	this->estado = -1;
	this->pIni = Ponto(-1, -1);
}

Palavra::Palavra(string palavra, int orientacao, int estado, Ponto pIni) {
	this->palavra = palavra;
	this->orientacao = orientacao;
	this->estado = estado;
	this->pIni = pIni;
}

Palavra::~Palavra() {
}

void Palavra::setOrientacao(int orientacao) {
	this->orientacao = orientacao;
}

void Palavra::setEstado(int estado) {
	this->estado = estado;
}

void Palavra::setPonto(Ponto pIni) {
	this->pIni = pIni;
}

void Palavra::showPalavra() {
	for (size_t i = 0; i < this->size(); i++) {
		cout << this->getPalavra()[i];
	}
}

void Palavra::setPalavra(string str) {
	this->palavra = str;
}

string Palavra::pedirpalavra(size_t DimX, size_t DimY) {
	Ponto::UpdateColWin();
	int w = Ponto::getWinW();
	int h = Ponto::getWinH();
	Ponto::gotoxy((short)DimY + 3, 0);
	cout << "                                                                ";
	Ponto::gotoxy((short)DimY + 4, 0);
	cout << "                                                                ";
	Ponto::gotoxy((short)DimY + 5, 0);
	cout << "                                                                ";
	Ponto::gotoxy((short)DimY + 6, 0);
	cout << "                                                                ";
	Ponto::gotoxy((short)DimY + 7, 0);
	cout << "                                                                ";
	Ponto::gotoxy((short)DimY + 3, 0);
	string pedir;
	cout << "Qual é a palavra que queres advinhar?\n->";
	cin >> pedir;
	if (Letra::getTipo_M_m() == 0) {
		transform(pedir.begin(), pedir.end(), pedir.begin(), ::toupper);
	}
	else {
		transform(pedir.begin(), pedir.end(), pedir.begin(), ::tolower);
	}
	return pedir;
}

void Palavra::CheckWordAccents(string& str) {
	string min = "áàãâéèêíìîóòõôúùûç";
	string mai = "ÁÀÃÂÉÈÊÍÌÎÓÒÕÔÚÙÛÇ";

	size_t strlen = str.length();
	int tipo = Letra::getTipo_M_m();
	for (size_t i = 0; i < strlen; i++) {
		if (tipo) {
			switch (min.find(str[i])) {
				case 0:
				case 1:
				case 2:
				case 3:{
					str[i] = 'a';
					break;
				}
				case 4:
				case 5:
				case 6:{
					str[i] = 'e';
					break;
				}
				case 7:
				case 8:
				case 9:{
					str[i] = 'i';
					break;
				}
				case 10:
				case 11:
				case 12:
				case 13:{
					str[i] = 'o';
					break;
				}
				case 14:
				case 15:
				case 16:{
					str[i] = 'u';
					break;
				}
				case 17:{
					str[i] = 'c';
					break;
				}
				default:
					break;
			}
		}
		else {
			switch (mai.find(str[i])) {
				case 0:
				case 1:
				case 2:
				case 3:
				{
					str[i] = 'A';
					break;
				}
				case 4:
				case 5:
				case 6:
				{
					str[i] = 'E';
					break;
				}
				case 7:
				case 8:
				case 9:
				{
					str[i] = 'I';
					break;
				}
				case 10:
				case 11:
				case 12:
				case 13:
				{
					str[i] = 'O';
					break;
				}
				case 14:
				case 15:
				case 16:
				{
					str[i] = 'U';
					break;
				}
				case 17:
				{
					str[i] = 'C';
					break;
				}
				default:
					break;
			}
		}
	}
}

size_t Palavra::size() {
	return (palavra.size());
}

bool Palavra::operator==(string str2) {
	return (this->getPalavra() == str2);
}

bool Palavra::operator<(Palavra str) {
	return (this->getPalavra() < str.getPalavra());
}

bool Palavra::operator>(Palavra str) {
	return (this->getPalavra() > str.getPalavra());
}
