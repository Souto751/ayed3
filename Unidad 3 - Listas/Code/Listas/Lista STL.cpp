// CPP program to show the implementation of List
#include <iostream>
#include <iterator>
#include <list>
#include <stdio.h>
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

class Paciente{
	private:
		string name;
		int historia_clinica;
	public:
		Paciente(string _name, int _hc){
			this->name = _name;
			this->historia_clinica = _hc;
		}
		
		void setName(string _name){
			this->name = _name;
		}
		
		void setHistoriaClinica(int _hc){
			this->historia_clinica = _hc;
		}
		
		string getName(){
			return this->name;
		}
		
		int getHistoriaClinica(){
			return this->historia_clinica;
		}
		
		~Paciente(){
		}
};

// function for printing the elements in a list
void showlist(list<Paciente> g)
{
	list<Paciente>::iterator it;
	int i = 1;
	for (it = g.begin(); it != g.end(); ++it){
		cout << "Posicion: " << i++ << " || HC: " << it->getHistoriaClinica() << " | " << it->getName() << endl;
	}
}

class SysPacientes{
	private:
		list<Paciente> lista;
	public:
		SysPacientes(){}
		
		int displayMenu(){
			clean_screen();
			int opc;
			try{
				cout << "Sistema de Gestion de Pacientes" << endl;
				cout << "-------------------------------" << endl << endl;
				cout << "1- Agregar nuevo paciente" << endl;
				cout << "2- Modificar datos de paciente" << endl;
				cout << "3- Listar pacientes" << endl;
				cout << "4- Eliminar paciente" << endl;
				cout << "99- Salir" << endl;
				cout << "Opcion: ";
				cin >> opc;
				cin.clear();
				cin.ignore();
			}catch(int num){
				this->displayMenu();
			}
			return opc;
		}
		
		void crearPaciente(){
			string _name;
			int _hc = this->lista.size() + 1;
			
			clean_screen();
			
			try{
				cout << "Sistema de Gestion de Pacientes" << endl;
				cout << "-------------------------------" << endl << endl;
				cout << "Agregar nuevo paciente" << endl;
				cout << "----------------------" << endl << endl;
				cout << "Historia clinica: " << _hc << endl;
				cout << "Nombre: ";
				getline(cin, _name);
				this->lista.push_back(Paciente(_name, _hc));
				system("pause");
				this->run();
			}catch(int num){
				this->crearPaciente();
			}
		}
		
		void listarPacientes(){
			clean_screen();
			cout << "Sistema de Gestion de Pacientes" << endl;
			cout << "-------------------------------" << endl << endl;
			cout << "Listar pacientes" << endl;
			cout << "----------------------" << endl << endl;
			showlist(this->lista);
			system("pause");
			this->run();
		}
		
		void modificarPaciente(){
			int _pos;
			int _hc;
			string _name;
			clean_screen();
			try{
				list<Paciente>::iterator it = lista.begin();
				cout << "Sistema de Gestion de Pacientes" << endl;
				cout << "-------------------------------" << endl << endl;
				cout << "Modificar paciente" << endl;
				cout << "----------------------" << endl << endl;
				showlist(this->lista);
				cout << "Ingrese posicion del paciente: ";
				cin >> _pos;
				cin.clear();
				cin.ignore();
				cout << "Ingrese la historia clinica del paciente: ";
				cin >> _hc;
				cin.clear();
				cin.ignore();
				cout << "Ingrese el nombre del paciente: ";
				getline(cin, _name);
				advance(it, _pos -1);
				
				for(int i = 0; i != lista.size(); i++){
					if(i == _pos){
						it->setName(_name);
						it->setHistoriaClinica(_hc);
						break;	
					}
				}
				
				system("pause");
				this->run();
			}catch(int num){
				this->modificarPaciente();
			}
		}
		
		void eliminarPaciente(){
			int _pos;
			clean_screen();
			try{
				list<Paciente>::iterator it = lista.begin();
				cout << "Sistema de Gestion de Pacientes" << endl;
				cout << "-------------------------------" << endl << endl;
				cout << "Eliminar paciente" << endl;
				cout << "----------------------" << endl << endl;
				showlist(this->lista);
				cout << "Ingrese posicion del paciente: ";
				cin >> _pos;
				cin.clear();
				cin.ignore();
				advance(it, _pos -1);
				this->lista.erase(it);
				system("pause");
				this->run();
			}catch(int num){
				this->eliminarPaciente();
			}
		}
		
		void run(){
			int opc = this->displayMenu();
			switch(opc){
				case 1:
					this->crearPaciente();
					break;
				case 2:
					this->modificarPaciente();
					break;
				case 3:
					this->listarPacientes();
					break;
				case 4:
					this->eliminarPaciente();
					break;
				case 99:
					break;
				default:
					this->run();
					break;
			}
		}
		
		~SysPacientes(){
		}
		
};

// Driver Code
int main()
{
	SysPacientes* sys = new SysPacientes();
	
	sys->run();

	return 0;
}
