#pragma once
#include <iostream>
#include <string>
using namespace std;

class Coche
{
private:
	string marca = "";
	string modelo = "";
	int    anyoMatricula = 0;
	int    potencia = 0;

public:
	void Acelerar();
	void Frenar();
	void Girar();
};
