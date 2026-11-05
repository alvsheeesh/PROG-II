#include "Capsula.h"

Capsula::Capsula()
{
	capacidad = 10000;
	energia = 0;			// una cápsula nueva por defecto... ¿llena o vacía? Tú decides //VACIA
}

Capsula::Capsula(float _capacidad, float _energia)
{
	capacidad = _capacidad;

	// ¿Y si me pasan más energía de la que cabe? No la puedo guardar entera.
	if (_energia > capacidad)
		energia = capacidad;
	else
		energia = _energia;
}

float Capsula::GetEnergia()
{
	return energia;
}

float Capsula::GetCapacidad()
{
	return capacidad;
}

float Capsula::Cargar(float cantidad)
{
	float libre = capacidad - energia;		// cuánto espacio le queda a la cápsula

	if (cantidad <= libre)
	{
		energia += cantidad;
		return 0;				// ha cabido todo -> no sobra nada
	}

	energia = capacidad;		// no cabe todo -> la cápsula se llena
	return cantidad - libre;					// y devuelvo lo que no ha cabido
}

float Capsula::Gastar(float cantidad)
{
	if (cantidad <= energia)                        // ¿la cápsula tiene suficiente para dar "cantidad"?
	{
		energia -= cantidad;       // caso A: le quito lo que me piden
		return 0;                 // caso A: "ha dado lo que se necesitaba" → ¿cuánto ha faltado?
	}

	float falta = cantidad - energia;              // caso B: lo que ha faltado (en el ejemplo, 2.000)
	energia = 0;                  // caso B: "quedan 0"
	return falta;
}