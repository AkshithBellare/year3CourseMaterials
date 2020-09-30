def number_of_ways(volume):
    num_ways = 1
    if volume == 4:
        return 3
    else: 
        num_ways = num_ways * number_of_ways(volume/2) *  number_of_ways(volume/2)
    return num_ways

print(number_of_ways(64))