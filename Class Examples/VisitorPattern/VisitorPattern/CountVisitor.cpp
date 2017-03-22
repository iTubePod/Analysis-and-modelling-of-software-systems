#include "CountVisitor.h"

void CountVisitor::visit(Integer* i)
{
	i->count();
}

void CountVisitor::visit(Double* d)
{
	d->count();
}
