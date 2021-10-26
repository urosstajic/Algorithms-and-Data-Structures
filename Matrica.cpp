#include "Matrica.h"

//CVOROVI SE BROJE OD 1( ALI U MATRICI SE BROJE OD 0, TJ 1 JE NA POZICIJI 0)

void Matrica::brisi(int** mat)
{
	for (int i = brCvorova - 1; i >= 0; i--)
		delete[] mat[i];
	delete[] mat;
	mat = nullptr;
}

Matrica::Matrica(int m)
{
	if (m <= 0) { std::cout << "nekorektan unos!"; exit(0); }
	brCvorova = m;
	mat = new int* [brCvorova];
	for (int i = 0; i < brCvorova; i++) {
		mat[i] = new int[brCvorova];
		for (int j = 0; j < brCvorova; j++)
			mat[i][j] = 0;
	}
}
//smatra se da korisnik zna sta unosi da ce uneti tacno ono sto se od njega ocekuje
void Matrica::dodajGranu(int i, int j) {//EKVIVALENTNO SA DODAJ 1 U MATRICU NA POZICIJI i,j

	mat[i-1][j-1] = mat[j-1][i-1] = 1;//radi se o ne usmerenom grafu , pa dodavanje gane izmedju cvorova i,j implicitno znaci dodavanje i grane j,i
}

void Matrica::brisiGranu(int i, int j) {//EKVIVALENTNO SA DODAJ O U MATRICU NA POZICIJI i, j

	mat[i-1][j-1] = mat[j-1][i-1] = 0;//slicno kao kod dodavanja
}

void Matrica::dodajCvor()// DODAJE NA KRAJ
{
	int** pom = new int* [brCvorova + 1];
	for (int i = 0; i < brCvorova + 1; i++) {
		pom[i] = new int[brCvorova + 1];
		for (int j = 0; j < brCvorova + 1; j++) {
			if (j < (brCvorova) && i < (brCvorova)) pom[i][j] = mat[i][j];
			else pom[i][j] = 0;
		}
	}
	brisi(mat); mat = nullptr;
	mat = pom; pom = nullptr;
	brCvorova++;

}
void Matrica::brisiCvor(int c) //BRISE ZADATI CVOR
{
	if (c > brCvorova || c < 0) {
		std::cout << "Nema tog cvora" << std::endl; exit(0);
	}

	int** pom = new int* [brCvorova - 1];
	for (int i = 0; i < brCvorova - 1; i++) {
		pom[i] = new int[brCvorova - 1];
		for (int j = 0; j < brCvorova - 1; j++)
			if (c < brCvorova - 1) {
				if (i < c && j < c)pom[i][j] = mat[i][j];
				else if (i < c && j >= c)pom[i][j] = mat[i][j + 1];
				else if (i >= c && j < c)pom[i][j] = mat[i + 1][j];
				else if (i >= c && j >= c)pom[i][j] = mat[i + 1][j + 1];
			}
			else  pom[i][j] = mat[i][j];
	}
	brisi(mat); mat = nullptr;
	mat = pom; pom = nullptr;
	--brCvorova;
}

void Matrica::pisiMatricu() const
{
	for (int i = 0; i < brCvorova; i++) {
		for (int j = 0; j < brCvorova; j++)
			std::cout << mat[i][j] << " ";
		std::cout << std::endl;
	}
}

Matrica::~Matrica()
{
	brisi(mat);
}