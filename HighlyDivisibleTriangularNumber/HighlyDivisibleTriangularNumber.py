import itertools
flatten_iter = itertools.chain.from_iterable

def generate_triangular_series(number_of_terms):
    triangular = []
    previous = 0
    current = 1
    while len(triangular)< number_of_terms:
        sum = current+previous
        previous = sum
        current+=1
        triangular.append(sum)
    return triangular

def generate_prime_numbers(n):
    primes = []
    primes.append(2)
    primes.append(3)
    primes.append(5)

    i=3
    while 1:
        if test_for_primeness(i):
            primes.append(i)
            if len(primes)==n:
                break
        i+=2
    return primes

def test_for_primeness(number):
    i = 0
    for i in range(3,int(number**0.5)+1):
        if number%i==0:
            return False
        else:
            i+=2
    return True

def factors(number):
    return len(set(flatten_iter((i,number/i) for i in range(1,int(number**0.5)+1)if number % i ==0)))

def main():
    primes = generate_prime_numbers(1000)
    t=1
    a=1
    cnt=0
    tt=0
    i=0
    exponent=0

    while cnt<=500:
        cnt=1
        a = a+1
        t = t+a
        tt = t
        for item in primes:
            if item*item >tt:
                cnt = 2*cnt
                break
            exponent=1
            while tt%item==0:
                exponent+=1
                tt = tt/item
            if exponent>1:
                cnt = cnt*exponent
            if tt==1:
                break

    print(t)

if __name__ == "__main__":
    main()