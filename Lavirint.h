#ifndef _LAVIRINT_H_
#define _LAVIRINT_H_
#include <iostream>
#include "Matputa.h"

class Lavirint :public Matputa { //dodaj:corovi imaju scoje koordinate, br Cvorova nevalja

protected:
	struct Koo {
		int i, j;
		Koo() {}
		Koo(int ii, int jj) { i = ii; j = jj; }
	};
	struct Elem { int i, j, ip, jp; Elem* sled = nullptr; };
	void insert(Koo, Koo);
	Koo& Delete();
	//bool isQEmty() { return Q; }// ako je T nula onda se " ispraznio red", tj nema elemenata
	void pisiPredjeni()const;
	int odrediIndeksjVizit(int, int);
	void pisiVisit();
	//void popuniGraneMatp();
public:
	Lavirint(int ii, int jj) :Matputa(ii, jj) {};
	void resiLvirint();//BST
	void dodajUliIzl(int, int, int, int) override;
	~Lavirint() override;//mozda bez override
	Lavirint(const Lavirint&) = delete;//lavirint se ne moze kopirati ni na koji nacin
	Lavirint& operator=(const Lavirint&) = delete;
private:
	Koo pocetniCvor, zavrsniCvor;//ulaz i izlaz, tj njihove koordinate 
	int* visit = nullptr;//pamti posecene
	Elem* Q = nullptr, * T = nullptr;//sluzi za ubacivanje sledbenika polju/cvora u lavirintu
};
#endif