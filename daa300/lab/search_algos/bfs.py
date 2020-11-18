class Vertex:
    def __init__(self, adj, name):
        self.name = name
        self.adj = adj
        self.color = "w"

class Graph:
    def __init__(self, graph):
        self.G = [Vertex(graph[i],i) for i in range(len(graph))]
        self.V = len(graph)
    
def main():
    f = open("input.txt", "r")
    graph = []
    while True:
        line = f.readline()
        if not line:
            break
        line = line.strip()
        line = line.split()
        adj_list = []
        first = True
        for x in line:
            if first == True:
                first = False
                continue
            x = int(x)
            adj_list.append(x)
        graph.append(adj_list)
    print(graph)

    G = Graph(graph)


main()