/*
 * SumOfMultiples.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: bryan
 */
#include <iostream>
#include <string>
#include <list>
#include <algorithm>


using namespace std;

void getInput(list <int>&factorsRef, int &maximumRef);
void findMultiples(list <int> &factorsRef, list <int> &multiplesRef, int &maximumRef);
template < class T >
void printList(list< T > &listRef);
template < class T >
void sumResults(list < T > &resultsRef, int &resultRef);


int main(){
	list< int > multiples,factors, results;
	int maximum=0, sum=0;
	getInput(factors,maximum);
	findMultiples(factors,multiples,maximum);
	printList(multiples);
	sumResults(multiples,sum);
    return 0;
}

void getInput(list <int>&factorsRef, int &maximumRef){
	int input;
	cout << "Please enter some integers (enter 0 to end):\n";

	do{
	   std::cin >> input;
	   factorsRef.push_back(input);
	  } while (input);

	factorsRef.sort();
	factorsRef.remove(0);

	cout << "Please enter the maximum number you wish the search to continue up until, then hit return...\n";
	cin >> maximumRef;

	cout << "The numbers that multiples will be found for are: ";
	list<int>::iterator iter = factorsRef.begin();
	while(iter!= factorsRef.end()){
		int num = *iter;
		cout << num << " ";
		iter++;
	}
	cout << endl;

	cout << "The search will stop when we reach " << maximumRef << endl;
}

void findMultiples(list <int> &factorsRef, list <int> &multiplesRef, int &maximumRef){
    list<int>::iterator iter = factorsRef.begin();
    int i;
    while (iter!= factorsRef.end()){
    	i=*iter;
    	while(i >= 0 && i < maximumRef){
    		if (i%*iter == 0){
    			multiplesRef.push_back(i);
    		}
    		i++;
    	}
    	iter++;
    }
	multiplesRef.sort();
	multiplesRef.unique();
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

template < class T>
void sumResults(list < T >&resultsRef, int &sumRef){
	list < int >::iterator iter = resultsRef.begin();

	while (iter!=resultsRef.end()){
		sumRef+=*iter;
		iter++;
	}
	cout << sumRef << endl;
}
