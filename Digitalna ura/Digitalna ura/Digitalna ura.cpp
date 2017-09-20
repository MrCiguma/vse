// Digitalna ura.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int ura[4][7];

void Spremeni(int stevka, int segment) {
	ura[stevka-1][segment-1]=(ura[stevka-1][segment-1]+1)%2;
}

void Osvezi(int h, int min) {
	if (min % 10 == 9) {
		Spremeni(4, 4);
		Spremeni(4, 5);
		if (min == 59) {
			Spremeni(3, 3);
			Spremeni(3, 4);
			Spremeni(3, 5);
			if (h % 10 == 9) {
				Spremeni(2, 4);
				Spremeni(2, 5);
			}
			if (h == 23) {
				Spremeni(2, 2);
				Spremeni(2, 4);
				Spremeni(2, 5);
			}
		}
	}
	else {

	}

}

int main()
{
	int ura[4][7];

    return 0;
}


