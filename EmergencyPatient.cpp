#include "EmergencyPatient.h"

EmergencyPatient::EmergencyPatient(){
		setTitle();
}

void EmergencyPatient::setTitle(){
	Title = "Emergency Patient";
}

EmergencyPatient::~EmergencyPatient()
{
}

istream& operator >>(istream& input,EmergencyPatient &E){
	string temp;
	int t; 
	cout<<endl<<"Enter Patient Name ";input>>temp;E.setName(temp);
	cout<<endl<<"Enter Patient Gender ";input>>temp;E.setGender(temp);
	cout<<endl<<"Enter Patient Address ";input>>temp;E.setAddress(temp);
	cout<<endl<<"Enter Patietn Phone ";input>>temp;E.setPhone(temp);
	cout<<endl<<"Enter Patient Age ";input>>t;E.setAge(t);
	cout<<endl<<"Enter Patient Blood Group ";input>>temp;
	return input;
}

ostream& operator <<(ostream& output,EmergencyPatient &E){
	output<<"Patient Title"<<E.getTitle();
	output<<endl<<"Patient Name "<<E.getName();
	output<<endl<<"Patient Gender "<<E.getGender();
	output<<endl<<"Patient Address "<<E.getAddress();
	output<<endl<<"Patietn Phone "<<E.getPhone();
	output<<endl<<"Patient Age "<<E.getAge();
	output<<endl<<"Patient Bill "<<E.getBill();
	return output;
}
