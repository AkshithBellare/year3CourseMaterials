def binarySearchModified(inpList, beg, end):
    if(beg <= end):
        mid = (beg + end) // 2
        if inpList[mid] > inpList[mid - 1]  and inpList[mid + 1] < inpList[mid]:
            return mid
        elif inpList[mid] > inpList[mid -1] and inpList[mid + 1] > inpList[mid]:
            return binarySearchModified(inpList, mid+1, end)
        else:
            return binarySearchModified(inpList,beg, mid-1)
    return -1




def peakElement(inpList):
    n = len(inpList)
    if(n == 0):
        print("empty array")
        return -1
    if n==1 or inpList[0] > inpList[1]:
        print("{} is the peak element".format(inpList[0]))
    peak = binarySearchModified(inpList,0,n-2)
    
    if peak != -1:
        print("{} is the peak element".format(inpList[peak]))
    else:
        print("There is no peak element")




peakElement([2,4,5,12,22,44,56, -12, -22])