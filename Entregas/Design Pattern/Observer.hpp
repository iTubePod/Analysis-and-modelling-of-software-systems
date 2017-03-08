//
//  Observer.hpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp
#include <iostream>
#include <string>
#include <vector>

class Observer
{
public:
    virtual void News(std::string _name, std::string latest) = 0;
};

#endif /* Observer_hpp */
