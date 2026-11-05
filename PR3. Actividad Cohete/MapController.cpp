#include "MapController.h"
#include <cstdlib>		// abs()

MapController::MapController(Cohete* n1, Cohete* n2)
{
	naves[0] = n1;
	naves[1] = n2;

	// Todo el mapa empieza libre
	for (int f = 0; f < 10; f++)
		for (int c = 0; c < 10; c++)
			mapa[f][c] = 0;

	// Posiciones iniciales (como en el dibujo de Pol: lejos una de otra)
	fila[0] = 1;	col[0] = 3;
	fila[1] = 3;	col[1] = 6;

	// Marco cada nave en el mapa con su número
	mapa[fila[0]][col[0]] = 1;
	mapa[fila[1]][col[1]] = 2;
}

void MapController::Dibujar()
{
	cout << "\n   0 1 2 3 4 5 6 7 8 9\n";
	for (int f = 0; f < 10; f++)
	{
		cout << f << "  ";
		for (int c = 0; c < 10; c++)
		{
			if (mapa[f][c] == 0)
				cout << ". ";
			else
				cout << mapa[f][c] << " ";
		}
		cout << "\n";
	}
}

bool MapController::Mover(int n, char tecla)
{
	// Calculo la casilla a la que quiero ir (todavía no me muevo)
	int nuevaF = fila[n];
	int nuevaC = col[n];

	switch (tecla)
	{
	case 'w': nuevaF--; break;		// arriba
	case 's': nuevaF++; break;			// abajo
	case 'a': nuevaC--; break;			// izquierda
	case 'd': nuevaC++; break;			// derecha
	default: return false;			// tecla no válida
	}

	// ¿Me saldría del mapa?
	if (nuevaF < 0 || nuevaF > 9 || nuevaC < 0 || nuevaC > 9)
		return false;

	// ¿La casilla está ocupada por la otra nave?
	if (mapa[nuevaF][nuevaC] != 0)
		return false;

	// Me muevo: libero la casilla vieja y marco la nueva
	mapa[fila[n]][col[n]] = 0;		// la casilla que dejo queda...
	fila[n] = nuevaF;
	col[n] = nuevaC;
	mapa[fila[n]][col[n]] = n + 1;		// ¡ojo! n vale 0 o 1, pero en el mapa la nave es 1 o 2
	return true;
}

bool MapController::EstanCerca()
{
	int df = abs(fila[0] - fila[1]);		// distancia en filas
	int dc = abs(col[0] - col[1]);			// distancia en columnas
	return df <= 1 && dc <= 1;				// pegadas (también en diagonal)
}

void MapController::PreguntarTransferencia()
{
	char resp;
	cout << "Las naves estan cerca! Quieres transferir una capsula? (s/n): ";
	cin >> resp;
	if (resp != 's')
		return;

	int origen;
	cout << "Desde que nave? (1/2): ";
	cin >> origen;
	if (origen != 1 && origen != 2)
		return;

	int pos;
	cout << "Posicion de la capsula (0-9): ";
	cin >> pos;

	// nave 1 -> naves[0], nave 2 -> naves[1]
	Cohete* desde;
	Cohete* hacia;
	if (origen == 1)
	{
		desde = naves[0];		// sale de la nave 1
		hacia = naves[1];		// va a la nave 2
	}
	else
	{
		desde = naves[1];		// sale de la nave 2
		hacia = naves[0];		// va a la nave 1
	}

	if (desde->TransferirCap(pos, hacia))
		cout << "Transferencia hecha\n";
	else
		cout << "No se ha podido transferir\n";
}

void MapController::Jugar()
{
	int n = 0;		// empiezo moviendo la nave 1 (índice 0)
	char tecla;

	while (true)
	{
		Dibujar();
		cout << "Nave " << n + 1 << " | WASD = mover, c = cambiar nave, q = volver al menu: ";
		cin >> tecla;

		if (tecla == 'q')
			break;

		if (tecla == 'c')
		{
			n = 1 - n;		// 0 -> 1, 1 -> 0
			continue;
		}

		if (!Mover(n, tecla))
			cout << "Movimiento no valido\n";
		else if (EstanCerca())
			PreguntarTransferencia();
	}
}
