#ifndef DATE_H_
#define DATE_H_

#include <iostream>
using namespace std;

class Date
{
	int yr, mo, day;
	static const int dys[];
	bool Leapyear(int y) const{ return  (y % 4 == 0 && y % 100 != 0) || (y % 400) == 0;}
public:
	Date() { yr = mo = day = 1; }
	Date(int y, int m, int d) { yr = y; mo = m; day = d;}
	Date(const Date & dt) { yr = dt.yr; mo = dt.mo; day = dt.day;}
	Date(long ndays);
	~Date() {};
	
	Date & operator=(const Date & dt) {yr = dt.yr; mo = dt.mo; day = dt.day; return *this;}
	Date & operator=(long ndays);
	
	operator long() const;
	
	bool Leapyear() const { return Leapyear(yr);}
	
	Date & operator++();
	Date operator++(int);
	Date & operator--();
	Date operator--(int);
	Date & operator+=(int n);
	Date & operator-=(int n);
	
	int Get_year() const { return yr;}
	int Get_month() const { return mo;}
	int Get_day() const { return day;}
	
	void Set_year(int y) { yr = y;}
	void Set_month(int m) { mo = m;}
	void Set_day(int d) { day = d;} 
	
	void Display() const { cout << yr << '/' << mo << '/' << day;}
	
	friend istream & operator>>(istream & istr, Date & dt);
	friend ostream & operator<<(ostream & ostr, const Date & dt);	
};
#endif
