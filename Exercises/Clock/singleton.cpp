#include <iostream>
#include <ctime>

class Singleton {
private:
    Singleton(){
        Instance = this;
    }
	static Singleton* Instance;
public:
    void doStuff() {std::cout<< Instance<<std::endl;}
    static Singleton* getInstance()
        {
            if (Instance != 0)
            {
                return Instance;
            }
             
            else
            {
                Singleton();
                return Instance;
            }
        }
        void gettime(){
            time_t t = time(0);
            tm* localtm = localtime(&t);
            std::cout<<asctime(localtm)<<std::endl;
        }
};
Singleton* Singleton::Instance = 0;
int main(){
    Singleton* s = Singleton::getInstance();
    s->gettime();
    Singleton* p = Singleton::getInstance();
    p->gettime();
}