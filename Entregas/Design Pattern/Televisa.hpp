//
//  Televisa.hpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#ifndef Televisa_hpp
#define Televisa_hpp
#include "Observer.hpp"

class Televisa : public Observer
{
public:
    std::string name = "Televisa";
    void News(std::string _name, std::string latest);
};

#endif /* Televisa_hpp */
