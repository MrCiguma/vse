// reader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int a;
	int b;
	ifstream ifs("poskus.in");
	ifs >> a >> b;
	ifs.close();
	ofstream ofs("poskus.out");
	ofs << 10 * (a + b) << '\n';
	ofs.close();

    return 0;
}

