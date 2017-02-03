//============================================================================
// Name        : SpecialPythagoreanTriplet.cpp
// Author      : Bryan Foley
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <cmath>
#include <math.h>
#include <time.h>

using namespace std;

int main(){

    int a,b,c=0;
    int sum = 1000;

    for (a = 1; a<sum/3; a++){
    	for (b = a; b<sum/2; b++){
    		c = sum - (b+a);
    		if(a*a + b*b == c*c){
    			break;
    		}
    	}
    	if (a*a + b*b == c*c){
    	    break;
    	}
    }
    cout << a*b*c << endl;

	return 0;
}

