#pragma once
#include "Number.h"
class Double :
	public Number
{
	int countDouble = 0;
public:
	void add();
	void count();
	void accept(Visitor*);
};

