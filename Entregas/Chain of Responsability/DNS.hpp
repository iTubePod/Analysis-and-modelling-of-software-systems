#include <vector>
#include "IP.hpp"
#include "Countries.hpp"
#include<iostream>

#pragma once
class DNS
{
private:
	std::vector<Countries> worldDNS;
protected:
	DNS()
	{
		instance = this;
	}
	static DNS* instance;
public:
	static DNS* getInstance();
	void addDNS(std::string _newDNS);
	Countries getDNS(int pos);
	std::vector<Countries>* getAll();
};

