//
//  Celebrity.hpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#ifndef Celebrity_hpp
#define Celebrity_hpp
#include "Personofinterest.hpp"


class Celebrity : public Personofinterest
{
public:
    Celebrity(std::string _name, std::vector<Observer*> x);
    
};

#endif /* Celebrity_hpp */
