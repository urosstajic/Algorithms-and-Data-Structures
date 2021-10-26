#ifndef _MATRICA_H_
#define _MATRICA_H_
#include <iostream>

class Matrica { //dodaj:corovi imaju scoje koordinate, br Cvorova nevalja
protected:
	//int brVrsta, brKolona;//nepotrebno, matrica susednosti je kvadratna matrica, brkolona=brvrsta=brcvorova 
	int brCvorova;//dovoljan podatak za dimenzije
	int** mat;
	void brisi(int**);
public:
	Matrica(int);
	void dodajGranu(int, int);
	void brisiGranu(int, int);
	void dodajCvor();
	void brisiCvor(int);
	void pisiMatricu() const;
	~Matrica();

};
#endif