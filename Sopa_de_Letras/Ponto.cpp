#include "Ponto.h"

Ponto::Ponto() {
	this->x = -1; 
	this->y = -1;
}

Ponto::Ponto(int m_x, int m_y) {
	this->x = m_x;
	this->y = m_y;
}

Ponto::~Ponto() {
}

bool Ponto::Set_x(int m_x) {
	return (this->x = m_x);
}

bool Ponto::Set_y(int m_y) {
	return (this->y = m_y);
}

void Ponto::Set_P(int m_x, int m_y) {
	this->x = m_x;
	this->y = m_y;
}

void Ponto::Set_P(Ponto m_P) {
	this->x = m_P.Get_x();
	this->y = m_P.Get_y();
}

void Ponto::gotoxy(short x, short y) {
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

pair<int, int> Ponto::AskPonto(size_t DimY) {
	pair<size_t, size_t> i;
	string x;
	string y;
	gotoxy(0, (short)DimY + 4);
	cout << "Digite a posição da palavra:                                    \n";
	cout << "Digite a posição x\n->";
	getline(cin, x);
	while (!is_numeric(x)) {
		gotoxy(2, (short)DimY + 6);
		for (size_t i = 0; i < x.length(); i++) {
			cout << " ";
		}
		gotoxy(0, (short)DimY + 5);
		cout << "Digite a posição x\n->";
		getline(cin, x);
	}
	cout << "Digite a posição y\n->";
	getline(cin, y);
	while (!is_numeric(y)) {
		gotoxy(2, (short)DimY + 8);
		for (size_t i = 0; i < y.length(); i++) {
			cout << " ";
		}
		gotoxy(0, (short)DimY + 7);
		cout << "Digite a posição y\n->";
		getline(cin, y);
	}
	i = make_pair(stoul(x), stoul(y));
	return i;
}

bool Ponto::IsValid(void) {
	return false;
}

void Ponto::ShowPonto(void) {
	cout << "X: " << this->x << " Y: " << this->y << endl;
}

bool Ponto::operator==(const Ponto p) const {
	return ((this->Get_x() == p.Get_x()) ? (this->Get_y() == p.Get_y()) ? 1 : 0 : 0);
}

bool Ponto::operator!=(const Ponto p) const {
	return !(*this == p);
}

void Ponto::operator=(Ponto p) {
	this->Set_x(p.Get_x());
	this->Set_y(p.Get_y());
}

void Ponto::Save(ofstream& os) {
	os << Get_x() << ";" << Get_y();
}

bool Ponto::Load(ifstream& is) {
	bool sms = 1;
	string p = "";
	getline(is, p, ';');
	if (is_numeric(p)) {
		Set_x(stoi(p));
		getline(is, p);
		if (is_numeric(p)) {
			Set_y(stoi(p));
		}
		else
			sms = 0;
	}
	else
		sms = 0;
	return sms;
}

ostream& operator<<(ostream& os, const Ponto ponto) {
	os << "x: " << ponto.Get_x() << "y: " << ponto.Get_y();
	return os;
}
