#include "AdmitPatient.h"

AdmitPatient::AdmitPatient()
{
}

void AdmitPatient::setTitle(){
	Title = "Admit Patient";
}

void AdmitPatient::setAdmitDate(Date a){
	AdmitDate = a;
}

Date AdmitPatient::getAdmitDate(){
	return AdmitDate;
}

void AdmitPatient::setDischargeDate(Date d){
	DischargeDate = d;
}

Date AdmitPatient::getDischargeDate(){
	return DischargeDate;
}

void AdmitPatient::setDays(){
	Days = AdmitDate.diffDay(DischargeDate);
}

int AdmitPatient::getDays(){
	return Days;
}

Doctor* AdmitPatient::getDoctor(){
	return Doc;
}

AdmitPatient::~AdmitPatient()
{
		setTitle();
}

istream& operator >>(istream& input,AdmitPatient& A){
	string temp;int t;Date t1;
	cout<<endl<<"Patient Name ";input>>temp;A.setName(temp);
	cout<<endl<<"Patient Gender ";input>>temp;A.setGender(temp);
	cout<<endl<<"Patient Address ";input>>temp;A.setAddress(temp);
	cout<<endl<<"Patietn Phone ";input>>temp;A.setPhone(temp);
	cout<<endl<<"Patient Age ";input>>t;A.setAge(t);
	cout<<endl<<"Patient Blood Group ";input>>temp;A.setBloodGroup(temp);
	cout<<endl<<"Patient Admit Date ";input>>t1;A.setAdmitDate(t1);
	cout<<endl<<"Patient Discharge Date ";input>>t1;A.setDischargeDate(t1);
	return input;
}

ostream& operator <<(ostream& output,AdmitPatient&A){
	output<<"Patient Title"<<A.getTitle();
	output<<endl<<"Patient Name "<<A.getName();
	output<<endl<<"Patient Gender "<<A.getGender();
	output<<endl<<"Patient Address "<<A.getAddress();
	output<<endl<<"Patietn Phone "<<A.getPhone();
	output<<endl<<"Patient Age "<<A.getAge();
	output<<endl<<"Patient Admit Date "<<A.AdmitDate;
	output<<endl<<"Patient Discharge Date "<<A.DischargeDate;
	output<<endl<<"Patient\'s Doctor Name "<<A.getDoctor()->getName();
	output<<endl<<"Patient Bill "<<A.getBill();
	return output;
}

void AdmitPatient::setDoctor(Doctor D){
	Doc = &D;
}
