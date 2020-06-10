#pragma once
#include "Main.h"
#include "Jogador.h"

class Principiante : public Jogador {
public:
	Principiante();
	~Principiante();
	int adquirirPontos();
	void Save(ofstream& os);
	bool Load(ifstream& is);
};

