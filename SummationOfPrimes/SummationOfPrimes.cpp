//============================================================================
// Name        : SummationOfPrimes.cpp
// Author      : Bryan Foley
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;

int main()
{
    long n = 2000000;
    long limit = 8000000;
    vector<long> prime;
    bool mark[limit];
    memset(mark, true, sizeof(mark));

    for (long p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (long i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    for (long p=2; p<limit; p++)
    {
        if (mark[p] == true && p < n)
        {
            prime.push_back(p);
        }
    }
    vector < long >::iterator iter = prime.begin();
    long sumRef = 0;
    	while (iter!=prime.end()){
    		sumRef+=*iter;
    		iter++;
    	}
    	cout << sumRef << endl;
    return 0;
}
