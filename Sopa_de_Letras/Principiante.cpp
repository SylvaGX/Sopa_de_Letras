#include "Principiante.h"

Principiante::Principiante() : Jogador() {
}

Principiante::~Principiante() {
}

int Principiante::adquirirPontos() {
	return GetPontos();
}

void Principiante::Save(ofstream& os) {// mudar para por o nivel de dificuldade
	os << "1\n" << this->GetNome() << "\n" << to_string(this->GetIdade()) << "\n" << this->GetPontos() << "\n";
}

bool Principiante::Load(ifstream& is) {// mudar para ler o nivel de dificuldade
	bool sms = 1;
	string j = "";
	getline(is, j);
	this->setNome(j);
	getline(is, j);
	if (is_numeric(j)) {
		this->setIdade(stoi(j));
		getline(is, j);
		if (is_numeric(j)) {
			this->setPontos(stoi(j));
		}
		else
			sms = 0;
	}
	else
		sms = 0;
	return sms;
}