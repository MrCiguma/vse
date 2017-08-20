// Izstevanka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int zivljenja[100] = { 0 };
	for (int i = 0; i < 100; i++) {
		zivljenja[i]++;
		zivljenja[i]++;
	}
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int stevilo;
	int korakov;
	ifs >> stevilo >> korakov;
	int pozicija = 0;
	int checker = 0;
	
	do {
		checker = 0;
		pozicija = (pozicija + korakov)%stevilo;
		zivljenja[pozicija]--;
		korakov++;
		if (zivljenja[pozicija] == 0) {
			checker = 1;
		}
		else continue;
	} while (checker == 0);
	pozicija++;
	ofs << pozicija;
    return 0;
}

