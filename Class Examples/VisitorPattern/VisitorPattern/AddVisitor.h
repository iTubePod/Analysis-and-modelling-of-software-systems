#pragma once
#include "Visitor.h"
class AddVisitor :
	public Visitor
{
public:
	void visit(Integer* i);
	void visit(Double* d);
};

