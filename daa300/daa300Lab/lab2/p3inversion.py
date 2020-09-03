def inversionCountNaive(numlist):
    n = len(numlist)
    count = 0
    for i in range(n-1):
        for j in range(i+1,n):
            if (i < j and numlist[i] > numlist[j]):
                count+=1
    return count

def main():
    inplist = [4,10,8,2,1]
    print(inversionCountNaive(inplist))

if __name__ == "__main__":
    main()
        