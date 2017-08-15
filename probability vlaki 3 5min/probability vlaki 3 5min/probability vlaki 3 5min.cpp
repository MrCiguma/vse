// probability vlaki 3 5min.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	double a;
	double b;
	double c;
	double average=0;
	for (double i = 0; i < 100000000; i++) {
		a = rand() * 3 / 32768.00;
		b = rand() * 5 / 32768.00;
		if (a < b) {
			c = a;
		}
		else {
			c = b;
		}
		average = (average*i + c) / (i + 1);
	}
	cout << average;
	cin >> a;

    return 0;
}

