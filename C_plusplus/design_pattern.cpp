/************** Composite Reuse Principle **************/
// more composite, less inherience

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Car
{
public:
	virtual void run() = 0;
};

class BMWCar: public Car
{
public:
	virtual void run()
	{
		cout<<"BMWCar run"<<endl;
	}
};

class DazhongCar: public Car
{
public:
	virtual void run()
	{
		cout<<"DazhongCar run"<<endl;
	}
};

class PersonA: public BMWCar	// bad example
{
public:
	void drive()
	{
		run();
	}
};

class PersonB
{
public:
	PersonB(Car* car)
	{
		pCar = car;
	}

	void drive()
	{
		pCar->run();
	}

	~PersonB()
	{
		if( pCar != nullptr )
		{
			delete pCar;
		}
	}

private:
	Car* pCar;
};

int main()
{
	PersonA* personA = new PersonA;
	personA->drive();

	PersonB* personB = new PerosnB(new BMWCar);
	personB->drive();
	delete personB;

	personB = new PersonB(new DazhongCar);
	personB->drive();
	delete personB;
}








/************** Law of Demeter(blackbox principle)**************/
// design an module try to know nothiing about another module

// #include <iostream>
// #include <memory>
// #include <string>
// #include <list>
// using namespace std;


// class AbstractBuilding 
// {
// public:
// 	typedef shared_ptr<AbstractBuilding> Ptr;
// 	AbstractBuilding(string quality) : m_quality(quality){}
// 	virtual void sale() = 0;
// 	string getQuality()
// 	{
// 		return m_quality;
// 	}

// protected:
// 	string m_quality;
// };

// class BuildingA : public AbstractBuilding
// {
// public:
// 	typedef shared_ptr<BuildingA> Ptr;
// 	BuildingA(string quality) : AbstractBuilding(quality){}
// 	virtual void sale()
// 	{
// 		cout<<"BuildingA sales building quality is : "<<m_quality<<endl;
// 	}
// };

// class BuildingB : public AbstractBuilding
// {
// public:
// 	typedef shared_ptr<BuildingB> Ptr;
// 	BuildingB(string quality) : AbstractBuilding(quality){}
// 	virtual void sale()
// 	{
// 		cout<<"BuildingB sales building quality is : "<<m_quality<<endl;
// 	}
// };

// class BuildingMediator
// {
// public:
// 	typedef shared_ptr<BuildingMediator> Ptr;
// 	BuildingMediator()
// 	{
// 		AbstractBuilding::Ptr building = nullptr;
// 		building = shared_ptr<BuildingA>(new BuildingA("LOW"));
// 		this->addNewBuilding(building);
// 		building = shared_ptr<BuildingB>(new BuildingB("HIGH"));
// 		this->addNewBuilding(building);
// 	}
// 	void addNewBuilding( AbstractBuilding::Ptr building)
// 	{
// 		m_list.push_back(building);
// 	}

// 	AbstractBuilding::Ptr findBuilding(string quality)
// 	{
// 		for (auto it = m_list.begin(); it != m_list.end(); it++)
// 		{
// 			if((*it)->getQuality().compare(quality) == 0)
// 			{
// 				return *it;
// 			}
// 		}
// 	}
// private:
// 	list<AbstractBuilding::Ptr> m_list;
// };

// void test01()
// {
// 	auto mediator = shared_ptr<BuildingMediator>(new BuildingMediator);
// 	auto building = mediator->findBuilding("HIGH");
// 	if (building != nullptr)
// 	{
// 		building->sale();
// 	}
// 	else
// 	{
// 		cout<<"no such building"<<endl;
// 	}
// }

// int main()
// {
// 	test01();
// }







/************** Open-Closed Principle **************/
// when you want to add some code, you don't have to revise previous code

// #include <iostream>
// // #include <memory>
// #include <boost/shared_ptr.hpp>
// using namespace std;

// class AbstractCaculator
// {
// public:
// 	AbstractCaculator(int a, int b): m_a(a), m_b(b){}
// 	virtual int getResult() = 0;

// protected:
// 	int m_a, m_b;
// };

// class Plus: public AbstractCaculator
// {
// public:
// 	Plus(int a, int b):AbstractCaculator(a,b){}
// 	virtual int getResult()
// 	{
// 		return m_a + m_b;
// 	}
// };


// class Minute: public AbstractCaculator
// {
// public:
// 	//typedef boost::shared_ptr<Minute> Ptr;
// 	Minute(int a, int b):AbstractCaculator(a,b){}
// 	virtual int getResult()
// 	{
// 		return m_a - m_b;
// 	}
// };

// void test01()
// {
// 	AbstractCaculator* caculator_plus = nullptr;

// 	caculator_plus = new Plus(30,20);
// 	cout<<caculator_plus->getResult()<<endl;
// 	delete caculator_plus;

// 	auto caculator_minute = boost::shared_ptr<Minute>(new Minute(30,20));
// 	cout<<caculator_minute->getResult()<<endl;
// 	cout<<caculator_minute.use_count()<<endl;

// }

// int main()
// {
// 	test01();
// }