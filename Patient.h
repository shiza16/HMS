#ifndef PATIENT_H
#define PATIENT_H
#include<iostream>
#include<string>
#include<fstream>
#include "Person.h"

//Abstart Class
using namespace std;
class Patient : public Person
{
	double Bill;
	string BloodGroup;
	public:
		Patient();
		void setBill(double);
		double getBill();
		void setBloodGroup(string);
		string getBloodGroup();
		~Patient();
	protected:
};

#endif
