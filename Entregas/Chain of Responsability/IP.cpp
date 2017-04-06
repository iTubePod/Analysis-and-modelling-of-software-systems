#include "IP.hpp"

IP::IP(std::string _add, std::string _ip)
{
	address = _add;
	ip = _ip;
}

std::string IP::GetIP(std::string _add)
{
	{
		if (_add == address)
			return ip;
		else
			return "NF";
	}
}

IP::~IP()
{
}
