#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>

//ABSTRACT CLASS

using namespace std;

class Person
{
	string Name;
	string Gender;
	string Address;
	string Phone;
	int Age;
	public:
		Person();
		void setName(string);
		string getName();
		void setGender(string);
		string getGender();
		void setAddress(string);
		string getAddress();
		void setPhone(string);
		string getPhone();
		void setAge(int);
		int getAge();
		virtual void setTitle()=0;
		string getTitle();	
		~Person();
	protected:
		string Title;
};

#endif
