#ifndef BUSCAMINAS_H
#define BUSCAMINAS_H
#include "Tablero.h"
#include "CasillaBuscaMinas.h"

class BuscaMinas
{
	public:
		BuscaMinas(int);
		
		~BuscaMinas();
		
		void jugar();
	private:
		Tablero tableroBombas;
};

#endif