// brisanje.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	
	static int shranjeno[1000];
	int used[26];
	int a;
	char c;
	char d;
	int n;
	int counter = 0;
	int counter2 = 0;
	int lock = 0;
	ifs >> n;
	for (int i = 0; i < n; i++) {
		ifs >> c;
		if (c != d) {
			n = c - 96;
			shranjeno[i] = n;
			counter++;
		}
		d = c;
	}
	for (int i = 0; i < counter; i++) {

	}

    return 0;
}

