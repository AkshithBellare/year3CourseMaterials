import math
import scipy.stats as st

X = int(input("Enter X:")) #% of people
if X < 0 or X > 100:
    print("X has to be a valid percentage")
    exit()

Y = int(input("Enter Y:")) #no of persons selected
if Y < 0:
    print("Y can't be negative")
    exit()

Z = int(input("Enter Z:")) #the number for which we have to find probability

if Z < 0 or Z > Y:
    print("Z has to be lesser than or equal to Y")
    exit()

n = Y
p = X/100
q = 1 - p
x = Z

print(f"\nn={n} p={p} q={q} x={x}\n")

print(f"np = {n} * {p} = {n * p}\n")
print(f"nq = {n} * {q} = {n * q}\n")

u = n * p

print(f"(u) = np = {n} * {p} = {u}\n")

std = math.sqrt(u * q)

print(f"standard deviation = {std}\n")

print("making correction for continuity\n")

pplus = (x + 0.5 - 15) / std
pminus = (x-0.5-15)/std

print(f"For x = {x+0.5}: z = ({x+0.5} - 15 )/{std} = ", (x + 0.5 - 15)/std)
print(f"For x = {x-0.5}: z = ({x-0.5} - 15 )/{std} = ", (x - 0.5 - 15)/std)

a = st.norm.cdf(pplus)
b = st.norm.cdf(pminus)

print(f"\nP({x-0.5} <= x <= {x+0.5}) = P({pminus} <= z <= {pplus})")
print(f"{a} - {b} = {a - b}")

