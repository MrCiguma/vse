// multiples35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int change;
	for (int i = 0; i < 1000; i++) {       //to pomeni da gre skozi vse stevilke od 0 do 999
		                    
		if (i % 3 == 0) {                  //pogleda ce je deljivo s 3, doda vsoti stevilko in that case.
			sum = sum + i;
			change = 1;                    //shrani, da je za to stevilo ze pristel zraven. to je pomembno recimo pri 15,
		}                                  //ker je deljivo s 3 pa 5 pa bi lahko drugace dvakrat ga poleg pristel
		if (change == 0 & i % 5 == 0) {    //pogleda ce stevilo ni blo deljivo s 3, in ce je deljivo s 5. in that case doda. k vsoti
			sum = sum + i;
		}
		change = 0;                        //resetira predn gre na naslednjo stevilo.
	} 

	cout << sum;                           //izpise vsoto

    return 0;
}

