#include <iostream>
#include <vector>

struct A{
  int x, y;

  A() = default;

  /*A(int x=1) : x(x) //Default constructor, defualt initialization
  {
      cout << "Default constructor" << endl;
  }
  */

  explicit A(int x, int y) : x(x), y(y) //Params constructor
  {
      std::cout << "Params Constructor" <<   std::endl;
  }

  A(const A&)
  {
        std::cout << "Copy Constructor" <<   std::endl;
  }

  A (A&&)
  {
        std::cout << "Move Constructor "<<  std::endl;
  }
};
A llamaCopyCons(A a){
  A temp (a);
  return temp;
}
int main(){
  std::vector<A> myVect;
  myVect.push_back(A(1,2));
  A b;
  //A a = move(b);

}
