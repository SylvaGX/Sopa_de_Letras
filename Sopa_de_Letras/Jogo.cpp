#include "Jogo.h"

using namespace std;

Jogo::Jogo(){
	this->jogador = NULL;
	this->tabuleiro = NULL;
	this->namefile = "";
}

Jogo::~Jogo() {
	delete jogador;
	delete tabuleiro;
}

//Loop do jogo
void Jogo::loop() {
	int j = 0;
	int l = 1;
	string ask = "";
	int sms = 0;
	this->tabuleiro->Draw();
	cout << "Categoria: " << this->getTabuleiro()->getCategoria() << endl;
	cout << "Pontos: " << this->getJogador()->GetPontos() << endl;
	cout << "1 - Tentar acertar a palavra\n2 - Save do jogo\n0 - Sair\n";
	while (l && !this->getTabuleiro()->getPalavras().empty()) {
		cin >> j;
		switch (j) {
			case 1:{
				ask = Palavra::pedirpalavra(this->getTabuleiro()->getDimX(), this->getTabuleiro()->getDimY());
				sms = this->getTabuleiro()->VerificarPalavra(ask, *(this->jogador));
				switch (sms) {
					case 0:
					case 2:
					case 3:
					case 4:{
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
						if (sms == 0) {
							cout << "Escreva uma palavra!!!                                        \n";
						}
						else if (sms == 2) {
							cout << "Essa palavra não pertence às selecionas!!!!                   \n";
						}
						else if(sms == 3){
							cout << "Já acertou essa palavra!!!                                    \n";
						}
						else if(sms == 4){
							cout << "A palavra não se encontra nas respetivas coordenadas!!!       \n";
						}
						else {
							cout << "Insira coordenadas validas!!!                                 \n";
						}
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
						for (size_t i = 0; i < ask.length(); i++) 
							cout << " ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
						cout << "1 - Tentar acertar a palavra\n";
						cout << "2 - Save do jogo                                                  \n";
						cout << "0 - Sair                                                          \n";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
						cout << "                                                                    ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
						cout << "->";
						break;
					}
					case 1:{
						system("CLS");
						this->tabuleiro->Draw();
						cout << "Categoria: " << this->getTabuleiro()->getCategoria() << endl;
						cout << "Pontos: " << this->getJogador()->GetPontos() << endl;
						cout << "Acertou a palavra!!!\n";
						cout << "1-Tentar acertar a palavra\n2-Save do jogo\n0-Sair\n";
						cout << "->";
						break;
					}
					default:
						break;
				}
				break;
			}
			case 2:{
				sms = Save();
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
				switch (sms) {
					case 0:{
						cout << "Erro ao gravar no ficheiro!!!                                 \n";
						break;
					}
					case 1:{
						cout << "Ficheiro gravado com sucesso!!!                                 \n";
						break;
					}
					default:
						break;
				}
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
				cout << "1 - Tentar acertar a palavra\n";
				cout << "2 - Save do jogo                                                  \n";
				cout << "0 - Sair                                                          \n";
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
				cout << "                                                                    ";
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
				cout << "->";
				sms = 0;
				break;
			}
			case 0:{
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
				cout << "                                                                ";
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
				cout << "                                                                ";
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 6);
				cout << "                                                                ";
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 7);
				cout << "                                                                ";
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
				cout << "                                                                ";
				Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
				cout << "1 - Sair e Guardar\n2 - Sair sem gravar\n0 - Voltar\n-> ";
				cin >> j;
				switch (j) {
					case 0:{
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
						cout << "                                                                    ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
						cout << "                                                                    ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 6);
						cout << "                                                                    ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 7);
						cout << "                                                                    ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
						cout << "1 - Tentar acertar a palavra\n";
						cout << "2 - Save do jogo                                                  \n";
						cout << "0 - Sair                                                          \n";
						cout << "-> ";
						break;
					}
					case 1:{
						sms = Save();
						switch (sms) {
							case 0:{
								Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
								cout << "Erro ao gravar no ficheiro!!!                                 \n";
								Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
								for (size_t i = 0; i < ask.length(); i++)
									cout << " ";
								Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
								cout << "1 - Tentar acertar a palavra\n";
								cout << "2 - Save do jogo                                                  \n";
								cout << "0 - Sair                                                          \n";
								Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
								cout << "                                                                    ";
								Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
								cout << "->";
								sms = 0;
								break;
							}
							case 1:{
								l = 0;
								break;
							}
							default:
								break;
						}
						break;
					}
					case 2:{
						l = 0;
						break;
					}
				}
				break;
			}
		}
	}
	if (this->getTabuleiro()->getPalavras().empty()) {
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 6);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 7);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 8);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
		cout << "Voce conseguiu acertar todas as palavras!!!! Parabéns!!!!\n";
		system("PAUSE");
	}
}

Tabuleiro* Jogo::getTabuleiro() {
	return this->tabuleiro;
}

Jogador* Jogo::getJogador() {
	return this->jogador;
}

bool Jogo::init() {
	bool err = false;
	this->jogador = new Jogador();
	this->tabuleiro = new Tabuleiro();
	Letra::setTipo_M_m(Letra::generateM_m());
	if(!(err = this->tabuleiro->loadPalavras()))
		this->tabuleiro->GenerarMatriz();
	system("CLS");
	return err;
}

int Jogo::Save() {
	ofstream ofs;
	string aux = "";
	int sms = 0;

	if (namefile == "") {
		time_t now = time(0);

		tm* ltm = localtime(&now);
		// print various components of tm structure.
		if (ltm->tm_hour < 10) {
			aux += "0" + to_string(ltm->tm_hour) + "-";
		}
		else aux += to_string(ltm->tm_hour) + "-";
		if (ltm->tm_min < 10) {
			aux += "0" + to_string(ltm->tm_min) + "-";
		}
		else aux += to_string(ltm->tm_min) + "-";
		if (ltm->tm_sec < 10) {
			aux += "0" + to_string(ltm->tm_sec) + " ";
		}
		else aux += to_string(ltm->tm_sec) + " ";
		if (ltm->tm_mday < 10) {
			aux += "0" + to_string(ltm->tm_mday) + "_";
		}
		else aux += to_string(ltm->tm_mday) + "_";
		if (ltm->tm_mon < 10) {
			aux += "0" + to_string(ltm->tm_mon) + "_";
		}
		else aux += to_string(ltm->tm_mon) + "_";
		aux += to_string(ltm->tm_year) + ".sopa";
	}
	else aux = namefile;
	ofs.open(aux);
	if (ofs){
		getJogador()->Save(ofs);
		getTabuleiro()->Save(ofs);
		ofs.close();
		sms = 1;
	}
	return sms;
}

void Jogo::Load() {
}
