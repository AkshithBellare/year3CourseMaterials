import tkinter as tk
import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

def nCr(n, r): 
  
    return (fact(n) / (fact(r)  * fact(n - r))) 
  
# Returns factorial of n 
def fact(n): 
    res = 1
    for i in range(2, n+1): 
        res = res * i
    return res

class Application(tk.Frame):
    def _init_(self, master=None):
        super()._init_(master)
        self.master = master
        self.pack()
        self.createwidgets()

    def createwidgets(self):
        tk.Label(self, text="p value : ").grid(row=0)
        tk.Label(self, text="N value : ").grid(row=1)
        tk.Label(self, text="M value : ").grid(row=2)
        self.p = tk.Entry(self)
        self.p.grid(row=0, column=1)
        self.n = tk.Entry(self)
        self.n.grid(row=1, column=1)
        self.M = tk.Entry(self)
        self.M.grid(row=2, column=1)
        self.submit = tk.Button(self, text="Submit", command=self.calc)
        self.submit.grid(row=3, column=0)
        self.master.bind("<Return>", self.calc)
        self.quit = tk.Button(self, text="QUIT", fg="red",command=self.master.destroy)
        self.quit.grid(row=3, column=1)
        self.result = tk.Label(self)

    def calc(self, event=None):
        try:
            p = float(self.p.get())
            m = int(self.M.get())
            n = int(self.n.get())
        except:

            self.result.config(text="Invalid Input")
            self.result.grid(row=4, column=1)
            
        m = int(self.M.get())
        n = int(self.n.get())
        
        p_ = 1 - (p)
        
        binp = 0.0
        for i in range(m, n+1):
            ncm = ncr(int(n), int(i))
            print(i)
            binp+=ncm*(p*i)(p_**(n-i))
        print(f"p = {p}, N = {n}, M = {m}, prob = {binp}")
        self.master.geometry("600x200")

        self.result.config(text="Binomial combination\n P(at least M) " + str(binp))
        self.result.grid(row=4, column=1)
    

root = tk.Tk()
width = root.winfo_reqwidth()
height = root.winfo_reqheight()
positionRight = int(root.winfo_screenwidth()/2 - width/2)
positionDown = int(root.winfo_screenheight()/2 - height/2)
 
# Positions the window in the center of the page.
root.geometry("+{}+{}".format(positionRight, positionDown))
app = Application(master=root)

app.mainloop()