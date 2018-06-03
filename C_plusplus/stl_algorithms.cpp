#include <algorithm>
#include <cstring>
#include <iostream>
#include <functional>
#include <numeric>
#include <ctime>
using namespace std;


// Algorithm: <algorithm> <functional> <numeric>


// find, return loaction(pointer)

// void test01()
// {
// 	int arr[] = {5,2,8,9,1,3};
// 	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
// 	auto it = find(v.begin(), v.end(), 1);
// 	if ( it == v.end())
// 	{
// 		cout<<"not find"<<endl;
// 	}
// 	else
// 	{
// 		cout<<*it<<endl;
// 	}
// }

// class Student
// {
// public:
// 	Student(int age, int salary):_age(age), _salary(salary){}
// 	int _age;
// 	int _salary;

// 	bool operator==(const Student& stu)
// 	{
// 		if (this->_age == stu._age && this->_age == stu._age)
// 		{
// 			return true;
// 		}
// 		else
// 		{
// 			return false;
// 		}
// 	}
// };
// void test02()
// {
// 	Student s1(1,2), s2(3,4), s3(5,6), s4(7,8);
// 	std::vector<Student> vs;
// 	vs.push_back(s1);
// 	vs.push_back(s2);
// 	vs.push_back(s3);
// 	vs.push_back(s4);

// 	auto it = find(vs.begin(), vs.end(), s2);
// 	if ( it == vs.end())
// 	{
// 		cout<<" s2 not find"<<endl;
// 	}
// 	else
// 	{
// 		cout<<"s2"<<endl;
// 	}
// }

// int main()
// {
// 	// test01();
// 	test02();
// }


// // transform: carry from one vector to another vector
// // result vector must be allocate memory in advance

// // vector1+100 ==> vector2
// void print1(int v)
// {
// 	cout<<v<<" ";
// }

// struct myplus01
// {
// 	int operator()(int v1)
// 	{
// 		return v1 + 100;
// 	}
// };

// void test01()
// {
// 	srand(time(NULL));
// 	vector<int> v, dest;
// 	for (int i = 0; i < 10; i++ )
// 	{
// 		v.push_back(rand() % 100);
// 	}

// 	for_each(v.begin(), v.end(), print1);
// 	cout<<endl;

// 	dest.resize(v.size());

// 	transform(v.begin(), v.end(), dest.begin(), myplus01());
// 	for_each(dest.begin(), dest.end(), print1);
// 	cout<<endl;
// }

// int main()
// {
// 	test01();
// }





// // for_each return value is an functor
// struct print4
// {
// 	print4():_count(0){}
// 	void operator()(int v1)
// 	{
// 		_count++;
// 		cout<<v1<<" ";
// 	}

// 	int _count;
// };

// void test()
// {
// 	std::vector<int> v;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		v.push_back(rand() % 100);
// 	}
// 	print4 temp1;
// 	print4 temp2 = for_each(v.begin(), v.end(), temp1);
// 	cout<<endl<<"temp1: "<< temp1._count<<endl;
// 	cout<<"temp2: "<< temp2._count<<endl;

// }
// int main()
// {
// 	test();
// }



// // functor/ function object adaptor
// class print
// {
// public:
// 	void operator()(int v)
// 	{
// 		cout<<v<<" ";
// 	}
// };
// void test01()
// {
// 	plus<int> myplus;
// 	int ret = myplus(10,20);
// 	cout<<"ret: "<<ret<<endl;
// 	cout<<plus<int>()(30,40)<<endl;

// 	vector<int> v1, v2, v3;
// 	for( int i = 0; i < 10; i++)
// 	{
// 		v1.push_back(i);
// 		v2.push_back(i + 1);
// 	}
// 	v3.resize(v1.size());
// 	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
// 	for_each(v1.begin(), v1.end(), print());
// 	cout<<endl;

// 	for_each(v2.begin(), v2.end(), print());
// 	cout<<endl;

// 	for_each(v3.begin(), v3.end(), print());
// 	cout<<endl;
// }

// // now I want all vector value+100 when for_reach
// // we can use bind1st bind2dn
// // bind1st: bind arguments as functor first arguments
// // bind2d: bind arguments as functor second arguments
// // bind1st bing2d turn binary_function into unary_function
// // binary_function<TYPE_arg1, TYPE_arg2, TYPE_return> 
// // unary_function<TYPE_arg1, TYPE_return> 
// struct myprint : public binary_function<int, int, void> 	// binary function must be used if you want to use bind2nd
// {
// 	void operator()(int v1, int v2) const
// 	{
// 		cout<< v1+v2<<" ";
// 	}
// };

// void test02()
// {
// 	vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	v.push_back(4);

// 	for_each(v.begin(), v.end(), bind1st(myprint(), 100));
// 	cout<<endl;
// }

// // not1, not2 reverser unary/binary function object
// void test03()
// {
// 	vector<int> v;
// 	v.push_back(2);
// 	v.push_back(1);
// 	v.push_back(5);
// 	v.push_back(4);

// 	auto it = find_if(v.begin(), v.end(), not1(bind2nd(less_equal<int>(),2)));
// 	cout<<*it<<endl;

// 	sort(v.begin(), v.end(), not2(greater<int>()));
// 	for_each(v.begin(), v.end(), print());
// 	cout<<endl;
// }

// // how to bind arguments for normal function?
// // use ptr_fun: turn normal function to functor
// void myprint_nomal(int v1, int v2)
// {
// 	cout<<v1 + v2<<" ";
// }

// void test04()
// {
// 	vector<int> v;
// 	v.push_back(2);
// 	v.push_back(1);
// 	v.push_back(5);
// 	v.push_back(4);

// 	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myprint_nomal),100));// cannot use () for mypring_normal
// 	cout<<endl;
// }

// class Student
// {
// public:
// 	Student(string name, int age):_name(name), _age(age){}

// 	void print(){ cout<<"name"<<_name<<"age"<<_age<<endl; }

// 	void print2(int a){ cout<<"name"<<_name<<"age"<<_age<<"a"<<a<<endl;}

// 	int _age;
// 	string _name;

// };

// // mem_fun mem_fun_ref
// // turn class member functiopn into functor
// void test05()
// {
// 	// mem_fun
// 	std::vector<Student*> v;
// 	Student* s1 = new Student("Amos10",10);
// 	Student* s2 = new Student("Amos20",20);
// 	Student* s3 = new Student("Amos30",30);
// 	Student* s4 = new Student("Amos40",40);
// 	v.push_back(s1);
// 	v.push_back(s2);
// 	v.push_back(s3);
// 	v.push_back(s4);
// 	for_each(v.begin(), v.end(), mem_fun(&Student::print));
// 	cout<<"----------------------"<<endl;

// 		// mem_fun_ref
// 	std::vector<Student> v2;
// 	Student s5 = Student("Amos10",10);
// 	Student s6 = Student("Amos20",20);
// 	Student s7 = Student("Amos30",30);
// 	Student s8 = Student("Amos40",40);
// 	v2.push_back(s5);
// 	v2.push_back(s6);
// 	v2.push_back(s7);
// 	v2.push_back(s8);
// 	for_each(v2.begin(), v2.end(), mem_fun_ref(&Student::print));
// 	cout<<"----------------------"<<endl;
// }

// int main()
// {
// 	//test01();
// 	//test02();
// 	// test03();
// 	// test04();
// 	test05();
// }







// predicate: functor with bool return value type / funciton will bool return value type
// ubary predicate, binary predicate
// unary predicate
// class print	
// {
// public:
// 	// void operator()(const int& val) 
// 	bool operator()(const int& val) 
// 	{
// 		cout<<val<<" ";
// 		count++;
// 	}
// 	int count;
// };

// class mygreater
// {
// public:
// 	bool operator()(const int& v)
// 	{
// 		return v > 2;
// 	}
// };

// // binary functor
// class myplus
// {
// public:
// 	int operator()(int v1, int v2)
// 	{
// 		return v1 + v2;
// 	}
// };

// int main()
// {
// 	vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	v.push_back(4);

// 	// test myprint
// 	// print myprint;
// 	// myprint = for_each(v.begin(), v.end(), myprint);
// 	for_each(v.begin(), v.end(), print());
// 	cout<<endl;
// 	// cout<<"number the functor been called: "<< myprint.count<<endl;

// 	// test mygreator
// 	auto it = find_if(v.begin(), v.end(), mygreater());
// 	cout<<*it<<endl;

// 	// test myplus
// 	vector<int> v1, v2, v3;
// 	v1.push_back(3);
// 	v1.push_back(4);
// 	v1.push_back(5);

// 	v2.push_back(7);
// 	v2.push_back(8);
// 	v2.push_back(9);

// 	v3.resize(v1.size() + v2.size());
// 	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), myplus());
// 	for_each(v3.begin(), v3.end(), print());
// 	cout<<endl;

//  // inner functional
//  // arithmatic functor, relationship calculate functor, logical functor
// 	// test inner functor
// 	plus<int> myplusIN;
// 	cout<<myplusIN(4,5)<<endl;
// 	cout<<plus<int>()(4,5)<<endl;
// }


// functor : class with overload operator(), enable class act like function
// usually used in algorithm
// can be used to calculate the state that the functor been called

// class print	
// {
// public:
// 	void operator()(const int& val) 
// 	{
// 		cout<<val<<" ";
// 		count++;
// 	}
// 	int count;
// };

// int main()
// {
// 	vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	v.push_back(4);

// 	print myprint;
// 	myprint = for_each(v.begin(), v.end(), myprint);
// 	cout<<endl;
// 	cout<<"number the functor been called: "<< myprint.count<<endl;
// }

