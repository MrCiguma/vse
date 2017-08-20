// zaklepajski izrazi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void Dopolni(string s) {
	int checker2 = 0;
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	for (int i = s.length()-1; i >= 0; i--) {
		if (s.at(i) == 42){
			int checker = 0;
			for (int j = i + 1; j < s.length(); j++) {
				if (s.at(j) == 41 || s.at(j) == 62 || s.at(j) == 93 || s.at(j) == 125) {
					checker++;
				}
				else {
					checker--;
				}
				if (checker > 0) {
					if (s.at(j) > 50) {
						s.at(i) = s.at(j) - 2;
					}
					else {
						s.at(i) = s.at(j) - 1;
					}
					break;
				}
				else continue;
			}

		}
		else continue;
	}
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 42) {
			ofs << "whoops shit happens" << s;
			break;
			checker2 = 1;
		}
		else continue;
	}
	ofs << s;

}

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	string s;
	ifs >> s;
	Dopolni(s);
    return 0;
}

