#pragma once
#include <iostream>

using namespace std;

class Capsula
{
private:
	float capacidad;	// kWh máximos que caben en la cápsula
	float energia;			// kWh que tiene AHORA

public:
	Capsula();
	Capsula(float _capacidad, float _energia);

	float GetEnergia();
	float GetCapacidad();

	// Mete energía en la cápsula.
	// Devuelve lo que NO ha cabido (el sobrante). Si cabe todo, devuelve 0.
	float Cargar(float cantidad);

	// Gasta energía de la cápsula.
	// Devuelve lo que ha FALTADO. Si había suficiente, devuelve 0.
	float Gastar(float cantidad);
};
