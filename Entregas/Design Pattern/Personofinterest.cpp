//
//  Personofinterest.cpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#include "Personofinterest.hpp"
void Personofinterest::NewinLife(std::string _latest)
{
    life=_latest;
    for (int i=0; i<fakemedia.size(); i++) {
        fakemedia.at(i)->News(name, life);
    }
}
