#include "Jogador.h"

Jogador::Jogador() {
	nome = "Sem nome";
	idade = -1;
	pontos = 0;
}

Jogador::Jogador(string m_nome, int m_idade, int m_pontos) {
	nome = m_nome;
	idade = m_idade;
	pontos = m_pontos;
}

Jogador::~Jogador() {
}

void Jogador::operator++(int pontos) {
}
