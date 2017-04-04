#include "Date.h"
const int Date::dys[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(long ndays)
{
	if(ndays == 0)
		yr = mo = day = 0;
	else
	{
		day = ndays;
		yr = 1;
		while(1)
		{
			int n = Leapyear(yr) ? 366: 365;
			if(day <= n)
				break;
			day -= n;
			++yr;
		}
		for(mo = 1; mo < 13; mo++)
		{
			int n = dys[mo - 1];
			if(mo == 2 && Leapyear(yr))
				n++;
			if(day <= n)
				break;
			day -= n;
		}
	}
}

Date & Date::operator=(long ndays)
{
	if(ndays == 0)
		yr = mo = day = 0;
	else
	{
		day = ndays;
		yr = 1;
		while(1)
		{
			int n = Leapyear(yr) ? 366: 365;
			if(day <= n)
				break;
			day -= n;
			++yr;
		}
		for(mo = 1; mo < 13; mo++)
		{
			int n = dys[mo - 1];
			if(mo == 2 && Leapyear(yr))
				n++;
			if(day <= n)
				break;
			day -= n;
		}
	}
	
	return *this;
}

Date::operator long() const
{
	long ndays = 0;
	for(int i = 1; i < yr; ++i)
		ndays += Leapyear(i) ? 366 : 365;
	for(int i = 1; i < mo; ++i)
		ndays += dys[i - 1];
	if(mo > 2 && Leapyear(yr))
		++ndays;
	ndays += day;
	
	return ndays;
}

Date & Date::operator++()
{
	long ndays = * this;
	++ndays;
	*this = ndays;
	
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);
	long ndays = *this;
	++ndays;
	*this = ndays;
	
	return temp;
}

Date & Date::operator--()
{
	long ndays = *this;
	--ndays;
	*this = ndays;
	
	return *this;
}

Date Date::operator--(int)
{
	Date temp(*this);
	long ndays = *this;
	--ndays;
	*this = ndays;
	
	return temp; 
}

Date & Date::operator+=(int n)
{
	long ndays = *this;
	ndays += n;
	*this = ndays;
	
	return *this;
}

Date & Date::operator-=(int n)
{
	long ndays = *this;
	ndays -= n;
	*this = ndays;
	
	return *this;
}

istream & operator>>(istream & istr, Date & dt)
{
	istr >> dt.yr >> dt.mo >> dt.day;
	
	return istr;
}

ostream & operator<<(ostream & ostr, const Date & dt)
{
	ostr << dt.yr << '/' << dt.mo << '/' << dt.day;
	
	return ostr; 
}
