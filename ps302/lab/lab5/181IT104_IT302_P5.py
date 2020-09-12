import xlrd 

tc=1
file = open("OutputFiles/181IT147_IT302_P4_Output_TC"+str(tc)+".txt", "w")

def fun(x , y , f ):
   print(f'when x = {x} and y = {y}  , ({x}^2 + {y}^2) * {f[x][y]} = {(x*x + y*y)* f[x][y]}')
   file.write(f'when x = {x} and y = {y}  , ({x}^2 + {y}^2) * {f[x][y]} = {(x*x + y*y)* f[x][y]}\n')
   return (x*y)* f[x][y]

def mean(f):
   sm=0
   xsum=0
   print("Ux = sigma(x* g(x) where g(x) is the marginal distribution of x")
   file.write("Ux = sigma(x* g(x) where g(x) is the marginal distribution of x\n")
   for x in f.keys():
      # k = sum(f[x].)
      # print((f[x].items()))
      print(f'x={x} , g(x) = {sum(f[x].values())} , x*g(x) = {x * sum(f[x].values())}')
      file.write(f'x={x} , g(x) = {sum(f[x].values())} , x*g(x) = {x * sum(f[x].values())}\n')
      sm = sm + x * sum(f[x].values())
      # xsum += 
   print("summation of all the above terms and Ux =" , sm)
   file.write(f"summation of all the above terms and Ux = {sm} \n\n")
   print('\n')


   print("Uy = sigma(y* g(y) where g(y) is the marginal distribution of y")
   file.write("Uy = sigma(y* g(y) where g(y) is the marginal distribution of y\n")
   sm=0
   for y in f[x].keys():
      ism=0
      for x in f.keys():
         ism += f[x][y]
      print(f'y={y} , g(y) = {ism} , y*g(y) = {y * ism}')
      file.write(f'y={y} , g(y) = {ism} , y*g(y) = {y * ism}\n')
      sm = sm + ism * y 
   print("summation of all the above terms and Uy =" , sm)
   file.write(f"summation of all the above terms and Uy = {sm}\n\n")

   print('\n')

def summation(f):

   sm=0
   print("Excpected value of G(x,y) = summation for all x over summation of all y G(x,y)*f(x,y)")
   file.write("Excpected value of G(x,y) = summation for all x over summation of all y G(x,y)*f(x,y)\n")
   for x in f.keys():
      for y in f[x].keys():
         sm = sm + fun(x,y,f)
   
   print("summation of all the above terms and the expected value of G(x,y) = " , sm)
   file.write(f"summation of all the above terms and the expected value of G(x,y) = {sm} ")
  
loc = ("Test-Cases-IT302-Lab-Program-5.xlsx") 
  
wb = xlrd.open_workbook(loc) 
sheet = wb.sheet_by_index(0) 
  
rows = [0] * 100
cols = [0] * 100

#print(rows)
# print(sheet.nrows);
for i in range(sheet.nrows): 
   for j in range(sheet.ncols):
      if sheet.cell_value(i,j) == "f(x,y)" and sheet.cell_value(i+2,j) == "y" and sheet.cell_value(i,j+2) == "x":
         print(f'Test case {tc}')
         file = open("OutputFiles/181IT147_IT302_P4_Output_TC"+str(tc)+".txt", "w")
         # tc+=1
         n=i+2;
         m=j+2;
         f={}
         # print("X")
         x_vals=[]
         y_vals=[]
         for k in range (j+2,sheet.ncols):
            if(sheet.cell_value(i+1,k)==''):
               break;
            else:
               m=m+1;
               try:
                  val = int(sheet.cell_value(i+1,k));
                  
                  x_vals.append(val)
                  # print("Input is an integer number. Number = ", val)
               except ValueError:
                  print("X does not have integer values");
                  file.write("X does not have integer values")
                  # exit()

         #checking for all value of y
         # print("Y")
         for k in range (i+2,sheet.nrows):
            if(sheet.cell_value(k,j+1)==''):
               break;
            else:
               n=n+1;
               try:
                  val = int(sheet.cell_value(k,j+1));
                  y_vals.append(val)
                  f[val]={}
                  # print("Input is an integer number. Number = ", val)
               except ValueError:
                  print("Y does not have integer values");
                  file.write("Y does not have integer values")

         ii=0

         for k in range(i+2,n):
            iij=0
            for l in range(j+2,m):
               try:
                  val = float(sheet.cell_value(k,l));
                  f[y_vals[ii]][x_vals[iij]]=val  
                  # print("F(x,y) is a float number. Number = ", val)
               except ValueError:
                  print("f(x,y) does not have float values");
                  file.write("f(x,y) does not have float values")

               if(val<0 or val>1):
                  print("ERROR : Invalid Value of f(x,y) ");
                  file.write("f(x,y) does not have float values")

               
               iij+=1
            ii+=1

         # print(f)

         tf={}

         for y in f.keys():
            for x in f[y].keys():
               if(tf.get(x)==None):
                  tf[x]={}

               tf[x][y] = f[y][x]
         # print(tf)

         mean(tf)
         summation(tf)
         tc+=1
         # exit()