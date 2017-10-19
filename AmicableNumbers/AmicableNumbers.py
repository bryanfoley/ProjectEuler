import os, sys
import math
import time, math

def testForPrimeness(number):
    answer=True
    if number%2==0:
        return False
    else:
        for i in range(3,int(math.sqrt(number))):
            if number%i==0:
                return False
            else:
                i+=2
    return answer

def sumOfProperDivisors(number):
    iSum=0
    if testForPrimeness(number)==False:
        if number%2!=0:
            divisors = [x for x in range(number/2+1,3,-2)]
        else:
            divisors = [x for x in range(number/2+1,0,-1)]

	for y in divisors:
            if (number%y)==0:
                iSum+=y
	    else:
                continue
    return iSum
sum=0
for a in range(2,10000):
    b=sumOfProperDivisors(a)
    if b > a:
        if sumOfProperDivisors(b)==a:
            sum+=(a+b)

print sum
