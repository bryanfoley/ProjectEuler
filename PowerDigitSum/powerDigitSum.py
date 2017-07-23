bigSum = 2**1000
bigString = str(bigSum)

sum = 0

for elem in bigString:
    sum+=int(elem)

print sum
