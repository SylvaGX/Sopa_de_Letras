#include "Ponto.h"
#include <iostream>


Ponto::Ponto(){
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

bool Ponto::Ask2Set_P(void) {
	return false;
}

bool Ponto::IsValid(void) {
	return false;
}

void Ponto::ShowPonto(void) {
	cout << "X: " << this->x << " Y: " << this->y << endl;
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
