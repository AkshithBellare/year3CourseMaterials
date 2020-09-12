import xlrd

loc = "Test-Cases-IT302-Lab-Program-5.xlsx"

wb = xlrd.open_workbook(loc)
sheet = wb.sheet_by_index(0)

print(f"number of rows = {sheet.nrows} number of colums = {sheet.ncols}")

print(sheet.cell_value(1,4))
print(sheet.cell_value(1,5))
print(sheet.cell_value(1,6))

tc = 1

for i in range(sheet.nrows-1):
    for j in range(sheet.ncols-1):
        if(sheet.cell_value(i,j) == "f(x,y)"):
            if(sheet.cell_value(i+2,j) == "y"  and sheet.cell_value(i,j+2) == "x"):
                print(f"TC {tc}")
                m = i+2
                n = j+2

                x_vals = []
                y_vals = []

                for k in range(j+2, sheet.ncols):
                    if(sheet.cell_value(i+1,k) == ''):
                        break
                    else:
                        x_vals.append(int(sheet.cell_value(i+1,k)))

                print(x_vals)
                print(y_vals)

                tc += 1
