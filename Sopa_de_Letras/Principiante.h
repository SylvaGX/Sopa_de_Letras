#pragma once
#include "Main.h"
#include "Jogador.h"

class Principiante : public Jogador {
public:
	Principiante();
	~Principiante();
	float adquirirPontos();
	void Save(ofstream& os);
	bool Load(ifstream& is);
};

