// nim.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a; //izbran stolpec
	int b; //st. zetonov
	int c; //check za kje je prva enka v binarnem sum
	int d; //2 na neko potenco, oznaci tam kje je treba prvo spremenit
	int e; //preveri ce je neko stevilo vredu po modulu d
	int n; //st.stolpcev
	int i;
	int j;
	int y; //st. vzetih zetonov
	int x; //st. zetonov na novo
	int m = 0; //maximum
	int p; // maximuma v arrayu
	int zetoni[10] = { 0 };
	int reduce[10] = { 0 };
	int stevke[6] = { 0 };
	int max[6] = { 0 };
	int dif[6] = { 0 };

	cout << "Nim je igra s nekim stevilom stolpcev, vsak ima poljubno stevilo zetonov. Dva igralca izmenicno izbereta stolpec in iz njega vzameta neko stevilo zetonov. Zmaga tisti, ki vzame zadnji zeton." << endl;

	for (i = 1; i < 2; i++) {
		cout << "Vnesite st. stolpcev" << endl;
		cin >> n;                                                                              //vnese stevilo stolpcev
		if (n == 0 || n > 10) {
			cout << "prosim vnesite stevilo med 1 in 10" << endl;
			i--;
		}
		else {
			continue;
		}
	}


	for (i = 0; i < n; i++) {                                                              //vnese stevila zetonov
		cout << "st. zetonov v " << i + 1 << ". stolpcu je:" << endl;
		cin >> zetoni[i];
		if (zetoni[i] >= 64) {
			cout << "prosim izberite st. manjse od 64" << endl;
			i--;
		}
		else {
			continue;
		}
	}

	for (i = 0; i < n; i++) {                                                              //naredi reduce array isti ko zetoni array
		reduce[i] = zetoni[i];
	}

	for (j = 0; j <= 5; j++) {                                                              //gre skozi 6 binarnih mest, najprej skozi najvecjo
		for (i = 0; i < n; i++) {                                                          //gre skozi vse stolpce
			if (reduce[i] >= pow(2, 5 - j)) {                                                //preveri, ce ma stolpec vec kot 0 na mestu, v tem primeru spremeni stevke[j] po mod 2
				stevke[j]++;
				stevke[j] = stevke[j] % 2;
				reduce[i] = reduce[i] - (pow(2, 5 - j));                                   //reduce zniza, odreze prvo stevilko iz binarnega zapisa
			}
			else {
				continue;
			}
		}
	}
	if (stevke[0] + stevke[1] + stevke[2] + stevke[3] + stevke[4] + stevke[5] == 0) {
		cout << "Zacnite vi." << endl;
		cout << "Izberite stevilo stolpca: " << endl;
		cin >> a;
		cout << endl << "izberite stevilo zetonov, ki jih vzamete" << endl;
		cin >> b;
		zetoni[a - 1] = zetoni[a - 1] - b;
	}
	else {
		cout << "Zacel bom jaz. " << endl;
	}
	do {
		for (i = 0; i < n; i++) {                                                              //naredi reduce array isti ko zetoni array
				reduce[i] = zetoni[i];
			}
			for (j = 0; j <= 5; j++) {                                                               //nastavi arraye na 0, tako morejo bit
				stevke[j] = 0;
				max[j] = 0;
				dif[j] = 0;
			}

			for (j = 0; j <= 5; j++) {                                                              //gre skozi 6 binarnih mest, najprej skozi najvecjo
				for (i = 0; i < n; i++) {                                                          //gre skozi vse stolpce
					if (reduce[i] >= pow(2, 5 - j)) {                                                //preveri, ce ma stolpec vec kot 0 na mestu, v tem primeru spremeni stevke[j] po mod 2
						stevke[j]++;
						stevke[j] = stevke[j] % 2;
						reduce[i] = reduce[i] - (pow(2, 5 - j));                                   //reduce zniza, odreze prvo stevilko iz binarnega zapisa
					}
					else {
						continue;
					}
				}
			}

			for (j = 0; j <= 5; j++) {                                                            //poisce prvo enko v stevkah
				if (stevke[j] != 0) {
					c = j;
					j = 6;
				}
				else {
					continue;
				}
			}

			d = (pow(2, 6 - c));
			e = (pow(2, 5 - c));

			for (i = 0; i < n; i++) {
				if (zetoni[i] % d>= e) {
					p = i + 1;
					m = zetoni[i];
					i = n;
				}
				else {
					continue;
				}
			}
					
			for (j = 0; j <= 5; j++) {                                                             //napise kupcek iz kerega bo jemo v max array binarno
				if (m >= pow(2, 5 - j)) {
					max[j]++;
					m = m - pow(2, 5 - j);
				}
				else {
					continue;
				}
			}
			for (j = 0; j <= 5; j++) {                                                              //napise binarni zapis od nove vrednosti stolpca iz kerega jemlje
				dif[j] = (stevke[j] + max[j]) % 2;
			}

			x = (dif[0] * 32) + (dif[1] * 16) + (dif[2] * 8) + (dif[3] * 4) + (dif[4] * 2) + (dif[5]);        //nova vrednost najvecjega stolpca
			y = zetoni[p - 1] - x;                                                                          //stevilo vzetih zetonov
			zetoni[p - 1] = x;

			cout << "Iz stolpca stevilka " << p << " vzamem "<< y <<" zetonov." << endl;
			cout << "Trenutno stanje je: " << endl;
			for (i = 0; i < n; i++) {
				cout << zetoni[i] << " ";
			}
			cout << endl;
			if (zetoni[0] + zetoni[1] + zetoni[2] + zetoni[3] + zetoni[4] == 0) {
				continue;
			}
			else {
				for (i = 1; i < 2; i++) {
					cout << "Vnesite st. stolpca" << endl;
					cin >> a;                                                                              //vnese stevilo stolpcev
					if (a == 0 || a > n) {
						cout << "prosim vnesite stevilo med 1 in stevilom stolpcev" << endl;
						i--;
					}
					else {
						continue;
					}
				}
				for (i = 1; i < 2; i++) {
					cout << "izberite stevilo zetonov, ki jih vzamete" << endl;
					cin >> b;                                                                              //vnese stevilo stolpcev
					if (b == 0 || b > zetoni[a-1]){
						cout << "prosim vnesite stevilo med 1 in " << zetoni[a-1] <<endl;
						i--;
					}
					else {
						zetoni[a - 1] = zetoni[a - 1] - b;
						continue;
					}
					
				}
				cout << "Trenutno stanje je: " << endl;
				for (i = 0; i < n; i++) {
					cout << zetoni[i] << " ";
				}
				cout << endl;
			}

		} while (zetoni[0] + zetoni[1] + zetoni[2] + zetoni[3] + zetoni[4] != 0);

		cout << endl << "Game over, you lost" << endl;

		return 0;
	}
