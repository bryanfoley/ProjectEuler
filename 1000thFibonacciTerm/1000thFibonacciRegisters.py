MAX=999	
A = [0 for x in range(0,MAX+1)]
B = [0 for x in range(0,MAX+1)]
C = [0 for x in range(0,MAX+1)]
B[-1]=1
count=1
#print A
#print B
#print C
DEBUG=False
print "*"*50
print "\n"
while True: #Infinite loop
	count+=1
	if DEBUG:
		print "Before"
		print A
		print B
		print C
		print "\n"
	for i in range(MAX,0,-1):
		if((A[i]+B[i])>9):
			C[i-1]+=1
			C[i]+=(A[i]+B[i])%10
			#print "C=%d+%d"%(A[i],B[i])
			#print "C[i-1]=%d"%(C[i-1])
		else:
			#print "C=%d"%(C[i])
			if C[i]==0:
				C[i]=A[i]+B[i]
			else:
				C[i]+=A[i]+B[i]
			#print "C=%d+%d"%(A[i],B[i])
			#print "C=%d"%(C[i])
		if(10 in C):
			index = C.index(10)
			C[index-1]+=1
			C[index]=0

		#print C
	if C[0]!=0:
		break

	if DEBUG:
		print "After"
		print "Index = %d"%count
		print A
		print B
		print C
		print "\n"
	A=B[:]
	B=C[:]
	C = [0 for x in range(0,MAX+1)]
	
print count, C
