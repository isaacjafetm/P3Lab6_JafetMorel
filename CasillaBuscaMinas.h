#ifndef CASILLABUSCAMINAS_H
#define CASILLABUSCAMINAS_H

class CasillaBuscaMinas
{
	public:
		CasillaBuscaMinas(int);
		bool getEsBomba();
		bool getDescubierta();
		bool getDisplay();
		bool getMarcada();
		void setDescubierta(bool);
		void setDisplay(char);
		void setMarcada(bool);
	private:
		bool esBomba;
		bool descubierta;
		char display;
		bool marcada;
};

#endif