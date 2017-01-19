//============================================================================
// Name        : SmallestMultiple.cpp
// Author      : Bryan Foley
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <math.h>
#include <time.h>

using namespace std;

bool testForPrimeness(long &numberRef);
bool testForDivision(long &numberRef, long &minRef, long &maxRef);
void calcExecutionTime(time_t startTime,time_t endTime);
template < class T >
void printList(list< T > &listRef);

int main(){
	long min, max,product,result,factor;
	result, product = 1;
	factor = 0;
	cin >> min >> max;
	time_t start, end;
	time(&start);
	list <long> primes;
	for (long i = min; i <=max; i++){
		if(testForPrimeness(i)){
			primes.push_back(i);
			product *=i;
		}
	}
	do{
		factor++;
		result = product*(max+factor);
	}while(testForDivision(result,min,max)!=true);
	cout <<result << endl;
	time(&end);
	calcExecutionTime(start,end);
	return 0;
}

bool testForPrimeness(long &numberRef){
	long i=0;
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

bool testForDivision(long &numberRef, long &minRef, long &maxRef){
	long num = minRef;
	while (num <= maxRef){
		if(numberRef%num!=0){
			return false;
		}
		else{
			num++;
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
