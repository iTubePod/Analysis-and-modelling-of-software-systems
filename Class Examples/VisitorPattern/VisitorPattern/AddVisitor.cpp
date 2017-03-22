#include "AddVisitor.h"

void AddVisitor::visit(Integer * i)
{
	i->add();
}

void AddVisitor::visit(Double * d)
{
	d->add();
}
