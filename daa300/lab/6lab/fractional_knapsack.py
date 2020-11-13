class Item:
    def __init__(self, value, weight):
        self.v = value
        self.w = weight
        self.x = 0
    
    def __str__(self):
        return f"weight={self.w} value={self.v}"

def greedy_fractional_knapsack(items, capacity):
    num_items = len(items)
    for i in range(num_items):
        items[i].x = 0
    weight = 0
    for i in range(num_items):
        if weight + items[i].w <= capacity:
            weight = weight + items[i].w
            items[i].x = 1
        else:
            items[i].x = (capacity - weight) / items[i].w
            weight = capacity
            break
    return [item.x for item in items]

def recursive_knapsack(items, index, num, capacity):
    if index >= num:
        return 0
    elif capacity < items[index].w:
        return recursive_knapsack(items, index+1, num, capacity)
    else:
        return max(recursive_knapsack(items, index+1, num, capacity), items[index].v + recursive_knapsack(items, index+1, num, capacity - items[index].w))

def main():
    values = [280, 100, 120, 120]
    weights = [40, 10, 20, 24]
    capacity = 60

    items = []

    for i in range(len(values)):
        item = Item(value = values[i], weight = weights[i])
        items.append(item)

    items.sort(reverse=True, key=lambda item: item.v/item.w)

    for item in items:
        print(item)

    x = greedy_fractional_knapsack(items=items, capacity=capacity)

    print(x)

    max_profit = 0
    for item in items:
        max_profit += item.v * item.x

    print(max_profit)

    print(recursive_knapsack(items=items, index=0, num=4, capacity=capacity))

if __name__ == "__main__":
    main()