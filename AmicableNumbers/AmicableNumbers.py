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
for number in range(1,10001):
    d(number)
for key in results.keys():
    try:
        #list of keys that have the same value as the current key
        temp=[k for (k, v) in results.iteritems() if v == int(key)]
        if len(temp)>0:
            final[key]=temp
    except:
        continue

for key in final.keys():
    temp = final[str(key)]
    for item in temp:
        try:
            if str(key) in final[str(item)]:
                if key!=item:
                    totalSum+=(int(key)+int(item))
                    del final[key]
        except Exception as exc:
            continue

print totalSum