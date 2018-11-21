#ifndef ADMITPATIENT_H
#define ADMITPATIENT_H
#include<iostream>
#include<string>
#include "Date.h"
#include "Patient.h"
#include "Doctor.h"

using namespace std;
class AdmitPatient : public Patient
{
	Doctor *Doc;
	Date AdmitDate;
	Date DischargeDate;
	int Days;
	public:
		AdmitPatient();
		void setTitle();
		void setAdmitDate(Date);
		Date getAdmitDate();
		void setDischargeDate(Date);
		Date getDischargeDate();
		void setDays();
		int getDays();
		void setDoctor(Doctor);
		Doctor* getDoctor();
		friend istream& operator >>(istream&,AdmitPatient&);
		friend ostream& operator <<(ostream&,AdmitPatient&);
		~AdmitPatient();
	protected:
};

#endif
