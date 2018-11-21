#ifndef DATE_H
#define DATE_H
#include<iostream>

using namespace std;
class Date
{
	int month;
	int date;
	int year;
	int calDays();
	public:
		Date();
		Date(int month,int date,int year);
		void setDate(int date);
		void setMonth(int month);
		void setYear(int year);
		int getDate();
		int getMonth();
		int getYear();
		void displayDate();
		friend ostream& operator << (ostream&,Date&);
		friend istream& operator >>(istream&,Date&);
		int diffDay(Date D);
		~Date();
	protected:
};

#endif
