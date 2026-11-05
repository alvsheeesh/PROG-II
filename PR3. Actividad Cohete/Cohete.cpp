#include "Cohete.h"

Cohete::Cohete()
{
	id = 0;
	destino = "";
	distancia = 0;
	capsulasRestantes = 0;		// un cohete nuevo, ¿cuántas cápsulas lleva?

	// Todos los huecos empiezan VACÍOS
	for (int i = 0; i < 10; i++)
		compartimento[i] = nullptr;
}

Cohete::Cohete(int _id)
{
	id = _id;
	destino = "";
	distancia = 0;
	capsulasRestantes = 0;

	for (int i = 0; i < 10; i++)
		compartimento[i] = nullptr;
}

Cohete::~Cohete()
{
	// El cohete es el DUEÑO de sus cápsulas -> las libera él
	for (int i = 0; i < 10; i++)
	{
		if (compartimento[i] != nullptr)		// solo si en ese hueco HAY cápsula
		{
			delete compartimento[i];			// libero la cápsula del heap
			compartimento[i] = nullptr;			// y el hueco queda vacío
		}
	}
}

bool Cohete::AgregarCap(Capsula* c)
{
	if (c == nullptr)
		return false;					// no me han dado ninguna cápsula

	// Busco el PRIMER hueco libre
	for (int i = 0; i < 10; i++)
	{
		if (compartimento[i] == nullptr)	// ¿este hueco está vacío?
		{
			compartimento[i] = c;		// meto la cápsula aquí
			capsulasRestantes++;						// ahora llevo una cápsula más
			return true;
		}
	}

	return false;							// he mirado los 10 huecos y no hay sitio
}

bool Cohete::EliminarCap(int pos)
{
	// Posición fuera del array, o hueco vacío -> no hay nada que eliminar
	if (pos < 0 || pos >= 10 || compartimento[pos] == nullptr)
		return false;

	// 1) Me GUARDO la energía de la cápsula antes de destruirla
	float sobrante = compartimento[pos]->GetEnergia();

	// 2) La elimino: libero la memoria, vacío el hueco y descuento
	delete compartimento[pos];
	compartimento[pos] = nullptr;
	capsulasRestantes--;

	// 3) Reparto su energía entre las otras cápsulas, una tras otra
	for (int i = 0; i < 10 && sobrante > 0; i++)
	{
		if (compartimento[i] != nullptr)
			sobrante = compartimento[i]->Cargar(sobrante);
	}

	return true;
}

bool Cohete::TransferirCap(int pos, Cohete* otro)
{
	if (otro == nullptr || otro == this)		// no hay cohete destino, o me la envío a mí mismo
		return false;
	if (pos < 0 || pos >= 10 || compartimento[pos] == nullptr)
		return false;

	// Intento meterla en el otro cohete (reutilizo su AgregarCap)
	if (otro->AgregarCap(compartimento[pos]))
	{
		// El otro cohete ya tiene la dirección -> ahora la cápsula es SUYA
		compartimento[pos] = nullptr;		// vacío MI hueco... ¡SIN delete!
		capsulasRestantes--;
		return true;
	}

	return false;		// el otro cohete estaba lleno -> la cápsula se queda conmigo
}

// ================== ENERGÍA ==================

// kWh que se gastan por cada km. Enunciado: 10.000 kWh cada 100.000 km
const float CONSUMO_KM = 0.1f;

float Cohete::EnergiaTotal()
{
	float total = 0;
	for (int i = 0; i < 10; i++)
	{
		if (compartimento[i] != nullptr)
			total += compartimento[i]->GetEnergia();
	}
	return total;
}

bool Cohete::ValidarViaje(float _distancia)
{
	float necesaria = _distancia * CONSUMO_KM;		// kWh que costaría el viaje
	return EnergiaTotal() >= necesaria;					// ¿tengo suficiente?
}

void Cohete::Objetivo(string _destino, float _distancia)
{
	destino = _destino;
	distancia = _distancia;
}

bool Cohete::Viajar()
{
	// Sin destino, o sin energía suficiente -> no despega
	if (destino == "" || !ValidarViaje(distancia))
		return false;

	// Mismo "relevo" que en EliminarCap: cada cápsula da lo que puede
	// y lo que falta lo paga la siguiente
	float porGastar = distancia * CONSUMO_KM;
	for (int i = 0; i < 10 && porGastar > 0; i++)
	{
		if (compartimento[i] != nullptr)
			porGastar = compartimento[i]->Gastar(porGastar);
	}

	cout << "Cohete " << id << " ha llegado a " << destino << "\n";
	destino = "";			// ya ha llegado: no tiene destino pendiente
	distancia = 0;
	return true;
}

void Cohete::Cargar(float cantidad)
{
	// Otra vez el relevo: lo que no cabe en una cápsula pasa a la siguiente
	for (int i = 0; i < 10 && cantidad > 0; i++)
	{
		if (compartimento[i] != nullptr)
			cantidad = compartimento[i]->Cargar(cantidad);
	}

	if (cantidad > 0)
		cout << "No caben " << cantidad << " kWh (cohete lleno)\n";
}

void Cohete::Mostrar()
{
	cout << "--- Cohete " << id << " ---\n";
	cout << "Destino: " << destino << " (" << distancia << " km)\n";
	cout << "Capsulas: " << capsulasRestantes << "/10 | Energia total: " << EnergiaTotal() << " kWh\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "  [" << i << "] ";
		if (compartimento[i] == nullptr)
			cout << "vacio\n";
		else
			cout << compartimento[i]->GetEnergia() << " / " << compartimento[i]->GetCapacidad() << " kWh\n";
	}
}
