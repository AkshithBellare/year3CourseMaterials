outFile = open("output.txt", "w")
res_str = ""

def nCr(n,r):
    r = min(n, n-r)
    res = 1
    for i in range(r):
        res *= n - i
        res/=(i+1)
    return int(res)

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
res_str += "f(x,y) = " + "(XCx * YCy * ZC(N - x - y)) / ((X + Y + Z)CN)\n"
res_str += "X/Y\t\t" 
for i in range(N+1):
    res_str += str(i) + "\t\t"
res_str += "g(x)\n"
for i in range(N+1):
    res_str += str(i) + "\t\t"
    for j in range(N+1):
        num = nCr(X,i) * nCr(Y, j) * nCr(Z, N - i - j)
        col_sum[j] += num
        row_sum[i] += num
        res_str+= str(num) + "/" + str(den) + "\t\t"
    res_str += str(row_sum[i]) + "/" + str(den) + "\n"
res_str += "h(y)\t\t"
for i in range(N+1):
    res_str+=str(col_sum[i]) + "/" + str(den) + "\t\t"
res_str += "\n"

x_str="sigma(g(x)) = "
y_str="sigma(h(y)) = "
for i in range(N+1):
    if i == N:
        x_str += str(row_sum[i]) + "/" + str(den)
        y_str += str(col_sum[i]) + "/" + str(den)
    else: 
        x_str += str(row_sum[i]) + "/" + str(den) + " + "
        y_str += str(col_sum[i]) + "/" + str(den) + " + "
y_str += " = {}/{} = 1\n".format(den,den)
x_str += " = {}/{} = 1\n".format(den,den)
res_str += x_str + y_str
print(res_str)
outFile.write(res_str)

