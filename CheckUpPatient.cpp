#include "CheckUpPatient.h"

CheckUpPatient::CheckUpPatient()
{	setTitle();
}

CheckUpPatient::~CheckUpPatient()
{
}
void CheckUpPatient::setTitle(){
	Title = "Check-Up Patient";
}

Doctor* CheckUpPatient::getDoctor(){
	return Doc;
}

istream& operator >>(istream& input,CheckUpPatient &C){
	string temp;
	int t;
	cout<<endl<<"Patient Name ";input>>temp;C.setName(temp);
	cout<<endl<<"Patient Gender ";input>>temp;C.setGender(temp);
	cout<<endl<<"Patient Address ";input>>temp;C.setAddress(temp);
	cout<<endl<<"Patietn Phone ";input>>temp;C.setPhone(temp);
	cout<<endl<<"Patient Age ";input>>t;C.setAge(t);
	cout<<endl<<"Patient Blood Group ";input>>temp;C.setBloodGroup(temp);
}

ostream& operator << (ostream& output,CheckUpPatient &C){
	output<<"Patient Title"<<C.getTitle();
	output<<endl<<"Patient Name "<<C.getName();
	output<<endl<<"Patient Gender "<<C.getGender();
	output<<endl<<"Patient Address "<<C.getAddress();
	output<<endl<<"Patietn Phone "<<C.getPhone();
	output<<endl<<"Patient Age "<<C.getAge();
	output<<endl<<"Patient\'s Doctor Name "<<C.getDoctor()->getName();
	output<<endl<<"Patient Bill "<<C.getBill();
	return output;
}

void CheckUpPatient::setDoctor(Doctor d){
	Doc = &d;
}
