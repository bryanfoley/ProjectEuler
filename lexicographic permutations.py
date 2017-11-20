import itertools

data = [''.join(i) for i in itertools.permutations("0123456789")]

print data[1000000-1]