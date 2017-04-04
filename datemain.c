#include <iostream>
#include "Date.h"

int main()
{
	Date d;
	Date d1(2012, 2, 10);
	long n = d1;
	Date d2(d1);
	Date d3(n);
	cout << d3 << endl;
	d3 = n - 1;
	d2 = d3;
	cout << d2 << endl;
	d2--;
	cout << d2 << endl;
	d2.Set_day(7);
	cout << d2 << endl;
	
	
	return 0; 
}
