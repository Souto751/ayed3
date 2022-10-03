// Agustin Souto
// 1. Un Negocio necesita gestionar la atenci�n a sus cliente, el mismo recibe los clientes en un Box de Atencia
// que registra los clientes y los carga para su atenci�n seg�n su llegada.
// Nos piden desarrollar un sistema de �Turnos� que se muestren en una pantalla.
// La aplicaci�n deber� registrar los clientes, mostrarlos en orden de llegada, llamarlos seg�n ese orden por
// pantalla con una opci�n �pr�ximo cliente � Box nro�

// 2. �dem 1 pero Implementando Listas en STL

// Hecho para funcionar correctamente en windows

#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

// function for printing the elements in a list
void showlist(list<string> g)
{
	list<string>::iterator it;
	int i = 1;
	for (it = g.begin(); it != g.end(); ++it){
		cout << *it << endl;
	}
}

// function for printing the elements in a list
void callFromQueue(list<string> g)
{
	srand(time(0));
	int num;
	cout << "Proximo cliente - Box nro\n";
	cout << "-------------------------\n"; 
	while(!g.empty()){
		num = rand() % 10 + 1;
		list<string>::iterator it = g.begin();
		Sleep(2000);
		cout << *it << " - " << num << endl;
		g.pop_front();
	}
}

int main(){
	list<string> lista;
	
	lista.push_back("Pepe");
	lista.push_back("Carlos");
	lista.push_back("Oliver");
	lista.push_back("Roman");
	
	cout << "Lista de clientes por orden de llegada:\n";
	showlist(lista);
	
	cout << "------------------------------------------\n\n";
	callFromQueue(lista);
	
	system("pause");
	
	return 0;
}
