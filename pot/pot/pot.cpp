// pot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int mesta;
	static int podatki[3][1000000];
	static int newlvl1[10000] = { mesta };
	static int newlvl2[10000] = { 0 };
	static int oddaljenost[1000000] = { 0 };
	int oddaljenost1;
	int counter=0;
	int counter1;
	int counter2;
	ifstream ifs("pot.in");
	ofstream ofs("pot.out");
	int ceste;
	ifs >> mesta >> ceste;
	for (int i = 0; i < ceste; i++) {
		ifs >> podatki[0][i] >> podatki[1][i] >> podatki[2][i];
	}
	do {
		for (int i = 0; i < counter1; i++) {                     //skozi newlvl1
			for (int j = 0; j < ceste; j++) {                     //skozi vse ceste
				if (podatki[0][j] == newlvl1[i]) {                 //ce je mesto del podatka, drugo mesto v podatku shrani v newlvl2
					if (oddaljenost[podatki[0][j]] != 0) {
						newlvl2[counter2] = podatki[1][j];
						counter2++;
						oddaljenost[podatki[0][j]] = oddaljenost1;
					}
					else continue;
				}
				else if (podatki[1][j] == newlvl1[i]) {
					if (oddaljenost[podatki[0][j]] != 0) {
						newlvl2[counter2] = podatki[0][j];
						counter2++;
						oddaljenost[podatki[1][j]] = oddaljenost1;
					}
					else continue;
				}
			}
		}
		for (int i = 0; i < 10000; i++) {
			newlvl1[i] = newlvl2[i];
		}
		oddaljenost1++;
	} while (oddaljenost[0] == 0);
	


	return 0;
}

