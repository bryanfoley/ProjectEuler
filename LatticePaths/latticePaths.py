import os, sys
n = int(sys.argv[1])
ListA = [1]
ListB=[]
for n in range(1,2*n+1):
    if len(ListA)==1:
       ListB.append(ListA[0])
    else:
        ListB.append(1)
	for elem in range(1,n):
	    ListB.append(0)
    	for elem in range(1,len(ListB)):
            ListB[elem] = ListA[elem-1]+ListA[elem]
    ListB.append(1)
    ListA = ListB
    ListB = []
print "%s unique paths through a %sx%s grid"%(max(ListA),n/2,n/2)
