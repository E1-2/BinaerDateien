#include <iostream> 
#include <fstream> 
using namespace std;


int main() {

	// Datensatz-Struktur: 
	struct pizza {
		char name[16];
		int preis;
	};  
	// 20 Bytes gesamt = 16 Bytes für 15 Buchstaben + binäre Null und 4 Bytes für ein Integer
	pizza pizzaKarte[4]{};

	cout << "Welcher Datensatz soll gelesen werden? 1-4" << endl;
	int wahl = 0;
	cin >> wahl;
	wahl--;


	ifstream dateipuffer;
	dateipuffer.open("../01.Binaere Datei schreiben/pizza.dat", ios::in | ios::binary);

	if (!dateipuffer) { cout << "Fehler beim Oeffnen der Datei!" << endl; }
	else
	{
		dateipuffer.seekg((sizeof(pizza) * wahl), ios::beg); // Setzte den lesenden get Positionszeiger auf ... Byte in der Datei

		int pos1 = dateipuffer.tellg(); // Auf welcher Position steht er? z.B. 20 Byte
		cout << "Dateizeiger auf Position: " << pos1 << endl;

		dateipuffer.read((char*)&pizzaKarte[0], sizeof(pizza)); // Lese einen Datensatz von 20 Byte
	  // neue Schreibweise: reinterpret_cast<char*>(&pizzaKarte[0]) 
	  // alte Schreibweise: (char*)&pizzaKarte[0]   // Ich empfehle die alte Schreibweise, da sie einfacher für Klausuren ist.

		int pos2 = dateipuffer.tellg(); // Auf welcher Position steht er? z. B. 40 Byte
		cout << "Dateizeiger auf Position: " << pos2 << endl;

		cout << pizzaKarte[0].name << '\t' << pizzaKarte[0].preis << endl;

		cout << "Verbrauchter Speicher: " << pos2 - pos1 << " Bytes" << endl;

		dateipuffer.close();
		return  0;
	}
}



