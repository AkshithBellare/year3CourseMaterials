def partition(array, beg, end):
    pivot = end
    pIndex = beg
    for i in range(beg, end+1):
       if(array[i] <= array[pivot]):
           array[i],array[pIndex] = array[pIndex], array[i]
           pIndex += 1
    array[pIndex],array[pivot] = array[pivot],array[pIndex]
    return pIndex - 1

def quicksort_util(array, beg, end):
    if beg < end:
        pi = partition(array,beg,end)
        quicksort_util(array,beg,pi-1)
        quicksort_util(array,pi+1,end)

def quicksort(array):
    n = len(array)
    quicksort_util(array,0,n-1)

def main():
    array = [7,2,1,6,8,5,3,4]
    print(partition(array,0,7))
    quicksort(array)
    print(array)

if __name__ == "__main__":
    main()