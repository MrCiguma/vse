// analiza signala.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
using namespace std;

int main()
{
	static int podatki[100000];
	int n;
	int neznani;
	ifstream ifs("signal10.in");
	ofstream ofs("signal10.out");
	ifs >> n;
	for (int i = 0; i < n; i++) {
		ifs >> podatki[i];
	}
	neznani = podatki[0];
	for (int i = 1; i < n; i++) {
		for (int j = 2; j <= n / i; j++) {
			podatki[i*j] = podatki[i*j] - podatki[i];
		}
		neznani = neznani - podatki[i];
	}
	ofs << podatki[0] << ' ' << neznani << '\n';
	for (int i = 1; i < n; i++) {
		if (podatki[i] > 0) {
			ofs << i << ' ' << podatki[i] << '\n';
		}
	}
	return 0;
}

