#include <iostream> 
#include <fstream> 
using namespace std;

int main() {

	// Datensatz-Struktur: 
	struct pizza {
		char name[16];	// 16 Byte
		int preis;		//  4 Byte 
	};
	// 20 Bytes gesamt = 16 Bytes für 15 Buchstaben + binäre Null und 4 Bytes für ein Integer
	cout << sizeof(pizza) << " Bytes - Struktur Pizza" << endl;

	pizza pizzaKarte[4] = {
		{ "Pizza Margerita", 9 },
		{ "Pizza Salami", 7 },
		{ "Pizza Fungi", 12 },
		{ "Calzone", 14 }
	};
	cout << sizeof(pizzaKarte[0].name) << " Bytes fuer 15 Buchstaben + binaere Null" << endl;
	cout << sizeof(pizzaKarte[0].preis) << " Bytes fuer ein Integer" << endl;
	cout << sizeof(pizzaKarte) << " Bytes fuer 4 Datensaetze" << endl;
    
	// Daten binaer in die Datei schreiben:    
	ofstream dateipuffer;
	dateipuffer.open("pizza.dat", ios::out | ios::binary);
	//ofstream dateipuffer("pizza.dat", ios::out | ios::binary); //  Damit wird ein Konstruktor aufgerufen, der gleich die Datei öffnet. Nicht zu empfehlen,wenn man nicht weiß was ein Konstruktor ist!
	if (!dateipuffer) 
	{ 
		cout << "Fehler beim Erstellen der Datei!" << endl; 
	}
	else
	{
		for (int i = 0; i < sizeof(pizzaKarte) / sizeof(pizza); i++) {
			dateipuffer.write((char*) &pizzaKarte[i], sizeof(pizza));
		    // Daten werden jetzt blockweise geschrieben. 
			// Ein DatenBlock ist in diesem Beispiel 20 Bytes groß. Nach 16 Bytes kommt der Preis ...
			// Es werden 4 DatenBlöcke geschrieben.
			// Der komplette Datenstrom ist 80 Bytes lang.

			// dateipuffer << '\n' << pizzaKarte[i].name << '\t' << pizzaKarte[i].preis; // nicht binaer Formatierung gespeichert
		}
		dateipuffer.close();
		return  0;
	}
}

