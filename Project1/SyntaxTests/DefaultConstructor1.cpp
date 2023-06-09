#include "LibHeaders.h"

namespace DefaultConstructor1{

class Building
{
public:
	// A default constructor is a constructor that either has no parameters, or if it has parameters, all the parameters have default values.
	// So by definition, this is a default constructor.
	Building()
	{
		data1 = 10;
		data2 = 30;
	}
	void show_data()
	{
		std::cout << "data1 " << data1 << "\n" << "data2 " << data2 << "\n";
	}
	~Building()
	{
		std::cout << "Building destructor\n";
	}
private:
	int data1;
	int data2;
};


class Campus
{
public:
	Campus()
	{
		//B1 = Building();
		// Even if we don't call Building's constructor here, the compiler is able to construct a Building object by its default constructor
	}
	void show_building_data()
	{
		B1.show_data();
	}
	~Campus()
	{
		std::cout << "Campus destructor\n";
	}
private:
	Building B1;
};



void Test_DefaultConstructor1()
{
	Campus C1 = Campus();
	C1.show_building_data();
}

}