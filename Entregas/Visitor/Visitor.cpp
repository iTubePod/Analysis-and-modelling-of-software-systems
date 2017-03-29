//
//  Visitor.cpp
//
//  Created by Mauricio G. Coello on 22/3/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//
// This implements the visitor design pattern with singleton inherited to visitor subclasses
//
#include<iostream>

using namespace std;
class Visitor;
class Number
{
protected:
    string quienSoy;
public:
    string getQuienSoy(){
        return quienSoy;
    }
    virtual void accept(Visitor*) = 0;
};

class Integer : public Number
{
public:
    Integer()
    {
        quienSoy = "Integer";
    }
    static int countInts;
    void accept(Visitor*);
};
int Integer::countInts = 0;
class Double : public Number
{
public:
    Double()
    {
        quienSoy = "Double";
    }
    static int countDouble;
    void accept(Visitor*);
};
int Double::countDouble = 0;

class Visitor
{
public:
    template <class T>
    static T* getInstance()
    {
        if(T::instance == NULL)
        {
            T();
            T* w = new T();
        }
        return T::instance;
    }
    virtual void visit(Integer*) = 0;
    virtual void visit(Double*) = 0;
};

class PresentVisitor : public Visitor
{
protected:
    friend class Visitor;
    PresentVisitor()
    {
        instance = this;
    }
    static PresentVisitor* instance;
public:
    static PresentVisitor* getInstance()
    {
        if(instance == 0)
        {
            return new PresentVisitor;
        }
        else
            return instance;
    }
    
    void visit(Integer* i)
    {
        cout << i->getQuienSoy();
    }
    void visit(Double* d)
    {
        cout << d->getQuienSoy();
    }
};
PresentVisitor* PresentVisitor::instance = 0;

class CountVisitor : public Visitor
{
protected:
    friend class Visitor;
    CountVisitor()
    {
        instance = this;
    }
    static CountVisitor* instance;
public:
    void visit(Integer* i)
    {
        cout << Integer::countInts;
    }
    void visit(Double* i)
    {
        cout << Double::countDouble;
    }
};
CountVisitor* CountVisitor::instance = 0;

class AddVisitor : public Visitor
{
protected:
    friend class Visitor;
    AddVisitor()
    {
        instance = this;
    }
    static AddVisitor* instance;
public:
    void visit(Integer*)
    {
        Integer::countInts++;
    }
    void visit(Double*)
    {
        Double::countDouble++;
    }
};
AddVisitor* AddVisitor::instance = 0;
void Double::accept(Visitor* v)
{
    v->visit(this);
}
void Integer::accept(Visitor* v)
{
    v->visit(this);
}

int main()
{
    AddVisitor* a = Visitor::getInstance<AddVisitor>();
    CountVisitor* c = Visitor::getInstance<CountVisitor>();
    PresentVisitor* p = Visitor::getInstance<PresentVisitor>();
    
    Number* n[] ={new Integer, new Double};
    
    for(int i=0; i< 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            n[j]->accept(a);
        }
    }
    
    n[0]->accept(p);
    n[0]->accept(c);
    cout << endl;
    n[1]->accept(p);
    n[1]->accept(c);
}
