#Cov(X,Y) = E(XY) - UxUy

from prettytable import PrettyTable

def fact(n):
    if(n == 0 or n == 1):
        return 1
    return int(n * fact(n-1))

def nCr(n,r):
    n = int(n)
    r = int(r)
    if(r < 0 or r > n):
        return 0
    if(r == n):
        return 1
    res = fact(n)//(fact(n-r) * fact(r))
    return res
    
def main():
    oranges = int(input("Enter number of oranges:\n"))
    apples = int(input("Enter number of apples:\n"))
    bananas = int(input("Enter number of bananas:\n"))
    select = int(input("Enter number of fruits selected:\n"))

    print(f"#oranges = {oranges} #apples = {apples} #bananas = {bananas} #of fruits selected = {select}")
    if(oranges < 0 or apples < 0 or bananas < 0):
        print("\nNumber of fruits can't be negative. INVALID CASE\n")
        exit()
    elif(select < 0):
        print("\nYou can't pick negative number of fruits.INVALID CASE\n")
        exit()

    matrix = [[0 for col in range(select+1)] for row in range(select+1)]

    table = PrettyTable()
    table.field_names = ["f(x,y)",] + [str(col) for col in range(select+1)]

    cols = [0 for col in range(select+1)]
    rows = [0 for col in range(select+1)]
    den = nCr(oranges+apples+bananas,select) 
    for x in range(select+1):
        list = [x]
        for y in range(select+1):
            num = nCr(oranges,x) * nCr(apples,y) * nCr(bananas,select - x - y)
            res = (num / den)
            res_str = str(num) + "/" + str(den)
            rows[x] += num
            cols[y] += num
            matrix[x][y] = res
            list.append(res_str)
        table.add_row(list)
    
    table.add_row(["h(x)"] + [(str(col) + "/" + str(den)) for col in cols])
    table.add_column("g(y)",[(str(row) + "/" + str(den)) for row in rows] + [""])

    print(table)

    eX = 0
    eY = 0
    eXY = 0
    for i in range(select+1):
        eX += i * (cols[i]/den)
        eY += i * (rows[i]/den)

    print("E(X) = ",end="")
    for i in range(select+1):
        print(str(i) + " * " + str(cols[i]) + "/" + str(den) + " +", end = " ")
    print(f" = {eX}\n")

    print("\nE(Y) = ",end="")
    for i in range(select+1):
        print(str(i) + " * " + str(rows[i]) + "/" + str(den) + " +", end = " ")
    print(f" = {eY}\n")
    
    print("E(X,Y) = summation(x * y * f(x,y)) = ", end=" ")
    for x in range(select+1):
        for y in range(select+1):
            print(str(x) + " * " + str(y) + " * " + str(int(matrix[x][y] * den)) + "/" + str(den) + "+", end=" ")
            eXY += x*y*matrix[x][y]
    print(f" = {eXY}\n")    

    cov = eXY - (eX * eY)
    print(f"\nCovariance(X,Y) = E(XY) - E(X)E(Y) = {eXY} - {eX} * {eY} = {cov}")

    

if __name__ == "__main__":
    main()