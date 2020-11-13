values = [280, 100, 120, 120]
weights = [40, 10, 20, 24]
n = 4
C = 60

table = [[None for i in range(n+1)] for j in range(C+1)]

print(table[0])

def memoized_knapsack(capacity, index):
    if table[capacity][index] != None:
        return table[capacity][index]
    if index >= n:
        table[capacity][index] = 0
    elif capacity < weights[index]:
        table[capacity][index] = memoized_knapsack(capacity, index + 1)
    else:
        table[capacity][index] = max(memoized_knapsack(capacity, index+1), values[index] + memoized_knapsack(capacity-weights[index], index+1))
    return table[capacity][index]

memoized_knapsack(capacity=C, index=0)

print(table[C][0])