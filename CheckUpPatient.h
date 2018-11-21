#ifndef CHECKUPPATIENT_H
#define CHECKUPPATIENT_H
#include<iostream>
#include<string>
#include "Doctor.h"
#include "Patient.h"

using namespace std;
class CheckUpPatient : virtual public Patient
{
	Doctor *Doc;
	public:
		CheckUpPatient();
		void setTitle();
		Doctor* getDoctor();
		void setDoctor(Doctor);
		~CheckUpPatient();
		friend istream& operator >>(istream& input,CheckUpPatient &C);
		friend ostream& operator <<(ostream& output,CheckUpPatient &C);

	protected:
};

#endif
