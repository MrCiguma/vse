// Zoom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Zoom(string s, double x1, double y1, double x2, double y2) {
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i)==48||s.at(i)==50) {
			x2 = (x1 + x2) / 2;
		}
		else {
			x1 = (x1 + x2) / 2;
		}
		if (s.at(i)==48||s.at(i)==49) {
			y1 = (y1 + y2) / 2;
		}
		else {
			y2 = (y1 + y2) / 2;
		}

	}
	cout << s << " " << x1 << " " << y1 << " " << x2 << " " << y2;
}

int main()
{
	string s;
	double x1;
	double y1;
	double x2;
	double y2;
	cin >> s;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	Zoom(s, x1, y1, x2, y2);

    return 0;
}

