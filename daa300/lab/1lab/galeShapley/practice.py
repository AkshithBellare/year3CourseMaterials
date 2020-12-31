n = 5

men = ["Prakash", "Quinton", "Raj", "Suraj", "Thanush"]
women = ["Asha", "Beyonce", "Carilyn", "Diana", "Esther"]
wpreflist = [[0,4,1,3,2],
             [1,2,0,4,3],
             [4,3,2,1,0],
             [2,0,4,3,1],
             [1,3,2,0,4]]
                
mpreflist = [[1,2,3,4,0],
             [4,0,3,2,1],
             [1,3,0,2,4],
             [2,4,3,1,0],
             [0,4,2,3,1]]

husb = [-1] * n #husb[i] = -1 indicated i is not engaged to anyone
wife = [-1] * n #wife[i] = j indicated woman i is engaged to man j

def make_inverse_preflist(wpreflist): #used in the step where a woman checks if she prefers one man over the other
    inverse_list = []
    for wlist in wpreflist:
        inv_list = [0] * n
        rank = 0
        for x in wlist:
            inv_list[x] = rank
            rank += 1
        inverse_list.append(inv_list)
    return inverse_list

inverse_list = make_inverse_preflist(wpreflist=wpreflist)

freemen = [x for x in range(n)]        

count = [0] * n

while(freemen):
    man = freemen.pop()
    woman = mpreflist[man][count[man]]
    count[man] += 1
    man_name = men[man]
    woman_name = women[woman]

    print(f"{man_name} proposes to {woman_name}")

    if husb[woman] == -1:
        husb[woman] = man
        wife[man] = woman
        print(f"{man_name} gets engaged to {woman_name}")
    else:
        mprime = husb[woman]
        if inverse_list[woman][mprime] < inverse_list[woman][man]:
            freemen.append(man)
            print(f"{man_name} is rejected by {woman_name}")
        else:
            husb[woman] = man
            wife[man] = woman 
            print(f"{woman_name} rejects cuurent partner {men[mprime]} and gets engaged to {man_name}")
            freemen.append(mprime)

print(husb)
print(wife)