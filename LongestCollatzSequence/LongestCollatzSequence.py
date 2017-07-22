max = 1000000
interim_max = 1
res = 0
temp_list = []
terms_list = []

def collatz(n,D):
    length = 1
    k = n
    while k!=1:
        if k%2==0:
            k //= 2
        else:
            k = 3*k+1
        if k in D.keys():
            D[n] = length+D[k]
            return D[n]
        length += 1
    D[n] = length
    return D[n]

def longest_chain(n,D):
    max_length = 0
    max_start = 0
    for i in range(1,n):
        length = collatz(i,D)
        if max_length<length:
            max_length = length
            max_start=i
    return max_start, max_length

def main():
    dic = {}
    n = 1000000
    print(longest_chain(n, dic))
    # longest = 0
    # answer = 0
    # for i in range(1, 1000000):
    #     temp = i
    #     count = 1
    #     while i != 1:
    #         count += 1
    #         if i % 2 == 0:
    #             i /= 2
    #         else:
    #             i = 3 * i + 1
    #     if count > longest:
    #         longest = count
    #         answer = temp
    # print(answer, longest)
    # for i in range(1,max):
    #     terms=1
    #     interim_max = 1
    #     if i%2==0:
    #         res=i/2
    #         terms+=1
    #     else:
    #         res = (3*i)+1
    #         terms+=1
    #     while res!=1:
    #         if res%2==0:
    #             res=res/2
    #             terms+=1
    #         else:
    #             res = (res*3)+1
    #             terms+=1
    #     terms_list.append([i,terms])
    #     if terms > interim_max:
    #         interim_max=terms
    #         temp_list.append([i,interim_max])
    #
    # temp_max = temp_list[0][1]
    # for item in temp_list:
    #     if item[1]>temp_max:
    #         temp_max = item[1]
    #         max_num = item[0]
    #     else:
    #         pass
    #
    # print(temp_max, max_num)


if __name__=="__main__":
    main()