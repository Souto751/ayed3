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
#include <iomanip>
using namespace std;

#ifdef _WIN32
  #include<windows.h>
#endif  

void clean_screen()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

class Turno{
	private:
		int tiempo_restante;
		string cliente;
		int nro_box;
		
	public:
		Turno(){
			this->tiempo_restante = 0;
			this->cliente = "";
			this->nro_box = 0;
		}
		
		Turno(int _tiempo, string _cliente, int _box){
			this->tiempo_restante = _tiempo;
			this->cliente = _cliente;
			this->nro_box = _box;
		}
		
		void setTiempoRestante(int _tiempo){
			this->tiempo_restante = _tiempo;
		}
		
		int getTiempoRestante(){
			return this->tiempo_restante;
		}
		
		string getCliente(){
			return this->cliente;
		}
		
		int getNroBox(){
			return this->nro_box;
		}
};

void showq(queue<Turno> gq, int tiempo_corrido)
{
	clean_screen();
	cout << "Box nro - Proximo cliente - Tiempo restante\n";
	cout << "-------------------------------------------\n"; 
    queue<Turno> g = gq;
    queue<Turno> comprobarListado;
    while (!g.empty()) {
    	Turno t = g.front();
        if(t.getTiempoRestante() - tiempo_corrido >= 0){
        	cout << setw(7) << t.getNroBox() << " | " << setw(15) << t.getCliente() << " | " << setw(15) << t.getTiempoRestante() - tiempo_corrido << endl << endl;
        	comprobarListado.push(t);
		}
		g.pop();
    }
    
    Sleep(1000);
    if(comprobarListado.size() > 0){
	    showq(gq, tiempo_corrido + 1);
	}
}

int main(){
	queue<Turno> cola;
	
	cola.push(Turno(150, "Pepe", 1));
	cola.push(Turno(150, "Eloy", 2));
	cola.push(Turno(175, "Oliver", 1));
	cola.push(Turno(180, "Roman", 3));
	cola.push(Turno(200, "Pipa", 3));
	cola.push(Turno(205, "Jordan", 2));
	
	cout << "Lista de clientes por orden de llegada:\n";
	showq(cola, 0);
	
	system("pause");
	
	return 0;
}
