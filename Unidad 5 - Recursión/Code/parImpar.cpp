// Agustin Souto
// 1. Un Negocio necesita gestionar la atención a sus cliente, el mismo recibe los clientes en un Box de Atencia
// que registra los clientes y los carga para su atención según su llegada.
// Nos piden desarrollar un sistema de “Turnos” que se muestren en una pantalla.
// La aplicación deberá registrar los clientes, mostrarlos en orden de llegada, llamarlos según ese orden por
// pantalla con una opción “próximo cliente – Box nro”

// Hecho para funcionar correctamente en windows

#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
using namespace std;

void esImpar(int numero, int _aux);
void esPar(int numero, int _aux);

void esImpar(int numero, int _aux){
	if(_aux == numero){
		cout << "\n\nEl numero " << numero << " es impar." << endl << endl;
	}else{
		cout << "Numero "<< numero << " || Comparativo " << _aux << endl;
		esPar(numero, _aux + 1);
	}
}

void esPar(int numero, int _aux){
	if(_aux == numero){
		cout << "\n\nEl numero " << numero << " es par." << endl << endl;
	}else{
		cout << "Numero "<< numero << " || Comparativo " << _aux << endl; 
		esImpar(numero, _aux + 1);
	}
}


int main(){
	
	int num = 0;
	
	while(num == 0){
		
		try{
			cout << "Inserte un numero para determinar si es par o impar: ";
			cin >> num;
		}catch(int n){
			
		}
	}
	
	esImpar(num, 1); // Llama a esImpar dado que el numero conocido es 1, que a su vez es impar, por lo que es un punto de partida dado.
	
	system("pause");
	
	return 0;
}
