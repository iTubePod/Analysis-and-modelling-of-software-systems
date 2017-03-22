#pragma once
#include <iostream>
#include "Visitor.h"
class Number
{
public:
	virtual void add() = 0;
	virtual void count() = 0;
	virtual void accept(Visitor*) = 0;
};

