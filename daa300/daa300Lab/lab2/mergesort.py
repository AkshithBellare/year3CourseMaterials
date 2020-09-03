def merge(inpList, beg, mid, end):
    i = j = 0
    k = beg
    ln = mid - beg + 1
    rn = end - mid
    left = [0] * ln
    right = [0] * rn

    while i < ln:
        left[i] = inpList[k]
        i+=1
        k+=1

    while j < rn:
        right[j] = inpList[k]
        j+=1
        k+=1

    i = j = 0
    k = beg

    while(i < ln and j < rn):
        if left[i] <= right[j]:
            inpList[k] = left[i]
            i += 1
        elif left[i] > right[j]:
            inpList[k] = right[j]
            j += 1
        k += 1
    
    while(i < ln):
        inpList[k] = left[i]
        k += 1
        i += 1
    
    while(j < rn):
        inpList[k] = right[j]
        k += 1
        j += 1

def mergeSort(inpList, beg, end):
    if(beg < end):
        mid = (beg + end)//2
        mergeSort(inpList, beg, mid)
        mergeSort(inpList, mid+1, end)
        merge(inpList,beg,mid,end)


inpList = [5,1,2,6,0]
mergeSort(inpList,0,4)
print(inpList)