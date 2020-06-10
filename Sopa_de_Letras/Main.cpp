#pragma once
#include "Main.h"
#include "Jogo.h"

bool compareStringFile(string str1, string str2) {
	size_t pos1 = str1.find(" ");
	size_t pos2 = str2.find(" ");
	string substr1 = str1.substr(pos1 + 1);
	string substr2 = str2.substr(pos2 + 1);
	substr1.erase(std::remove(substr1.begin(), substr1.end(), '_'), substr1.end());
	substr2.erase(std::remove(substr2.begin(), substr2.end(), '_'), substr2.end());
	int p = -1;
	size_t i = 0;
	for (i = 0; i < substr1.length(); i++) {
		if (i < 4) {
			if (substr1[i] > substr2[i] && i % 2 == 0) {
				p = 1;
				i++;
			}
			else if (substr1[i] < substr2[i] && i % 2 == 0) {
				p = 0;
				i++;
			}
			else if (substr1[i] == substr2[i] && i % 2 == 0) {
				continue;
			}
			else if(substr1[i] > substr2[i] && i % 2 != 0){
				p = 1;
			}
			else if (substr1[i] < substr2[i] && i % 2 != 0) {
				p = 0;
			}
		}
		else {
			if (substr1[i] > substr2[i]) {
				p = 1;
				break;
			}
			else if(substr1[i] < substr2[i]) {
				p = 0;
				break;
			}
		}
	}
	if (p == -1) {
		substr1 = str1.substr(0, pos1);
		substr2 = str2.substr(0, pos2);
		substr1.erase(std::remove(substr1.begin(), substr1.end(), '-'), substr1.end());
		substr2.erase(std::remove(substr2.begin(), substr2.end(), '-'), substr2.end());
		for (i = 0; i < substr1.length(); i++) {
			if (substr1[i] > substr2[i] && i % 2 == 0) {
				p = 1;
				break;
			}
			else if (substr1[i] < substr2[i] && i % 2 == 0) {
				p = 0;
				break;
			}
			else if (substr1[i] == substr2[i] && i % 2 == 0) {
				continue;
			}
			else if (substr1[i] > substr2[i] && i % 2 != 0) {
				p = 1;
				break;
			}
			else if(substr1[i] < substr2[i] && i % 2 != 0){
				p = 0;
				break;
			}
		}
		if (p == -1) p = 0;
	}
	return p;
}

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
		else if(sms == 2){
			cout << "Não existe jogos guardados!!!!                                                                 \n";
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
					sort(files.begin(), files.end(), compareStringFile);
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
					}
					else {
						sms = 2;
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