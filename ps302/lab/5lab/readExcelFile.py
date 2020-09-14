import xlrd

loc = "Test-Cases-IT302-Lab-Program-5.xlsx"

wb = xlrd.open_workbook(loc)
sheet = wb.sheet_by_index(0)

print(f"number of rows = {sheet.nrows} number of colums = {sheet.ncols}")


tc = 1

for i in range(sheet.nrows):
    for j in range(sheet.ncols):
        if(sheet.cell_value(i,j) == "f(x,y)"):
            if(sheet.cell_value(i+2,j) == "y"  and sheet.cell_value(i,j+2) == "x"):
                x_vals=[]
                y_vals=[]

                f = {}

                print(f"TC {tc}\n")
                m = i+2
                n = j+2
                for k in range(n, sheet.ncols):
                    if sheet.cell_value(m-1,k) == '':
                        break
                    else:
                        n+=1
                        val = int(sheet.cell_value(m-1,k))
                        x_vals.append(val)
                
                for k in range(m, sheet.nrows):
                    if sheet.cell_value(k,n-1) == '':
                        break
                    else:
                        m+=1
                        val = int(sheet.cell_value(k,n-1))
                        y_vals.append(val)
                ii = 0 
                for k in range(i+2,m):
                    for l in range(j+2,n):
                        print(sheet.cell_value(k,l), end = " ")
                    print("\n")

                tc += 1

#reading excel file successfully completed