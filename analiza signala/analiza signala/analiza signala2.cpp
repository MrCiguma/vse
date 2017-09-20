#include "stdafx.h"
#include <fstream>
using namespace std;




int main2()
{
	static int podatki[10000];
	static int rezultat[10000];
	int n;
	int neznani;
	ifstream ifs("signal02.in");
	ofstream ofs("signal02.out");
	ifs >> n;
	for (int i = 0; i < n; i++) {
		ifs >> podatki[i];
	}
	for (int i = 0; i < 10000; i++) {
		rezultat[i]--;
	}
	neznani = podatki[0];
	for (int i = 1; i < n; i++) {
		if (rezultat[i] == -1) {
			for (int j = 1; j <= i; j++) {
				if (rezultat[i*j] == -1) {
					if (i*j <= n - 1) {
						if (j == 1) {
							if (i == 1) {
								rezultat[i*j] = podatki[i*j];
								neznani = neznani - rezultat[i*j];
								ofs << neznani << ' ' << i << j;
							}
							else {
								rezultat[i*j] = podatki[i] - podatki[1];
								neznani = neznani - rezultat[i*j];
								ofs << neznani << ' ' << i << j;
							}
						}
						else {
							if (j == i) {
								rezultat[i*j] = podatki[i*j] - podatki[i];
								neznani = neznani - rezultat[i*j];
								ofs << neznani << ' ' << i << j;
							}
							else {
								rezultat[i*j] = podatki[i*j] - podatki[i] - podatki[j] + podatki[1];
								neznani = neznani - rezultat[i*j];
								ofs << neznani << ' ' << i << j;
							}
						}
					}
				}
			}
		}
	}
	ofs << podatki[0] << ' ' << neznani << '\n';
	for (int i = 1; i < n; i++) {
		if (rezultat[i] > 0) {
			ofs << i << ' ' << rezultat[i] << '\n';
		}
	}

	return 0;
}