#include "Integer.h"
#include "Double.h"
class Visitor {
public:
	virtual void visit(Integer*) = 0;
	virtual void visit(Double*) = 0;
};

