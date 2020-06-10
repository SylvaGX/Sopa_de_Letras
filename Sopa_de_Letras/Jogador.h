#pragma once
#include "Main.h"

class Jogador {
	private:
		string nome;
		int idade;
		int pontos;
	public:
		Jogador();
		Jogador(string nome, int idade, int pontos);
		virtual ~Jogador();
		void newJogador();
		void setJogador(string nome, int idade);
		void setNome(string nome);
		void setIdade(int idade);
		void setPontos(int pontos);
		string PedirNome(void);
		int PedirIdade(void);
		string GetNome(void) const { return nome; };
		int GetIdade(void) const { return idade; };
		int GetPontos(void) const { return pontos; };
		bool JogarPalavra();
		void operator++ (int);
		friend ostream& operator<<(ostream& os, const Jogador *jog);
		virtual int adquirirPontos() =0;
		virtual void Save(ofstream& os) =0;
		virtual bool Load(ifstream& is) =0;
};

