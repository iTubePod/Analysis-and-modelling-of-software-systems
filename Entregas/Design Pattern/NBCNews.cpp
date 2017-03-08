//
//  NBCNews.cpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#include "NBCNews.hpp"
void NBCNews::News(std::string _name, std::string latest)
{
    std::cout<<name + " REPORTA: " + _name + " " + latest<<std::endl;
}
