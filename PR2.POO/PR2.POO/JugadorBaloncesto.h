#pragma once
#include <iostream>
#include <string>
using namespace std;

class JugadorBaloncesto
{
private:
	string nombre = "";
	float  altura = 0.0f;
	float  peso = 0.0f;
	int    edad = 0;

public:
	void Lanzar();
	void Saltar();
};
