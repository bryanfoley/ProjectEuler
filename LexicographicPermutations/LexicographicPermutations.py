import sys

def getFactorialRepresentation(permutation):
    modulus=[]
    divisor=1
    permutation-=1
    while True:
        result = permutation/divisor
        modulus.append(permutation%divisor)
        permutation=result
        if result==0:
            return modulus[::-1]
        else:
            divisor+=1
			
def getNthPermutation(permutation,arrayOfDigits):
    result = ''
    factorialRepresentation=getFactorialRepresentation(permutation)
    for i in factorialRepresentation:
        result+=str(arrayOfDigits[i])
        arrayOfDigits.pop(i)
    return int(result)

def main():
    permutation = int(sys.argv[1])
    arrayOfDigits = sys.argv[2].split(',')
    #arrayOfDigits = [int(x) for x in arrayOfDigits]
    print getNthPermutation(permutation,arrayOfDigits)

if __name__ == "__main__":
    main()