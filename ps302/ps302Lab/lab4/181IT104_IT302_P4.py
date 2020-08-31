outFile = open("output.txt", "w")
res_str = ""
def fact(n):
    res = 1
    for i in range(2, n+1):
        res = res * i
    return int(res)

def nCr(n, r):
    return int(fact(n)/(fact(r)*fact(n-r)))

def getInput(message, var, res_str):
    try:
        val = int(input(message)) 
        if(val < 0):
            res_str += "Invalid input: " + val + " entered for " + var + " was not a positive integer"
            res_str += "\nPlease enter a positive integer for " + var 
            outFile.write(res_str)
            print(res_str)
            exit()
    except:
        res_str += "Invalid input: input for " + var + " was not a non-integer\nPlease enter positive integer"
        outFile.write(res_str)
        print(res_str)
        exit()
    return val
    
N = getInput("Enter the number of pens to be selected: N = ", "N", res_str) 
X = getInput("Enter the number of Blue pens : X = ", "N", res_str) 
Y = getInput("Enter the number of Red pens : Y = ", "Y", res_str)
Z = getInput("Enter the number of Green pens: Z = ", "Z", res_str)
if(N > (X + Y + Z )):
    print("N has to be lesser than total pens")

den = nCr(X+Y+Z, N)
col_sum = [int('0')]*(N+1)
res_str += "X/Y\t" 
print("X/Y\t", end="")
for i in range(N+1):
    res_str += str(i) + "\t"
    print("{}\t".format(i), end="")
res_str += "h(y)\n"
print("h(y)\n")
for i in range(N+1):
    res_str += str(i) + "\t"
    print(i, end="\t")
    sum = 0
    for j in range(N+1):
        num = nCr(X,i) * nCr(Y, j) * nCr(Z, N - i - j)
        col_sum[j]+=num
        sum = sum + num
        res_str+= str(num) + "/" + str(den) + "\t"
        print("{}/{}".format(num, den), end="\t")
    res_str += str(sum) + "/" + str(den) + "\n"
    print("{}/{}\n".format(sum, den))
res_str += "g(x)\t"
print("g(x)\t",end="")
for i in range(N+1):
    res_str+=str(col_sum[i]) + "/" + str(den) + "\t"
    print("{}/{}".format(col_sum[i],den), end="\t")
print("\n")
res_str += "\n"
print(res_str)
print("\n")