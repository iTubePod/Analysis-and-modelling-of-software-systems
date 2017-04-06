#include "DNS.hpp"

DNS* DNS::getInstance()
{
	if (instance == NULL)
	{
		DNS* x = new DNS();
	}
	return instance;
}

void DNS::addDNS(std::string _newDNS)
{
	Countries tmp = Countries(_newDNS, worldDNS.size());
	worldDNS.push_back(&tmp);
}

Countries * DNS::getDNS(int pos)
{
	return worldDNS.at(pos);
}

std::vector<Countries*>* DNS::getAll()
{
	return &worldDNS;
}
