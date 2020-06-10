#include "Jogador.h"


Jogador::Jogador() {
	nome = "";
	idade = 0;
	pontos = 0;
}

Jogador::Jogador(string nome, int idade, int pontos) {
	setJogador(nome, idade);
	this->pontos = pontos;
}

Jogador::~Jogador() {
}

void Jogador::newJogador() {
	string Nnome = PedirNome();
	int Nidade = PedirIdade();
	setJogador(Nnome, Nidade);
}

void Jogador::setJogador(string nome, int idade) {
	this->nome = nome;
	this->idade = idade;
	this->pontos = 0;
}

void Jogador::setNome(string nome) {
	this->nome = nome;
}

void Jogador::setIdade(int idade) {
	this->idade = idade;
}

void Jogador::setPontos(int pontos) {
	this->pontos = pontos;
}

string Jogador::PedirNome() {
	string Nnome;
	cout << "Insira o seu nome\n-> ";
	getline(cin, Nnome);
	return Nnome;
}

int Jogador::PedirIdade() {
	string Nidade;
	do {
		system("CLS");
		cout << "Insira a sua idade\n-> ";
		getline(cin, Nidade);
	} while (!is_numeric(Nidade));
	return stoi(Nidade);
}

bool Jogador::JogarPalavra() {

	return false;
}

void Jogador::operator++(int p) {
	this->pontos++;
}

ostream& operator<<(ostream& os, const Jogador *jog) {
	os << jog->GetNome() << endl << jog->GetIdade();
	return os;
}
