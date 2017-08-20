// tipkanje.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include <fstream>
#include <iostream>
#include <math.h>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;


int main()
{
	string beseda1;
	string beseda2;
	ifstream ifs("besede.txt");
	ofstream ofs("output.txt");
	int vrstice;
	int checker=0;
	ifs >> vrstice;
	ifs >> beseda1;
	int znaki = 0;
	znaki = 2*beseda1.length()+1;
	for(int i=0;i<vrstice-1;i++){
		ifs >> beseda2;
		znaki = znaki + 2 * beseda2.length()+1;
		for (int j = 0; j < MIN(beseda1.length(),beseda2.length()); j++) {
			if (beseda1.at(j) == beseda2.at(j)) {
				znaki = znaki - 2;
				checker++;
			}
			else {
				j = beseda1.length();
			}

		}
	}
	znaki = znaki - beseda2.length();
	ofs << znaki << " " << checker;

    return 0;
}

