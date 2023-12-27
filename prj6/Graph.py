class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.previous = None


class Graph:

    def __init__(self):
        self.graph_dict = dict()

    def add_vertex(self, vertex):
        self.graph_dict[vertex] = []

    def add_edge(self, firstVertex, secondVertex):
        try:
            key = self.graph_dict[firstVertex]
            key.append(secondVertex)

            key = self.graph_dict[secondVertex]
            key.append(firstVertex)
        except:
            print("Key Not Found !!")

    def remove_edge(self, firstVertex, secondVertex):
        try:
            key = self.graph_dict[firstVertex]
            key.remove(secondVertex)

            key = self.graph_dict[secondVertex]
            key.remove(firstVertex)
        except:
            print("Key Not Found!")

    def remove_vertex(self, vertex):
        del self.graph_dict[vertex]

    def BFS(self):
        pass

    def DFS(self):
        pass

    def display_values(self):
        print(self.graph_dict)


sample = Graph()

sample.add_vertex("a")
sample.add_vertex("b")
sample.add_vertex("c")
sample.add_vertex("d")
sample.add_vertex("e")

sample.add_edge("a", "b")
sample.add_edge("b", "c")
sample.add_edge("c", "d")
sample.add_edge("a", "e")
sample.add_edge("e", "d")
sample.add_edge("a", "d")
sample.add_edge("b", "d")


sample.display_values()
