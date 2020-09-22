def partition(array, beg, end, approx_median_index):
    pivot = array[approx_median_index]
    pIndex = beg
    for i in range(beg,end+1):
        if i != approx_median_index:
            if array[i] <= pivot:
                print(f"array[{i}] = {array[i]} is lesser than {pivot}")
                array[i], array[pIndex] = array[pIndex], array[i]
                pIndex += 1
                print(f"pIndex = {pIndex}")
                print(f"array = {array}")
                print("\n")
            else:
                print(f"array[{i}]={array[i]} is greater than or equal to {pivot}")
                print(f"pIndex = {pIndex}")
                print(f"array = {array}")
                print("\n")
    if(approx_median_index > pIndex):
        array[pIndex], array[approx_median_index] = array[approx_median_index], array[pIndex]
    else:
        array[pIndex-1],array[approx_median_index] = array[approx_median_index], array[pIndex-1]
    return pIndex


def main():
    array = [1,5,12,9,8,17,32,0]
    print(partition(array,0,7,2))
    print(array)

if __name__ == "__main__":
    main()