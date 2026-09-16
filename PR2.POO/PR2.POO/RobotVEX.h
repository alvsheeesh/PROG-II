#pragma once
#include <iostream>
#include <string>
using namespace std;

class RobotVEX
{
private:
	int    ruedas = 0;
	int    motores = 0;
	int    piston = 0;
	string nombre = "";
	int    velocidad = 0;

public:
	void AgregarRueda(int num);
	void ActivarElevador(int motornum);
	void ActivarAutonoma();
	bool Colision();
};
