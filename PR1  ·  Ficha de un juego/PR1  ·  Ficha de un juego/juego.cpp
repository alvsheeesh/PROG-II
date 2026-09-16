#include "juego.h"

void Juego::IntroducirDatos(string _nombre, string _creador, int _lanzamiento,
	string _lenguaje, float _precio)
{
	nombre = _nombre;
	creador = _creador;
	lanzamiento = _lanzamiento;
	lenguaje = _lenguaje;
	precio = _precio;
}

void Juego::visualizar_datos() const
{
	cout << "-----------------------------" << endl;
	cout << "Nombre      : " << nombre << endl;
	cout << "Creador     : " << creador << endl;
	cout << "Lanzamiento : " << lanzamiento << endl;
	cout << "Lenguaje    : " << lenguaje << endl;
	cout << "Precio      : " << precio << " EUR" << endl;
}

void Juego::modificar_lanzamiento(int anyo)
{
	// Ya no hace falta pasar el juego por referencia (sJuego& j):
	// el metodo trabaja directamente sobre los atributos del objeto que lo llama.
	lanzamiento = anyo;
}

void Juego::hacer_descuento(float desc)
{
	precio = precio - (precio * desc / 100);
}
