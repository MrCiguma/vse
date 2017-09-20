// Kompresija.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int i = 1;
	int n;
	ifs >> n;
	int k = 0;
	int a = 0;
	int b = 0;
	do {
		ifs >> a;
		if (a==b) {
			i++;
		}
		else {
			i = 1;
		}
		if (i%2 == 1) {
			ofs << a<<' ';
		}
		b = a;
		k++;
	} while (k < n);

    return 0;
}

