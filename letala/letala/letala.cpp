// letala.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int stletal;
	int stzaboj;
	ifs >> stzaboj;
	ifs >> stletal;
	static float saved = stzaboj/stletal;
	static float zaboji[100000];
	static float letala[100000];
	for (int i = 0; i < stzaboj; i++) {
		ifs >> zaboji[i];
	}
	for (int i = 0; i < stletal; i++) {
		ifs >> letala[i];
	}
	sort(letala, letala + stletal);
	sort(zaboji, zaboji + stzaboj);
	for (int i = 0; i < stzaboj; i++) {
		ofs << zaboji[i]<<' ';
	}
	ofs << '\n';
	for (int i = 0; i < stletal; i++) {
		ofs << letala[i]<<' ';
	}

	float stletal2 = stletal;
	float stzaboj2 = stzaboj;
	if (zaboji[0] <= letala[0]) {
		for (int i = 0; i < stletal2-1; i++) {
			for (int j = 0; j < stzaboj2-1; j++) {
				if (letala[i] >= zaboji[j]) {
					continue;
				}
				else {
					if ((stzaboj2 - j) / (stletal2 - i-1) >= saved) {
						saved =ceil((stzaboj2 - j)/(stletal2 - i-1));
						ofs <<saved<<' '<< i << ' ' << j << '\n';
						j = stzaboj2 + 1;
					}
				}
			}
		}
		ofs << saved << ' ' << stzaboj << ' ' << stletal;
	}
	else {
		ofs << "ne gre";
	}
    return 0;
}

