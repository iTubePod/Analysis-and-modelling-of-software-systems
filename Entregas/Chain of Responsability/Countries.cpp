#include "Countries.hpp"



Countries::Countries(std::string _name, int _place)
{
	cName = _name;
	place = _place;
}


Countries::~Countries()
{
}

void Countries::addDomain(IP _newDomain)
{
	IPs.push_back(_newDomain);
}
std::string Countries::Resolution(std::string domain, std::vector<Countries*>* worldDNS)
{
	for (int i = 0; i < IPs.size(); i++)
	{
		if (IPs.at(i).GetIP(domain) != "NF")
		{
			if (place == IPs.size())
				return "ADDRESS NOT FOUND";
			else
				return worldDNS->at(place + 1)->Resolution(domain, worldDNS);
		}
		else
			return "THE IP OF" + domain + " IS " + IPs.at(i).GetIP(domain) + " IN " + cName;
	}
}
void Countries::setPlace(int _place)
{
	place = _place;
}
