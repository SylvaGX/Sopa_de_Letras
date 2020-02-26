#include "Ponto.h"

Ponto::Ponto(){
	x = -1;
	y = -1;
}

Ponto::Ponto(int m_x, char m_y) {
}

Ponto::Ponto(int m_x, int m_y) {
	x = m_x;
	y = m_y;
}

Ponto::~Ponto() {
}

bool Ponto::Set_x(int m_x) {
	return false;
}

bool Ponto::Set_y(int m_y) {
	return false;
}

void Ponto::Set_P(int m_x, int m_y) {
}

void Ponto::Set_P(Ponto m_P) {
}

bool Ponto::Ask2Set_P(void) {
	return false;
}

bool Ponto::IsValid(void) {
	return false;
}

void Ponto::ShowPonto(void) {
}

bool Ponto::operator==(const Ponto ponto) const {
	return false;
}

bool Ponto::operator!=(const Ponto ponto) const {
	return false;
}

void Ponto::operator=(Ponto ponto) {
}

void Ponto::Save(ofstream& os) {
}

void Ponto::Read(ifstream& is) {
}
