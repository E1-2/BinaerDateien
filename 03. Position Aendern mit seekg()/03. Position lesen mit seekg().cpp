#include <iostream> 
#include <fstream> 
using namespace std;


int main() {

	// Datensatz-Struktur: 
	struct pizza {
		char name[16];
		int preis;
	};

	pizza datensatz{};

	cout << "1.Datensatz: Margerita    9" << endl;
	cout << "2.Datensatz: Salami       7" << endl;
	cout << "3.Datensatz: Pizza Fungi 12" << endl;
	cout << "4.Datensatz: Calzone     14" << endl;
	cout << endl;
	cout << "Welcher Datensatz soll gelesen werden? 1-4" << endl;

	int wahl = 0;
	cin >> wahl;
	wahl--;

	// Einen Datensatz aus der Datei lesen:    
	ifstream dateipuffer("../01.Binaere Datei schreiben/pizza.dat", ios::in | ios::binary);
	if (!dateipuffer)
	{
		cout << "Fehler beim Oeffnen der Datei!" << endl;
	}
	else
	{
		dateipuffer.seekg((sizeof(pizza) * wahl), ios::beg);    // Setzt den Dateizeiger auf den Anfang des gewünschten Datensatzs.
		// seekg(20*wahl, relativ vom Beginn der Datei)

		dateipuffer.read((char*)&datensatz, sizeof(pizza));  // Speichert diesen in die Struktur datensatz. 

		cout << datensatz.name << '\t'						 // Gibt den Inhalt der Struktur datensatz aus.
			<< datensatz.preis << endl;
	}

	dateipuffer.close();
	return  0;
}

