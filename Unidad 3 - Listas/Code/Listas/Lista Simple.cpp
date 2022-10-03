// C++ program for the above approach
#include <iostream>
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
			cout << "Paciente eliminado" << endl;
		}
};

// Node class to represent
// a node of the linked list.
class Node {
public:
	Paciente* data;
	Node* next;

	// Parameterised Constructor
	Node(Paciente* _data)
	{
		this->data = _data;
		this->next = NULL;
	}
};

// Linked list class to
// implement a linked list.
class Linkedlist {
	Node* head;
	int qPacientes = 0;
public:
	// Default constructor
	Linkedlist() { head = NULL; }

	// Function to insert a
	// node at the end of the
	// linked list.
	void insertNode(Paciente*);

	// Function to print the
	// linked list.
	void printList();

	// Function to modify the
	// node at given position
	void updateNode(int, string, int);

	// Function to delete the
	// node at given position
	void deleteNode(int);
	
	// Function to return the
	// next value to set HC
	int getNewHC();
};

// Function to update the
// node at given position
void Linkedlist::updateNode(int nodeOffset, string _name, int _hc)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;
	int aux = 2;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	// Check if the position to be
	// deleted is less than the length
	// of the linked list.
	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	// Declare temp1
	temp1 = head;
	
	if(ListLen > 1){
		temp2 = temp1->next;
	}

	// Deleting the head.
	if (nodeOffset == 1) {

		// Update head
		head->data->setName(_name);
		head->data->setHistoriaClinica(_hc);
		return;
	}

	// Traverse the list to
	// find the node to be deleted.
	while (aux++ <= nodeOffset) {
		temp1 = temp2;
		temp2 = temp1->next;
		if(aux == nodeOffset){
			temp1->data->setName(_name);
			temp1->data->setHistoriaClinica(_hc);
			break;
		}
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
	
	this->qPacientes--;
}

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	// Check if the position to be
	// deleted is less than the length
	// of the linked list.
	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	// Declare temp1
	temp1 = head;

	// Deleting the head.
	if (nodeOffset == 1) {

		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to
	// find the node to be deleted.
	while (nodeOffset-- > 1) {

		// Update temp2
		temp2 = temp1;

		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
	
	this->qPacientes--;
}

// Function to return the new HC
int Linkedlist::getNewHC(){
	return this->qPacientes + 1;
}

// Function to insert a new node.
void Linkedlist::insertNode(Paciente* data)
{
	// Create the new Node.
	Node* newNode = new Node(data);

	// Assign to head
	if (head == NULL) {
		head = newNode;
		return;
	}

	// Traverse till end of list
	Node* temp = head;
	while (temp->next != NULL) {

		// Update temp
		temp = temp->next;
	}

	// Insert at the last.
	temp->next = newNode;
	
	this->qPacientes++;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
	Node* temp = head;
	
	int position = 1;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout << "Posicion: " << position++ << " || HC: " << temp->data->getHistoriaClinica() << " | " << temp->data->getName() << endl;
		temp = temp->next;
	}
	
	cout << endl;
}

class SysPacientes{
	private:
		Linkedlist* list;
	public:
		SysPacientes(){
			this->list = new Linkedlist();
		}
		
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
			int _hc = this->list->getNewHC();
			
			clean_screen();
			
			try{
				cout << "Sistema de Gestion de Pacientes" << endl;
				cout << "-------------------------------" << endl << endl;
				cout << "Agregar nuevo paciente" << endl;
				cout << "----------------------" << endl << endl;
				cout << "Historia clinica: " << _hc << endl;
				cout << "Nombre: ";
				getline(cin, _name);
				this->list->insertNode(new Paciente(_name, _hc));
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
			this->list->printList();
			system("pause");
			this->run();
		}
		
		void modificarPaciente(){
			int _pos;
			int _hc;
			string _name;
			clean_screen();
			try{
				cout << "Sistema de Gestion de Pacientes" << endl;
				cout << "-------------------------------" << endl << endl;
				cout << "Modificar paciente" << endl;
				cout << "----------------------" << endl << endl;
				this->list->printList();
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
				this->list->updateNode(_pos, _name, _hc);
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
				cout << "Sistema de Gestion de Pacientes" << endl;
				cout << "-------------------------------" << endl << endl;
				cout << "Eliminar paciente" << endl;
				cout << "----------------------" << endl << endl;
				this->list->printList();
				cout << "Ingrese posicion del paciente: ";
				cin >> _pos;
				cin.clear();
				cin.ignore();
				this->list->deleteNode(_pos);
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
			delete [] list;
		}
		
};

// Driver Code
int main()
{
	SysPacientes* sys = new SysPacientes();
	
	sys->run();
	
	return 0;
}

