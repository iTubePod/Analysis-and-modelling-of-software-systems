//
//  main.cpp
//  Observer
//
//  Created by Mauricio G. Coello on 3/8/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//

#include <iostream>
#include "Reforma.hpp"
#include "Televisa.hpp"
#include "NBCNews.hpp"
#include "Personofinterest.hpp"
#include "President.hpp"
#include "Celebrity.hpp"

int main(int argc, const char * argv[]) {
    Observer* Tv = new Televisa;
    Observer* Rf = new Reforma;
    Observer* nb = new NBCNews;
    std::vector<Observer*> x;
    x.push_back(Tv);
    x.push_back(Rf);
    x.push_back(nb);
    Personofinterest pena = President("Peña", x);
    Personofinterest jlo = Celebrity("Jennifer Lopez", x);
    pena.NewinLife("Contrataca a Trump");
    jlo.NewinLife("Se casa!");
}
