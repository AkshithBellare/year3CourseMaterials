import sys
import tkinter
import math
from tkinter import *
from functools import partial


def calc(resultLabel,n1,n2,n3,p1,p2,p3):
    planes1 = n1.get()
    if not planes1.isdigit() or int(planes1)<1:
        resultLabel.config(text = "Invalid Input : Number of planes must be a positive integer")
        return
    planes2 = n2.get()
    if not planes2.isdigit() or int(planes2)<1:
        resultLabel.config(text = "Invalid Input : Number of planes must be a positive integer")
        return
    planes3 = n3.get()
    if not planes3.isdigit() or int(planes3)<1:
        resultLabel.config(text = "Invalid Input : Number of planes must be a positive integer")
        return
    planes1 = int(planes1)
    planes2 = int(planes2)
    planes3 = int(planes3)

    prob1 = float(p1.get())
    prob2 = float(p2.get())
    prob3 = float(p3.get())

    if prob1 + prob2 + prob3 > 1:
        resultLabel.config(text = "Invalid Input: SUM OF PROBABILITIES MUST BE ONE")
        return

    ans  = (math.factorial(planes1 + planes2 + planes3)/(math.factorial(planes1)*math.factorial(planes2)*math.factorial(planes3)))*((prob1**planes1)*(prob2**planes2)*(prob3**planes3))

    resultLabel.config(text = "Result - {}".format(ans))

    return


def main():
    mainWindow = tkinter.Tk()
    mainWindow.title("MULTINOMIAL CALCULATOR")
    mainWindow.geometry("1000x400")
    n1 = tkinter.StringVar()
    n2 = tkinter.StringVar()
    n3 = tkinter.StringVar()
    p1 = tkinter.StringVar()
    p2 = tkinter.StringVar()
    p3 = tkinter.StringVar()
    planes1Label = Label(mainWindow, text = "NUMBER OF PLANES RUNWAY 1").place(x = 30,y = 50)
    planes1Value = Entry(mainWindow, bd = 5, textvariable=n1).place(x = 350,y = 50)
    planes2Label = Label(mainWindow, text = "NUMBER OF PLANES RUNWAY 2").place(x = 30,y = 80)
    planes2Value = Entry(mainWindow, bd = 5, textvariable=n2).place(x = 350,y = 80)
    planes3Label = Label(mainWindow, text = "NUMBER OF PLANES RUNWAY 3").place(x = 30,y = 110)
    planes3Value = Entry(mainWindow, bd = 5, textvariable=n3).place(x = 350,y = 110)
    prob1Label = Label(mainWindow, text = "P(Runway 1 is accessed)").place(x = 30,y = 140)
    prob1Value = Entry(mainWindow, bd = 5, textvariable=p1).place(x = 350,y = 140)
    prob2Label = Label(mainWindow, text = "P(Runway 2 is accessed)").place(x = 30,y = 170)
    prob2Value = Entry(mainWindow, bd = 5, textvariable=p2).place(x = 350,y = 170)
    prob3Label = Label(mainWindow, text = "P(Runway 3 is accessed)").place(x = 30,y = 200)
    prob3Value = Entry(mainWindow, bd = 5, textvariable=p3).place(x = 350,y = 200)

    resultLabel = Label(mainWindow, text = "RESULT")
    resultLabel.pack(side = BOTTOM)
    calc_with_args = partial(calc,resultLabel,n1,n2,n3,p1,p2,p3)

    submitButton = Button(mainWindow,text = "CALCULATE",command = calc_with_args,activeforeground = "black",activebackground = "white",pady=10)
    submitButton.pack(side = BOTTOM)

    mainWindow.mainloop()


if __name__ == '__main__':
    main()