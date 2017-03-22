#include "Double.h"
#include "Integer.h"
#include "Number.h"
#include "Visitor.h"
#include "AddVisitor.h"
#include "CountVisitor.h"

int main()
{
	int tmp;
	Number* n[] = { new Integer, new Double };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			n[j]->add();
		}
	}
	n[1]->count();
	n[0]->count();
	std::cout << "NOW WITH VISITORS" << std::endl;
	Number* nm[] = { new Integer, new Double };
	AddVisitor a;
	CountVisitor c;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			nm[j]->accept(&a);
		}
	}
	nm[1]->accept(&c);
	nm[0]->accept(&c);
	std::cin >> tmp;
}