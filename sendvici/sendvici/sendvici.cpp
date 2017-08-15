// sendvici.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int i;
	int a;
	int c=1;
	int zaloga[6];
	int zahteva[6] = { 0 };

	for (i = 1; i <= 6; i++) {
		cout << "Zaloga sendvicev st. " << i << ": ";
		cin >> zaloga[i - 1];
		cout << endl;
	}
	for (i = 1; i <= 6; i++) {
		zaloga[i - 1]++;
	}

	do {
		cout << "Pozdravljeni, kateri sendvic zelite? ";
		cin >> a;
		if (a == 0) {
			continue;
		}
		else {
			zahteva[a - 1]++;
			if (zaloga[a - 1] >= 2) {                                                                      //zmanjsa zalogo ce ma sendvic
				cout << "Izvolite sendvic st. " << a << ". Dober tek!" << endl;
				zaloga[a - 1] = zaloga[a - 1] - 1;
			}
			else {                                                                                         //zmanjsa ko je sendvic zahtevan in manjka, prvic
				cout << "Sendvicev tipa " << a << " nam je zal zmanjkalo. Vec srece prihodnjic!" << endl;
				if (zaloga[a - 1] == 1) {
					zaloga[a - 1] = zaloga[a - 1] - 1;
				}
				else{                                                                                      //ostane na istem ce je sendvic zahtevan in manjka veckrat
					continue;
				}
			}
		}
	} while (a != 0);
	cout << "Premalo je bilo sendvicev st. ";
	for (i = 1; i <= 6; i++) {
		if (zaloga[i - 1] == 0) {
			cout << i << " ";
		}
		else {
			continue;
		}
	}
	cout << endl << "Najbolj popularni so sendvici st. ";
	for (i = 1; i <= 6; i++) {
		if (zahteva[i - 1] >= c) {
			c = zahteva[i - 1];
		}
		else continue;
	}
	for (i = 1; i <= 6; i++) {
		if (zahteva[i - 1] == c) {
			cout << i << " ";
		}
		else continue;
	}
    return 0;
}

