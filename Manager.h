#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<string>
#include<fstream>
#include "Person.h"
#include "AdmitPatient.h"
#include "EmergencyPatient.h"
#include "CheckUpPatient.h"
#include "ServicePatient.h"
#include <vector>
#include <windows.h>

class Manager : public Person
{
	string Password;
	public:
		Manager();
		void resetPassword(string);
		void setPassword(string);
		string getPassword();
		void changePassword();
		void setTitle();
		template <typename T> void printBill(T);
		void printServices();
		void printListOfDoctors();
		void awardCheckUp();
		void awardAdmit();
		void awardEmergency();
		void awardService();
		friend ostream& operator <<(ostream&,Manager&);
		friend istream& operator >>(istream&,Manager&);
		~Manager();
	protected:
};

#endif
