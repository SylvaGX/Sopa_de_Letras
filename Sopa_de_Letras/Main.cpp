#pragma once
#include <iostream>
#include <vector>
#include "Ponto.h"
#include "Letra.h"
#include "Palavra.h"
#include "Tabuleiro.h"
#include "Jogador.h"
#include "Jogo.h"
#include "Principiante.h"
#include "Experiente.h"
#include "Main.h"

using namespace std;

int main() {
	Jogo jogo;
	char c;
	int l = 1;
	while (l) {
		cout << "Esta no jogo de LeTraS\n";
		cout << "----------------------\n";
		cout << "----------------------\n";
		cout << "----------------------\n";
		cout << "1 - Novo Jogo\n2 - Carregar Jogo\n0 - Sair\n-> ";
		cin >> c;
		cin.ignore();
		switch (c) {
			case '1':{
				jogo.NewGame();//Inicializar o Jogo com os dados da pessoa, tabuleiro, palavras, etc...
				jogo.init();//Loop do jogo
				break;
			}
			case '2':{
				cout << "Não funciona\n";
				break;
			}
			case '0':{
				l = 0;
				break;
			}
		}
	}
	return 0;
}