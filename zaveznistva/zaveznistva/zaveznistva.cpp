// zaveznistva.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int max[50] = { 0 };
	int trenutno[50] = { 0 };
	static int shranjeno[50][7500] = { 0 };
	int stplanetov;
	int stpolozajev;
	char a;
	ifs >> stplanetov;
	ifs >> stpolozajev;
	int zaveznistvo[3] = { 0 };

	for (int i = 0; i < stplanetov; i++) {
		for (int j = 0; j < stpolozajev; j++) {
			ifs >> a;
			shranjeno[j][i] = a-48;
		}
	}
	for (int i = 0; i < stplanetov - 2; i++) {
		for (int j = i + 1; j < stplanetov - 1; j++) {
			for (int l = j + 1; l < stplanetov; l++) {
				for (int k = 0; k < stpolozajev; k++) {
					trenutno[k] = (shranjeno[k][i] + shranjeno[k][j] + shranjeno[k][l]) % 2;
				}
				for (int k = 0; k < stpolozajev; k++) {
					if (trenutno[k] < max[k]) {
						k = stpolozajev;
					}
					else {
						if (trenutno[k] > max[k]) {
							for (k = 0; k < stpolozajev; k++) {
								max[k] = trenutno[k];
							}
							k = stpolozajev;
							zaveznistvo[0] = i+1;
							zaveznistvo[1] = j+1;
							zaveznistvo[2] = l+1;
						}
						else continue;
					}
				}
			}
		}
	}
	ofs << zaveznistvo[0] << ' ' << zaveznistvo[1] << ' ' << zaveznistvo[2] << '\n';
	for (int k = 0; k < stpolozajev; k++) {
		ofs << max[k];
	}

    return 0;
}

