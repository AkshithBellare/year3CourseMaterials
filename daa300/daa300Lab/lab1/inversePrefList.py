n = 5
list = [0,2,4,1,3]
inv_pre_list = [0]*n
for i in range(n):
    inv_pre_list[list[i]] = i+1 
print(inv_pre_list)


set = {1,2,3}
print(next(iter(set)))