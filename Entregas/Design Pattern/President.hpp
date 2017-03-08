//
//  President.hpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#ifndef President_hpp
#define President_hpp
#include "Personofinterest.hpp"


class President : public Personofinterest
{
public:
    President(std::string _name, std::vector<Observer*> x);
    
};

#endif /* President_hpp */
