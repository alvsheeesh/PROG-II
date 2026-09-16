#include "RobotVEX.h"

void RobotVEX::AgregarRueda(int num)
{
	cout << "Se ha entrado en el metodo RobotVEX::AgregarRueda(" << num << ")" << endl;
}

void RobotVEX::ActivarElevador(int motornum)
{
	cout << "Se ha entrado en el metodo RobotVEX::ActivarElevador(" << motornum << ")" << endl;
}

void RobotVEX::ActivarAutonoma()
{
	cout << "Se ha entrado en el metodo RobotVEX::ActivarAutonoma()" << endl;
}

bool RobotVEX::Colision()
{
	cout << "Se ha entrado en el metodo RobotVEX::Colision()" << endl;
	return false;   // de momento no detecta nada
}
