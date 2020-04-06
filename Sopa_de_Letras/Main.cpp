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

void gotoxy(short x, short y) {
	COORD coord = {y, x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//get the dimension of the terminal
	GetConsoleScreenBufferInfo(outcon, &csbi);
	int w = csbi.dwSize.X;//Colunsa da janela
	int h = csbi.dwSize.Y;//Linhas da janela
	setlocale(LC_ALL, "");
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
				system("CLS");
				gotoxy(0,0);
				cout << "                       ";
				gotoxy(1, 0);
				cout << "                       ";
				gotoxy(2, 0);
				cout << "                       ";
				gotoxy(3, 0);
				cout << "                       ";
				gotoxy(4, 0);
				cout << "              ";
				gotoxy(5, 0);
				cout << "                  ";
				gotoxy(6, 0);
				cout << "         ";
				gotoxy(7, 0);
				cout << "    ";
				gotoxy(0, 0);
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