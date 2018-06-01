#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "MyVector.hpp"
#include <cstring>
#include <iomanip>
#include <fstream>



// read write binary file
class Teacher
{
public:
	Teacher(int age, string id)
	{
		this->_age = age;
		this->_id = id;
	}
public:
	int _age;
	string _id;
};

int main()
{
	char fileName[255] = "teacher.dat";
	ofstream fout(fileName, ios::binary);
	if (!fout)
	{
		cout<<"unable to open"<<fileName<<endl;
		return(1);
	}

	Teacher t1(31,"31");
	Teacher t2(32,"32");
	fout.write((char*)&t1, sizeof (Teacher));
	fout.write((char*)&t2, sizeof (Teacher));
	fout.close();
	cout<<"success"<<endl;

	ifstream fin(fileName, ios::binary);
	if(!fin)
	{
		cout<<"fail"<<endl;
		return(1);
	}
	Teacher tmp(100,"100");

	fin.read((char*)&tmp, sizeof(Teacher));
	cout<<tmp._age<<endl;
}


// ifstream oftream
// int main()
// {


	// ofstream myfile("f1.bat", ios::app);
	// myfile<<"ios::app"<<endl<<"haha";
	// myfile.close();


	// ifstream myfile;
	// myfile.open("f1.bat", ios::in);
	// char ch;
	// string content;
	// while(myfile.get(ch))
	// {
	// 	content += ch;
	// 	cout.put(ch);
	// }
	// myfile.close();
	// cout<<content;
// }



// open file
// int main()
// {
	// char fileName[80];
	// char buffer[255];

	// cout<<"please input file: ";
	// cin>>fileName;

	// ofstream fout(fileName, ios::app);
	// fout<<"1\n";
	// fout<<"2\n";
	// cin.ignore(1);
	// cin.getline(buffer,255);
	// fout<<buffer<<"\n";
	// fout.close();

	// char p[80] = "f1.bat";
	// ifstream fin(p);
	// cout<<"here is the content of the file\n";
	// char ch;
	// while(fin.get(ch)) cout<<ch;
	// cout<<"end\n";
	// fin.close();


	// ofstream myfile("f1.bat", ios::app);
	// myfile<<"ios::app"<<endl<<"haha";
	// myfile.close();


// }




// format cout
// int main()
// {
// 	// int a;
// 	// cout<<"input a: ";
// 	// cin>>a;
// 	// cout<<"dec"<<dec <<a<<endl;
// 	// cout<<"hex"<<hex <<a<<endl;
// 	// cout<<"oct"<<setbase(8) <<a<<endl;

// 	// string pt = "China";
// 	// cout<<setw(10)<<pt<<endl;
// 	// cout<<setfill('*')<<setw(10)<<pt<<endl;

// 	// double pi = 22.0/7.0;
// 	// cout<<setiosflags(ios::scientific)<<setprecision(8);
// 	// cout<<"pi= "<< pi<<endl;
// 	// cout<<"pi= "<<setprecision(4)<<pi<<endl;
// 	// cout<<"pi= "<<setiosflags(ios::fixed)<<pi<<endl;

// 	int a = 21;
// 	cout.setf(ios::showbase);
// 	cout<<"dec: "<<a<<endl;
// 	cout.unsetf(ios::dec);
// 	cout.setf(ios::hex);
// 	cout<<"hex: "<<a<<endl;
// 	cout.unsetf(ios::hex);
// 	cout.setf(ios::oct);
// 	cout<<"oct: "<<a<<endl;
// 	cout.unsetf(ios::oct);

// 	string pt = "China";
// 	cout.width(10);
// 	cout<<pt<<endl;
// 	cout.width(10);
// 	cout.fill('*');
// 	cout<<pt<<endl;

// 	double pi = 22.0/7.0;
// 	cout.width(12);
// 	cout.fill('*');
// 	cout.setf(ios::showpos);
// 	cout.setf(ios::internal);
// 	cout.precision(6);
// 	cout<<pi<<endl;

// }



// std ostream
// int main()
// {
// 	cout<<"hello world!"<< endl;
// 	cout.put('h').put('e').put('1')<<endl;

// 	char* str = (char*)"hello world";
// 	cout.write(str, strlen(str))<<endl;
// 	cout.write(str, strlen(str)-2)<<endl;
// }


// std istream
// int main()
// {
	// test 1
	// char ch;
	// while ((ch = cin.get() != EOF))
	// {
	// 	cout<<ch<<endl<<word<<endl;
	// }

	// test 2
	// #if 0
	// char c1, c2, c3;
	// cin.get(c1);
	// cin.get(c2);
	// cin.get(c3);
	// cout<<"out tut : "<<endl;
	// cout<<"c1 "<< c1 << endl;
	// cout<<"c2 "<< c2 << endl;
	// cout<<"c3 "<< c3 << endl;
	// // cin.get();

	// cin.get(c1).get(c2).get(c3);
	// cout<<"out put 2: "<<endl;
	// cout<<" c1 " << c1 << endl;
	// cout<<" c2 " << c2 << endl;
	// cout<<" c3 " << c3 << endl;
	// #endif
	// #if 0
	// char buf[1024] = {0};
	// cin >> buf;	// not stop until " "
	// cout << buf << endl;
	// #endif

	// // test 03
	// #if 0
	// char buf1[256] = {0};
	// char buf2[256] = {0};
	// cin.getline(buf1, 256);
	// cout<<"buf1: "<< buf1 <<endl;
	// #endif

	// test 04
	// char buf1[256] = {0};
	// char buf2[256] = {0};
	// cin>>buf1;
	// cout<<"buf1: "<<buf1<<endl;
	// cin.ignore(1);	// ignore 1 char '\n'
	// char ch = cin.peek();
	// cout<<ch<<endl;
	// cin.getline(buf2, 256);
	// cout<<"buf2 : "<<buf2<<endl;

	// cout<<"input a string or a number: "<<endl;
	// char ch = cin.get();
	// if(ch >= '0' && ch <= '9')
	// {
	// 	int number;
	// 	cin.putback(ch);
	// 	cin>>number;
	// 	cout<<"number: "<<number<<endl;
	// }
	// else
	// {
	// 	char buf[1024] = {0};
	// 	cin.putback(ch);
	// 	cin.getline(buf,1024);
	// 	cout<<"char: "<<buf<<endl;
	// }
// }




// // self define exception
// class MyOutRangeException : public exception
// {
// public:
// 	MyOutRangeException(const char* error)
// 	{
// 		int len = strlen(error) + 1;
// 		this->pError = new char[len];
// 		strcpy(this->pError, error);
// 	}
// 	virtual const char* what() const  	// const makes it a compiler error for this class function to change a member variable of the class. 
// 	{
// 		return this->pError;
// 	}
// 	virtual ~MyOutRangeException()
// 	{
// 		if ( this->pError !=NULL)
// 		{
// 		delete[] this->pError;
// 		}
// 	}

// public:
// 	char* pError;
// };

// class Person
// {
// public:
// 	Person(int age, string name)
// 	{
// 		if (age < 0 || age > 100)
// 		{
// 			throw MyOutRangeException("age out of range")
// 		}
// 		mName = name;
// 		mAge = age;
// 	}
// public:
// 	string mName;
// 	int mAge;
// };
// int main()
// {
// 	try{
// 		Person p(101, "aaa");
// 	}
// 	catch(exception& e)
// 	{
// 		cout << e.what()<<endl;
// 	}
// }

// standard exception library
// #include <stdexcept>

// class Teacher
// {
// public:
// 	Teacher(int age)
// 	{
// 		if (age > 100)
// 		{
// 			throw out_of_range("Too old");
// 		}
// 		this->_age = age;
// 	}

// private:
// 	int _age;
// };
// int main()
// {
// 	try
// 	{
// 		Teacher t1(102);
// 	}
// 	catch (out_of_range e)
// 	{
// 		cout<<e.what()<<endl;
// 	}
// }



// Exception
// int divide(int x, int y)
// {
//      if (y == 0)
//      {    throw x;  }
//      return x/y;
// }

// int main(void)
// {
//      try
//      {
//           cout<<"8/2= "<<divide(8,2)<<endl;
//           cout<<"10/0= "<<divide(10,0)<<endl;
//      }
//      catch( int e )
//      {
//           cout<<"e "<<"is divided by error"<<endl;
//      }
//      catch(...)
//      {
//           cout<<"unknow exception"<<endl;
//      }
// }



// const_cast
// class A { int data; };
// int main()
// {
// 	const A a ={100}; 

// 	// A a1 = const_cast<A>(a);
// 	// a1.data = 200;

// 	A *a2 = const_cast<A*>(&a);
// 	a2->data = 300;
// 	cout<<a2->data<<endl;

// 	A &a3 = const_cast<A&>(a);
// 	a3.data = 400;

// 	cout<<a2->data<<endl<<a3.data<<endl;

// }




// function template & function overload

// int Max(int a, int b)
// {
// 	cout<< "function overload"<<endl;
// 	return a > b ? a : b;
// }

// template<typename T>
// T Max(T a, T b)
// {
// 	cout<< "function template"<<endl;
// 	return a > b ? a : b;
// }

// template<typename T>
// T Max(T a, T b, T c)
// {
// 	cout<< "function template overload"<<endl;
// 	return Max(Max(a,b),c);
// }

// int main()
// {
// 	int a = 1;
// 	int b = 2;
// 	cout<<"Max(a,b): "<<Max(a,b)<<endl;
// 	cout<<"Max<>(a,b): "<<Max<>(a,b)<<endl;

// 	cout<<"Max(3.1,4.1): "<<Max(3.1,4.1)<<endl;
// 	cout<<"Max<>(3.1,4.1): "<<Max<>(3.1,4.1)<<endl;
// 	cout<<"Max<>(3.1,4.1): "<<Max<int>(3.1,4.1)<<endl;
// 	cout<<"Max(3.1,4.1,5.1): "<<Max(3.1,4.1,5.1)<<endl;

// 	cout<<"Max('a',4.1): "<<Max('a',4.1)<<endl;
// 	//cout<<"Max('a',4.1): "<<Max<>('a',4.1)<<endl; // no matching function for call to ‘Max(char, double)

// 	// function overload
// 	// Max(a,b): 2
// 	// function template
// 	// Max<>(a,b): 2
// 	// function template
// 	// Max(3.1,4.1): 4.1
// 	// function template overload
// 	// function template
// 	// function template
// 	// Max(3.1,4.1,5.1): 5.1
// }

// function template

// template<typename T>
// T myswap(T &a, T &b)
// {
// 	T t = a;
// 	a = b;
// 	b = t;
// 	return b;
// }
// int main()
// {
// 	int a = 1;
// 	int b = 2;
// 	cout<<myswap( a , b)<<endl;		
// 	cout<<myswap<>( a , b)<<endl;
// 	cout<<myswap<int>( a , b)<<endl;

// }




// parents/child step

// class Parent
// {
// public:
// 	Parent(int a=0)
// 	{
// 		this->a = a;
// 		print();
// 	}
// 	virtual void print()
// 	{
// 		cout<<"I am parents vitual print"<<endl;
// 	}
// private:
// 	int a;
// };

// class Child : public Parent
// {
// public:
// 	Child(int b=0):Parent(0)
// 	{
// 		this->b = b;
// 		print();
// 	}
// 	virtual void print()
// 	{
// 		cout<<"I am Child vitual print"<<endl;
// 	}
// private:
// 	int b;
// };

// int main()
// {
// 	Parent *pP = NULL;
// 	Child *pC = NULL;

// 	Child array[] = {Child(1), Child(2), Child(3)};
// 	pP = array;
// 	pC = array;
// 	cout<<"before print"<<endl<<endl;
	
// 	pP->print();
// 	pC->print();
// 	cout<<"1 print"<<endl<<endl;

// 	pP++;
// 	pC++;

// 	pP->print();
// 	pC->print();
// }


// base construct call virtual memberfunction
// class Parent
// {
// public:
// 	Parent(int a=0)
// 	{
// 		this->a = a;
// 		print();
// 	}
// 	virtual void print()
// 	{
// 		cout<<"I am parents vitual print"<<endl;
// 	}
// private:
// 	int a;
// };

// class Child : public Parent
// {
// public:
// 	Child(int a=0, int b=0):Parent(a)
// 	{
// 		this->b = b;
// 		print();
// 	}
// 	virtual void print()
// 	{
// 		cout<<"I am Child vitual print"<<endl;
// 	}
// private:
// 	int b;
// };

// void HowToPlay(Parent *base){ base->print(); }

// int main()
// {
// 	Child c1;
// 	cout<<"hh"<<endl;
// 	HowToPlay(&c1);
// 	//I am parents vitual print
// 	// I am Child vitual print
// 	// hh
// 	// I am Child vitual print

// }

// Verify vptr
// class Parent1
// {
// public:
// 	Parent1( int a=0 )
// 	{
// 		this->a = a;
// 	}
// 	void print()
// 	{
// 		cout<<"I am Parent1"<<endl;
// 	}
// private:
// 	int a;
// };

// class Parent2
// {
// public:
// 	Parent2( int a=0 )
// 	{
// 		this->a = a;
// 	}
// 	virtual void print()
// 	{
// 		cout<<"I am Parent2"<<endl;
// 	}
// private:
// 	int a;
// };

// int main()
// {
// 	cout<<"p1: "<<sizeof(Parent1)<<endl;// # 4
// 	cout<<"p2: "<<sizeof(Parent2)<<endl;// # 16

// }



// const reference
// int main(void)
// {
// 	double x = 3.14;
// 	const int &b=x;
// 	cout<<b<<endl;
// }


//2
// int& getA2()	// without staic warning: reference to local variable ‘a’ returned 
// {
// 	static int a;
// 	a = 10;
// 	return a;
// } 
// int main(void)
// {
// 	int a1 = getA2();
// 	int& a2 = getA2();
// 	cout<<"a1 = "<<a1<<endl; // 10
// 	cout<<"a2 = "<<a2<<endl; // static 10 memory legal;without static 32543 memory illegal
// 	getA2() = 20;
// 	cout<<"a20 = "<<a2<<endl;
// }