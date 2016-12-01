/*
 * LargestPrimeFactor.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: bryan
 */

#include <iostream>
#include <list>
#include <math.h>
#include <time.h>

using namespace std;

void getInput(long &maxNumberRef);
bool testForPrimeness(long &numberRef);
void getResults(list <long> &primeFactorsRef, long &maxNumberRef);
void findRange(list <long> &primeFactorsRef,long &maxNumberRef);
template < class T >
void printList(list< T > &listRef);
void calcExecutionTime(time_t startTime,time_t endTime);

int main(){
	time_t start, end;
	long maxNumber, number, divisor, remainder =0;
	divisor = 2;
	list <long> primeFactors;
	getInput(maxNumber);
	number = maxNumber;
	time(&start);
	findRange(primeFactors,maxNumber);
	printList(primeFactors);
	getResults(primeFactors,maxNumber);
	time(&end);
	calcExecutionTime(start,end);
	return 0;
}

void getInput(long &maxNumberRef){
	long originalNumber;
	cout << "Please enter the number whose largest Prime Factor you wish to find: ";
	cin >> maxNumberRef;
}

bool testForPrimeness(long &numberRef){
	long i=0;
	cout << "Testing for Primeness: " << numberRef << endl;
	if (numberRef == 2){
		return true;
	}
	for (i = 2; i < numberRef;){
		if (numberRef%i==0){
			return false;
		}
		else{
			i++;
		}
	}
	return true;
}

void getResults(list <long> &primeFactorsRef, long &maxNumberRef){
	primeFactorsRef.sort();
	//primeFactorsRef.unique();
	printList(primeFactorsRef);
	list <long>::iterator iter = primeFactorsRef.end();
	iter--;
	cout << "The largest Prime Factor of " << maxNumberRef << " is " << *iter << endl;
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

void findRange(list <long> &primeFactorsRef,long &maxNumberRef){
	long divisor = 2;
	long number = maxNumberRef;
	bool bottomFound = false;

	do{
		if (number%divisor==0){
			cout << "Found a prime: " << divisor << endl;
			primeFactorsRef.push_back(divisor);
			number = number/divisor;
		}
		else{
			break;
		}
		if (divisor==number){
			cout << "Found a prime: " << divisor << endl;
			primeFactorsRef.push_back(divisor);
			bottomFound = true;
			break;
		}
	}while(divisor != number);

	if(bottomFound!=true){
		divisor = 3;
		do{
			if (number%divisor==0){
				if (testForPrimeness(divisor)){
					cout << "Found a prime: " << divisor << endl;
					primeFactorsRef.push_back(divisor);
				}
				number = number/divisor;
			}
			else{
				divisor = divisor+2;
			}
			if (divisor==number){
				cout << "Found a prime: " << divisor << endl;
				primeFactorsRef.push_back(divisor);
				break;
			}
		}while(divisor != number);
	}
}

void calcExecutionTime(time_t startTime,time_t endTime){
	//Calculate the time to run the loop
	double diff = difftime(endTime,startTime);
	cout << "It has taken " << diff/60 << " minutes to run the main loop." << endl;
}
