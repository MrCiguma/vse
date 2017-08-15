// klondike.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;


int main()
{
	int f;
	int a;
	int l;
	int k = 1;
	int i;
	int j;
	int w;   //sirina mreze
	int h;   //visina mreze
	ifstream ifs("klondike10.in");
	ofstream ofs("klondike10.out");
	ifs >> w >> h;  //w pa h dobi
	static int razdalja[1000][1000] = { 0 };
	static int tabela[1000][1000];
	for (i = 0; i < h; i++) {                       //prepise v tabelo, zadnji je na h-1, w-1
		for (j = 0; j < w; j++) {
			ifs >> tabela[i][j];
		}
	}
	for (j = 0; j < w - 1; j++) {
		if (w != j) {
			if (w > j) {
				a = w - j -1;
			}
			else {
				a = j - w-1;
			}
			if (a == tabela[h - 1][j]) {
				razdalja[h - 1][j] = 1;
			}
			else continue;
		}
		else continue;
	}
	for (j = 0; j < h - 1; j++) {
		if (h != j) {
			if (h > j) {
				a = h - j-1;
			}
			else {
				a = j - h-1;
			}
			if (a == tabela[j][w-1]) {
				razdalja[j][w - 1]=1;
			}
			else continue;
		}
		else continue;
	}
	do {
		for (i = 0; i < h; i++) {                      //vrstice
			for (j = 0; j < w; j++) {                  //stolpci
				if (razdalja[i][j] == k) {  //checka, ce je v polju prava stevilka(aka ko gre pisat dvojke poisce kje so enke v tabeli)
					for (l = 0; l < w; l++) {          //gre skozi vse v isti vrstici
						if (j != l) {
							if (j > l) {
								a = j - l;
							}
							else {
								a = l - j;
							}
							if (a == tabela[i][l]) {
								if (razdalja[i][l] == 0) {
									razdalja[i][l] = k + 1;
								}
								else continue;
							}
							else continue;
						}
						else continue;
					}
					for (l = 0; l < h; l++) {         //gre skozi vse v istem stolpcu
						if (i != l) {
							if (i > l) {
								a = i - l;
							}
							else {
								a = l - i;
							}
							if (a == tabela[l][j]) {
								if (razdalja[l][j] == 0) {
									razdalja[l][j] = k + 1;
								}
								else continue;
							}
							else continue;
						}
						else continue;
					}

				}
				else continue;
			}
		}
		k = k + 1;
		ofs << k << '\n';
	} while (razdalja[0][0] == 0);
	if (razdalja[0][0] == 0) {
		ofs << "-1" << '\n';
	}
	else {
		ofs << razdalja[0][0] << '\n';
	}
	return 0;
}

