import os, math
table = [map(int,s.split()) for s in open("p067_triangle.txt").readlines()]

for row in range(len(table)-1,0,-1):
    for col in range(0,row):
        table[row-1][col]+=max(table[row][col],table[row][col+1])

print table[0][0]
