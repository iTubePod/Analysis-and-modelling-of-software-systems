#include<iostream>
class Product
{
public:
    virtual void operacion1() = 0;
    virtual void operacion2() = 0;

    template <class T>
    static Product* factoryMethod()
    {
      T* t = new T;
      t->operacion1(); //*
      t->operacion2(); //*
      return t;
    }
};

class Prod1 : public Product
{
public:
    void operacion1(){ std::cout << "OP1 de Prod1" << std::endl; }
    void operacion2(){ std::cout << "OP2 de Prod1" << std::endl; }
};

class Prod2 : public Product
{
public:
    void operacion1(){ std::cout << "OP1 de Prod2" << std::endl; }
    void operacion2(){ std::cout << "OP2 de Prod2" << std::endl; }
};

int main(){
  Product* myProduct1 = Product::factoryMethod<Prod1>();

  Product* myProduct2 = Product::factoryMethod<Prod2>();
}
