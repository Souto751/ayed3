#include <stdio.h>
#include <cstdlib>

class Motor {
	public:
		Motor(){};
		virtual void encender() = 0;
		virtual void acelerar() = 0;
		virtual void apagar() = 0;		
};

class MotorComun : public Motor{
	public:
		MotorComun(){};
		void encender(){
			printf("El motor comun ha encendido\n");
		}
		void acelerar(){
			printf("Se ha acelerado el motor comun\n");
		}
		void apagar(){
			printf("El motor comun ha sido apagado\n");
		}
};

class MotorEconomico : public Motor{
	public:
		MotorEconomico(){};
		void encender(){
			printf("El motor economico ha encendido\n");
		}
		void acelerar(){
			printf("Se ha acelerado el motor economico\n");
		}
		void apagar(){
			printf("El motor economico ha sido apagado\n");
		}
};

class MotorElectrico{
	public:
		MotorElectricoAdapter(){};
		void conectar(){
			printf("El motor electrico se ha conectado\n");
		}
		void activar(){
			printf("El motor electrico ha sido activado\n");
		}
		void moverMasRapido(){
			printf("El motor electrico se mueve mas rapido\n");
		}
		void detener(){
			printf("El motor electrico se ha detenido\n");
		}
		void desconectar(){
			printf("El motor electrico se ha detenido\n");
		}
};

class MotorElectricoAdapter : public Motor{
	private:
		MotorElectrico motorElectrico;
	public:
		MotorElectricoAdapter(){};
		void encender(){
			this->motorElectrico.conectar();
			this->motorElectrico.activar();
		}
		void acelerar(){
			this->motorElectrico.moverMasRapido();
		}
		void apagar(){
			this->motorElectrico.detener();
			this->motorElectrico.desconectar();
		}
};

int main(){
	Motor* myMotor = new MotorComun();
	printf("Primer motor -> Motor Comun\n");
	myMotor->encender();
	myMotor->acelerar();
	myMotor->apagar();
	
	delete myMotor;
	
	myMotor = new MotorEconomico();
	printf("\nSegundo motor -> Motor Economico\n");
	myMotor->encender();
	myMotor->acelerar();
	myMotor->apagar();
	
	delete myMotor;
	
	myMotor = new MotorElectricoAdapter();
	printf("\nTercer motor -> Motor Electrico\n");
	myMotor->encender();
	myMotor->acelerar();
	myMotor->apagar();
	
	printf("\n");
	
	system("pause");
	return 0;
}
