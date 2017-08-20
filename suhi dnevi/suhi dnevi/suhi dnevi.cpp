// suhi dnevi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	string datum1;
	string datum2;
	int kolicina;
	int kolicinaskupno=0;
	int suhi=0;
	int zaporedni=0;
	int saved=0;
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	ifs >> datum1;
	do {
		ifs >> kolicina;
		datum2 = "string";
		ifs >> datum2;
		kolicinaskupno = kolicinaskupno + kolicina;
		if (datum2 == datum1) {
			continue;
		}
		else {
			if (kolicinaskupno == 0) {
				zaporedni++;
				suhi++;
				if (zaporedni > saved) {
					saved = zaporedni;
				}
			}
			else {
				zaporedni = 0;
				kolicinaskupno = 0;
			}
		}
		datum1 = datum2;
	} while (datum2!="string");

	ofs << suhi << ' ' << saved;

	return 0;
}

