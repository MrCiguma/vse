// reader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	char c;
	int d;
	for(int i=0; i<9;i++){
		ifs.get(c);
		d = c;
		ofs << d << ' ';
	}
}