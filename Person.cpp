#include "Person.h"

Person::Person()
{
}

void Person:: setName(string nam){
	Name=nam;
}

string Person:: getName(){
	return Name;
}

void Person::setGender(string gen){
	if(gen=="Male"||gen=="MALE"||gen=="male"||gen=="m"||gen=="M") Gender = "Male";
	else if(gen=="Female"||gen=="FEMALE"||gen=="female"||gen=="f"||gen=="F") Gender = "Female";
	else Gender = "--";
}

string Person::getGender(){
	return Gender;
}

void Person::setAddress(string add){
	Address = add;
} 

string Person::getAddress(){
	return Address;
}

void Person::setPhone(string ph){
	Phone = ph;
}

string Person::getPhone(){
	return Phone;
}

void Person::setAge(int a){
	Age = a;
}

int Person::getAge(){
	return Age;
}

string Person::getTitle(){
	return Title;
}

Person::~Person()
{
}
