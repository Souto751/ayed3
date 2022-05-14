// -- TP U1: 001 - Abstract Factory --
#include <stdio.h>
#include <cstdlib>
#include <vector>

// Coffee Tables
class CoffeeTable{
	public:
		CoffeeTable(){};
		virtual bool hasLegs() = 0;
};

class ArcDecoCoffeeTable : public CoffeeTable{
	public:
		ArcDecoCoffeeTable(){};
		bool hasLegs(){
			return true;
		}
};

class ModernCoffeeTable : public CoffeeTable{
	public:
		ModernCoffeeTable(){};
		bool hasLegs(){
			return true;
		}
};

class VictorianCoffeeTable : public CoffeeTable{
	public:
		VictorianCoffeeTable(){};
		bool hasLegs(){
			return true;
		}
};

// Chairs
class Chair{
	public:
		Chair(){};
		virtual bool hasLegs() = 0;
};

class ArcDecoChair : public Chair{
	public:
		ArcDecoChair(){};
		bool hasLegs(){
			return true;
		}
};

class ModernChair : public Chair{
	public:
		ModernChair(){};
		bool hasLegs(){
			return true;
		}
};

class VictorianChair : public Chair{
	public:
		VictorianChair(){};
		bool hasLegs(){
			return true;
		}
};

// Sofas
class Sofa{
	public:
		Sofa(){};
		virtual bool hasLegs() = 0;
};

class ArcDecoSofa : public Sofa{
	public:
		ArcDecoSofa(){};
		bool hasLegs(){
			return true;
		}
};

class ModernSofa : public Sofa{
	public:
		ModernSofa(){};
		bool hasLegs(){
			return true;
		}
};

class VictorianSofa : public Sofa{
	public:
		VictorianSofa(){};
		bool hasLegs(){
			return true;
		}
};

// Abstract Factories
class AbstractFactory{
	public:
		AbstractFactory(){};
		virtual Chair* createChair() = 0;
		virtual CoffeeTable* createCoffeeTable() = 0;
		virtual Sofa* createSofa() = 0;
};

class ArcDecoFactory : public AbstractFactory{
	public:
		ArcDecoFactory(){};
		Chair* createChair(){
			printf("Added ArcDeco chair.\n");
			return new ArcDecoChair();
		};
		CoffeeTable* createCoffeeTable(){
			printf("Added ArcDeco coffee table.\n");
			return new ArcDecoCoffeeTable();
		};
		Sofa* createSofa(){
			printf("Added ArcDeco sofa.\n");
			return new ArcDecoSofa();
		};
};

class ModernFactory : public AbstractFactory{
	public:
		ModernFactory(){};
		Chair* createChair(){
			printf("Added Modern chair.\n");
			return new ModernChair();
		};
		CoffeeTable* createCoffeeTable(){
			printf("Added Modern coffee table.\n");
			return new ModernCoffeeTable();
		};
		Sofa* createSofa(){
			printf("Added Modern sofa.\n");
			return new ModernSofa();
		};
};

class VictorianFactory : public AbstractFactory{
	public:
		VictorianFactory(){};
		Chair* createChair(){
			printf("Added Victorian chair.\n");
			return new VictorianChair();
		};
		CoffeeTable* createCoffeeTable(){
			printf("Added Victorian coffee table.\n");
			return new VictorianCoffeeTable();
		};
		Sofa* createSofa(){
			printf("Added Victorian sofa.\n");
			return new VictorianSofa();
		};
};

// Clientes
class Cliente{
	private:
		AbstractFactory* factory;
	public:
		Cliente(AbstractFactory* af){
			this->factory = af;
		};
		
		Chair* addChair(){
			printf("Added chair: ");
			return this->factory->createChair();
		}
		
		CoffeeTable* addTable(){
			printf("Added coffee table: ");
			return this->factory->createCoffeeTable();
		}
		
		Sofa* addSofa(){
			printf("Added sofa: ");
			return this->factory->createSofa();
		}
};

int main(){
	std::vector<Chair*> chairs;
	std::vector<Sofa*> sofas;
	std::vector<CoffeeTable*> tables;
	
	Cliente* a = new Cliente(new VictorianFactory());
	
	printf("new client\n");
	
	do{
		sofas.push_back(a->addSofa());
	}while(sofas.size() < 2);
	
	do{
		chairs.push_back(a->addChair());
	}while(chairs.size() < 6);
	
	tables.push_back(a->addTable());
	
	Cliente* b = new Cliente(new ModernFactory);
	
	sofas.clear();
	chairs.clear();
	tables.clear();
	
	printf("\nnew client\n");
	
	do{
		sofas.push_back(b->addSofa());
	}while(sofas.size() < 2);
	
	do{
		chairs.push_back(b->addChair());
	}while(chairs.size() < 6);
	
	do{
		tables.push_back(b->addTable());
	}while(tables.size() < 2);
	
	
	
	Cliente* c = new Cliente(new ArcDecoFactory());
	
	sofas.clear();
	chairs.clear();
	tables.clear();
	
	printf("\nnew client\n");
	
	do{
		sofas.push_back(c->addSofa());
	}while(sofas.size() < 1);
	
	do{
		chairs.push_back(c->addChair());
	}while(chairs.size() < 6);
	
	do{
		tables.push_back(c->addTable());
	}while(tables.size() < 3);
	
	delete a, b, c, sofas, tables, chairs;
	
	printf("\n");
	system("pause");
	return 0;
}
