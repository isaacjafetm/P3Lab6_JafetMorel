#include "Tablero.h"
#include <iostream>
#include "CasillaBuscaMinas.h"
using namespace std;
Tablero::Tablero(int dificultad)
{
	//facil
	if(dificultad==1){
		this-> size=8;
		this->tablero= new CasillaBuscaMinas**[size];
		for(int i=0;i<8;i++){
			tablero[i]= new CasillaBuscaMinas*[size];
		}
		int bombas=0;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(bombas<12){
					int auxBomba= rand()%2;
					tablero[i][j]=new CasillaBuscaMinas(auxBomba);
					bombas++;
				}else{
					tablero[i][j]= new CasillaBuscaMinas(0);
				}
			}
		}
	
	//normal
	}else if(dificultad==2){
		this->size=10;
		this->tablero= new CasillaBuscaMinas**[10];
		for(int i=0;i<10;i++){
			tablero[i]= new CasillaBuscaMinas*[10];
		}
		int bombas=0;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(bombas<25){
					int auxBomba= rand()%2;
					tablero[i][j]=new CasillaBuscaMinas(auxBomba);
					bombas++;
				}else{
					tablero[i][j]= new CasillaBuscaMinas(0);
				}
			}
		}
	
	//dificil	
	}else if(dificultad==3){
		this->size=12;
		this->tablero= new CasillaBuscaMinas**[12];
		for(int i=0;i<12;i++){
			tablero[i]= new CasillaBuscaMinas*[12];
		}
		int bombas=0;
		for(int i=0;i<12;i++){
			for(int j=0;j<12;j++){
				if(bombas<43){
					int auxBomba= rand()%2;
					tablero[i][j]=new CasillaBuscaMinas(auxBomba);
					bombas++;
				}else{
					tablero[i][j]= new CasillaBuscaMinas(0);
				}
			}
		}
	}
}

bool Tablero::destaparCasilla(int fila, int col){
	if(this->tablero[fila][col]->getEsBomba()){
		return true;
	}else{
		this->tablero[fila][col]->setDescubierta(true);
		
					
					
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(i!=j){	
					if(!tablero[fila+i][col+j]->getDescubierta() && !tablero[fila+i][col+j]->getMarcada()){		
						if(calcularBombas(fila+i,col+j)==0){
							char c = ' ';
							tablero[fila+i][col+j]->setDisplay(c);
							return destaparCasilla(fila+i,col+j);
						}else{
							tablero[fila+i][col+j]->setDisplay(calcularBombas(fila+i,col+j)+48);
						}
					}
				
				}
			}
		}
		
	}
}

int Tablero::calcularBombas(int fila, int col){
	int cantidad=0;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i!=0 & j!=0){
				if(tablero[fila+i][col+j]->getEsBomba()){
					cantidad++;
				}
			}		
		}
	}
	return cantidad;
}

void Tablero::marcarCasilla(int fila, int col){
	if(!this->tablero[fila][col]->getMarcada()){
		this->tablero[fila][col]->setMarcada(true);
		this->tablero[fila][col]->setDisplay('X');
	}
}

void Tablero::imprimirBombas(){
	for(int i=0; i<this->size;i++){
		for(int j=0;j<this->size;j++){
			if(this->tablero[i][j]->getEsBomba()){
				cout<<"# ";
			}
			else{
				cout<<"- ";
			}
		}
		cout<<endl;
	}
}

void Tablero::imprimirTablero(){
	for(int i=0; i<this->size;i++){
		for(int j=0;j<this->size;j++){
			cout<<this->tablero[i][j]->getDisplay()<<" ";
		}
		cout<<endl;
	}
}


Tablero::~Tablero()
{
	for(int i =0; i< size; i++){
		delete[] tablero[i];
	}
	delete[]tablero;
	tablero=NULL;
}