import time

memo = {}
def memoized_fib(n):
    if n in memo:
        return memo[n]
    if n <= 2:
        return 1
    f = memoized_fib(n-1) + memoized_fib(n-2)
    memo[n] = f 
    return f

def fib(n):
    if n <= 2:
        return 1
    f = fib(n-1) + fib(n-2)
    return f

num = 40

start = time.time()
mf = memoized_fib(num)
end = time.time()
print(mf)
print((end - start))

start = time.time()
mf = fib(num)
end = time.time()
print(mf)
print((end - start))