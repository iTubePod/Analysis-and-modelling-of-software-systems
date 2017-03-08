//
//  NBCNews.hpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#ifndef NBCNews_hpp
#define NBCNews_hpp
#include "Observer.hpp"

class NBCNews : public Observer
{
public:
    std::string name = "NBCNews";
    void News(std::string _name, std::string latest);
    
};
#endif /* NBCNews_hpp */
