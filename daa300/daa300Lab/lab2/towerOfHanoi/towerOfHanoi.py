def move(f,t):
    print("Move a disc from {} to {}.".format(f,t))

def towerOfHanoi(n,f,v,t):
    if(n>0):
        towerOfHanoi(n-1,f,t,v)
        move(f,t)
        towerOfHanoi(n-1,v,f,t)

towerOfHanoi(3,"A","B","C")