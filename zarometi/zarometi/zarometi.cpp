// zarometi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	int i;
	long int j;
	long int n;
	long int q;
	long long int a;
	long int p = 0;
	ifstream ifs("zarometi10.in");
	ofstream ofs("zarometi10.out");
	static long int zarometi[1000000][3];
	ifs >> n;
	for (i = 0; i < n; i++) {            //vpise zaromete v array
		for (j = 0; j < 3; j++) {
			ifs >> zarometi[i][j];
		}
	}
	ifs >> q;
	ifs >> a;

	for (i = 0; i < n; i++) {
		if (a <= zarometi[i][0] + zarometi[i][1] && a >= zarometi[i][0] - zarometi[i][1]) {
			p = p + zarometi[i][2];
		}
		else continue;
	}
	ofs << p << '\n';
	for (j = 0; j < q - 1; j++) {
		ifs >> a;
		a = p + a;
		p = 0;
		for (i = 0; i < n; i++) {
			if (a <= zarometi[i][0] + zarometi[i][1] && a >= zarometi[i][0] - zarometi[i][1]) {
				p = p + zarometi[i][2];
			}
			else continue;
		}
		ofs << p << '\n';
	}


    return 0;
}

