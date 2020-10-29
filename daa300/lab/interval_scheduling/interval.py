class Interval:
    def __init__(self, start, finish):
        self.start = start
        self.finish = finish

interval_list = [Interval(1,4), Interval(3,4), Interval(2,5), Interval(4,5), Interval(6,7), Interval(8,20)]

def takeFinishTime(elem):
    return elem.finish

def interval_scheduling():
    #sort interval_list based on finish time
    interval_list.sort(key=takeFinishTime)
    picked_list = []
    picked = interval_list[0]
    picked_list.append(picked)
    interval_list.pop(0) 
    for x in interval_list:
        if x.start < picked.finish:
            continue
        else: 
            picked_list.append(x)
    return picked_list
    
def main():
    result = interval_scheduling()
    for x in result:
        print(f"start = {x.start} finish = {x.finish}\n")

if __name__ == "__main__":
    main()