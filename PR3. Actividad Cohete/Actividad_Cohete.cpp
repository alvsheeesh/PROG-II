#include <iostream>
#include "Cohete.h"
#include "MapController.h"

using namespace std;

// Pregunta al usuario qué cohete quiere y devuelve un PUNTERO a ese cohete
// (nullptr si el número no es válido)
Cohete* ElegirCohete(Cohete* c1, Cohete* c2)
{
	int n;
	cout << "Que cohete? (1/2): ";
	cin >> n;

	if (n == 1) return c1;
	if (n == 2) return c2;

	cout << "Cohete no valido\n";
	return nullptr;
}

int main()
{
	Cohete cohete1(1);
	Cohete cohete2(2);
	Capsula* cap = nullptr;		// el "apuntador a cápsula" que pide el enunciado
	MapController mapa(&cohete1, &cohete2);

	int opcion;
	do
	{
		cout << "\n";
		cohete1.Mostrar();
		cohete2.Mostrar();

		cout << "\n========== MENU ==========\n";
		cout << "1) Crear capsula y anadirla a un cohete\n";
		cout << "2) Eliminar capsula\n";
		cout << "3) Transferir capsula entre cohetes\n";
		cout << "4) Cargar energia a un cohete\n";
		cout << "5) Determinar destino de un cohete\n";
		cout << "6) Activar lanzamiento\n";
		cout << "7) Mover naves por el mapa\n";
		cout << "0) Salir\n";
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
		{
			Cohete* c = ElegirCohete(&cohete1, &cohete2);		// le paso las DIRECCIONES de los dos cohetes
			if (c == nullptr) break;

			float energia;
			cout << "Energia inicial de la capsula (kWh): ";
			cin >> energia;

			cap = new Capsula(10000, energia);		// la creo en el HEAP

			if (c->AgregarCap(cap))
			{
				cout << "Capsula anadida\n";
				// A partir de aqui la capsula es del cohete -> main ya no la toca
			}
			else
			{
				cout << "No hay sitio en el cohete\n";
				delete cap;		// el cohete NO se la ha quedado... ¿quién es el dueño? ¿qué hay que hacer?
			}

			cap = nullptr;		// main ya no la usa
			break;
		}

		case 2:		// TODO: eliminar capsula
		{
			Cohete* c = ElegirCohete(&cohete1, &cohete2);		// le paso las DIRECCIONES de los dos cohetes
			if (c == nullptr) break;

			int posCap;
			cout << "En que posición está la capsula deseas eliminar?: ";
			cin >> posCap;
			
			if (c->EliminarCap(posCap))
			{
				cout << "Capsula eliminada\n";
			}
			else {
				cout << "No se ha podido eliminar la capsula\n";
			}
			break;
		}

		case 3:		// TODO: transferir capsula
		{
			Cohete* c = ElegirCohete(&cohete1, &cohete2);		// le paso las DIRECCIONES de los dos cohetes
			Cohete* otro;
			if (c == nullptr) break;

			int posCap;
			cout << "En que posición está la capsula deseas transferir?: ";
			cin >> posCap;

			if (c == &cohete1) otro = &cohete2;
			else otro = &cohete1;

			if (c->TransferirCap(posCap, otro))
			{
				cout << "Capsula transferida exitosamente\n";
			}
			else {
				cout << "No se ha podido transferir la capsula\n";
			}
			break;
		}


		case 4:		// TODO: cargar energia
		{
			Cohete* c = ElegirCohete(&cohete1, &cohete2);		// le paso las DIRECCIONES de los dos cohetes
			if (c == nullptr) break;

			float cantRecarga;
			cout << "Cuanta energia deseas cargar?: ";
			cin >> cantRecarga;

			c->Cargar(cantRecarga);
			break;
		}

		case 5:		// TODO: determinar destino
		{
			Cohete* c = ElegirCohete(&cohete1, &cohete2);		// le paso las DIRECCIONES de los dos cohetes
			if (c == nullptr) break;

			string Destino;
			float Distancia;
			cout << "A donde deseas llegar?: ";
			cin >> Destino;

			cout << "A cuanta distancia está?: ";
			cin >> Distancia;

			c->Objetivo(Destino, Distancia);
			break;
		}

		case 6:		// TODO: lanzamiento
		{
			Cohete* c = ElegirCohete(&cohete1, &cohete2);		// le paso las DIRECCIONES de los dos cohetes
			if (c == nullptr) break;

			if (c->Viajar())
			{
				cout << "Bon voyage!\n";
			}
			else {
				cout << "No se puede despegar!\n";
			}
			break;
		}

		case 7:
			mapa.Jugar();
			break;
		
		case 0:
			cout << "Adios!\n";
			break;

		default:
			cout << "Opcion no valida\n";
		}

	} while (opcion != 0);

	return 0;
}
