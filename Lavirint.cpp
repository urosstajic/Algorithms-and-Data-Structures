#include "Lavirint.h"
#include <cstring>
#include <iostream>

void Lavirint::resiLvirint(){//BST nacin obilaska, PO SIRINI,obidje taj cvor pa doada u Q susede ako nisu vec obidjeni....
//lavirint uvek ima ulz i izlz, i u Q ce uvek biti bar 1 cvor pre delete
	visit = new int[brCvorova];
	for (int i = 0; i < brCvorova; i++) visit[i] = 0;//inicijalizacija vektora visit na 0
	
	visit[odrediIndeksjVizit(pocetniCvor.i, pocetniCvor.j)] = 1;
	insert(pocetniCvor, pocetniCvor);//on nema prethodnika pa je njegovprethodnik on sam

	int izlaz = 0;//sugerise da li nadjen izlaz, moglo je da bude i bool tipa

	while(Q && !izlaz) {
		Koo vp;
		//pisiVisit();//za proveru
		while (!izlaz) {//obilaze se samo oni cvorovi sa prolazom iz matriceputa
			vp = Delete();
			visit[odrediIndeksjVizit(vp.i, vp.j)] = 1;
			if ((vp.i - 1) >= 0)
				if ((visit[odrediIndeksjVizit(vp.i - 1, vp.j)] == 0) && (matp[vp.i - 1][vp.j] != '#'))
					insert(Koo(vp.i - 1, vp.j), Koo(vp.i, vp.j));//ide gore ako moze, i ubacujemo polje sa kog se "pomerio",zbog rekonstrukcije puta

			if ((vp.i + 1) < brVrsta)
				if ((visit[odrediIndeksjVizit(vp.i + 1, vp.j)] == 0) && (matp[vp.i + 1][vp.j] != '#'))
					insert(Koo(vp.i + 1, vp.j), Koo(vp.i, vp.j));//ide zatim dple

			if ((vp.j - 1) >= 0)
				if ((visit[odrediIndeksjVizit(vp.i, vp.j - 1)] == 0) && (matp[vp.i][vp.j - 1] != '#'))
					insert(Koo(vp.i, vp.j - 1), Koo(vp.i, vp.j));//ide levo

			if ((vp.j + 1) < brKolona)
				if ((visit[odrediIndeksjVizit(vp.i, vp.j + 1)] == 0) && (matp[vp.i][vp.j + 1] != '#'))
					insert(Koo(vp.i, vp.j + 1), Koo(vp.i, vp.j));//ide desno

			//nakon stavljanja skedbenika u red, obilazi se sledeci moguci i postupak se ponalja
			//pisiVisit();//za proveru
			if (T->i == zavrsniCvor.i && T->j == zavrsniCvor.j) { izlaz = 1; break; }
			if (!T->sled) break;
		}if (!T->sled)break;// Q se "ispraznilo"
	}if (!izlaz) std::cout << "Put do izlaza ne postoji! :( " << std::endl;// slucaj kada se Q "isprazni"
	else {
		std::cout << "CESTITAMO, IZLAZ JE USPESNO PRONADJEN! Hvala na ucescu! :) \n";
		pisiPredjeni();
	}//ispisuje put do izlaza ako postoji
}
void Lavirint::dodajUliIzl(int iu, int ju, int ii, int ji)
{
	dodajGranu(iu * brKolona + ju + 1, iu * brKolona + ju + 1);// u matrici susednosti upisuje 1
	dodajGranu(ii * brKolona + ji + 1, ii * brKolona + ji + 1);// isto kao korak pre
	pocetniCvor.i = iu;
	pocetniCvor.j = ju;
	matp[iu][ju] = 'O';//ulaz
	zavrsniCvor.i = ii;
	zavrsniCvor.j = ji;
	matp[ii][ji] = 'X';//izlaz
}
Lavirint::~Lavirint()
{
	T = nullptr;
	delete[] Q; Q = nullptr;
	delete[] visit;
	visit = nullptr;
}
void Lavirint::pisiPredjeni() const//ISPRAVI DA ISPISUJE SAMO POTREBNE CVOROVE!! FALI NEKI USLOV
{
	Elem* pom = Q, * tren = nullptr;
	while ((pom->i != zavrsniCvor.i) || (pom->j != zavrsniCvor.j)) {
		std::cout << "(" << pom->i << "," << pom->j << ")->";
		tren = pom->sled;
		while ((pom->i != tren->ip) || (pom->j != tren->jp)) {// AKO NIJE ULAZNI CVOR I SVE DOK SE NE NADJE potomak cvora na koji pokazuje pom i dok i,j iz pom ne postane = tren ip,jp 
			tren = tren->sled;
		}
		pom = tren;
	}
	if ((pom->i == zavrsniCvor.i) && (pom->j == zavrsniCvor.j)) std::cout << "(" << pom->i << "," << pom->j << ")" << std::endl;
}

int Lavirint::odrediIndeksjVizit(int ii, int jj) 
{
	int indeks;
	return indeks = (ii)*brKolona + jj;
}
void Lavirint::pisiVisit()
{
	for (int i = 0; i < brCvorova; i++) std::cout << visit[i] << " ";
	std::cout << std::endl;
}
/*void Lavirint::popuniGraneMatp()// NEPOTREBNO, POPUNJAVA SE PRILIKOM UNOSA "ULAZNIH PODATAKA"
{
	for (int i = 0; i < brVrsta; i++)
		for (int j = 0; j < brKolona;j++) {
				if (i == 0 && j==0) {
				    if (matp[i][j+1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j+1 + 1);//desni sused
				   if(matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i + brKolona) * brKolona + j + 1);//dpnji sused
				   pisiMatricu();
				}
				else if(i< (brVrsta-1) && i!=0 && j<(brKolona-1)&& j!=0){
					if (matp[i][j + 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j + 1 + 1);//desni
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i + brKolona) * brKolona + j + 1);//donji
					if (matp[i - brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i - brKolona) * brKolona + j + 1);// gornji
					pisiMatricu();//PROVERA
				}
				else if(i == (brVrsta-1) && j == (brKolona-1)){
					if (matp[i][j + 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j + 1 + 1);//desnni
					if (matp[i - brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i - brKolona) * brKolona + j + 1);//gornji

				}
				else if (i!= 0 && i<(brVrsta-1) && j== 0 ) {
					if (matp[i][j + 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j + 1 + 1);//desni
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i + brKolona) * brKolona + j + 1);//donji
					if (matp[i][j-1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j);// levi
					pisiMatricu();//PROVERA
				}
				else if (i> 0 && i<(brVrsta-1) && j < (brKolona - 1) && j!=0) {
					if (matp[i][j + 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j + 1 + 1);//desni
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i + brKolona) * brKolona + j + 1);//donji
					if(matp[i][j - 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j);// levi// levi
					if (matp[i - brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i - brKolona) * brKolona + j + 1);// gornji
				}
				else if (i == (brVrsta-1) && j< (brKolona - 1) && j!=0) {
					if (matp[i][j + 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j + 1 + 1);//desni
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i - brKolona) * brKolona + j + 1);//gornji
					if (matp[i][j - 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j);// levi
					pisiMatricu();//PROVERA
				}

				if (i== (brVrsta - 1) && j == (brKolona-1)) {
					if (matp[i + 1][j] == ' ')dodajGranu(i * brKolona + j + 1, (i + 1) * brKolona + j + 1);//levi sused
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i - brKolona) * brKolona + j + 1);//gornji sused
				}
				else if (i== 0 && j == (brKolona - 1)) {
					if (matp[i][j - 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j);// levi
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i + brKolona) * brKolona + j + 1);//donji
				}
				else if (i!= 0 && i<(brVrsta-1)&& j == (brKolona - 1)) {
					if (matp[i][j - 1] == ' ')dodajGranu(i * brKolona + j + 1, i * brKolona + j);// levi
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i - brKolona) * brKolona + j + 1);//gornji
					if (matp[i + brKolona][j] == ' ')dodajGranu(i * brKolona + j + 1, (i + brKolona) * brKolona + j + 1);//donji
					pisiMatricu();//PROBVERA
				}
		}
}*/

void Lavirint::insert(Koo e, Koo p)
{
	Elem* tren = nullptr;
	if (Q) {
		tren = Q;
		while (tren->sled) tren = tren->sled;
		tren->sled = new Elem;
		tren->sled->i = e.i;
		tren->sled->j = e.j;
		tren->sled->ip = p.i;
		tren->sled->jp = p.j;
	}
	else {
		Q = new Elem;
		Q->i = e.i;
		Q->j = e.j;
		Q->ip = p.i;
		Q->jp = e.j;
	}

}

Lavirint::Koo& Lavirint::Delete() { //ne brise u bukvalnom smislu, posto mi treba za rekonstrukciju puta, vec vraca cvor koji je sledeci za obilazak(T)
	/*Elem* pom = Q;
	Q = Q->sled;
	pom->sled = nullptr;
	return *new Lavirint::Koo(pom->i, pom->j);*/
	if (T)T = T->sled;
	else T = Q;
	return *new Lavirint::Koo(T->i, T->j);

}