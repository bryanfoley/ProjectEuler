res=[1]
n=1001
for i in range(2,n,2):
    for j in range(0,4):
        res.append(res[-1]+i)
print(sum(res))
