#include "Double.h"



void Double::add()
{
	countDouble++;
}

void Double::count()
{
	std::cout << countDouble << std::endl;
}

void Double::accept(Visitor* v)
{
	v->visit(this);
}
