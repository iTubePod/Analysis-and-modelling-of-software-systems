#include <iostream>

using namespace std;
// Héctor Mauricio González Coello
//A01328258
class Child
{
public:
	int* p;
	Child()
	{
		p = new int;
	}
	//Copy Constructor
	Child(const Child &x)
	{
		p = x.p;
	}
};
int main ()
{
	Child a;
	*(a.p)=6;
	Child b = a;
	cout<<*a.p<<" "<<*b.p<<endl;
	delete &a;
	delete &b;
}
