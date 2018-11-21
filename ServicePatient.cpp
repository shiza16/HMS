#include "ServicePatient.h"

ServicePatient::ServicePatient()
{
		setTitle();
}

ServicePatient::~ServicePatient()
{
}

string ServicePatient::getService(){
	return Service;
}

void ServicePatient::setTitle(){
	Title = "Service Patient";
}

void ServicePatient::setService(string s){
	Service= s;
}

istream& operator >>(istream& input,ServicePatient &S){
	string temp;
	int t;
	cout<<endl<<"Patient Name ";input>>temp;S.setName(temp); 
	cout<<endl<<"Patient Gender ";input>>temp;S.setGender(temp);
	cout<<endl<<"Patient Address ";input>>temp;S.setAddress(temp);
	cout<<endl<<"Patietn Phone ";input>>temp;S.setPhone(temp);
	cout<<endl<<"Patient Age ";input>>t;S.setAge(t);
	cout<<endl<<"Patient Blood Group ";input>>temp;S.setBloodGroup(temp);
	return input;
}

ostream& operator <<(ostream& output,ServicePatient &S){
	output<<"Patient Title "<<S.getTitle();
	output<<endl<<"Patient Name "<<S.getName();
	output<<endl<<"Patient Gender "<<S.getGender();
	output<<endl<<"Patient Address "<<S.getAddress();
	output<<endl<<"Patietn Phone "<<S.getPhone();
	output<<endl<<"Patient Age "<<S.getAge();
	output<<endl<<"Patient Service used "<<S.getService();
	output<<endl<<"Patient Bill "<<S.getBill();
	return output;
}	

