#include "juego.h"

int main()
{
	Juego j;

	j.IntroducirDatos("Doom", "id Software", 1993, "C", 20.0f);
	j.visualizar_datos();

	j.hacer_descuento(25);
	j.modificar_lanzamiento(1994);
	j.visualizar_datos();

	// Paso 4: estas dos lineas funcionaban con el struct, ahora NO compilan.
	//
	// j.lanzamiento = 1978;
	// j.precio = -300;
	//
	// Motivo: en una class los miembros son private por defecto, y aqui ademas
	// lanzamiento y precio estan declarados explicitamente en la seccion private.
	// A un atributo privado solo se puede acceder desde los metodos de la propia
	// clase (Juego::...), nunca desde fuera como hace main. El compilador da el
	// error "'Juego::lanzamiento' is private within this context" (g++) o
	// "C2248: no se puede obtener acceso al miembro private" (Visual Studio).
	// Asi el objeto protege sus datos y nadie puede dejarlo en un estado
	// incorrecto (un precio negativo, por ejemplo) saltandose sus metodos.

	return 0;
}
