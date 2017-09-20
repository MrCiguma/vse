// Kontrolna naloga.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");
	char c;
	string s;
	int a = 0;
	ifs >> s;
	if (s.length() % 2 == 0) {
		for (int i = 0; i < (s.length()) / 2; i++) {
			if (s.at(i) == 48 || s.at(i) == 49 || s.at(i) == 54 || s.at(i) == 56 || s.at(i) == 57) {
			}
			else {
				if (s.at(i) < 54) {
					s.at(i) = 54;
				}
				else {
					s.at(i) = 56;
				}
			}
			if (s.at(i) == 54) {
				s.at(s.length() - i - 1) = s.at(i)+3;
			}
			if (s.at(i) == 57) {
				s.at(s.length() - i - 1) = s.at(i) - 3;
			}
			if (s.at(i) != 57 && s.at(i) != 54) {
				s.at(s.length() - i - 1) = s.at(i);
			}
		}
	}
	else {
		int i = 0;
		if (s.at((s.length() - 1) / 2) == 57) {
			do {
				i++;
				s.at((s.length() - i) / 2) = 48;
			} while (s.at((s.length() - i-2) / 2) == 57);
			if ((s.at((s.length() - i - 2) / 2) == 48)) {
				(s.at((s.length() - i - 2) / 2)) = 49;
			}
			else {
				if ((s.at((s.length() - i - 2) / 2) < 54)) {
					(s.at((s.length() - i - 2) / 2)) = 54;
				}
				else {
					if ((s.at((s.length() - i - 2) / 2)) == 56) {
						(s.at((s.length() - i - 2) / 2)) = 57;
					}
					else {
						(s.at((s.length() - i - 2) / 2)) = 56;
					}
				}
			}
		}
		else if (s.at((s.length() - 1) / 2!=48&&s.at((s.length() - 1) / 2) != 49)){
			s.at((s.length() - 1) / 2) = 56;
		}
		for (int i = 0; i < (s.length()-1) / 2; i++) {
			if (s.at(i) == 48 || s.at(i) == 49 || s.at(i) == 54 || s.at(i) == 56 || s.at(i) == 57) {
			}
			else {
				if (s.at(i) < 54) {
					s.at(i) = 54;
				}
				else {
					s.at(i) = 56;
				}
			}
			if (s.at(i) == 54) {
				s.at(s.length() - i - 1) = s.at(i) + 3;
			}
			if (s.at(i) == 57) {
				s.at(s.length() - i - 1) = s.at(i) - 3;
			}
			if (s.at(i) != 57 && s.at(i) != 54) {
				s.at(s.length() - i - 1) = s.at(i);
			}
		}
	}
	ofs << s;

    return 0;
}

