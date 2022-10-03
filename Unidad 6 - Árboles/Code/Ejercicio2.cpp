// Agustín Souto
// Ejercicio 2. Para el árbol obtenido en el ejercicio 1 muestra el estado del mismo tras extraer de forma
// iterativa los siguientes elementos: a) E b) C c) G

// El siguiente programa muestra un arbol binario, posicionado de manera horizontal.
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Nodo{
	char caracter;
	Nodo * izq;
	Nodo * der;
	Nodo * padre;
};

Nodo *crearNodo(char *_c, Nodo *_padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->caracter = *_c;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = _padre;
	
	return nuevo_nodo;
} 

void insertar(Nodo *&arbol, char* _c, Nodo* _padre){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(_c, _padre);
		arbol = nuevo_nodo;
	}else{
		if(arbol->caracter == *_c){
			insertar(arbol->izq, _c, arbol);
		}else if(arbol->caracter < *_c){
			insertar(arbol->der, _c, arbol);
		}else if(arbol->caracter > *_c){
			insertar(arbol->izq, _c, arbol);
		}
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

Nodo *minimo(Nodo *arbol){
	cout << "minimo" << endl;
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}else{
		return arbol;
	}
}

void reemplazar(Nodo* arbol, Nodo* nuevoNodo){
	cout << "reemplazar" << endl;
	if(arbol->padre){
		cout << "tiene padre" << endl;
		if(arbol->padre->izq){
			if(arbol->padre->izq->caracter == arbol->caracter)
				arbol->padre->izq = nuevoNodo;
		}
		if(arbol->padre->der){ 
			if(arbol->padre->der->caracter == arbol->caracter)
				arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}

void destruirNodo(Nodo *arbol){
	cout << "destruirNodo" << endl;
	arbol->der = NULL;
	arbol->izq = NULL;
	delete arbol;
}

void eliminarNodo(Nodo* arbol){
	cout << "eliminarNodo" << endl;
	if(arbol->izq && arbol->der){
		Nodo *menor = minimo(arbol->der);
		arbol->caracter = menor->caracter;
		eliminarNodo(menor);
	}else if(arbol->izq){
		reemplazar(arbol, arbol->izq);
		destruirNodo(arbol);
	}else if(arbol->der){
		reemplazar(arbol, arbol->der);
		destruirNodo(arbol);
	}else{
		reemplazar(arbol, NULL);
		destruirNodo(arbol);
	}
}

void eliminar(Nodo* arbol, char* _c){
	cout << "eliminar	" << arbol->caracter << " " << *_c << endl;
	char valorRaiz = arbol->caracter;
	char* valorAux = new char;
	*valorAux = *_c;
	
	if(arbol == NULL){
		return;
	}else if(arbol->caracter == *valorAux){
		eliminarNodo(arbol);
	}else if(arbol->caracter < *valorAux){
		eliminar(arbol->der, _c);
	}else if(arbol->caracter > *valorAux){
		eliminar(arbol->izq, _c);
	}
}

int main(){
	
	try{
		Nodo *arbol = NULL;
		int contador = 0;
		
		char caracteres[] = {'G','B','Q','A','C','K','F','P','D','E','R','H'};
		
		char caracteres_eliminar[] = {'E', 'C', 'G'};
		
		for(int i = 0; i < sizeof(caracteres); i++){
			char* caracter = new char(caracteres[i]);
			insertar(arbol, caracter, NULL);
		}
		cout << "Arbol sin eliminar: "<< endl;
		mostrarArbol(arbol, contador);
		cout << endl;
	
	
		for(int i = 0; i < sizeof(caracteres_eliminar); i++){
			char* caracter = new char();
			strcpy(caracter, &caracteres_eliminar[i]);
			eliminar(arbol, caracter);
		}
		
		cout << "\n\nArbol despues de eliminar:" << endl;
		mostrarArbol(arbol, contador);
	}catch(const std::exception &exc){
		cerr << exc.what();
	}
	system("pause");
	return 0;
}
