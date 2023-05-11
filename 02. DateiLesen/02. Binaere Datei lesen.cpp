#include <iostream> 
#include <fstream> 
#include <string>
using namespace std;

int main() {
	// Datensatz-Struktur: 
	struct pizza {
		char name[16];
		int preis;
	};

	pizza pizzaKarte[4] = { 0 }; // Kurzform: pizza pizzaKarte[4]{};


	// Daten in die Datei lesen:    
	ifstream dateipuffer("../01.Binaere Datei schreiben/pizza.dat", ios::in | ios::binary);
	if (!dateipuffer)
	{
		cout << "Fehler beim Oeffnen der Datei!" << endl;
	}
	else
	{
		// Von der Datei in die Sturktur:
		for (int i = 0; i < sizeof(pizzaKarte) / sizeof(pizza); ++i) {
			dateipuffer.read((char*)&pizzaKarte[i], sizeof(pizza));
		}

		// Konsolenausgabe: 
		for (int i = 0; i < sizeof(pizzaKarte) / sizeof(pizza); ++i) {
			cout << pizzaKarte[i].name << '\t'
				<< pizzaKarte[i].preis;
		}
		dateipuffer.close();
		return  0;
	}
}
