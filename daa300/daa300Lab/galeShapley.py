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
        man = next(iter(freeMen.values()))
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
    Raj = Man("Raj", ["Aparna", "Bhavna", "Chithra"])
    Suraj = Man("Suraj", ["Aparna", "Chithra", "Bhavna"])
    Tejas = Man("Tejas", ["Bhavna", "Chithra", "Aparna"])
    Men = {"Raj":Raj, "Suraj":Suraj, "Tejas":Tejas}
    
    Aparna = Woman("Aparna", ["Raj", "Suraj", "Tejas"])
    Bhavna = Woman("Bhavna", ["Suraj", "Raj", "Tejas"])
    Chithra = Woman("Chithra", ["Tejas", "Raj", "Suraj"])
    Women = {"Aparna": Aparna, "Bhavna": Bhavna, "Chithra": Chithra}

    galeShapley(Men, Women)

if __name__ == "__main__":
    main()