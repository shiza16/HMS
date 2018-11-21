#include "Manager.h"

void bill(){
	system("COLOR F9"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GENERATING BILL\n";
	Sleep(500);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(500);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GENERATING BILL   \n";
	cout<<"\t\t\t\t   WAIT FOR FEW SECONDS   \n";
	Sleep(500);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   GENERATING BILL   \n";
	cout<<"\t\t\t\t   WAIT FOR FEW SECONDS   \n";
	Sleep(400);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   \n";
	Sleep(200);
	system("cls");
	system("COLOR F0");
}

Manager::Manager()
{
		setTitle();
}

Manager::~Manager()
{
}

void Manager::setTitle(){
	Title = "Manager";
}

void Manager::resetPassword(string p){
	string p1;
	cout<<"Renter the password ";cin>>p1;
	while (p1 != p){
		cout<<"Enter the same password.\nEnter the password ";cin>>p;
		cout<<"Renter the password ";cin>>p1;
	}
	Password = p;
}

void Manager::setPassword(string p){
	Password = p;
}

string Manager::getPassword(){
	return Password;
}

void Manager::changePassword(){
	string p,p1,p2;
	cout<<"Enter the previous password ";cin>>p;
	while(Password != p){
		cout<<"Password mismatch.\nEnter the previous password ";cin>>p;
	}
	cout<<"Enter the new password ";cin>>p1;
	cout<<"Reneter the new password ";cin>>p2;
	while (p1 != p2){
		cout<<"Enter the same password.\nEnter the password ";cin>>p1;
		cout<<"Renter the password ";cin>>p2;
	}
	Password = p1;
}

template <typename T> void Manager::printBill(T t){
	cout<<t;
}

void Manager::printServices(){
	
	const int n=10;
	string Services[n]={"X-Ray","UltraSound","CT Scan","TC DC HB","Urine Test","Blood Test","Biliribin","Stool Test","Bed Charge","Sugar Test"};
	double Cost[n]={3,5,5,1.5,1.5,1.5,2,1.5,1.5,2};
	cout<<"\nAVAILABLE SERVICES";
	for(int i=0;i<n;i++) cout<<endl<<"Press "<<i+1<<" for "<<Services[i]<<" (Cost = $"<<Cost[i]<<")";
	
}

void Manager::awardService(){
	fstream file;
	int ch;
	const int n=10;
	string Services[n]={"X-Ray","UltraSound","CT Scan","TC DC HB","Urine Test","Blood Test","Biliribin","Stool Test","Bed Charge","Sugar Test"};
	double Cost[n]={3,5,5,1.5,1.5,1.5,2,1.5,1.5,2};
	cout<<"Key\tService\t\tCost\n";
	for(int k=0;k<n;k++) cout<<k+1<<"\t"<<Services[k]<<"\t"<<Cost[k]<<"\n";
	cout<<endl<<"Enter your choice "; cin>>ch;
	if(ch>=1&&ch<=n){
		ServicePatient S;
		cin>>S;
		S.setService(Services[ch-1]);
		S.setBill(Cost[ch-1]);
		file.open("Service_Patient.csv",ios_base::app);
		if(file.bad()){
			cout<<"Unable to open Service_Patient.csv.";
			exit(1);
		}
		file<<S.getName()<<','<<S.getAge()<<','<<S.getGender()<<','<<S.getAddress()<<','<<S.getPhone()<<','<<S.getService()<<endl;
		bill();
		printBill(S);cout<<endl;
	}
	else cout<<"You entered invalid choice.";
}

void Manager::awardEmergency(){
	EmergencyPatient e;
	cin>>e;
	fstream file;
	file.open("Emergency_Patient.csv",ios_base::app);
	if(file.bad()){
		cout<<"Emergency_Patient.csv is unable to open.";
		exit(1);	
	}
	file<<e.getName()<<','<<e.getAge()<<','<<e.getGender()<<','<<e.getAddress()<<','<<e.getPhone()<<',';
	e.setBill(10);
	bill();
	printBill(e);cout<<endl;
}

void Manager::awardAdmit(){
	const int n=26;
	vector<Doctor> doc(n);
	ifstream file;
	string s;int i;double dd;
	file.open("Doctor.csv");
	if(file.bad()){
		cout<<"Doctor.csv unable to open.";
		exit(1);
	}
	int ii=1;
	cout<<"Key\tName\tSpecialization\tSurgeryFee\n";
	while(file.good()){
		Doctor d;
		cout<<ii++<<"\t";
		getline(file,s,',');
		d.setName(s);
		cout<<s<<"\t";
		getline(file,s,',');d.setGender(s);
		getline(file,s,',');d.setAddress(s);
		getline(file,s,',');d.setPhone(s);
		file>>i;d.setAge(i);
		getline(file,s,',');d.setSpecialization(s);
		cout<<s<<"\t";
		file>>dd;d.setCheckUpFees(dd);
		file>>dd;d.setSurgeryFees(dd);
		cout<<dd<<"\n";
		file>>dd;d.setSalary(dd);
		doc.push_back(d);
	}
	cout<<"Per day fee for hospital ward is $25.\n";
	int choice;
	cout<<"Enter your choice ";
	cin>>choice;
	if(choice>=1&&choice<=26){
		AdmitPatient c;
		cin>>c;
		c.setDoctor(doc[ii-1]);
        fstream file;
		file.open("Admit_Patient.csv",ios::app);
		if (file.bad()){
	    	cout<<"Admit_Patient.csv unable to open.";
			exit(1);
		}
		file<<c.getName()<<','<<c.getAge()<<','<<c.getGender()<<','<<c.getAddress()<<','<<c.getPhone()<<','<<c.getDoctor()->getName()<<endl;
		c.setBill(c.getDoctor()->getCheckUpFees()+(c.getDischargeDate().diffDay(c.getAdmitDate()))*25);
		bill();
		printBill(c);
		cout<<endl;
	}
	else{
		cout<<"Incorrect Doctor Name.";
	}
}

void Manager::awardCheckUp(){
	const int n=26;
	vector<Doctor> doc(n);
	doc.clear();
	ifstream file1;
	string s;int i;double dd;
	file1.open("Doctor.csv");
	if(file1.bad()){
		cout<<"Doctor.csv unable to open.";
		exit(1);
	}
	int ii=1;
	cout<<"Key\tName\tSpecialization\tCheckUpFee\n";
	while(file1.good()){
		Doctor d;
		cout<<ii++<<"\t";
		getline(file1,s,',');d.setName(s);cout<<s<<"\t";
		getline(file1,s,',');d.setGender(s);
		getline(file1,s,',');d.setAddress(s);
		getline(file1,s,',');d.setPhone(s);
		file1>>i;d.setAge(i);
		getline(file1,s,',');d.setSpecialization(s);cout<<s<<"\t";
		file1>>dd;d.setCheckUpFees(dd);cout<<dd<<"\n";
		file1>>dd;d.setSurgeryFees(dd);
		file1>>dd;d.setSalary(dd);
		doc.push_back(d);
		
	}
	file1.close();
	int choice;
	cout<<"Enter your choice ";
	cin>>choice;
	if(choice>=1&&choice<=26){
		CheckUpPatient c;
		c.setDoctor(doc[ii-1]);
        ofstream file2;
		file2.open("CheckUp_Patient.csv",ios_base::app);
		if (file2.bad()){
	    	cout<<"CheckUp_Patient.csv unable to open.";
			exit(1);
		}
		file2<<c.getName()<<','<<c.getAge()<<','<<c.getGender()<<','<<c.getAddress()<<','<<c.getPhone()<<','<<c.getDoctor()->getName()<<endl;
		c.setBill(c.getDoctor()->getCheckUpFees());
		bill();
		printBill(c);
		cout<<endl;
		file2.close();
	}
	else{
		cout<<"Incorrect Doctor Name.";
	}
}

ostream& operator << (ostream& out,Manager & M){
	out<<"Manager Name = "<<M.getName();
	out<<"\nManager Gender = "<<M.getGender();
	out<<"\nManager Age = "<<M.getAge();
	out<<"\nManager Address = "<<M.getAddress();
	out<<"\nManager Phone Number = "<<M.getPhone();
	return out;
}

istream& operator >> (istream& in, Manager &M){
	string temp;int t;
	cout<<"Enter Manager Name ";in>>temp;M.setName(temp);
	cout<<"\nEnter Manager Password ";in>>temp;M.resetPassword(temp);
	cout<<"\nEnter Manager Age ";in>>t;M.setAge(t);
	cout<<"\nEnter Manager Address ";in>>temp;M.setAddress(temp);
	cout<<"\nEnter Manager Phone Number ";in>>temp;M.setPhone(temp);
	return in;
}
