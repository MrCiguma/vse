// Delni izid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int delni[2] = { 0 };
	int a;
	int i = 0;
	int n;
	int max = 0;
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	ifs >> n;
	do {
		ifs >> a;
		delni[0] = delni[0] + a;
		if (delni[0] < 0) {
			delni[0] = 0;
		}
		delni[1] = delni[1] - a;
		if (delni[1] < 0) {
			delni[1] = 0;
		}
		if (delni[0] > max) {
			max = delni[0];
		}
		if (delni[1] > max) {
			max = delni[1];
		}
		i++;
	} while (i < n);
	ofs << max;

    return 0;
}

