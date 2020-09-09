import csv

def calcans(xval,yandval,newfile):
    if newfile == "":
        return 
    print(xval)
    print(yandval)   


def main():
    file = open("Test-Cases-IT302-Lab-Program-5.csv",'r')
    reader = csv.reader(file)
    currfile = ""
    xrow = False
    xval = []
    yandval = []
    newfile = ""
    for row in reader:
        if row[0] != '':
            calcans(xval,yandval,newfile)    
            currfilename = row[0] + ".txt"
            newfile = open(currfilename,'a')
            newfile.write(row[0])
            xrow = True
        elif xrow == True:
            for ele in row:
                if ele != "":
                    xval.append(int(ele))
            xrow = False
        elif row[3] != "":
            arr = []
            for ele in row:
                if ele != "" and ele != "y":
                    arr.append(float(ele))
            yandval.append(arr)





                    


if __name__ == '__main__':
    main()