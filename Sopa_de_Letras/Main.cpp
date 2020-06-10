#pragma once
#include "Main.h"
#include "Jogo.h"

int main() {
	locale::global(locale(""));
	Jogo *jogo;
	ifstream is;
	string k = "";
	int err = 0;
	int sms = -1;
	int l = 1;
	int smsf = -1;
	string file_path = __FILE__;
	string dir_path = file_path.substr(0, file_path.rfind("\\"));
	while (l) {
		system("CLS");
		cout << "Está no jogo de LeTraS\n";
		cout << "----------------------\n";
		cout << "----------------------\n";
		cout << "----------------------\n";
		if (err == 1) {
			cout << "Houve um erro ao carregar as palavras. Verifique se o formato do ficheiro se encontra correto.\n";
			err = 0;
		}
		if (sms == 0) {
			cout << "Insira um número!!!!                                                                           \n";
			sms = -1;
		}
		else if (sms == 1) {
			cout << "Insira um número válido!!!!                                                                    \n";
			sms = -1;
		}
		cout << "1 - Novo Jogo\n2 - Carregar Jogo\n0 - Sair\n-> ";
		getline(cin, k);
		if (is_numeric(k)) {
			int j = stoi(k);
			k = "";
			switch (j) {
				case 1:
				{
					system("CLS");
					Ponto::gotoxy(0, 0);
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
					if (!(err = jogo->init()))//Inicializar o Jogo com os dados da pessoa, tabuleiro, palavras, etc...
						jogo->loop();//Loop do jogo
					delete jogo;//Apagar o jogo
					system("CLS");
					break;
				}
				case 2:
				{
					path pathToShow(dir_path);
					path file;
					vector<string> files;
					for (const auto& entry : directory_iterator(pathToShow)) {
						file = entry.path();
						if (file.extension().string() == ".sopa") {
							files.push_back(file.stem().string());
						}
					}
					if (!files.empty()) {
						string c = "";
						bool r = 1;
						int  j = 1;
						while (r) {
							system("CLS");
							cout << "Escolha o ficheiro gravado:\n";
							j = 1;
							for (vector<string>::iterator i = files.begin(); i != files.end(); i++, j++) {
								cout << j << " - " << *i << endl;
							}
							j--;
							cout << "0 - Voltar\n";
							if (smsf == 0) {
								cout << "Insira um número!!!!                                                                           \n";
								smsf = -1;
							}
							else if (smsf == 1) {
								cout << "Insira um número válido!!!!                                                                    \n";
								smsf = -1;
							}
							cout << "-> ";
							getline(cin, c);
							if (is_numeric(c)) {
								if (stoi(c) >= 1 && stoi(c) <= j) {
									string aux = "";
									size_t pos = stoi(c);
									aux = files.at(pos - 1);
									is.open(aux + ".sopa");
									if (is) {
										jogo = new Jogo;
										jogo->setNameFile(aux + ".sopa");
										if (jogo->Load(is)) {
											system("CLS");
											jogo->loop();
										}
										delete jogo;
										is.close();
									}
									r = 0;
								}
								else if (stoi(c) == 0) {
									r = 0;
								}
								else {
									smsf = 1;
								}
							}
							else {
								smsf = 0;
							}
						}
						system("CLS");
					}
					else {
						system("CLS");
					}
					break;
				}
				case 0:
				{
					l = 0;
					break;
				}
				default:
				{
					sms = 1;
				}
			}
		}
		else
			sms = 0;
	}
	return 0;
}

bool is_numeric(const string& value) { return all_of(value.begin(), value.end(), isdigit); }