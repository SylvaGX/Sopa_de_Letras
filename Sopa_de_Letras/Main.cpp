#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
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
	Ponto::UpdateColWin();
	int w = Ponto::getWinW();//Colunas da janela
	int h = Ponto::getWinW();//Linhas da janela
	locale::global(locale(""));
	Jogo *jogo;
	char c;
	bool err = false;
	int l = 1;
	while (l) {
		cout << "Está no jogo de LeTraS\n";
		cout << "----------------------\n";
		cout << "----------------------\n";
		cout << "----------------------\n";
		if (err) {
			cout << "Houve um erro ao carregar as palavras. Verifique se o formato do ficheiro se encontra correto.\n";
			err = false;
		}
		cout << "1 - Novo Jogo\n2 - Carregar Jogo\n0 - Sair\n-> ";
		cin >> c;
		cin.ignore();
		switch (c) {
			case '1':{
				system("CLS");
				Ponto::gotoxy(0,0);
				cout << "                       ";
				Ponto::gotoxy(1, 0);
				cout << "                       ";
				Ponto::gotoxy(2, 0);
				cout << "                       ";
				Ponto::gotoxy(3, 0);
				cout << "                       ";
				Ponto::gotoxy(4, 0);
				cout << "              ";
				Ponto::gotoxy(5, 0);
				cout << "                  ";
				Ponto::gotoxy(6, 0);
				cout << "         ";
				Ponto::gotoxy(7, 0);
				cout << "    ";
				Ponto::gotoxy(0, 0);
				jogo = new Jogo();
				if(!(err = jogo->init()))//Inicializar o Jogo com os dados da pessoa, tabuleiro, palavras, etc...
					jogo->loop();//Loop do jogo
				delete jogo;//Apagar o jogo
				system("CLS");
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