#pragma once
#include "Number.h"
class Integer :
	public Number
{
	int countInts = 0;
public:
	void add();
	void count();
	void accept(Visitor*);
};

