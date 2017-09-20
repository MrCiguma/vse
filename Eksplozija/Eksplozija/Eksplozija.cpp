// Eksplozija.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	static int koordinate[2][25];
	static int sorted[2][25];
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	for (int i = 0; i < 25; i++) {
		ifs >> koordinate[0][i] >> koordinate[1][i];
		sorted[0][i] = koordinate[0][i];
		sorted[1][i] = koordinate[1][i];
	}
	sort(sorted[0], sorted[0] + 25);


    return 0;
}

