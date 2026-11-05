#pragma once
#include "Capsula.h"
#include <string>

using namespace std;

class Cohete
{
private:
	int id;
	string destino;			// "" = no tiene destino asignado
	float distancia;		// km hasta el destino

	Capsula* compartimento[10];	// el compartimento: 10 huecos. Si un hueco está vacío -> nullptr
	int capsulasRestantes;				// cuántas cápsulas lleva AHORA (0..10)

public:
	Cohete();
	Cohete(int _id);
	~Cohete();					// destructor

	// Devuelven bool para que el main sepa si ha funcionado (true) o no (false)
	bool AgregarCap(Capsula* c);						// recibe el PUNTERO a una cápsula
	bool EliminarCap(int pos);					// pos = hueco del compartimento (0..9)
	bool TransferirCap(int pos, Cohete* otro);		// otro = PUNTERO al cohete que la recibe

	float EnergiaTotal();						// suma de la energía de todas las cápsulas
	bool ValidarViaje(float _distancia);
	void Objetivo(string _destino, float _distancia);
	bool Viajar();
	void Cargar(float cantidad);

	void Mostrar();								// para ver por pantalla cómo está el cohete
};
