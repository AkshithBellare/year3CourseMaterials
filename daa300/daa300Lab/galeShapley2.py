n = 5
wpref = [[4,0,1,3,2],[2,1,3,0,4],[1,2,3,4,0],[0,4,3,2,1],[3,1,4,2,0]]
mpref = [[1,0,3,4,2],[3,1,0,2,4],[1,4,2,3,0],[0,3,2,1,4],[1,3,0,4,2]]
wife = [-1]*n
husb = [-1]*n
inv_pref_list = []
count = [0]*n
for i in range(n):
    inv = [0]*n
    cur_pre_list = wpref[i]
    for j in range(n):
        inv[cur_pre_list[j]] = j+1
    inv_pref_list.append(inv)

freemen = {0,1,2,3,4}

while(freemen):
    man = next(iter(freemen))
    print(man)
    woman = mpref[man][count[man]]
    if(count[man]!=n):  
        if(husb[woman] == -1):
            husb[woman] = man
            wife[man] = woman
            count[man] += 1
            freemen.remove(man)
        elif inv_pref_list[woman][man] > inv_pref_list[woman][husb[woman]]:
            wife[husb[woman]] = -2
            freemen.add(husb[woman])
            husb[woman] = man
            wife[man] = woman
            count[man] += 1
            freemen.remove(man)
        else:
            freemen.add(man)
            count[man] += 1



print(wife)
print(husb)


        



