#pragma once
#include "IP.hpp"
#include <vector>

class Countries
{
private:
	int place;
	std::string cName;
	std::vector<IP> IPs;
public:
	Countries(std::string _name, int _place);
	~Countries();
	void addDomain(IP _newDomain);
	void setPlace(int _place);
	std::string Resolution(std::string domain, std::vector<Countries>* worldDNS);
};

