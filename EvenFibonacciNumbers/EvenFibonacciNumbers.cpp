//============================================================================
// Name        : EvenFibonacciNumbers.cpp
// Author      : Bryan Foley
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>

using namespace std;

void getRange(int &maximumRef);
void createFibonacci(list <int> &fibonacciRef, int &maximumRef);
void testIfEven(list <int> &fibonacciRef,list <int> &evenTerms,list <int> &oddTerms);
void sumResults(list <int> &evenTerms, int &maximumRef, int &resultsRef);
template < class T >
void printList(list< T > &listRef);

int main(){
	int maximum=0, result=0;
	list <int> fibonacci;
	list <int> evenTerms;
	list <int> oddTerms;
	getRange(maximum);
	createFibonacci(fibonacci,maximum);
	testIfEven(fibonacci,evenTerms,oddTerms);
	sumResults(evenTerms,maximum,result);

	return 0;
}


void getRange(int &maximumRef){
	cout << "Please enter the upper limit of the Fibonacci Series and hit return: ";
	cin >> maximumRef;
	cout << endl;
}

void createFibonacci(list <int> &fibonacciRef, int &maximumRef){
	fibonacciRef.push_back(1); //These two terms are added explicitly
	fibonacciRef.push_back(2);
	int previous, current, next = 0;
	cout << "Creating a Fibonacci series up to " << maximumRef << "..." << endl;

	list <int>::iterator iter = fibonacciRef.begin(); //Point to the last value
	--iter;

	while (next < maximumRef){
		current = *(--iter);
		previous = *(--iter);
		next = current + previous;
		if (next >= maximumRef){
			break;
		}
		else{
		fibonacciRef.push_back(next);
		iter = fibonacciRef.end();
		}
	}
	fibonacciRef.sort();
}

void testIfEven(list <int> &fibonacciRef,list <int> &evenTermsRef,list <int> &oddTermsRef){
	list <int>::iterator iter = fibonacciRef.begin();

	while(iter != fibonacciRef.end()){
		if (*iter%2 == 0){
			evenTermsRef.push_back(*iter); //Remove if it fails the even number test
		}
		else{
			oddTermsRef.push_back(*iter);
		}
		iter++;
	}
	evenTermsRef.sort();
	oddTermsRef.sort();
}

void sumResults(list <int> &evenTermsRef, int &maximumRef, int &resultsRef){
	list <int>::iterator iter = evenTermsRef.begin();

	while(iter != evenTermsRef.end()){
		resultsRef+=*iter;
		iter++;
	}
	cout << "The sum of the even terms of the Fibonacci Series up to " << maximumRef << " is " << resultsRef << endl;
}

template < class T >
void printList(list< T > &listRef){
	if(listRef.empty()){
		cout << "List is empty";
	}
	else{
		list < int >::iterator iter = listRef.begin();
		while (iter!=listRef.end()){
			cout << *iter << " ";
			iter++;
		}
		cout << endl;
	}
}
