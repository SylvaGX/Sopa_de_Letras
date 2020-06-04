#pragma once
#include "Main.h"
#include "Jogador.h"

class Experiente : public Jogador {
public:
	float time;
	static tm* auxTime;
public:
	Experiente();
	~Experiente();
	float GetTime() { return time; };
	void SetTime(float time) { this->time = time; };
	float adquirirPontos();
	void Save(ofstream& os);
	bool Load(ifstream& is);
};

