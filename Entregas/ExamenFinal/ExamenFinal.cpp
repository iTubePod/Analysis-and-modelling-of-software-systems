/*
	Héctor Mauricio González Coello
	A01328258
	Final Exam AyMSS
*/

#include <iostream>
#include <string>

using namespace std;

class Asteroids;
class Planets;
class Spacecrafts {
protected:
	string content;
public:
	string getContent()
	{
		return content;
	}
	void CollisionedTo(Asteroids* x);
	void CollisionedWith(Asteroids* x);
	void CollisionedTo(Planets* x);
	void CollisionedWith(Planets* x);
};
template <class T>
T* factoryMethod()
{
	return T::Create();
}

class PES : public Spacecrafts
{
	friend class Spacecrafts;
private:
	PES()
	{
		Instance = this;
		content = "Planet Exploration Ship";
	}
	static PES* Instance;
public:
	static PES* Create()
	{
		cout << "Building Planet exploration ship..." << endl;
		if (Instance == NULL)
		{
			PES* p = new PES();
			return Instance;
		}
		return Instance;
	}
};
class ColonizationShips : public Spacecrafts
{
	friend class Spacecrafts;
private:
	ColonizationShips()
	{
		Instance = this;
		content = "Colonization Ship";
	}
	static ColonizationShips* Instance;
public:
	static ColonizationShips* Create()
	{
		cout << "Building Colonization Ship..." << endl;
		if (Instance == NULL)
		{
			ColonizationShips();
			ColonizationShips* p = new ColonizationShips();
			return Instance;
		}
		return Instance;
	}
};
class POS : public Spacecrafts
{
	friend class Spacecrafts;
private:
	POS()
	{
		Instance = this;
		content = "Planet Observation Ship";
	}
	static POS* Instance;
public:
	static POS* Create()
	{
		cout << "Building Planet Observation Ship..." << endl;
		if (Instance == NULL)
		{
			POS* p = new POS();
			return Instance;
		}
		return Instance;
	}
};
class Planets {
protected:
	string content;
public:
	string getContent()
	{
		return content;
	}
	void CollisionedTo(Asteroids* x);
	void CollisionedWith(Asteroids* x);
	void CollisionedTo(Spacecrafts* x);
	void CollisionedWith(Spacecrafts* x);
};
class DP : public Planets
{
	friend class Planets;
private:
	DP()
	{
		Instance = this;
		content = "Desert Planet";
	}
	static DP* Instance;
public:
	static DP* Create()
	{
		cout << "Initializing creation of Desert Planet..." << endl;
		if (Instance == NULL)
		{
			DP* p = new DP();
			return Instance;
		}
		return Instance;
	}
};
class EAP : public Planets
{
	friend class Planets;
private:
	EAP()
	{
		Instance = this;
		content = "Earth Analog Planet";
	}
	static EAP* Instance;
public:
	static EAP* Create()
	{
		cout << "Initializing creation of Earth Analog Planet..." << endl;
		if (Instance == NULL)
		{
			EAP* p = new EAP();
			return Instance;
		}
		return Instance;
	}
};
class Asteroids {
protected:
	string content;
public:
	string getContent()
	{
		return content;
	}
	void CollisionedTo(Planets* x);
	void CollisionedWith(Planets* x);
	void CollisionedTo(Spacecrafts* x);
	void CollisionedWith(Spacecrafts* x);
};
class SM : public Asteroids
{
	friend class Asteroids;
private:
	SM()
	{
		Instance = this;
		content = "Stony Meteorite";
	}
	static SM* Instance;
public:
	static SM* Create()
	{
		cout << "Initializing creation of Stony Meteorite..." << endl;
		if (Instance == NULL)
		{
			SM* p = new SM();
			return Instance;
		}
		return Instance;
	}
};
class IM : public Asteroids
{
	friend class Asteroids;
private:
	IM()
	{
		Instance = this;
		content = "Iron Meteorite";
	}
	static IM* Instance;
public:
	static IM* Create()
	{
		cout << "Initializing creation of Iron Meteorite..." << endl;
		if (Instance == NULL)
		{
			IM* p = new IM();
			return Instance;
		}
		return Instance;
	}
};
void Spacecrafts::CollisionedTo(Asteroids* x)
{
	cout << content << " collisioned whith a " << x->getContent() << endl;
}
void Spacecrafts::CollisionedWith(Asteroids* x)
{
	x->CollisionedTo(this);
}
void Spacecrafts::CollisionedTo(Planets* x)
{
	cout << content << " collisioned whith a " << x->getContent() << endl;
}
void Spacecrafts::CollisionedWith(Planets* x)
{
	x->CollisionedTo(this);
}
void Asteroids::CollisionedTo(Spacecrafts* x)
{
	cout << content << " collisioned whith a " << x->getContent() << endl;
}
void Asteroids::CollisionedWith(Spacecrafts* x)
{
	x->CollisionedTo(this);
}
void Asteroids::CollisionedTo(Planets* x)
{
	cout << content << " collisioned whith a " << x->getContent() << endl;
}
void Asteroids::CollisionedWith(Planets* x)
{
	x->CollisionedTo(this);
}
void Planets::CollisionedTo(Asteroids* x)
{
	cout << content << " collisioned whith a " << x->getContent() << endl;
}
void Planets::CollisionedWith(Asteroids* x)
{
	x->CollisionedTo(this);
}
void Planets::CollisionedTo(Spacecrafts* x)
{
	cout << content << " collisioned whith a " << x->getContent() << endl;
}
void Planets::CollisionedWith(Spacecrafts* x)
{
	x->CollisionedTo(this);
}

ColonizationShips* ColonizationShips::Instance = NULL;
PES* PES::Instance = NULL;
POS* POS::Instance = NULL;
DP* DP::Instance = NULL;
EAP* EAP::Instance = NULL;
SM* SM::Instance = NULL;
IM* IM::Instance = NULL;

int main()
{
	ColonizationShips* x = factoryMethod<ColonizationShips>();
	POS* y = factoryMethod<POS>();
	PES* z = factoryMethod<PES>();
	DP* a = factoryMethod<DP>();
	EAP* b = factoryMethod<EAP>();
	SM* c = factoryMethod<SM>();
	IM* d = factoryMethod<IM>();
	c->CollisionedWith(b);
	d->CollisionedTo(a);
	y->CollisionedTo(a);
	z->CollisionedWith(b);
	a->CollisionedTo(c);
	b->CollisionedWith(d);
	y->CollisionedTo(c);
	z->CollisionedWith(d);
}

