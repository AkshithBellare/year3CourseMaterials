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
        val = int(input("Enter the " + message)) 
        if(val < 0):
            res_str += "Invalid input: " + val + " entered for " + var + " was not a positive integer"
            res_str += "\nPlease enter a positive integer for " + var 
            outFile.write(res_str)
            print(res_str)
            exit()
        res_str += message + str(val) + "\n"
        outFile.write(res_str)
        print(res_str)
    except:
        res_str += "Invalid input: input for " + var + " was not a non-integer\nPlease enter positive integer"
        outFile.write(res_str)
        print(res_str)
        exit()
    return val
    
N = getInput("number of pens to be selected: N = ", "N", res_str) 
X = getInput("number of Blue pens : X = ", "N", res_str) 
Y = getInput("number of Red pens : Y = ", "Y", res_str)
Z = getInput("number of Green pens: Z = ", "Z", res_str)
if(N > (X + Y + Z )):
    res_str+="N has to be lesser than total pens\n"
    outFile.write(res_str)
    print(res_str)
    exit()

den = nCr(X+Y+Z, N)
col_sum = [int('0')]*(N+1)
row_sum = [int('0')]*(N+1)
res_str += "X/Y\t" 
for i in range(N+1):
    res_str += str(i) + "\t"
res_str += "h(y)\n"
for i in range(N+1):
    res_str += str(i) + "\t"
    for j in range(N+1):
        num = nCr(X,i) * nCr(Y, j) * nCr(Z, N - i - j)
        col_sum[j] += num
        row_sum[i] += num
        res_str+= str(num) + "/" + str(den) + "\t"
    res_str += str(row_sum[i]) + "/" + str(den) + "\n"
res_str += "g(x)\t"
for i in range(N+1):
    res_str+=str(col_sum[i]) + "/" + str(den) + "\t"
res_str += "\n"
print(res_str)
outFile.write(res_str)