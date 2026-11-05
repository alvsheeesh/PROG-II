#pragma once
#include "Cohete.h"

class MapController
{
private:
	int mapa[10][10];		// 0 = casilla libre, 1 = nave 1, 2 = nave 2
	Cohete* naves[2];			// los dos cohetes del main (PUNTEROS a ellos)
	int fila[2];			// fila de cada nave    (naves[0] -> fila[0], naves[1] -> fila[1])
	int col[2];				// columna de cada nave

public:
	MapController(Cohete* n1, Cohete* n2);
	// No hay destructor. ¿Por qué? (pregunta de Pol)

	void Dibujar();
	bool Mover(int n, char tecla);		// n = 0 o 1 (índice de la nave). true si se ha movido
	bool EstanCerca();
	void PreguntarTransferencia();
	void Jugar();						// bucle: dibujar, leer tecla, mover...
};
