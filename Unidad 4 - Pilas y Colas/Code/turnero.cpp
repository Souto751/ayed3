// Agustin Souto
// 1. Un Negocio necesita gestionar la atención a sus cliente, el mismo recibe los clientes en un Box de Atencia
// que registra los clientes y los carga para su atención según su llegada.
// Nos piden desarrollar un sistema de “Turnos” que se muestren en una pantalla.
// La aplicación deberá registrar los clientes, mostrarlos en orden de llegada, llamarlos según ese orden por
// pantalla con una opción “próximo cliente – Box nro”

// Hecho para funcionar correctamente en windows

#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void showq(queue<string> gq)
{
    queue<string> g = gq;
    while (!g.empty()) {
        cout << g.front() << endl;
        g.pop();
    }
    cout << '\n';
}

void callFromQueue(queue<string> gq)
{
	srand(time(0));
	int num;
	cout << "Proximo cliente - Box nro\n";
	cout << "-------------------------\n"; 
    while (!gq.empty()) {
    	num = rand() % 10 + 1;
    	Sleep(3000);
        cout << gq.front() << " - " << num << endl;
        gq.pop();
    }
    cout << '\n';
}

int main(){
	queue<string> cola;
	
	cola.push("Pepe");
	cola.push("Carlos");
	cola.push("Oliver");
	cola.push("Roman");
	
	cout << "Lista de clientes por orden de llegada:\n";
	showq(cola);
	
	cout << "------------------------------------------\n\n";
	callFromQueue(cola);
	
	system("pause");
	
	return 0;
}
