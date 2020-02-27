#pragma once
#include <fstream>

using namespace std;

class Ponto{
	private:
		int x; //1 -- 3
		int y; //1 -- 3
	public:
		Ponto();
		Ponto(int m_x, int m_y);
		virtual ~Ponto();
		bool Set_x(int m_x);
		bool Set_y(int m_y);
		void Set_P(int m_x, int m_y);
		void Set_P(Ponto m_P);
		bool Ask2Set_P(void);
		int Get_x(void) const { return x; }
		int Get_y(void) const { return y; }
		bool IsValid(void);
		void ShowPonto(void);
		bool operator == (const Ponto ponto) const;
		bool operator != (const Ponto ponto) const;
		void operator = (Ponto ponto);
		void Save(ofstream& os);
		void Read(ifstream& is);
};

