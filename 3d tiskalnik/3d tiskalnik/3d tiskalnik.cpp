// 3d tiskalnik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;



int main()
{
	static int tabela[1001][1001][2] = { 0 };
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	int x, y, z;
	ifs >> x >>  y >>  z;
	for (int j = 0; j < y; j++) {
		for (int l = 0; l < x; l++) {
			ifs >> tabela[l][j][0];
		}
	}

	int i, j, l;
	for (i = 1; i < z; i++) {
		for (j = 0; j < y; j++) {
			for (l = 0; l < x; l++) {
				ifs >> tabela[l][j][1];
			}
		}
		for (j = 0; j < y; j++) {
			for (l = 0; l < x; l++) {
				if (tabela[l][j][1] == 1) {
					if (tabela[l][j][0] == 1 || tabela[l + 1][j][1] == 1 || tabela[l][j + 1][1] == 1) {
						continue;
					}
					else {
						ofs << "ne gre " << l << ' ' << j << ' ' << i;
						i = z + 1;
					}
				}
			}
		}
		
		
		for (j = 0; j < y; j++) {
			for (l = 0; l < x; l++) {
				tabela[l][j][0] = tabela[l][j][1];
			}
		}
	}
	if (i == z) {
		ofs << "gre";
	}

    return 0;
}

