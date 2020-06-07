#include "Experiente.h"

Experiente::Experiente() : Jogador() {
	time = 0;
	auxTime = nullptr;
}

Experiente::~Experiente() {
}

void Experiente::setAuxTime(tm* auxTime) {
	if (auxTime != nullptr) {
		this->auxTime = new tm;
	}
	else {
		delete (this->auxTime);
		this->auxTime = new tm;
	}
	this->auxTime->tm_year = auxTime->tm_year;
	this->auxTime->tm_mon = auxTime->tm_mon;
	this->auxTime->tm_wday = auxTime->tm_wday;
	this->auxTime->tm_mday = auxTime->tm_mday;
	this->auxTime->tm_yday = auxTime->tm_yday;
	this->auxTime->tm_hour = auxTime->tm_hour;
	this->auxTime->tm_min = auxTime->tm_min;
	this->auxTime->tm_sec = auxTime->tm_sec;
	this->auxTime->tm_isdst = auxTime->tm_isdst;
}

void Experiente::diferencaHora(tm* atualTime) {
	//fazer a diferenca das horas
	long long int sec = GetTime();
	sec += ((long long int)atualTime->tm_sec - (long long int)auxTime->tm_sec);
	sec += ((long long int)atualTime->tm_min - (long long int)auxTime->tm_min) * 60;
	sec += ((long long int)atualTime->tm_hour - (long long int)auxTime->tm_hour) * 3600;
	if (sec < 0) {
		cout << "Errooo!!!!";
	}
	else {
		SetTime(sec);
	}
	delete auxTime;
	auxTime = nullptr;
}

float Experiente::adquirirPontos() {
	float p = (float)GetPontos();
	float max = p * 2 * 60;
	return (time <= max) ? p : round(((max)/time)*p);
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