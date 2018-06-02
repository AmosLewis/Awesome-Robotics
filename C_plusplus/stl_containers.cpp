#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// stl container deep copy

class myclass
{
public:
	myclass(char* data)
	{
		int len = strlen(data) + 1;
		this->data = new char[len];
		strcpy(this->data, data);
	}

	~myclass()
	{
		if(NULL != this->data)
		{
			delete[] this->data;
			this->data = NULL;
		}
	}

	// copy constructor for deep copy
	myclass(const myclass& mc)
	{
		int len = strlen(mc.data) + 1;
		this->data = new char[len];
		strcpy(this->data, mc.data);
	}

	// overload operator= for deep copy
	myclass& operator=(const myclass& mc)
	{
		int len = strlen(mc.data) + 1;
		strcpy(this->data, mc.data);
		return *this;
	}
public:
	char* data;
};

int main()
{
	char* data = (char*)"data";
	myclass mc(data);
	vector<myclass> v;
	v.push_back(mc);
	mc.~myclass();
	cout<<(*v.begin()).data<<endl;
	cout<<v[0].data<<endl;
}





// multimap pracitce 

// implemention the function for a company to assign 5 different people
// to 3 different department


// #define SALE_DEPARTMENT 1
// #define	DEVELOP_DEPARTMENT 2
// #define FINACIAL_DEPARTMENT 3
// #define ALL_DEPARTMENT 4

// // staff
// class person
// {
// public:
// 	string name;
// 	int age;
// 	double salary;
// 	string tele;
// };

// void CreatePerson(std::vector<person>& vlist)
// {
// 	string seed = "ABCDE";
// 	for (int i = 0; i < 5; i++)
// 	{
// 		person p;
// 		p.name = "staff ";
// 		p.name += seed[i];
// 		p.age = rand()%30 + 20;
// 		p.salary = rand()% 20000 + 10000;
// 		p.tele = "010-88888888";
// 		vlist.push_back(p);
// 	}
// }

// void PersonByGroup(std::vector<person>& vlist, multimap<int, person>& plist)
// {
// 	int operate = -1;
// 	for(auto it = vlist.begin(); it != vlist.end(); it++)
// 	{
// 		cout<<"current staff information: "<<endl;
// 		cout<<"name: "<<(*it).name<<" age: "<<(*it).age<<" salary "<<
// 		(*it).salary<<" telephone: "<<(*it).tele<<endl;
// 		cout<<"which apartment(1 2 3 4: )"<<endl;
// 		scanf("%d", &operate);

// 		while(true)
// 		{
// 			if(operate == SALE_DEPARTMENT)
// 			{
// 				plist.insert(make_pair(SALE_DEPARTMENT, *it));
// 				break;
// 			}
// 			else if (operate == DEVELOP_DEPARTMENT)
// 			{
// 				plist.insert(make_pair(DEVELOP_DEPARTMENT, *it));
// 				break;
// 			}
// 			else if(operate == FINACIAL_DEPARTMENT)
// 			{
// 				plist.insert(make_pair(FINACIAL_DEPARTMENT, *it));
// 				break;
// 			}
// 			else
// 			{
// 				cout<<"wrong number"<<endl;
// 				scanf("%d", &operate);
// 			}
// 		}
// 	}

// 	cout<<"finish assigning staff "<<endl;
// 	cout<<"***********************"<<endl;
// }

// void printList(multimap<int, person>& plist, int myoperate)
// {
// 	if (myoperate == ALL_DEPARTMENT)
// 	{
// 		for (auto it = plist.begin(); it != plist.end(); it++)
// 		{
// 			cout<<"name: "<<(*it).second.name<<" age: "<<(*it).second.age<<endl;
// 		}
// 		return;
// 	}

// 	auto it = plist.find(myoperate);
// 	int depatCount = plist.count(myoperate);
// 	int num = 0;
// 	if(it != plist.end())
// 	{
// 		cout<<"myoperate"<< myoperate<<endl;
// 		while(it != plist.end() && num < depatCount)
// 		{
// 			cout<<"name: "<< (*it).second.name<<" age "<<endl;
// 			it++;
// 			num++;
// 		}
// 	}
// }

// void ShowPersonList(multimap<int, person>& plist, int myoperate)
// {
// 	switch (myoperate)
// 	{
// 		case SALE_DEPARTMENT:
// 		printList(plist, SALE_DEPARTMENT);
// 		break;

// 		case DEVELOP_DEPARTMENT:
// 		printList(plist, DEVELOP_DEPARTMENT);
// 		break;

// 		case FINACIAL_DEPARTMENT:
// 		printList(plist, FINACIAL_DEPARTMENT);
// 		break;

// 		case ALL_DEPARTMENT:
// 		printList(plist, ALL_DEPARTMENT);
// 		break;
// 	}
// }

// void PersonMenue(multimap<int, person>& plist)
// {
// 	int flag = -1;
// 	int isexit = 0;
// 	while(true)
// 	{
// 		cout<<"please input department number 1 2 3 4 0:"<<endl;
// 		scanf("%d", &flag);
// 		switch(flag)
// 		{
// 			case SALE_DEPARTMENT:
// 			ShowPersonList(plist, SALE_DEPARTMENT);
// 			break;

// 			case DEVELOP_DEPARTMENT:
// 			ShowPersonList(plist, DEVELOP_DEPARTMENT);
// 			break;

// 			case FINACIAL_DEPARTMENT:
// 			ShowPersonList(plist, FINACIAL_DEPARTMENT);
// 			break;

// 			case ALL_DEPARTMENT:
// 			ShowPersonList(plist, ALL_DEPARTMENT);
// 			break;

// 			case 0:
// 			isexit = 1;
// 			break;

// 			default:
// 			cout<<"wrong input, re-enter:"<<endl;
// 			break;
// 		}

// 		if(isexit = 1)
// 		{
// 			break;
// 		}
// 	}
// }

// int main()
// {
// 	std::vector<person> vlist;
// 	multimap<int, person> plist;

// 	CreatePerson(vlist);
// 	PersonByGroup(vlist, plist);
// 	PersonMenue(plist);
// }







// deque example & vector example

// class Player
// {
// public:
// 	string name;
// 	int score;
// };

// void Create_Player(vector<Player>& plist)
// {
// 	string randseed = "ABCDE";
// 	for(int i = 0; i < 5; i++)
// 	{
// 		Player player;
// 		player.name = "player";
// 		player.name += randseed[i];
// 		player.score = 0;

// 		plist.push_back(player);
// 	}
// }

// bool mycompare(int v1, int v2) 	// could be used in sort, we can also use lamda
// {
// 	return v1 < v2;
// }

// // score player, delete highest and lowest, average
// void Set_Player_Score(std::vector<Player>& plist)
// {
// 	for(auto it = plist.begin(); it != plist.end(); it++)
// 	{
// 		// store 10 score
// 		deque<int> dscore;
// 		for (int i = 0; i<10; i++)
// 		{
// 			int score = 50 + rand() % 50;
// 			dscore.push_back(score);
// 		}
// 		// sort
// 		sort(dscore.begin(), dscore.end(), mycompare);
// 		// delete top and low
// 		dscore.pop_front();
// 		dscore.pop_back();

// 		// average
// 		int totalscore = 0;
// 		for (auto it = dscore.begin(); it != dscore.end(); it++)
// 		{
// 			totalscore += *it;
// 		}
// 		int scoreavg = totalscore / dscore.size();
// 		(*it).score = scoreavg;
// 	}
// }

// bool comparePlayer (Player player1, Player player2)
// {
// 	return player1.score < player2.score;
// }

// // sorrt player
// void Show_Player_List(std::vector<Player> plist)
// {
// 	sort(plist.begin(), plist.end(), comparePlayer);
// 	cout<<"sort player"<<endl;
// 	for(auto it = plist.begin(); it < plist.end(); it++)
// 	{
// 		cout<<"name: "<< (*it).name <<"score: "<<(*it).score<<endl;
// 	}
// }

// int main()
// {
// 	std::vector<Player> plist;
// 	Create_Player(plist);
// 	Set_Player_Score(plist);
// 	Show_Player_List(plist);
// 	// sort player
// 	// name: playerDscore: 69
// 	// name: playerCscore: 72
// 	// name: playerBscore: 75
// 	// name: playerEscore: 75
// 	// name: playerAscore: 84
// }


// string example

// check if email address valid
// bool Check_Valid(string& email)
// {
// 	int pos1 = email.find("@");
// 	int pos2 = email.find(".");

// 	// if @ . exist
// 	if (pos1 == -1 || pos2 == -1)
// 	{
// 		return false;
// 	}

// 	if(pos1 > pos2)
// 	{
// 		return false;
// 	}

// 	return true;
// }

// // check if username include char that out of small char
// bool Check_Username(string& email)
// {
// 	int pos = email.find("@");
// 	string username = email.substr(0, pos-1);
// 	for(string::iterator it = username.begin(); it != username.end(); it++)
// 	{
// 		if(*it < 97 || *it > 122)
// 		{
// 			cout<<*it<<endl;
// 			return false;
// 		}
// 	}

// 	return true;
// }

// // check is email is right
// bool Check_EqualtTo(string& email)
// {
// 	string rightEmail = "amoslewis@foxmail.com";
// 	if(email.compare(rightEmail) != 0)
// 	{
// 		return false;
// 	}
// 	return true;
// }

// void testEmail()
// {
// 	string email;
// 	cout<<"input your email"<<endl;
// 	cin>>email;

// 	bool flag = Check_Valid(email);
// 	if(!flag)
// 	{
// 		cout<<"Invalid email"<<endl;
// 		return;
// 	}

// 	flag = Check_Username(email);
// 	if(!flag)
// 	{
// 		cout<<"input lower char"<<endl;
// 		return;
// 	}

// 	flag = Check_EqualtTo(email);
// 	if(!flag)
// 	{
// 		cout<<"wrong email"<<endl;
// 		return;
// 	}
// 	cout<<"email correct"<<endl;
// }

// int main()
// {
// 	testEmail();
// 	return EXIT_SUCCESS;
// }