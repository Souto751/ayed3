// Agustin Souto
// 3. Una empresa necesita implementar un Historial de llamadas a sus cliente, la aplicación deberá ir cargando
// los números telefónicos en un historial y el usuario podrá ir recorriendo el histórico de llamadas (similar al
// botón Back del navegador).
// Implementar una app que realice esta función.

#include <iostream>
#include <stdio.h>
#include <string>
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

class Cqueue{
	private:
		int Rear, Front;
		string Queue[50];
		int Max;
		int Size;
		int Current;
	public:
		Cqueue(){
			this->Current = 0;
			this->Size = 0;
			this->Max = 50;
			this->Rear = this->Front = - 1;
		}
		
		int Empty(){
			if(this->Front == 0){
				return 1;
			}else{
				return 0;
			}
		}
		
		int Full(){
			if(this->Rear == this->Max){
				return 1;
			}else{
				return 0;
			}
		}
		
		void Add(string element){
			if(!this->Full()){
				this->Rear = (this->Rear + 1) % this->Max;
				this->Queue[this->Rear] = element;
				this->Size++;
			}
		}
		
		string Delete(){
			if(!this->Empty()){
				this->Front = (this->Front + 1) % this->Max;
				this->Size--;
			}
			return this->Queue[this->Front];
		}
		
		void restartCurrent(){
			this->Current = 0;
		}
		
		void display(){
			clean_screen();
			string opc;
			cout << "Llamada " << this->Current + 1 << " de " << this->Size << endl;
			cout << "Numero: " << this->Queue[this->Current] << "\n";
			cout << "\nPara ver la llamada anterior marque 1.\nPara ver la llamada siguiente marque 2.\nPulse cualquier otra tecla para salir.\nOpcion: ";
			getline(cin, opc);
			if(opc == "1"){
				if(this->Current == 0){
					this->Current = this->Rear;
				}else{
					this->Current--;
				}
				this->display();
			}else if(opc == "2"){
				if(this->Current == this->Size - 1){
					this->Current = 0;
				}else{
					this->Current++;
				}
				this->display();
			}
		}
		
		string getFront(){
			int Temp;
			if(!this->Empty()){
				Temp = (this->Front + 1) % this->Max;
			}
			return this->Queue[Temp];
		}
};

int menu(){
	clean_screen();
	int opc;
	
	try{
		cout << "1. Llamar\n";
		cout << "2. Ver historial\n";
		cout << "99. Salir\n";
		cout << "Opcion: ";
		cin >> opc;
	}catch(int o){
		cout << "Opcion incorrecta" << endl;
		system("pause");
		opc = menu();
	}
	
	return opc;
}

int main(){
	int opc;
	string num;
	Cqueue cola;
	
	do{
		opc = menu();
		switch(opc){
			case 1:
				cin.clear();
				cin.ignore();
				clean_screen();
				cout << "Ingrese el numero a llamar: ";
				getline(cin, num);
				cola.Add(num);
				cout << "Llamando al numero " << num << " ...\n";
				system("pause");
				break;
			case 2:
				clean_screen();
				cola.restartCurrent();
				cin.clear();
				cin.ignore();
				cout << "Lista de llamadas\n";
				cout << "-----------------\n";
				cola.display();
				system("pause");
				break;
			default:
				break;
		}
	}while(opc != 99);
	
	return 0;
}
