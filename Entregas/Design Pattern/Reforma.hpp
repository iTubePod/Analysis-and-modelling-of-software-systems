//
//  Reforma.hpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#ifndef Reforma_hpp
#define Reforma_hpp
#include "Observer.hpp"

class Reforma : public Observer
{
public:
    std::string name = "Reforma";
    void News(std::string _name, std::string latest);
    
};

#endif /* Reforma_hpp */
