import statistics
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

input_file = open("input.txt", "r")

test_cases = []

for line in input_file.readlines():
    line = line.strip()
    line = line.split()
    test_cases.append(line)

def check_valid(test_case):
    n = len(test_case)
    for i in range(n):
        try:
            test_case[i] = int(test_case[i])
            if(test_case[i] <= 0):
                print("INVALID TEST CASE")
                return -1
        except:
            print("INVALID TEST CASE")
            return -1
    my_data = pd.Series(test_case)
    bins = np.linspace(0,100,25, endpoint=True  )

    plt.hist(my_data, bins)
    plt.show()

for tc in test_cases:
    check_valid(tc)