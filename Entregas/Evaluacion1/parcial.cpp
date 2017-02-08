#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>  


using namespace std;

class Videojuego
{
private:
	string a;
	string b;
	string c;
	string d;
public:
	Videojuego ()
	{
		a="primer atributo";
		b="segundo atributo";
		c="tercer atributo";
		d="cuarto atributo";
	}
	template <class VJ>
	Videojuego* clonar()
	{
        return new VJ(dynamic_cast <VJ&>(*this));
	}
	virtual void Concepcion()=0;
	virtual void Diseno ()=0;
	virtual void Planificacion ()=0;
	virtual void Produccion ()=0;
	virtual void Prueba ()=0;
};
class Estrategia : public Videojuego
{
private:
	string name;
public:
	Estrategia(string _name)
    {
    	name = _name;
    }
	virtual void Concepcion()
	{
		cout<<"Concepcion del nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Diseno ()
	{
		cout<<"Disenando el nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Planificacion ()
	{
		cout<<"Planificando el nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Produccion ()
	{
		cout<<"Produciendo el nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Prueba ()
	{
		cout<<"Probando el nuevo juego de Estrategia "<<name<<endl;
	}
};
class Aventura : public Videojuego
{
private:
	string name;
public:
	Aventura (string _name)
    {
    	name = _name;
    }
	virtual void Concepcion()
	{
		cout<<"Concepcion del nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Diseno ()
	{
		cout<<"Disenando el nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Planificacion ()
	{
		cout<<"Planificando el nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Produccion ()
	{
		cout<<"Produciendo el nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Prueba ()
	{
		cout<<"Probando el nuevo juego de Aventura "<<name<<endl;
	}
};
class Aprendizaje : public Videojuego
{
private:
	string name;
public:
	Aprendizaje(string _name)
    {
    	name = _name;
    }
	virtual void Concepcion()
	{
		cout<<"Concepcion del nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Diseno ()
	{
		cout<<"Disenando el nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Planificacion ()
	{
		cout<<"Planificando el nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Produccion ()
	{
		cout<<"Produciendo el nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Prueba ()
	{
		cout<<"Probando el nuevo juego de Aprendizaje "<<name<<endl;
	}
};
template <class VJ> 
VJ* factoryMethod(string _name)
{
	VJ* tmp = new VJ(_name);
    tmp->VJ::Concepcion();
    tmp->VJ::Diseno();
    tmp->VJ::Planificacion();
    tmp->VJ::Produccion();
    tmp->VJ::Prueba();
    return tmp;
}
template <class item>
class Item
{
private:
	item * itm;
	int tag;
	float price;
public:
	Item (string _name, float _price, int _tag)
	{
		cout<<"Creating new Inventory item with tag: "<<_tag<<" and price: "<<_price<<endl;
		itm = factoryMethod<item>(_name);
		price=_price;
		tag=_tag;
	}
	item* getItem()
	{
		return itm;
	}
	float getPrice()
	{
		return price();
	}
	void setPrice(float _price)
	{
		price=_price;
	}
	int getTag()
	{
		return tag;
	}
};
class Inventario
{
private:
	vector<Item<Videojuego*>* > inv;
	Inventario()
	{
		Instance = this;
	}
	static Inventario* Instance;
public:
	static Inventario* crear()
	{
		if(Instance==NULL)
		{
			Inventario();
			return Instance;
		}
		return Instance;
	}
	int generateTag()
	{
		srand (time(NULL));
		int tag = rand() % 10000;
		for (int i = 0; i < inv.size(); i++)
		{
			if(inv.at(i)->getTag()==tag)
				tag=rand() % 10000;
		}
		return tag;
	}
	void AddItem(string type, string _name, float _price)
	{
		int _tag = generateTag();
		if(type=="Estrategia")
			inv.push_back(new Item<Estrategia*>(_name, _price, _tag));
		else if(type=="Aventura")
			inv.push_back(new Item<Aventura*>(_name, _price, _tag));
		else if (type=="Aprendizaje")
			inv.push_back(new Item<Aprendizaje*>(_name, _price, _tag));
	}

};

int main()
{
	string _name = "HOLA";
	float _price = 10.06;
	int _tag = 465456;
    Item<Estrategia>* e = new Item<Estrategia>(_name, _price, _tag);

    return 1;
}