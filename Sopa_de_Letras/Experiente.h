#pragma once
#include "Main.h"
#include "Jogador.h"

class Experiente : public Jogador {
public:
	long long int time;
	tm* auxTime;
public:
	Experiente();
	~Experiente();
	long long int GetTime() { return time; };
	void SetTime(long long int time) { this->time = time; };
	void setAuxTime(tm* auxTime);
	tm* getAuxTime() { return auxTime; };
	void diferencaHora(tm* atualTime);
	int adquirirPontos();
	void Save(ofstream& os);
	bool Load(ifstream& is);
};

