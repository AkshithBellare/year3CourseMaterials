class Man: 
    def __init__(self, name, prefList):
        self.gender = "male"
        self.name = name
        self.prefList = prefList
        self.isFree = True

class Woman:
    def __init__(self, name, prefList):
        self.gender = "female"
        self.name = name
        self.prefList = prefList
        self.isFree = True
        self.proposedList = []
        self.partner = ""

def galeShapley(Men, Women):
    freeMen = Men 
    while(freeMen):
        man = next(iter(Men.values()))
        print(man.name)
        woman = Women[man.prefList[0]];
        man.prefList.remove(woman.name);
        if woman.isFree:
            man.partner = woman.name
            man.isFree = False
            woman.isFree = False
            woman.partner = man.name
            del freeMen[man.name]
            print(woman.name, " engaged to ", man.name)
        elif (woman.prefList.index(man.name) < woman.prefList.index(woman.partner)):
            Men[woman.partner].partner = ""
            Men[woman.partner].isFree = False
            freeMen[woman.partner] = Men[woman.partner]
            man.isFree = False
            man.partner = woman
            del freeMen[man.name]



def main():
    R = Man("R", ["B", "A", "D", "E", "C"])
    S = Man("S", ["D", "B", "A", "C", "E"])
    T = Man("T", ["B", "E", "C", "D", "A"])
    U = Man("U", ["A", "D", "C", "B", "E"])
    V = Man("V", ["B", "D", "A", "E", "C"])
    Men = {"R":R, "S":S, "T":T, "U":U, "V":V}
    
    A = Man("A", ["V", "R", "S", "U", "T"])
    B = Man("B", ["T", "S", "U", "R", "V"])
    C = Man("C", ["S", "T", "U", "V", "R"])
    D = Man("D", ["R", "V", "U", "T", "S"])
    E = Man("E", ["U", "S", "V", "T", "R"])
    Women = {"A":A, "B":B, "C":C, "D":D, "E":E}
    galeShapley(Men, Women)

if __name__ == "__main__":
    main()