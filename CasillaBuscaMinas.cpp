#include "CasillaBuscaMinas.h"

CasillaBuscaMinas::CasillaBuscaMinas(int auxBomba)
{
	if(auxBomba==0){
		this->esBomba=false;
	}else{
		this->esBomba=true;
	}
	
	this->descubierta=false;
	this->display='-';
	this->marcada=false;
}

bool CasillaBuscaMinas::getEsBomba(){
	return esBomba;
}

bool CasillaBuscaMinas::getDescubierta(){
	return descubierta;
}

bool CasillaBuscaMinas::getMarcada(){
	return marcada;
}
	
void CasillaBuscaMinas::setDescubierta(bool desc){
	this->descubierta=desc;
}

void CasillaBuscaMinas::setDisplay(char c){
	this->display=c;
}

void CasillaBuscaMinas::setMarcada(bool mar){
	this->marcada=mar;
}