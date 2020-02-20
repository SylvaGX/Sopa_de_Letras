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
		Jogador(string m_nome, int m_idade, int m_pontos);
		virtual ~Jogador();
		string Get_nome(void) const { return nome; };
		int Get_idade(void) const { return idade; };
		int Get_pontos(void) const { return pontos; };
		void operator ++ (int pontos);
};

