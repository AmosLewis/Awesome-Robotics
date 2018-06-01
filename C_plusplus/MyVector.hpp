#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
using namespace std;

template<class T>
class MyVector
{
	friend ostream& operator<< (ostream& out, MyVector<T> vec)
	{
		for( int i = 0; i < vec.mSize; i++)
		{
			out<< vec.pAddr[i] <<endl;
		}
		return out;
	}

public:
	// constructor
	MyVector(int capacity)
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		this->pAddr = new T[capacity];
	}
	// copy constructor
	MyVector(const MyVector& vector)
	{
		this->mCapacity = vector.mCapacity;
		this->mSize = vector.mSize;
		// apply memory, copy data
		this->pAddr = new T[mSize];
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddr[i] = vector.pAddr[i];
		}
	}
	// destructor
	~MyVector()
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}
	}
	// add item
	void PushBack(const T& value)
	{
		if (this->mSize == this->mCapacity)
		{
			return;
		}
		this->pAddr[this->mSize] = value;
		this->mSize++;
	}
	// void PushBack(T&& value)
	// {
	// 	if (this->mSize == this->mCapacity)
	// 	{
	// 		return;
	// 	}
	// 	this->pAddr[this->mSize] = value;
	// 	this->mSize++;
	// }

	// operator overload
	T& operator[](int index)
	{
		return this->pAddr[index];
	}
	MyVector& operator=(const MyVector& vector)
	{
		this->mCapacity = vector.mCapacity;
		this->mSize = vector.mSize;
		// apply memory, copy project
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}
		this->pAddr = new T[mSize];
		for (int i=0; i < this->mSize; i++)
		{
			this->pAddr[i] = vector.pAddr[i];
		}
		return *this;
	}
	


private:
	T* pAddr;
	int mCapacity;
	int mSize;
};

#endif














