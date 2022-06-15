#include <cstdlib>
#include <stdio.h>
#include <vector>

class Alojamiento{
	public:
		Alojamiento(){};
		virtual void brindarPresupuesto() = 0;
		~Alojamiento(){};
};

class Hotel : public Alojamiento{
	public:
		void brindarPresupuesto(){
			printf("El presupuesto del hotel es de: AR$2500\n");
		};
};

class Apartamento : public Alojamiento{
	public:
		void brindarPresupuesto(){
			printf("El presupuesto del apartamento es de: AR$2000\n");
		};
};

class Hostel : public Alojamiento{
	public:
		void brindarPresupuesto(){
			printf("El presupuesto del hostel es de: AR$1500\n");
		};
};

class Composite : public Alojamiento{
	private:
		std::vector<Alojamiento*> alojamientos;
	public:
		Composite(){};
		void add(Alojamiento* aloja){
			this->alojamientos.push_back(aloja);	
		};
		void remove(Alojamiento* aloja){
			for(int i = 0; i < this->alojamientos.size(); i++){
				if(this->alojamientos[i] == aloja){
					this->alojamientos.erase(this->alojamientos.begin() + i);
				}
			}
		};
		void brindarPresupuesto(){
			for(int i = 0; i < this->alojamientos.size(); i++){
				this->alojamientos[i]->brindarPresupuesto();
			}
		};
		~Composite(){};
};


int main(){
	
	Composite* compo = new Composite();
	
	Alojamiento* hotel = new Hotel();
	Alojamiento* hostel = new Hostel();
	Alojamiento* apartamento = new Apartamento();
	
	compo->add(hotel);
	compo->add(hostel);
	compo->add(apartamento);
	
	compo->remove(hostel);
	
	compo->brindarPresupuesto();
	
	delete compo, hotel, hostel, apartamento;
	system("pause");
	return 0;
}
