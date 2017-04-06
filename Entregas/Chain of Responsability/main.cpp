#include "Countries.hpp"
#include "DNS.hpp"
#include "IP.hpp"
#include <vector>

DNS* DNS::instance = 0;

int main()
{
	int x;
	DNS* worldInternet = DNS::getInstance();
	IP ausSites1 = IP("www.a.com", "0.0.0.1");
	IP ausSites2 = IP("www.b.com", "0.0.0.2");
	IP USSites1 = IP("www.c.com", "0.0.0.3");
	IP USSites2 = IP("www.d.com", "0.0.0.4");
	IP LATAMSites1 = IP("www.e.com", "0.0.0.5");
	IP LATAMSites2 = IP("www.f.com", "0.0.0.6");
	IP RUSSites1 = IP("www.g.com", "0.0.0.7");
	IP RUSSites2 = IP("www.h.com", "0.0.0.8");
	IP EURSites1 = IP("www.i.com", "0.0.0.9");
	IP EURSites2 = IP("www.j.com", "0.0.1.1");
	worldInternet->addDNS("AUSTRALIA");
	worldInternet->addDNS("LATAM");
	worldInternet->addDNS("UNITED STATES");
	worldInternet->addDNS("RUSSIA");
	worldInternet->addDNS("EUROPE");
	worldInternet->getDNS(0)->addDomain(ausSites1);
	worldInternet->getDNS(0)->addDomain(ausSites2);
	worldInternet->getDNS(1)->addDomain(LATAMSites1);
	worldInternet->getDNS(1)->addDomain(LATAMSites2);
	worldInternet->getDNS(2)->addDomain(USSites1);
	worldInternet->getDNS(2)->addDomain(USSites2);
	worldInternet->getDNS(3)->addDomain(RUSSites1);
	worldInternet->getDNS(3)->addDomain(RUSSites2);
	worldInternet->getDNS(4)->addDomain(EURSites1);
	worldInternet->getDNS(4)->addDomain(EURSites2);
	worldInternet->getDNS(0)->Resolution("www.j.com", worldInternet->getAll());
	std::cin >> x;
}