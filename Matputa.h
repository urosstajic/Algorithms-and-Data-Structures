#ifndef _MATPUTA_H_
#define _MATPUTA_H_
#include "Matrica.h"
#include <iostream>

class Matputa:public Matrica{ //dodaj:corovi imaju scoje koordinate, br Cvorova nevalja	
protected:
	int brVrsta, brKolona;
	int brCvorova;
	char** matp;
	void brisi(char**);
public:
	Matputa(int, int);
	void dodajProlaz(int, int);
	void brisiProlaz(int, int);
	void pisiMatputa() const;
	virtual void dodajUliIzl(int, int, int, int) = 0;
	virtual ~Matputa() { brisi(matp); } //mozda bez virtual
};
#endif