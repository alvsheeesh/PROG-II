#pragma once
#include <iostream>
#include <string>
using namespace std;

class Perro
{
private:
	string nombre = "";
	int    edad = 0;
	float  peso = 0.0f;
	float  altura = 0.0f;

public:
	void Correr();
	void Dormir();
};
