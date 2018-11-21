#ifndef SERVICEPATIENT_H
#define SERVICEPATIENT_H
#include<iostream>
#include<string>
#include "Patient.h"

using namespace std;
class ServicePatient : public Patient
{
	string Service;
	public:
		ServicePatient();
		string getService();
		void setService(string);
		void setTitle();
		~ServicePatient();
		friend istream& operator >>(istream& input,ServicePatient &S);
		friend ostream& operator <<(ostream& output,ServicePatient &S);
	protected:
};

#endif
