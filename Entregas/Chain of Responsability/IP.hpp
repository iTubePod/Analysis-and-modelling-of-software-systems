#include <string>
#pragma once
class IP
{
protected:
	std::string address;
	std::string ip;
public:
	IP(std::string _add, std::string _ip);
	std::string GetIP(std::string _add);
	~IP();
};

