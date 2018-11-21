#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<vector>
#include "Manager.h"
#include<string>
#include<cstring>
#include<fstream>
#include<windows.h>
//#include "AdmitPatient.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void AssignManager(vector<Manager>&);
void AssignCheckUpPatient();
void AssignEmergencyPatient();
void AssignAdmitPatient();
void AssignServicePatient();

void startup();
void goodbye();
void goback();
void patient_list();
void login();
void logout();
void disease_list();
void addP();
void viewP();

int main(int argc, char** argv) {
	
	startup();
	
	system("COLOR F0");
	vector<Manager> Man;
	
	int ch1=0,ch2=0;
	r:
	system("cls");
	system("COLOR F0");
	cout<<"\t\t\t\t\t\t================\n";
	cout<<"\t\t\t\t\t\t||MMH HOSPITAL||\n";
	cout<<"\t\t\t\t\t\t================\n";
	cout<<endl<<endl;
	
	AssignManager(Man);
		
	cout<<"Press 1 for Manager\nPress 2 for Patient\nPress 3 for Exit\nEnter your choice ";
	cin>>ch1;
	while (!(ch1>0&&ch1<4)){
		cout<<endl<<"You enter invalid choice.";
		cout<<"\nPress 1 for Manager\nPress 2 for Patient\nPress 3 for Exit\nEnter your choice ";
		cin>>ch1;
	}
	if(ch1==1){
		system("cls");
		string man_name,man_pass;
		x:
		Manager temp;	
		cout<<"\nEnter Name of Manager ";
		cin>>man_name;
		int flag=-1,ch2,i=0;
		for (std::vector<Manager>::iterator it = Man.begin() ; it != Man.end(); ++it){
			if (Man[i].getName()==man_name) {
				flag = i;
				i++;
				cout<<"Manager found";
				break;	
			}
		}
		if(flag == -1){
			int ch_t;
			cout<<"\nManager not found.";
			cout<<"\nPress 1 to continue\nPress 2 for BackMenu\nEnter your choice ";
			cin>>ch_t;
			while(!(ch_t>0&&ch_t<3)){
				cout<<"You entered invalid choice.";
				cout<<"\nPress 1 to continue\nPress 2 for BackMenu\nEnter your choice ";
				cin>>ch_t;
			}
			if(ch_t==2){
				cout<<"\nPress any key to continue ";
				getch();
				goback();
				goto r;
			}
			cout<<"\nPress any key to continue ";
			getch();
			goback();
			goto x;
		}
		cout<<"\nEnter Password of Manager ";
		cin>>man_pass;
		if(Man[flag].getPassword()!=man_pass){
			cout<<"\nYou entered incorrect Password.";
			cout<<endl<<"Press any key to continue ";
			getch();
			goto x;
		}
		else cout<<"Correct";
		login();
		y:
		system("cls");
		cout<<"\nPress 1 for Add Patient\nPress 2 for View List of Patients\nPress 3 for Back Menu\nEnter your Choice ";
		cin>>ch2;
		while(!(ch2>0&&ch2<4)){
			cout<<"\nYou enter invalid choice.";
			cout<<"\nPress 1 for Add Patient\nPress 2 for View List of Patients\nPress 3 for Back Menu\nEnter your Choice ";
			cin>>ch2;
		}
		
		if(ch2==1){
			m:
			addP();
				system("cls");
				Patient *P;
				ofstream file;
			int ch3;
			cout<<"\nPress 1 for Emergeny Patient\nPress 2 for Checkup Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
			cin>>ch3;
			while(!(ch3>0&&ch3<6)){
				cout<<"\nYou entered invalid choice.";
				cout<<"\nPress 1 for Emergeny Patient\nPress 2 for Checkup Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
				cin>>ch3;
			}
			if(ch3 == 1){
				patient_list();
				Man[flag].awardEmergency();	
		    }
			else if(ch3 == 2){
				patient_list();
				Man[flag].awardCheckUp();
			}
			else if(ch3 == 3){
				patient_list();
				Man[flag].awardAdmit();
			}
			else if(ch3 == 4){
				patient_list();
				Man[flag].awardService();
			}
			else if(ch3 == 5){
				cout<<"\nPress any key to continue ";
				getch();
				goback();
				goto y;
			}
			cout<<"Press any key to continue";
			getch();
			goto m;
					
		}
		else if(ch2==2){
			mm:
				viewP();
				system("cls");
			int ch3;
			cout<<"\nPress 1 for Checkup Patient\nPress 2 for Emergeny Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
			cin>>ch3;
			while(!(ch3>0&&ch3<6)){
				cout<<"\nYou entered invalid choice.";
				cout<<"\nPress 1 for Checkup Patient\nPress 2 for Emergeny Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
				cin>>ch3;
			}
			if(ch3 == 1){
				patient_list();
				AssignCheckUpPatient();
			}
			else if(ch3 == 2){
				patient_list();
				AssignEmergencyPatient();
			}
			else if(ch3 == 3){
				patient_list();
				AssignAdmitPatient();
			}
			else if(ch3 == 4){
				patient_list();
				AssignServicePatient();
			}
			else if(ch3 == 5){
				cout<<"\nPress any key to continue ";
				getch();
				goback();
				goto y;
			}
			cout<<"Press any key to continue";
			getch();
			goto mm;
		}
		else if(ch2==3){
			cout<<endl<<"Press any key to continue ";
			getch();
			logout();
			goto r;			
		}
		cout<<endl<<"Press any key to continue ";
		getch();
		goback();
		goto y;
	}
	else if(ch1==2){
		login();
		p:
		system("cls");
		cout<<"\nPress 1 for List of Doctor, Disease and Cost\nPress 2 for List of Other Services and Cost\nPress 3 for Back Menu\nEnter your Choice ";
		cin>>ch2;
		while(!(ch2>0&&ch2<4)){
			cout<<endl<<"You enter invalid choice.";
			cout<<"\nPress 1 for List of Doctor, Disease and Cost\nPress 2 for List of Other Services and Cost\nPress 3 for Back Menu\nEnter your Choice ";
			cin>>ch2;
		}
		if(ch2 == 1){
			disease_list();
			system("cls");
			const int n=26;
			string DoctorsDept[n]={"General Physician","Diarrhea\t","Allergy\t\t","Depression\t","Acne\t\t","Diabetes\t","Head Ache\t","Arthritis\t","Asthma\t\t","Personality Disorder","Rickits\t\t","Autism\t\t",
			"Back Pain\t","Bad Breath\t","Alopecia\t","Bladder Cancer\t","Bone Cancer\t","Breast Cancer\t","Brain Tumor\t","Burn\t\t","High/Low Blood Pressure","Cholesterol\t","Heart Problem\t",
			"High/Low Uric Acid","Dehydration\t","Severe Flu/Cough"};
			double Cost[n]={10,12,11,12,14,15,17,15,20,25,18,12,8,15,30,25,35,45,10,7,8,25,15,10,10,15};
			string DoctorsName[n]={"James","Shawn","Paul","Andrew","Fadricks","Micheal","Chaplin","John","David","Anthony","Amam","Prakash","Bob","Martin","George","Ramesh","Farooq",
			"Laiba","Lubna","Robert","Harry","Kathrine","Peter","Jack","Mike","Saqib"};
			cout<<"\nAVAILABLE DISEASES, DOCTOR NAMES";
			cout<<"\nSR#\tDISEASES\t\tDOCTOR\tCOST";
			for(int i=0;i<n;i++) cout<<endl<<i+1<<"\t"<<DoctorsDept[i]<<"\t(Dr "<<DoctorsName[i]<<")\t$"<<Cost[i];
		}
		else if(ch2 == 2){
			system("cls");
			const int n=10;
			string Services[n]={"X-Ray\t","UltraSound","CT Scan\t","TC DC HB","Urine Test","Blood Test","Biliribin","Stool Test","Bed Charge","Sugar Test"};
			double Cost[n]={3,5,5,1.5,1.5,1.5,2,1.5,1.5,2};
			disease_list();
			cout<<"\nAVAILABLE SERVICES\nSR#\tService\t\tCost";
			for(int i=0;i<n;i++) cout<<endl<<i+1<<"\t"<<Services[i]<<"\t$"<<Cost[i];
		}
		else if(ch2==3){
			cout<<endl<<"Press any key to continue ";
			getch();
			logout();
			goto r;
		}
		cout<<endl<<"Press any key to continue ";
		getch();
		goback();
		goto p;
	}
	else if(ch1==3){
		goodbye();
		return 0;	
	}
	cout<<endl<<"Press any key to continue ";
	getch();
	goback();
	goto r;
}	

void AssignManager(vector<Manager> &M){
//	ifstream man;
//	Manager m_temp;
//	string s_temp;
//	int i_temp;
//	man.open("Manager.csv");
//	if(man.bad()){
//		cout<<"Manager.csv is unable to open.";
//		exit(1);
//	}
//	M.clear();
//	cout<<"Start\n";
//	while(!man.eof()){
//		getline(man,s_temp,',');m_temp.setName(s_temp);
//		getline(man,s_temp,',');m_temp.setGender(s_temp);
//		getline(man,s_temp,',');m_temp.setAddress(s_temp);
//		getline(man,s_temp,',');m_temp.setPhone(s_temp);
//		man>>i_temp;m_temp.setAge(i_temp);
//		getline(man,s_temp,',');m_temp.setPassword(s_temp);
//		M.push_back(m_temp);
//		cout<<M[0].getName();
//		getline(man,s_temp);
//	}
//	cout<<"Done "<<endl;

Manager m;
m.setName("m");
m.setGender("m");
m.setAddress("S2");
m.setPhone("0213");
m.setAge(1); 
m.setPassword("a");
M.push_back(m); 
}
void AssignCheckUpPatient(){
	ifstream pat;
	string s_temp;
	int i_temp;
	pat.open("CheckUp_Patient.csv");
	if(pat.bad()){
		cout<<"CheckUp_Patient.csv is unable to open.";
		exit(1);
	}
	cout<<"Name\tAge\tGender\tAddress\tPhone\tAge\tDoctor Name\n";
	while(pat.good()){
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		pat>>i_temp;cout<<i_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
	}
	pat.close();
}

void AssignServicePatient(){
	ifstream spat;
	ServicePatient sp_temp;
	string s_temp;
	int i_temp;
	spat.open("Service_Patient.csv");
	if(spat.bad()){
		cout<<"Service_Patient.csv is unable to open";
		exit(1);
	}
	cout<<"Name\tAge\tGender\tAddress\tPhone\tService\n";
	while(spat.good()){
		getline(spat,s_temp,',');cout<<s_temp<<"\t";
		spat>>i_temp;cout<<i_temp<<"\t";
		getline(spat,s_temp,',');cout<<s_temp<<"\t";
		getline(spat,s_temp,',');cout<<s_temp<<"\t";
		getline(spat,s_temp,',');cout<<s_temp<<"\t";
		getline(spat,s_temp,',');cout<<s_temp<<"\n";
	}
	spat.close();
}

void AssignEmergencyPatient(){
	ifstream pat;
	EmergencyPatient p_temp;
	string s_temp;
	int i_temp;
	pat.open("Emergency_Patient.csv");
	if(pat.bad()){
		cout<<"Emergency_Patient.csv is unable to open";
		exit(1);
	}
	cout<<"Name\tAge\tGender\tAddress\tPhone\n";
	while(pat.good()){
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		pat>>i_temp;cout<<i_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\n";
	}pat.close();
}
	
void AssignAdmitPatient(){
	ifstream pat;
	AdmitPatient p_temp;
	string s_temp;
	int i_temp;
	pat.open("Admit_Patient.csv");
	if(pat.bad()){
		cout<<"Admit_Patient.csv is unable to open";
		exit(1);
	}
	cout<<"Name\tAge\tGender\tAddress\tPhone\tDoctor Name\tAdmit Date\tDischarge Date\n";
	while(pat.good()){
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		pat>>i_temp;cout<<i_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\t";
		getline(pat,s_temp,',');cout<<s_temp<<"\n";
	}
	pat.close();
}

void startup(){
	//Welcome to ABC HOSPITAL
	system("COLOR F9"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   WELCOME\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   WELCOME TO   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   WELCOME TO MMH HOSPITAL\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   WELCOME TO MMH HOSPITAL\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   WELCOME TO MMH HOSPITAL\n";
	Sleep(200);
	system("cls");
	system("COLOR F0");
}

void goodbye(){
	system("COLOR F3"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKYOU FOR USING NAKAFI HOSPITAL APP.\n";
	Sleep(250);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOOD BYE\n";
	Sleep(250);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(300);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   GOOD ...\n";
	Sleep(250);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   GOOD BYE\n";
	Sleep(250);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   GOOD ...\n";
	Sleep(250);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   GOOD BYE\n";
	Sleep(250);
	system("cls");
	system("COLOR F0");
}

void goback(){
	system("COLOR F9"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   G.........\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GO........\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOI.......\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOIN......\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOING ....\n";
	Sleep(300);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOING B...\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOING BA..\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOING BAC.\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GOING BACK\n";
	Sleep(250);
	system("cls");
	system("COLOR F0");
}

void login(){
	system("COLOR F9"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SI........\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGN......\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNIN.....\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNING ..\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNING UP\n";
	Sleep(300);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ..........\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNING UP\n";
	Sleep(300);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ..........\n";
	Sleep(200);
	system("cls");
	system("COLOR F0");
}

void logout(){
	system("COLOR F9"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SI........\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGN......\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNIN.....\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNING ...\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNING OUT\n";
	Sleep(300);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ..........\n";
	Sleep(200);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   SIGNING OUT\n";
	Sleep(300);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ..........\n";
	Sleep(200);
	system("cls");
	system("COLOR F0");
}

void disease_list(){
	system("COLOR F3"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   PREPARING LIST.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   PREPARING LIST.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   IT MAY TAKE FEW SECONDS.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t    .........................\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t IT MAY TAKE FEW SECONDS.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ........................\n";
	Sleep(400);
	system("cls");
	system("COLOR F0");	
}

void addP(){
	system("COLOR F3"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ADD NEW PATIENT.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ADD NEW PATIENT.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   ADD NEW PATIENT.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t    \n";
	Sleep(400);
	system("cls");
	system("COLOR F0");	
}

void viewP(){
		system("COLOR F3"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   VIEW LIST OF PATIENT.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   VIEW LIST OF PATIENT.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   VIEW LIST OF PATIENT.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t    \n";
	Sleep(400);
	system("cls");
	system("COLOR F0");		
}

void patient_list(){
	system("COLOR F3"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   PREPARING LIST OF PATIENTS.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   PREPARING LIST OF PATIENTS.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   IT MAY TAKE FEW SECONDS.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t    .........................\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t IT MAY TAKE FEW SECONDS.\n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ........................\n";
	Sleep(400);
	system("cls");
	system("COLOR F0");	
}
