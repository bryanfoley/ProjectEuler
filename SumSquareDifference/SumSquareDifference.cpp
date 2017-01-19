//============================================================================
// Name        : SumSquareDifference.cpp
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

void calcExecutionTime(time_t startTime,time_t endTime);

int main(){
	long max, sum, result;
	cin >> max;
	time_t start, end;
	time(&start);
	long sumOfSquares = 0;
	for (long i = 1; i <= max; i++){
		sumOfSquares+= pow(i,2.0);
	}
	long squareOfSum = (pow(max,2.0)*pow(max+1,2.0))/4.0;
	time(&end);
	cout << squareOfSum - sumOfSquares << endl;
	calcExecutionTime(start,end);
}

void calcExecutionTime(time_t startTime,time_t endTime){
	//Calculate the time to run the loop
	double diff = difftime(endTime,startTime);
	cout << "It has taken " << diff/60 << " minutes to run the main loop." << endl;
}
