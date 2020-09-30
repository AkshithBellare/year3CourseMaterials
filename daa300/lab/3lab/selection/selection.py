def partition(array, beg, end, approx_median_index):
    array[end], array[approx_median_index] = array[approx_median_index], array[end]
    pivot = array[end]
    pIndex = beg
    for i in range(beg,end):
            if array[i] <= pivot:
                array[i], array[pIndex] = array[pIndex], array[i]
                pIndex += 1
    array[pIndex], array[end] = array[end], array[pIndex]
    return pIndex

def select(array, rank):
    n = len(array)
    element = select_util(array, rank, 0, n-1)
    return element 

def select_util(array, rank, beg, end):
    am = find_approx_median(array, rank, beg, end)
    pi = partition(array, beg, end, am)
    if rank == pi + 1:
        return array[pi]
    elif rank < pi + 1:
        return select_util(array, rank, beg, pi-1)
    else:
        return select_util(array, rank - (pi-beg) + 1, pi+1, end)

def find_approx_median(array, rank, beg, end):
    pass
    

def main():
    array = [1,5,12,9,8,17,32,0]
    array.sort()
    print(array)

if __name__ == "__main__":
    main()