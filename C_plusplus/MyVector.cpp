#include <iostream>
using namespace std;
#include "MyVector.hpp"

// MyVector with basic datatype
void test01()
{
	MyVector<int> vec(20);
	for (int i = 0; i < 20; i++)
	{
		vec.PushBack(i + 1);
	}
	cout<< vec <<endl;
}

// MyVector with complex datatype 
class Person
{
	friend ostream& operator<<(ostream& out, Person& person)
	{
		out<<"Age:"<< person.mAge<<" ID: "<<person.mId;
		return out;
	}
	
public:
	// constructor
	Person()
	{
		this->mAge = 0;
		this->mId = 0;
	}
	Person(int age, int id)
	{
		this->mAge = age;
		this->mId = id;
	}
private:
	int mAge;
	int mId;
};

void test02()
{
	Person p1(10,11), p2(20,21), p3(30,31);
	MyVector<Person> vec(20);
	vec.PushBack(p1);
	vec.PushBack(p2);
	vec.PushBack(p3);
	cout<< vec <<endl;
}

int main()
{
	test01();
	test02();
	return 0;
}
























