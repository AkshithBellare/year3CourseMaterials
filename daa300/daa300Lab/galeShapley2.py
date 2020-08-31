n = 5
men = {"0": "Raj", "1":"Suraj", "2": "Tejas", "3": "Urman", "4": "Vinay"}
women = {"0": "Aparna", "1": "Bhavna", "2": "Chithra", "3": "Divya", "4": "Eliana"}
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
    print("freemen list {}".format(freemen))
    woman = mpref[man][count[man]]
    if(count[man] == n):
        freemen.remove(man)
        continue
    if(count[man] != n):  
        if(husb[woman] == -1):
            husb[woman] = man
            wife[man] = woman
            count[man] += 1
            freemen.remove(man)
            print("paired {} and {}".format(men[str(man)], women[str(woman)]))
        elif inv_pref_list[woman][man] < inv_pref_list[woman][husb[woman]]:
            print("{} chooses {} over {}".format(women[str(woman)], men[str(man)], men[str(husb[woman])]))
            wife[husb[woman]] = -1
            freemen.add(husb[woman])
            husb[woman] = man
            wife[man] = woman
            count[man] += 1
            freemen.remove(man)
        else:
            freemen.add(man)
            count[man] += 1

for i in range(n):
    print("{} marries {}".format(men[str(i)], women[str(wife[i])]))