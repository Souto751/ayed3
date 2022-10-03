// Agustín Souto
// Ejercicio 1. Construye un árbol binario de búsqueda a partir de la siguiente lista: G B Q A C K F P D E R H

// El siguiente programa muestra un arbol binario, posicionado de manera horizontal.
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Nodo{
	char caracter;
	Nodo * izq;
	Nodo * der;
};

Nodo *crearNodo(char *_c){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->caracter = *_c;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
} 

void insertar(Nodo *&arbol, char* _c){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(_c);
		arbol = nuevo_nodo;
	}else{
		char valorRaiz = arbol->caracter;
		int comparacion = strcmp(&valorRaiz, _c);
		if(comparacion == 0){
			insertar(arbol->izq, _c);
		}else if(comparacion < 0){
			insertar(arbol->der, _c);
		}else if(comparacion > 0){
			insertar(arbol->izq, _c);
		}
	}
}

void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		cout << arbol->caracter << " - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		inOrden(arbol->izq);
		cout << arbol->caracter << " - ";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		inOrden(arbol->izq);
		inOrden(arbol->der);
		cout << arbol->caracter << " - ";
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der, cont+1);
		for(int i = 0; i < cont; i++){
			cout << "	";
		}
		cout << arbol->caracter << endl;
		mostrarArbol(arbol->izq, cont+1);
	}
}

int main(){
	Nodo *arbol = NULL;
	int contador = 0;
	
	char caracteres[] = {'G','B','Q','A','C','K','F','P','D','E','R','H'};
	
	for(int i = 0; i < sizeof(caracteres); i++){
		char * caracter = &caracteres[i];
		insertar(arbol, caracter);
	}
	
	cout << "Mostrar arbol" << endl << endl;
	mostrarArbol(arbol, contador);
	cout << "\n\nRecorrido en preOrden: ";
	preOrden(arbol);
	cout << endl << endl;
	
	cout << "Recorrido en inOrden: ";
	inOrden(arbol);
	cout << endl << endl;
	
	cout << "Recorrido en postOrden: ";
	postOrden(arbol);
	cout << endl << endl;
	
	system("pause");
	return 0;
}
