#pragma once
#include <string>

using namespace std;

class Jogador {
	private:
		string nome;
		int idade;
		int pontos;
	public:
		Jogador();
		Jogador(string nome, int idade, int pontos);
		virtual ~Jogador();
		void setJogador(string nome, int idade);
		void setNome(string nome);
		void setIdade(int idade);
		string PedirNome(void);
		int PedirIdade(void);
		string GetNome(void) const { return nome; };
		int GetIdade(void) const { return idade; };
		int GetPontos(void) const { return pontos; };
		bool JogarPalavra();
		void operator++ (int);
};

