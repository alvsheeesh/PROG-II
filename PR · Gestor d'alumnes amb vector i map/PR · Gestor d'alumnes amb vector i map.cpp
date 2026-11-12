#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Alumne {
public:
	string nom;
	int curs;
	vector<double> notes;

	Alumne(string n, int c) : nom(n), curs(c) {}
};

void afegirAlumne(map<int, Alumne> &alumnes) {
	int id;
	string nom;
	int curs;

	cout << "Id: ";
	cin >> id;

	if (alumnes.count(id) > 0) {
		cout << "Ja existeix un alumne amb l'id " << id << endl;
		return;
	}

	cout << "Nom: ";
	cin >> nom;
	cout << "Curs: ";
	cin >> curs;

	alumnes.insert({ id, Alumne(nom, curs) });
	cout << "Alumne afegit!" << endl;
}

void afegirNota(map<int, Alumne> &alumnes) {
	int id;
	cout << "Id de l'alumne: ";
	cin >> id;

	if (alumnes.count(id) == 0) {
		cout << "No existeix cap alumne amb l'id " << id << endl;
		return;
	}

	double nota;
	cout << "Nota: ";
	cin >> nota;

	Alumne &a = alumnes.at(id);
	a.notes.push_back(nota);

	cout << "Nota afegida a " << a.nom << ". Ara te " << a.notes.size() << " notes" << endl;
}

void veureMitjana(map<int, Alumne> &alumnes) {
	int id;
	cout << "Id de l'alumne: ";
	cin >> id;

	if (alumnes.count(id) == 0) {
		cout << "No existeix cap alumne amb l'id " << id << endl;
		return;
	}

	Alumne &a = alumnes.at(id);

	if (a.notes.empty()) {
		cout << a.nom << " encara no te notes" << endl;
		return;
	}

	double suma = 0;
	for (double n : a.notes) {
		suma += n;
	}
	cout << "Mitjana de " << a.nom << ": " << suma / a.notes.size() << endl;
}

void llistarAlumnes(map<int, Alumne> &alumnes) {
	if (alumnes.empty()) {
		cout << "No hi ha cap alumne" << endl;
		return;
	}

	for (auto &p : alumnes) {
		cout << "Id " << p.first << ": " << p.second.nom
			<< " (curs " << p.second.curs << ") - " << p.second.notes.size() << " notes" << endl;
	}
}

int main() {
	map<int, Alumne> alumnes;
	int opcio;

	do {
		cout << endl;
		cout << "===== GESTOR D'ALUMNES =====" << endl;
		cout << "1. Afegir alumne" << endl;
		cout << "2. Afegir nota" << endl;
		cout << "3. Veure la mitjana d'un alumne" << endl;
		cout << "4. Llistar tots els alumnes" << endl;
		cout << "0. Sortir" << endl;
		cout << "Opcio: ";
		cin >> opcio;

		switch (opcio) {
		case 1:
			afegirAlumne(alumnes);
			break;
		case 2:
			afegirNota(alumnes);
			break;
		case 3:
			veureMitjana(alumnes);
			break;
		case 4:
			llistarAlumnes(alumnes);
			break;
		case 0:
			cout << "Adeu!" << endl;
			break;
		default:
			cout << "Opcio no valida" << endl;
		}
	} while (opcio != 0);
}
