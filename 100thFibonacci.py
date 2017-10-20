MAX=2
A = [0 for x in range(0,MAX)]
B = [0 for x in range(0,MAX)]
C = [0 for x in range(0,MAX)]
B[-1]=1
answer=""
count=1
#print A
#print B
#print C
DEBUG=True
print "*"*50
print "\n"
while C[0]!=9:
	count+=1
	if DEBUG:
		print "Before"
		print A
		print B
		print C
		print "\n"
	for i in range(MAX-1,0,-1):
		if i==0:
			C[i]=A[i]+B[i]
		if((A[i]+B[i])>9):
			C[i-1]+=1
			C[i]=(A[i]+B[i])%10
		else:
			C[i]=A[i]+B[i]
	if DEBUG:
		print "After"
		print "Index = %d"%count
		print A
		print B
		print C
		print "\n"
	A=B[:]
	B=C[:]
	
print count, C
