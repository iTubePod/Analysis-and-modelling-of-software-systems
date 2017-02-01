/*
  Tarea 1 AyMSS
  Hector Mauricio Gonzalez Coello
  A01328258
*/
#include <iostream>
#include <string>
using namespace std;

class Personaje
{
public:
    virtual void correr() = 0;
    virtual Personaje* clonar() = 0;
};
template <class SubClase>
class ClonPersonaje : public Personaje
{
public:
    virtual Personaje* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};
//factoryMethod, manda llamar al Singleton de cada Villano
template <class SubClase>
SubClase* factoryMethod()
{
  return SubClase::crear();
}

class Principe : public ClonPersonaje<Principe>
{
private:
  Principe()
  {
    Instance=this;
  }
  static Principe* Instance;
public:
    //Singleton de Principe
    static Principe* crear()
    {
      if(Instance==NULL)
      {
        Principe();
        return Instance;
      }
      return Instance;
    }
    void seleccionarArma();
    void atacar();
    void correr()
    {
        cout << "El principe corre rápido" << endl;
    }
};

class Princesa : public ClonPersonaje<Princesa>
{
private:
    Princesa()
    {
      Instance=this;
    }
    static Princesa* Instance;
public:
    //Singleton de Princesa
    static Princesa* crear()
    {
      if(Instance==NULL)
      {
        Princesa();
        return Instance;
      }
      return Instance;
    }
    void gritar();
    void correr()
    {
        cout << "La princesa corre medio lento" << endl;
    }
};

class Villano : public ClonPersonaje<Villano>
{
private:
  Villano()
  {
    Instance=this;
  }
  static Villano* Instance;
public:
    //Singleton de Villano
    static Villano* crear()
    {
      if (Instance==NULL)
      {
        Villano();
        return Instance;
      }
      return Instance;
    }
    void atacar();
    void atraparPricnesa();
    void correr()
    {
        cout << "El villano no necesita correr" << endl;
    }
};

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
private:
  VillanoVolador()
  {
    Instance=this;
  }
  static VillanoVolador* Instance;
public:
    //Singleton de VillanoVolador
    static VillanoVolador* crear()
    {
      if(Instance==NULL)
      {
        VillanoVolador();
        return Instance;
      }
      return Instance;
    }
    void correr()
    {
        cout << "También puede volar" << endl;
    }
};
Principe* Principe::Instance = NULL;
Princesa* Princesa::Instance = NULL;
VillanoVolador* VillanoVolador::Instance = NULL;
Villano* Villano::Instance = NULL;
int main()
{
    Principe* v = factoryMethod<Principe>();
    v->correr();

    return 1;
}
