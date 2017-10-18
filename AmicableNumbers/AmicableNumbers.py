import os, sys
import math
import collections

results = {}
final = {}

def d(number):
    divisors = [x for x in range(1,number/2+1)]
    iSum=0
    for y in divisors:
        if (number%y)==0:
            iSum+=y
        else:
            continue
    if iSum > 0:
        results[str(number)] = iSum

totalSum=0
    
results = collections.OrderedDict()
for number in range(1,1001):
    d(number)
for key in results.keys():
    try:
        #list of keys that have the same value as the current key
        final[key]=[k for (k, v) in results.iteritems() if v == int(key)]
        if len(final[key])>0:
            print "key: %s, keys with same value: %s"%(key,final[key])
    except:
        continue

print results['220']
print totalSum
