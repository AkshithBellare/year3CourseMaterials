def binarySearch(inpList, beg, end, key):
    if(beg <= end):
        mid = (beg + end)//2
        if inpList[mid] == key:
            return mid
        elif inpList[mid] < key:
            return binarySearch(inpList,mid+1,end, key)
        else:
            return binarySearch(inpList,beg, mid-1, key)
    return -1

print(binarySearch([1,2,4,5,19], 0, 4, 20))