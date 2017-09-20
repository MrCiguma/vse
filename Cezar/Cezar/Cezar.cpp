// Cezar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
using namespace std;
int main()
{
	static string shranjeno[1000];
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");

	for (int i = 0; i < 1000; i++) {
		int checker = 0;
		ifs >> shranjeno[i];
		int j;
		for (j = 0; j < i; j++) {
			if (shranjeno[i] == shranjeno[j]) {
				checker = 1;
				break;
			}
		}
		for (int j = 0; j < shranjeno[i].length(); j++) {
			shranjeno[i].at(j) = ((shranjeno[i].at(j) - 84) % 26) + 97;
		}
		if (checker == 1) {
			ofs << shranjeno[i] << ' ' << shranjeno[j] << '\n';
		}
	}


    return 0;
}

