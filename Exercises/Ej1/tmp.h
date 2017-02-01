#include <iostream>
#include <ctime>

class tmp {
private:
	char* tp;

public:
    tmp();
    char* gettime();
};
    tmp::tmp(){
        tp=gettime();
    }
    char* tmp::gettime(){
        time_t t = time(0);
        tm* localtm = localtime(&t);
        return asctime(localtm);
    }