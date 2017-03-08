//
//  President.cpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#include "President.hpp"
President::President(std::string _name, std::vector<Observer*> x)
{
    fakemedia = x;
    name = _name + ", el presidente";
    
}
