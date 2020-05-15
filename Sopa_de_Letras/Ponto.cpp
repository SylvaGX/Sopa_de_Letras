#include "Ponto.h"

int Ponto::w{0};
int Ponto::h{0};

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

void Ponto::UpdateColWin() {
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//get the dimension of the terminal
	GetConsoleScreenBufferInfo(outcon, &csbi);
	Ponto::w = csbi.dwSize.X;
	Ponto::h = csbi.dwSize.Y;
}

void Ponto::gotoxy(short x, short y) {
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

pair<int, int> Ponto::AskPonto(size_t DimY) {
	pair<size_t, size_t> i;
	size_t x, y;
	gotoxy(0, (short)DimY + 4);
	cout << "Digite a posi��o da palavra:                                    \n";
	cout << "Digite a posi��o x\n->";
	cin >> x;
	cout << "Digite a posi��o y\n->";
	cin >> y;
	i = make_pair(x, y);
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
}

void Ponto::Read(ifstream& is) {
}

ostream& operator<<(ostream& os, const Ponto ponto) {
	os << "x: " << ponto.Get_x() << "y: " << ponto.Get_y();
	return os;
}
