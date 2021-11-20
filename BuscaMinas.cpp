#include "BuscaMinas.h"
#include "Tablero.h"
#include <iostream>
using namespace std;
BuscaMinas::BuscaMinas(int dificultad)

{
	this->tableroBombas=new Tablero(dificultad);

}

BuscaMinas::~BuscaMinas()
{
}

void BuscaMinas::jugar(){
	bool gameOver = false;
	while (gameOver){
		tableroBombas->imprimirTablero();
		tableroBombas->imprimirBombas();
		char respMarc = ' ';
		char respDest = ' ';
		int fila=0, col=0;
		cout<<"Desea marcar una casilla? [s/n]: ";
		cin>>respMarc;
		if(respMarc == 's'){
			cout<<"Ingrese fila a marcar: ";
			cin>>fila;
			cout<<"Ingrese columna a marcar: ";
			cin>>col;
			tableroBombas->marcarCasilla(fila,col);
		}
		cout<<"Desea marcar una destapar? [s/n]: ";
		cin>>respDest;
		if(respMarc == 's'){
			cout<<"Ingrese fila a destapar: ";
			cin>>fila;
			cout<<"Ingrese columna a destapar: ";
			cin>>col;
			gameOver=tableroBombas->destaparCasilla(fila,col);
		}
	}
}