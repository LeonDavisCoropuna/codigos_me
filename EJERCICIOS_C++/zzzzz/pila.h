#pragma once
#include "ctime"
#include "iostream"
using namespace std;

class Nodo{
public:
	Nodo *sig;
	int num;
};

class Cola{
private:
	Nodo *raiz;
public:
	Cola();
	void insertar_elemento(int);
	void eliminar_elemento(int);
	bool buscar_elemento(int);
	void mostrar_pila();
	bool ultimo_elemento(int);
	void hombres_mujeres(int);
};
