#include "Doctor.h"

Doctor::Doctor()
{
		setTitle();
}

void Doctor::setTitle(){
	Title = "Doctor";
}

void Doctor::setSpecialization(string s){
	Specialization = s;
}

string Doctor::getSpecialization(){
	return Specialization;
}

void Doctor::setSalary(double s){
	Salary = s;
}

double Doctor::getSalary(){
	return Salary;
}

void Doctor::setCheckUpFees(double c){
	CheckUpFees = c;
}

double Doctor::getCheckUpFees(){
	return CheckUpFees;
}

void Doctor::setSurgeryFees(double s){
	SurgeryFees = s;
}

double Doctor::getSurgeryFees(){
	return SurgeryFees;
}

ostream& operator << (ostream& out, Doctor& d){
	out<<d.getName()<<"\t\t"<<d.getSpecialization()<<"\t\t"<<d.getSurgeryFees()<<"\t\t\t"<<d.getCheckUpFees();
	return out;
}

Doctor::~Doctor()
{
}
