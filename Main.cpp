#include "Matrica.h"
#include "Lavirint.h"
#include <iostream>
using namespace std;

const int MAXVRSTA = 80;
const int MAXKOLONA = 50;

//SMATRAM DA CE KORISNIK PRATITI UPUTSTVA IZATO NISAM PISALA NEKE IZUZETKE(npr ako unese koordinate za prolaz iste kao za ulaz i izlaz)
// pravila sam matricu puta i na nju primenjivala BST, jer sam nju posmatrala kao graf
//matrica susednosti je dodatak, jer mi jije bilo bas najjasnije kako treba povezati prvi i drugi zadatak
//zadatak je mogao da se resi i bez matrice puta, samo sa matricom susednosti, kada se na mat.sus. primeni BST, ali mi je bilo logicnije da radim sa mat. puta

int main() {
	while (1) {
		cout << "DOBRODOSLI!\nMolimo Vas da unesete dimenzije lavirinta (i,j)?" << endl;
		int i, j, ii, jj; cin >> i; cin >> j;//pomocne promenljive
		if (i > MAXVRSTA || j > MAXKOLONA || j < 0 || i < 0) { cout << "Nekotektan unos!\n"; exit(0); }
		Lavirint L(i, j);
		cout << "Unesite koordinate ulaza iizlaza:\n"; cin >> i; cin >> j; cin >> ii; cin >> jj;
		L.dodajUliIzl(i, j, ii, jj);
		//L.pisiMatricu();//PORVERA
		int odluka;

		while (1) {
			cout << "Sta zelite?\n 1)DODAVANJE PROLAZA\n 2)BRISANJE PROLAZA\n 3)IZMENA ULAZA IIZLAZA U LAVIRINT\n 4)ISPIS LAVIRINTA\n 5)NACI PUT DO IZLAZA\n 6)ISPOCETKA\n 7)NAPUSTANJE PROGRAMA(UNESITE 0)?\n";
			cout << "Vasa odluka?\n";
			cin >> odluka;
			if (!odluka) { cout << "HVALA NA UCESCU! POZDRAV! :(\n";  exit(0); }
			if (odluka == 1) {
				int odluka2 = 1;
				while (odluka) {
					cout << "Ako zelite da unesete prolaz-> 1, ako ste zavrsili sa unosom-> 0.\nPAZNJA:NEMOJTE UNOSITI ISTE KOORDINATE KAO ZA ULAZ I IZLAZ!"; cin >> odluka2;
					if (odluka2) {
						cout << "Unesite koordinate prolaza (i,j):\n";
						cin >> ii; cin >> jj;
						L.dodajProlaz(ii, jj);
					}
					else break;
				}
			}
			if (odluka == 2) { cout << "Unesite koordinate prolaza koji zelite da obrisete:\n"; cin >> i; cin >> j; L.brisiGranu(i, j); }
			if (odluka == 3) { cout << "Unesite koordinate ulaza iizlaza:\n"; cin >> i; cin >> j; cin >> ii; cin >> jj; L.dodajUliIzl(i, j, ii, jj); }
			if (odluka == 4) { cout << "Vas lavirint:\n"; L.pisiMatputa(); }
			if (odluka == 5) { L.resiLvirint(); }
			if (odluka == 6) { break; }
		}
	}
	return 0;
}