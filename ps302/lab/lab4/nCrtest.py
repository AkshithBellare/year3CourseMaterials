def nCr(n,r):
    r = min(n, n-r)
    res = 1
    for i in range(r):
        res *= n - i
        res/=(i+1)
    return int(res)

print(nCr(2,1))