
f = open("input.txt", "r")

class Job:
    def __init__(self, weight, length):
        self.w = weight
        self.l = length
        self.score = weight / length

    def __str__(self):
        return "weight=" + str(self.w) + " length=" +str(self.l) + " score=" + str(self.score)

lines = f.readlines()

jobs = []

for line in lines:
    line = line.strip()
    line = line.split()
    jobs.append(Job(int(line[0]), int(line[1])))

def score(job):
    return job.score

jobs.sort(reverse=True, key=score)

for job in jobs:
    print(job)

def cost(jobs):
    c = 0
    prev = 0
    for job in jobs:
        t = job.l + prev
        c += job.w * t 
        prev = t
    return c

print(cost(jobs))

