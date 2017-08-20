// H-indeks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int clanki[100] = { 0 };
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int i = 0;
	int resitev = 0;
	do {
		ifs >> clanki[i];
		i++;
	} while (i < 100);
	sort(clanki, clanki + 99);
	reverse(clanki, clanki + 99);
	for (int i = 0; i < 100; i++) {
		if (clanki[i] >= i + 1) {
			continue;
		}
		else {
			ofs << i;
			i = 100;
		}
	}

    return 0;
}

