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
		string Get_nome(void) const { return nome; };
		int Get_idade(void) const { return idade; };
		int Get_pontos(void) const { return pontos; };
		void operator++ (int pontos);
};

