#include "Integer.h"



void Integer::add()
{
	countInts++;
}

void Integer::count()
{
	std::cout << countInts << std::endl;
}

void Integer::accept(Visitor* v)
{
	v->visit(this);
}
