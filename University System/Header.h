#pragma once


#include<iostream>
#include<string>
using namespace std;



class student
{
	int id; 
	string name;
	int mark1;
	int mark2;
	int mark3;
public:

	int getid() {
		return id;
	}

	string getname()
	{
		return name; 
	}

	int getmark1() {
		return mark1;
	}

	int getmark2() {
		return mark2;
	}

	int getmark3() {
		return mark3;
	}

	void setname(string name)
	{
		this->name = name;
	}

	void setid(int id)
	{
		this->id = id;
	}

	void setmark1 (int mark1)
	{
		this->mark1=mark1;
	}

	void setmark2(int mark2)
	{
		this->mark2 = mark2;
	}

	void setmark3(int mark3)
	{
		this->mark3 = mark3;
	}
};
