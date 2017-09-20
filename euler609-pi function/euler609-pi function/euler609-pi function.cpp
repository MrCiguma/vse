// euler609-pi function.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int main()
{
	ifstream ifs("primes1.txt");
	ofstream ofs("output.txt");
	int a;
	int x;
	int length;
	static int borders[2049] = { 0 };
	borders[0] = 1;
	static int binary[2049][12] = { -1 };
	binary[0][0] = 0;
	binary[0][1] = 1;
	//ofs << binary[0][0];
	//ofs << binary[0][1];
	ofs << '\n';
	for (int i = 1; i < 2048; i++) {
		length = floor(log2(i+1));
		x = i + 1;
		x = x - pow(2, floor(log2(x)));
		binary[i][length] = 0;
		binary[i][length + 1] = 1;
		//ofs << binary[i][length] << binary[i][length + 1] << ' ';
		for (int j = length-1; j >=0; j--) {
			binary[i][j] = x / pow(2, j);
			x = x - (binary[i][j])*pow(2, j);
			//ofs << binary[i][j];
		}
		//ofs << '\n';
	}
	for (int i = 1; i < 8; i++) {
		borders[i] = i + 1;
	}
	for (int i = 8; i < 2049; i=i+2) {
		for (int j = 0; j < borders[(i / 2)] - borders[(i / 2)-1]; j++) {
			ifs >> a;
		}
		borders[i] = a;
		borders[i + 1] = a + 1;     //should work. next checkaj, pa treba bo skozi vec fileov stevil it, ker so prek 1million.
		if (borders[i] > 100000000) {
			i = 2049;
		}
	}
	for (int i = 1; i < 2049; i++) {
		ofs << i << ' ';
		for (int j = 0; j < 12;j++) {
			ofs << binary[i][j];
		}
		ofs << ' ';
		ofs << borders[i+1] << '\n';
	}
    return 0;
}

