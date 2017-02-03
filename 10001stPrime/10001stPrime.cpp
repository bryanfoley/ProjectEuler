//============================================================================
// Name        : 10001stPrime.cpp
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

bool testForPrimeness(long &numbeRef);
void calcExecutionTime(time_t startTime,time_t endTime);
template < class T >
void printList(list< T > &listRef);

int main() {
	long n;
	list <long> primes;
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	time_t start, end;

	cin >> n;
	time(&start);

	for (long i = 3; i+=2;){
		if(testForPrimeness(i)){
			primes.push_back(i);
			if (primes.size() == n){
				break;
			}
		}
	}
	time(&end);

	calcExecutionTime(start,end);
	list <long>::iterator it = primes.end();
	it--;
	cout << *it << endl;

	return 0;
}

bool testForPrimeness(long &numberRef){
	long i=0;
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

void calcExecutionTime(time_t startTime,time_t endTime){
	//Calculate the time to run the loop
	double diff = difftime(endTime,startTime);
	cout << "It has taken " << diff/60 << " minutes to run the main loop." << endl;
}

template < class T >
void printList(list< T > &listRef){
	if(listRef.empty()){
		cout << "List is empty";
	}
	else{
		listRef.sort();
		list < long >::iterator iter = listRef.begin();
		while (iter!=listRef.end()){
			cout << *iter << " ";
			iter++;
		}
		cout << endl;
	}
}
