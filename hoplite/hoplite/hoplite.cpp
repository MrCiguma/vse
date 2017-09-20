// hoplite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

ofstream ofs("output.txt");

int polje[5][25] = { 0 };
int dmg[5][25] = { 0 };
int x;

void move(int a1, int a2, int b1, int b2) {
	polje[b1][b2] = polje[a1][a2];
	polje[a1][a2] = 0;
}
void attack(int a1, int a2, int b1, int b2) {
	polje[b1][b2] = max(polje[b1][b2]-dmg[a1][a2], 0);
}
void printtable(int x) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4-i; j++) {
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++) {
			if (polje[j][i] == 0) {
				cout << "*";
			}
			else {
				cout << polje[j][i];
			}
			cout << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < 4; j++) {
		int i = 5;
		cout << " ";
		if (polje[j][i] == 0) {
			cout << "*";
		}
		else {
			cout << polje[j][i];
		}
	}
	cout << endl;
	for (int i = 0; i < (x / 2); i++) {
		i = 2*i + 6;
		for (int j = 0; j < 5; j++) {
			if (polje[j][i] == 0) {
				cout << "*";
			}
			else {
				cout << polje[j][i];
			}
			cout << " ";
		}
		cout << endl;
		for (int j = 0; j < 4; j++) {
			cout << " ";
			if (polje[j][i+1] == 0) {
				cout << "*";
			}
			else {
				cout << polje[j][i+1];
			}
		}
		cout << endl;
		i = (i - 6) / 2;
	}
	for(int i=5;i>0;i--){
		i = x + 11 - i;
		for (int j = 0; j < 5-i; j++) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			if (polje[j][i] == 0) {
				cout << "*";
			}
			else {
				cout << polje[j][i];
			}
			cout << " ";
		}
		cout << endl;
		i = x + 11 - i;
	}
}

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int ok = 0;
	cout << "To je igra hoplite. Prosim izberite višino polja. Le-ta naj bo liho število, ki je >=11 in <=25";
	do {
		cin >> x;
		if (x < 11) {
			ok = 1;
		}
		if (x > 25) {
			ok = 1;
		}
		if (x % 2 == 0) {
			ok = 1;
		}
	} while (ok == 1);
	x = x - 11;
	printtable(x);
	


    return 0;
}

