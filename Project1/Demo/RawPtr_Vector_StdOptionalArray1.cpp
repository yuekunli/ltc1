#include "LibHeaders.h"

namespace RawPtr_Vector_StdOptionalArray1 {
class Building
{
public:
	Building(int cap) : m_capacity(cap)
	{

	}
	void show_capacity()
	{
		std::cout << "Capacity of the build is " << m_capacity << "\n";
	}

	int get_capacity() const
	{
		return (m_capacity);
	}
private:
	int m_capacity;
};

/*-------------------------------------------*/

template <class T>
class Campus
{
public:
	Campus(int bld_count)
	{
		buildings = new std::optional<T>[bld_count];
		current = 0;
	}

	bool add_building(const T& bld)
	{
		buildings[current] = bld;
		current++;
		return (true);
	}

	bool add_building(T&& bld)
	{
		buildings[current] = bld;
		current++;
		return (true);
	}

	int get_current()
	{
		return (current);
	}

	T& get_element(int id)
	{
		return (buildings[id].value());
	}
private:
	std::optional<T>* buildings;
	int current;
};

/*-------------------------------------------*/

template <class T>
class Campus2
{
public:
	Campus2()
	{
	}
private:
	std::vector<T> buildings;
};

/*-------------------------------------------*/

template <class T>
class Campus3
{
public:
	Campus3(int bld_count)
	{
		rawmemptr = operator new[](sizeof(T)* bld_count);
		buildings = static_cast<T*>(rawmemptr);
		current = 0;
	}


	bool add_building(const T& bld)
	{
		buildings[current] = bld;
		current++;
		return (true);
	}

	bool add_building(T&& bld)
	{
		buildings[current] = std::move(bld);
		current++;
		return (true);
	}

	T& get_element(int id)
	{
		return (buildings[id]);
	}

	const T& operator[](int id)
	{
		return (buildings[id]);
	}

	~Campus3()
	{
		operator delete[](rawmemptr);
	}
private:
	void* rawmemptr;
	T* buildings;
	int   current;
};



/*-------------------------------------------------------------------*/

template <typename T>
void show_building_capacity(Campus3<T>& camp)
{
	int i;

	//std::cout << "Test Capacity " << camp[0] << "\n\n";

	for (i = 0; i < 3; i++)
	{
		std::cout << "Building " << i + 1 << " has capacity of " << camp[i].get_capacity() << "\n\n";
	}
}

/*------------------------------------------------------------------*/

void show_building_capacity2(Campus3<Building>& camp)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		std::cout << "Building " << i + 1 << " has capacity of " << camp[i].get_capacity() << "\n\n";
	}
}



/*------------------------------------------------------------------*/

class Region
{
public:
	Region(int n) :
		region_number(n),
		cmp(Campus3<Building>(5))
	{
	}
private:
	Campus3<Building> cmp;
	int region_number;
};

/*-------------------------------------------*/

void Test_RawPtr_Vector_StdOptionalArray1()
{

	Campus<Building> ms_campus(10);

	Building b1 = Building(136);
	ms_campus.add_building(b1);

	Building b2 = Building(379);
	ms_campus.add_building(b2);

	std::cout << "First building capacity is " << ms_campus.get_element(0).get_capacity() << "\n\n";

	std::cout << "Second building capacity is " << ms_campus.get_element(1).get_capacity() << "\n\n";

	std::cout << "Current is " << ms_campus.get_current() << "\n\n";


	Campus3<Building> ms_campus3(10);
	ms_campus3.add_building(b1);
	std::cout << "First building capacity is " << ms_campus3.get_element(0).get_capacity() << "\n\n";

	ms_campus3.add_building(Building(466));
	std::cout << "Second building capacity is " << ms_campus3.get_element(1).get_capacity() << "\n\n";

	ms_campus3.add_building(Building(529));
	std::cout << "Third building capacity is " << ms_campus3[2].get_capacity() << "\n\n";

	show_building_capacity(ms_campus3);

	std::cout << "show_building_capacity2" << "\n\n";
	show_building_capacity2(ms_campus3);



	//ms_campus3[0] = Building(715);  // operator [] of Campus3 returns const ref, we can't change it.

	//Building &B = ms_campus3[0];    // B is not a const ref, so we can't assign a const ref to it
	//B = Building(832);


	show_building_capacity(ms_campus3);

	Region rg(30);
}

}