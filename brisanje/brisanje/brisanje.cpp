// brisanje.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	
	static int shranjeno[1000];
	int used[26];
	static int razdalja[1000];
	int a;
	char c;
	char d = 0;
	int n;
	int sum;
	int x;
	int brisanja = 0;
	int counter = 0;
	int counter2 = 0;
	int lock = 0;
	int lokacija1 = 0;
	int lokacija2 = 0;
	ifs >> n;
	for (int i = 0; i < n; i++) {
		ifs >> c;
		if (c != d) {
			a = c - 96;
			shranjeno[counter] = a;
			counter++;
		}
		d = c;
	}
	for (int i = 0; i < counter; i++) {
		ofs << shranjeno[i] << ' ';
	}
	ofs << n<<'\n';
	
	int min;
	do {
		min = counter;
		for (int i = 0; i < counter; i++) {
			counter2 = 0;
			for (int j = i + 1; j < counter; j++) {
				if (shranjeno[i] == shranjeno[j]) {
					if (counter2 < min&&counter2>0) {
						min = counter2;
						lokacija1 = i;
						lokacija2 = j;
						if (min == 1) {
							i = counter;
						}
					}
					j = counter;
				}
				else {
					counter2++;
				}
				ofs << i << ' ' << j << ' ' << min << ' ' << lokacija1 << ' ' << lokacija2 << '\n';
			}
		}
		x = lokacija2 - lokacija1;
		counter = counter - x;
		brisanja=brisanja+x-1;
		sum = 0;
		for (int i = lokacija1 + 1; i < counter + x; i++) {
			shranjeno[i] = shranjeno[i + x];
			shranjeno[i + x] = 0;
		}
		for (int i = 0; i < counter; i++) {
			sum = sum + shranjeno[i];
		}
		for (int i = 0; i < counter; i++){
			ofs << shranjeno[i] << ' ';
		}
		ofs << '\n' << sum << ' ' << brisanja<<' '<<counter << '\n';
	} while (sum != 0);
	ofs << brisanja;
    return 0;
}

