def merge(inpList, beg, mid, end):
    i = 0
    j = 0
    ln = mid - beg + 1
    rn = end - mid 
    left = [0] * ln
    right = [0] * rn

    inv_count = 0

    k = beg

    while i < ln:
        left[i] = inpList[k]
        i += 1
        k += 1

    while j < rn:
        right[j] = inpList[k]
        j += 1
        k += 1
    
    i = j = 0
    k = beg

    while i < ln and j < rn:
        if(left[i] <= right[j]):
            inpList[k] = left[i]
            i += 1
        elif left[i] > right[j]:
            inv_count += ln - i
            inpList[k] = right[j]
            j += 1
        k+=1

    
    while i < ln:
        inpList[k] = left[i] 
        i+=1
        k+=1
    
    while j < rn:
        inpList[k] = right[j]
        j+=1
        k+=1
    
    return inv_count

def _mergeSort(inpList, beg, end):
    if(beg < end):
        mid = (beg + end)//2
        left_count = _mergeSort(inpList, beg, mid)
        right_count = _mergeSort(inpList, mid+1, end)
        return left_count + right_count + merge(inpList, beg, mid, end)
    return 0

def mergeSort(inpList, beg, end):
    return _mergeSort(inpList, beg, end)

def inversionCountEnhanced(inpList):
    n = len(inpList)
    print(n)
    inv_count = mergeSort(inpList,0,(n-1))
    return inv_count


def main():
    inpList = [1,2,10,6,8,5,4,0]
    print("no of inversions is {}".format(inversionCountEnhanced(inpList)))

if __name__ == "__main__":
    main()