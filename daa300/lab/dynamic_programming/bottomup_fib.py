num = 10

def bottomup_fib(n):
    prev = -1
    pprev = -1
    r = 0
    for i in range(1, n+1):
        if i <= 2:
            if prev == -1:
                prev = 1
            else:
                pprev = prev
                prev = 1
            r = 1
        else:
            r = prev + pprev
            pprev = prev
            prev = r
    return r


print(bottomup_fib(num))