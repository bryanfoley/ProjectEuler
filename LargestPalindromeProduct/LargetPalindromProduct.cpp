/*
 * LargestPalindromeProduct.cpp
 *
 *  Created on: Dec 01, 2016
 *      Author: bryan
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <time.h>
#include <math.h>
#include <sstream>

using namespace std;
void getInput(long &maxDigits);
void determineFactorRanges(long &maxDigitsRef,long &maxFactor, long &minFactor, long &maxRange);
bool isPalindrome(long &numCandidateRef);
bool determinePalindromeProduct(long &maxDigits, list <long> &palindromeProductListRef,long &maxFactorRef, long &minFactorRef);
template < class T >
void printList(list< T > &listRef);
template <typename T>
std::string to_string(T value);
void getResults(list <long> &palindromeProductListef, long &maxDigitsRef);
void calcExecutionTime(time_t startTime,time_t endTime);

int main(){

	long maxDigits,maxRange;
	long maxFactor, minFactor;
	list <long> palindromeProductList;
	time_t start, end;

	getInput(maxDigits);
	determineFactorRanges(maxDigits,maxFactor,minFactor,maxRange);
	time(&start);
	determinePalindromeProduct(maxDigits,palindromeProductList,maxFactor,minFactor);
	time(&end);
	getResults(palindromeProductList,maxDigits);
	calcExecutionTime(start,end);

}

template <typename T>
std::string to_string(T value)
{
  ostringstream os;
  os << value;
  return os.str();
}

void getInput(long &maxDigitsRef){
	cout << "Please enter the number digits that both factors should contain: ";
	cin >> maxDigitsRef;
}

void determineFactorRanges(long &maxDigitsRef,long &maxFactorRef, long &minFactorRef, long &maxRangeRef){
	maxFactorRef = pow(10,maxDigitsRef)-1;
	minFactorRef = pow(10,(maxDigitsRef-1));
	maxRangeRef = pow(maxFactorRef,2);
	cout << maxFactorRef << " " << minFactorRef << " " << maxRangeRef << endl;
}

bool determinePalindromeProduct(long &maxDigits, list <long> &palindromeProductListRef,long &maxFactorRef, long &minFactorRef){
	long a, b;
	long max, min, minPalindrome;
	long candidate;
	max = maxFactorRef;
	min = minFactorRef;
	minPalindrome = max*min;

	for(a=max; a>=min;a--){
		for (b=max; b>=min;b--){
			candidate = a*b;
			if(isPalindrome(candidate) && (candidate>minPalindrome)){
				min=b;
				minPalindrome=candidate;
				palindromeProductListRef.push_back(candidate);
			}
		}
	}

	return true;
}

bool isPalindrome(long &numCandidateRef){
	string strCandidate = to_string(numCandidateRef);
	long len = strCandidate.length();

	if(len ==1){
		return true;
	}
	if(len%2==0){
		string s1 = strCandidate.substr(0,len/2);
		string s2 = strCandidate.substr(len/2,len/2);
		std::reverse(s2.begin(),s2.end());
		if(s1==s2){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		string s1 = strCandidate.substr(0,len/2);
		string s2 = strCandidate.substr((len/2)+1,len/2);
		std::reverse(s2.begin(),s2.end());
		if(s1==s2){
			return true;
		}
		else{
			return false;
		}
	}
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

void getResults(list <long> &palindromeProductListRef, long &maxDigitsRef){
	palindromeProductListRef.sort();
	list <long>::iterator iter = palindromeProductListRef.end();
	iter--;
	cout << "The largest Product of two, " << maxDigitsRef << "-digit factors is " << *iter << endl;
}

void calcExecutionTime(time_t startTime,time_t endTime){
	//Calculate the time to run the loop
	double diff = difftime(endTime,startTime);
	cout << "It has taken " << diff/60 << " minutes to run the main loop." << endl;
}
