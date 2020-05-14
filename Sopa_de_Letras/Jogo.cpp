#include <iostream>
#include "Jogo.h"

using namespace std;

Jogo::Jogo(){
	this->jogador = NULL;
	this->tabuleiro = NULL;
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
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 3);
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
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
						for (size_t i = 0; i < ask.length(); i++) 
							cout << " ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
						cout << "1 - Tentar acertar a palavra\n";
						cout << "2 - Save do jogo                                                  \n";
						cout << "0 - Sair                                                          \n";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 7);
						cout << "                                                                    ";
						Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 7);
						cout << "->";
						break;
					}
					case 1:{
						system("CLS");
						this->tabuleiro->Draw();
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
				break;
			}
			case 0:{
				l = 0;
				break;
			}
		}
	}
	if (this->getTabuleiro()->getPalavras().empty()) {
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 3);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 4);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 5);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 6);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 7);
		cout << "                                                                ";
		Ponto::gotoxy(0, (short)this->getTabuleiro()->getDimY() + 3);
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

void Jogo::init() {
	this->jogador = new Jogador();
	this->tabuleiro = new Tabuleiro();
	Letra::setTipo_M_m(Letra::generateM_m());
	this->tabuleiro->loadPalavras();
	this->tabuleiro->GenerarMatriz();
	system("CLS");
}

void Jogo::SaveGame() {
}

void Jogo::LoadGame() {
}
