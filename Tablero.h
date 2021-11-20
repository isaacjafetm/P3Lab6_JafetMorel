#ifndef TABLERO_H
#define TABLERO_H
#include "CasillaBuscaMinas.h"
class Tablero
{
	public:
		Tablero(int);
		~Tablero();
		
		bool destaparCasilla(int,int);
		int calcularBombas(int, int);
		void marcarCasilla(int, int);
		void imprimirBombas();
		void imprimirTablero();
	private:
		CasillaBuscaMinas*** tablero;
		int size;
};

#endif