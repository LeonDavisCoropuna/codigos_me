#include "pila.h"
#include <iostream>
#include "ctime"
using namespace std;

Cola::Cola(){
	raiz = NULL;
}

bool Cola::ultimo_elemento(int num){
	Nodo *ultimo = raiz;
	while(ultimo->sig != NULL){
		ultimo = ultimo->sig;
	}
	if(ultimo->num == num){
		return true;
	}
	return false;
}

void Cola::insertar_elemento(int num){
	
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->num = num;
	nuevo_nodo->sig = NULL;
	if(raiz == NULL){
		raiz = nuevo_nodo;
	}
	else{
		Nodo *aux = raiz;
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = nuevo_nodo;
	}
}

void Cola::eliminar_elemento(int num){
	if(raiz == NULL){
		cout<<"Lista vacía\n";
		return;
	}
	
	if(buscar_elemento(num)){
		
		if(ultimo_elemento(num)){
			cout<<"\nNo se puede eliminar el ultimo elemento\n";
			return;
		}
		
		if(raiz->num == num){
			Nodo *aux = raiz;
			raiz = raiz->sig;
			delete aux;
			return;
		}
		
		Nodo *actual = raiz;
		Nodo *anterior = raiz;
		
		while(actual->num != num){
			actual = raiz;
			raiz = raiz->sig;
			delete actual;
		}
		/*
		while(actual != NULL){
			if(actual->num == num){
				anterior->sig = actual->sig;
				delete actual;
				return;
			}
			else{
				Nodo *aux = raiz;
				raiz = raiz->sig;
				delete aux;
				
			}
			anterior = actual;
			actual = actual->sig;
		}
		*/
		
	}
}

bool Cola::buscar_elemento(int num){
	Nodo *aux = raiz;
	while(aux != NULL){
		if(aux->num == num){
			return true;
		}
		aux = aux->sig;
	}
	return false;
}

void Cola::mostrar_pila(){
	Nodo *aux = raiz;
	while(aux != NULL){
		cout<<aux->num<<"  ";
		aux = aux->sig;
	}
}

void Cola::hombres_mujeres(int num){
	int h,m;
	cout<<"Cantidad de hombres?: ";cin>>h;
	cout<<"Cantidad de mujeres?: ";cin>>m;
	
	Cola *hombres = new Cola();
	Cola *mujeres = new Cola();
	
	for(int i=0;i<h;i++){
		int aux;
		cout<<"Edad hombres "<<i+1<<": ";cin>>aux;
		hombres->insertar_elemento(aux);
	}
	for(int i=0;i<m;i++){
		int aux;
		cout<<"Edad mujeres "<<i+1<<": ";cin>>aux;
		mujeres->insertar_elemento(aux);
	}
	int contH =0, contM=0;
	
	for(int i=0;i<num;i++){
		
		if(hombres->raiz->num > mujeres->raiz->num){
			contH++;
		}
		else{
			contM++;
		}
		Nodo *aux = hombres->raiz;
		hombres->insertar_elemento(aux->num);
		hombres->raiz = hombres->raiz->sig;
		delete aux;
		
		Nodo *aux2 = mujeres->raiz;
		mujeres->raiz = mujeres->raiz->sig;
		mujeres->insertar_elemento(aux2->num);
		delete aux2;
		
	}
	
	cout<<"Hombres: "<<contH<<endl;
	cout<<"Mujeres: "<<contM<<endl;
}
