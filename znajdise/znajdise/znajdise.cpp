// znajdise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int podatki[2][25] = { 0 };
	FILE *fp;
	int c;
	fp = fopen("input.txt","r");
	ofstream ofs("output.txt");
	char a;
	int i=0;
	int prvi;
	int zadnji;
	prvi = fgetc(fp);
	zadnji = fgetc(fp);
	zadnji = fgetc(fp);
	do {
		c=fgetc(fp);
		if (c <= 90 && c >= 65) {
			podatki[i%2][i/2] = c;
			i++;
		}
	} while (c != EOF);
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 2; j++) {
			ofs << podatki[j][i] << ' ';
		}
		ofs << '\n';
	}
	do {
		a = prvi;
		ofs << a;
		for (int i = 0; i < 25; i++) {
			if (prvi == podatki[0][i]) {
				prvi = podatki[1][i];
				i = 25;
			}
		}
	} while (prvi != zadnji);
	a = prvi;
	ofs << a;


    return 0;
}

