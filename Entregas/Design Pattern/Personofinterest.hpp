//
//  Personofinterest.hpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#ifndef Personofinterest_hpp
#define Personofinterest_hpp
#include <string>
#include<vector>
#include"Observer.hpp"

class Personofinterest
{
public:
    std::vector<Observer*> fakemedia;
    std::string name;
    std::string life;
    void NewinLife(std::string _latest);
};

#endif /* Personofinterest_hpp */
