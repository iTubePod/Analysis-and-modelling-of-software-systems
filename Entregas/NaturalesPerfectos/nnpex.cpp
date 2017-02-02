#include <iostream>
class ArrayNNP;
class Proxy
{
private:
	ArrayNNP& arr;
	int idx;
public: 
	Proxy(ArrayNNP& arr, int idx) : arr(arr), idx(idx){}
	Proxy &operator = (int value);
	int isnnp(int n);
	friend ostream& operator<<(ostream&, Proxy&); //acceso a atributos publicos y privados
};
class ArrayNNP
{
private:
	int *arr;
	int size;
public:
	friend class Proxy; // Proxy puede acceder a ArrayNNP, no al revés
	ArrayNNP(int _size)
	{
		arr= new int[_size+1];
		size=_size;
	}
	Proxy operator[](int index)
	{
		if(index<0 || index>=size)
		{
			std::cout<<"Whoa, you can't go there, index "<<index<<std::endl;
			return Proxy(*this, size);
		}
		return Proxy(*this, index);

	}
};
int Proxy::isnnp(int n)
{
    int x = 0;
    for (int i = n-1; i > 0; i--)
  	{
       	if(n%i==0)
       	{
           	x += i;
        }
    }
    if(x==n)
      	return n;
    else
      	return -1;
}
Proxy& Proxy::operator = (int value)
{
	int tmp = isnnp(value);
	if(tmp!=-1)
		arr.arr[idx] = tmp;
	else
		std::cout<<"No es un Natural Perfecto"<<std::endl;
	return *this;
}
ostream& Proxy::operator<<(ostream& os, Proxy& p)
{
    std::os << p.arr.arr[p.inx];
    return std::os
}
int main()
{
	ArrayNNP a(5);
    a[0]=1;
    a[5]= 2;
    a[-1] = -1;
}