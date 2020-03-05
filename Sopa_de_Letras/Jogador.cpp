#include "Jogador.h"

using namespace std;

Jogador::Jogador() {
	string Nnome = PedirNome();
	int Nidade = PedirIdade();
	setJogador(Nnome, Nidade);
}

Jogador::Jogador(string nome, int idade, int pontos) {
	setJogador(nome, idade);
	this->pontos = pontos;
}

Jogador::~Jogador() {
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

string Jogador::PedirNome() {
	string Nnome;
	cout << "Insira o seu nome\n-> ";
	getline(cin, Nnome);
	return Nnome;
}

int Jogador::PedirIdade() {
	int Nidade;
	cout << "Insira a sua idade\n-> ";
	cin >> Nidade;
	return Nidade;
}

bool Jogador::JogarPalavra() {

	return false;
}

void Jogador::operator++(int p) {
	this->pontos++;
}

ostream& operator<<(ostream& os, const Jogador *jog) {
	os << jog->GetNome() << endl << jog->GetIdade() << endl;
	return os;
}
