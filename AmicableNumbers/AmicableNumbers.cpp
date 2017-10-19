#include <iostream>
#include <list>
#include <cmath>
#include <math.h>

using namespace std;

bool testForPrimeness(int &numberRef);
int sumOfProperDivisors(int &numberRef);

int main(){
    int sum=0;
    for (int a=2; a < 10000;a++){
        int b=0;
        b=sumOfProperDivisors(a);
        if (b > a){
            if (sumOfProperDivisors(b)==a){
                sum+=(a+b);
            }
        }
    }
    cout << sum << endl;
}


bool testForPrimeness(int &numberRef){
	int i=0;
	if (numberRef%2==0 && numberRef !=2){
		return false;
	}
	else{
		for (i = 3; i < sqrt(numberRef)+1;){
			if (numberRef%i==0){
                return false;
			}
			else{
			    i+=2;
			}
		}
	}
	return true;
}


int sumOfProperDivisors(int &numberRef){
    if (numberRef==1){
	return 0;
	}
	int iSum=0;
	
	if (testForPrimeness(numberRef)==false){
	    int r,f,step;
	    r = floor(sqrt(numberRef));
	    if (r*r==numberRef){
		iSum+=1+r; r= r-1;
	    }
	    else{
		iSum=1;
	    }
	    if (numberRef%2!=0){
		f=3; step=2;
	    }
	    else{
		f=2;step=1;
	    }
	    while(f<r){
		if (numberRef%f==0){
		    iSum+=f+numberRef/f;
		}
		f=f+step;
	    }
	}
    return iSum;
}
