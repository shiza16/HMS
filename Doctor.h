#ifndef DOCTOR_H
#define DOCTOR_H
#include<iostream>
#include<string>
#include<fstream>
#include "Person.h"

using namespace std;
class Doctor : public Person
{
	string Specialization;
	double Salary;
	double CheckUpFees;
	double SurgeryFees;
	public:
		Doctor();
		void setTitle();
		void setSpecialization(string);
		string getSpecialization();
		void setSalary(double);
		double getSalary();
		void setCheckUpFees(double);
		double getCheckUpFees();
		void setSurgeryFees(double);
		double getSurgeryFees();
		friend ostream& operator << (ostream& , Doctor&);
		~Doctor();
	protected:
};

#endif
