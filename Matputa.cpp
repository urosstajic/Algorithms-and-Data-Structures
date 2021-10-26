#include "Matputa.h"

void Matputa::brisi(char** matp)
{
	for (int i = brVrsta - 1; i >= 0; i--)
		delete[] matp[i];
	delete[] matp;
	matp = nullptr;
}

Matputa::Matputa(int m, int n): Matrica(m*n){ //NEPOTREBNA JE MATRICA CHAROVA
	brKolona = n; brVrsta = m;
	brCvorova = brKolona * brVrsta;
	matp = new char* [brVrsta];
	for (int i = 0; i < brVrsta; i++) {
		matp[i] = new char[brKolona];
		for (int j = 0; j < brKolona; j++)
			matp[i][j] = '#';
	}
}

void Matputa::dodajProlaz(int i, int j)
{
	//if (i > brVrsta || j > brKolona) { std::cout << "Nekorekten unos!"; exit(0); }
	dodajGranu(i*brKolona+j+1, i * brKolona + j+1);
	
	matp[i][j] = ' ';
}

void Matputa::brisiProlaz(int i, int j)
{
	//if (i > brVrsta || j > brKolona) { std::cout << "Nekorekten unos!"; exit(0); }
	brisiGranu(i * brKolona + j+1 , i * brKolona + j+1);
	matp[i][j] = '#';//slicno kao kod dodavanja
}

void Matputa::pisiMatputa() const
{
	for (int i = 0; i < brVrsta; i++) {
		for (int j = 0; j < brKolona; j++)
			std::cout << matp[i][j];
		std::cout << std::endl;
	}
}