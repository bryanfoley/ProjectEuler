import os, sys
import math

results = {}

def d(number):
    divisors = [x for x in range(1,(number/2)+1)]
    iSum=0
    for y in divisors:
        if (x%y)==0:
            iSum+=y
    if iSum > 0:
        results[str(number)] = iSum
totalSum=0
for number in range(1,1001):
    d(number)
    for key in results.keys():
        try:
            totalSum+=(int(key)+results.keys[results.values().index(int(key))])
        except:
            pass
print results
print totalSum
