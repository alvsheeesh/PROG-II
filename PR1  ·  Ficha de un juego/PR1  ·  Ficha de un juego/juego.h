#pragma once
#include <iostream>
#include <string>
using namespace std;

// PR1 - Ficha de un juego
// Partimos de structuraJuego.cpp: el struct sJuego pasa a ser la clase Juego.
// Los atributos quedan en private y solo se accede a ellos desde los metodos.

class Juego
{
private:
	string nombre;
	string creador;
	int    lanzamiento;
	string lenguaje;
	float  precio;

public:
	// Como los atributos son privados, main ya no puede rellenarlos con strcpy
	// ni con j.precio = ...; necesitamos un metodo publico que lo haga.
	void IntroducirDatos(string _nombre, string _creador, int _lanzamiento,
		string _lenguaje, float _precio);

	// Los tres metodos del enunciado, ahora dentro de la clase y en public
	void visualizar_datos() const;   // const: solo lee, no modifica el objeto
	void modificar_lanzamiento(int anyo);
	void hacer_descuento(float desc);
};
