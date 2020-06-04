#include "Experiente.h"

tm* Experiente::auxTime = nullptr;

Experiente::Experiente() : Jogador() {
	time = 0;
}

Experiente::~Experiente() {
}

float Experiente::adquirirPontos() {
	float p = (float)GetPontos();
	if (time > 0.0f) {
		p = p / time;
	}
	return p;
}

void Experiente::Save(ofstream& os) {// mudar para por o nivel de dificuldade
	os << "2\n" << this->GetTime() << "\n" << this->GetNome() << "\n" << this->GetIdade() << "\n" << this->GetPontos() << "\n";
}

bool Experiente::Load(ifstream& is) {// mudar para ler o nivel de dificuldade
	bool sms = 1;
	string j = "";
	getline(is, j);
	if (is_numeric(j)) {
		this->SetTime(stoi(j));
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
	}
	else
		sms = 0;
	return sms;
}