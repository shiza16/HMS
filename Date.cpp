#include "Date.h"

Date::Date()
{
}

Date::Date(int month,int date,int year){
	if(month<=12 && month>=1) (*this).month = month;
	else (*this).month=1;
	(*this).date = date;
	(*this).year = year;
}

int Date::calDays(){
	
	int d = date;
	int leapDays = year / 4;
	if(year % 4==0&&month<=2) leapDays--;
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=0;i<month-1;i++) d = d + m[i];	
	d = 365*(year-1) + leapDays + d;
	return d;
}

void Date::setDate(int date){
	(*this).date = date;
}
void Date::setMonth(int month){
	if(month<=12 && month>=1) (*this).month = month;
}
void Date::setYear(int year){
	(*this).year = year;
}

int Date::getDate(){
	return date;
}
int Date::getMonth(){
	return month;
}
int Date::getYear(){
	return year;
}

void Date::displayDate(){
	cout<<month<<"/"<<date<<"/"<<year;
}

int Date::diffDay(Date D){
	int t1 = calDays();
	int t2 = D.calDays();
	
	return t2 - t1+1;
}	

Date::~Date()
{
}

ostream& operator << (ostream& output,Date& d){
	output<<d.month;
	output<<"/";
	output<<d.date;
	output<<"/";
	output<<d.year;
	return output;
}

istream& operator >>(istream& input, Date& d){
	int t;
	cout<<"Enter Date ";input>>t;d.setDate(t);
	cout<<"Enter Month ";input>>t;d.setMonth(t);
	cout<<"Enter Year ";input>>t;d.setYear(t);
	return input; 
}
