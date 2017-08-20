// analiza enot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


int main()
{
	int stevilokolicin;
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	ifs >> stevilokolicin;
	string crke;
	int shranjeno[26][26] = { 0 };
	int enacba[26] = { 0 };
	int rezultat[26] = { 0 };
	int c;
	char c4;
	char c3;
	int c2 = 0;
	int c5;
	for(int i=0;i<stevilokolicin;i++){
		ifs >> c4;
		c = c4-97;
		int plusminus = 1;
		while (c2 != 10); {
			ifs >> c3;
			c2 = c3;
			ofs << c2 << ' ';
			if (c2 <= 122 && c2 >= 97) {
				c5 = c2 - 97;
				shranjeno[c][c5] = shranjeno[c][c5] + plusminus;
			}
			else continue;
			if (c2 == 47) {
				plusminus = plusminus*(-1);
			}
			else continue;
		}
	}
	int plusminus = 1;
	ifs >> c3;
	c2 = c3;
	if (c2 <= 122 && c2 >= 97) {
		enacba[c2] = enacba[2] + plusminus;
	}
	if (c2 == 47) {
		plusminus = plusminus*(-1);
	}

	for (int i = 0; i < 26; i++) {
		if (enacba[i] != 0) {
			for (int j = 0; j < 26; j++) {
				rezultat[j] = rezultat[j] + enacba[i] * (shranjeno[i][j]);
			}
		}
		else continue;
	}
	int i;
	for (i = 0; i < 26; i++) {
		if (rezultat[i] == 0) {
			continue;
		}
		else {
			ofs << "nope";
			i = 27;
		}
	}

	if (i == 26) {
		ofs << "yes";
	}

	for (i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			ofs << shranjeno[i][j];
		}
		ofs << '\n';
	}

    return 0;
}

