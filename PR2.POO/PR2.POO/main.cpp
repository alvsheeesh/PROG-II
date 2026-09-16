#include "Coche.h"
#include "Perro.h"
#include "RobotVEX.h"
#include "JugadorBaloncesto.h"

int main()
{
	cout << "===== Coche =====" << endl;
	Coche coche;
	coche.Acelerar();
	coche.Frenar();
	coche.Girar();

	cout << endl << "===== Perro =====" << endl;
	Perro perro;
	perro.Correr();
	perro.Dormir();

	cout << endl << "===== Robot VEX =====" << endl;
	RobotVEX robot;
	robot.AgregarRueda(4);
	robot.ActivarElevador(2);
	robot.ActivarAutonoma();
	if (robot.Colision())
		cout << "  -> Colision detectada" << endl;
	else
		cout << "  -> Sin colision" << endl;

	cout << endl << "===== Jugador de Baloncesto =====" << endl;
	JugadorBaloncesto jugador;
	jugador.Lanzar();
	jugador.Saltar();

	return 0;
}
