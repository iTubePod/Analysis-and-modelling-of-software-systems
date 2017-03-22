#pragma once
#include "Visitor.h"
class CountVisitor :
	public Visitor
{
public:
	void visit(Integer*);
	void visit(Double*);
};

