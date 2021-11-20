#include <iostream>
#include "BuscaMinas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int opcion=0;
	while(opcion != 4){
		cout<<"Ingrese opcion de dificultad:"<<endl<<"1. Facil"<<endl<<"2. Normal"<<endl<<"3. Dificil"<<endl<<"4. Salir"<<endl;
		cin>>opcion;
		BuscaMinas nuevo = new BuscaMinas(opcion);
		nuevo->jugar();
	}
	return 0;
}