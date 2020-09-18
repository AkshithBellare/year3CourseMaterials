def sort_and_count_splitInv(array, temp_arr, beg, mid, end):
    split_invcount = 0
    i, j, k = beg, mid+1, beg
    while i < mid+1 and j < end+1:
        if array[i] <= array[j]:
            temp_arr[k] = array[i]
            i+=1
        else:
            split_invcount += mid + 1- i
            temp_arr[k] = array[j]
            j+=1
        k+=1

    while i < mid+1:
        temp_arr[k] = array[i]
        i+=1
        k+=1

    while j < end+1:
        temp_arr[k] = array[j]
        j+=1
        k+=1
    
    for i in range(beg, end+1):
        array[i] = temp_arr[i]

    return split_invcount

def sort_and_countInv(array, temp_arr, beg, end):
    inv_count = 0
    if(beg < end):
        mid = (beg + end)//2
        inv_count += sort_and_countInv(array,temp_arr,beg,mid)
        inv_count += sort_and_countInv(array,temp_arr,mid+1,end)
        inv_count += sort_and_count_splitInv(array,temp_arr,beg,mid,end)
    return inv_count

def count_inversions(array):
    n = len(array)
    temp_arr = [0]*n
    inv_count = sort_and_countInv(array,temp_arr,0,n-1)
    return inv_count

def main():
    array = [2,8,3,10,6]
    print(count_inversions(array))

if __name__ == "__main__":
    main()
