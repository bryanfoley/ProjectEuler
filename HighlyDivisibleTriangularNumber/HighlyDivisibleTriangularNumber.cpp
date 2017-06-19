//============================================================================
// Name        : HighlyDivisibleTriangularNumber.cpp
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

bool testForPrimeness(int &numbeRef);
template < class T >
void printList(list< T > &listRef);

int main() {
	int n = 1000;
	list <int> primes;
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	time_t start, end;

	for (int i = 3; i+=2;){
		if(testForPrimeness(i)){
			primes.push_back(i);
			if (primes.size() == n){
				break;
			}
		}
	}
    int t=1;
    int a=1;
    int cnt=0;
    int tt=0;
    int i=0;
    int exponent=0;

    while (cnt<=500){
        cnt=1;
        a = a+1;
        t = t+a;
        tt = t;
        list<int>::const_iterator itt;
        for (itt = primes.begin(); itt != primes.end(); itt++){
            if (((*itt) * (*itt)) > tt){
                cnt = 2*cnt;
                break;
                }
            exponent=1;
            while (tt%(*itt)==0){
                exponent+=1;
                tt = tt/(*itt);
                }
            if (exponent>1){
                cnt = cnt*exponent;
                }
            if (tt==1){
                break;
                }
        }
    }
    cout << t << endl;

	return 0;
}

bool testForPrimeness(int &numberRef){
	int i=0;
	for (i = 3; i < sqrt(numberRef)+1;){
		if (numberRef%i==0){
			return false;
		}
		else{
			i+=2;
		}
	}
	return true;
}
