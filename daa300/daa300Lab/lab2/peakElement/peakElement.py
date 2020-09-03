def peakElementnaive(inpList):
    n = len(inpList)
    peak = inpList[0]
    for i in range(1,n-1):
        if inpList[i+1] < inpList[i] and inpList[i] > inpList[i-1]:
            peak = inpList[i]
    return peak

print(peakElementnaive([2,4,6,8,7,5,3]))
print(peakElementnaive([10, 12, 8, 4, -3, -15]))
print(peakElementnaive([5,10,20,15]))
print(peakElementnaive([10,20,15,2,23,90,67]))