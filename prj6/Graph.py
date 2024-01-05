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

    def BFS(self, startVertex):

        visited = [False] * (max(self.graph_dict) + 1)

        queue = []

        queue.append(startVertex)
        visited[startVertex] = True

        while queue:

            s = queue.pop(0)
            print(s, end=" ")

            for i in self.graph_dict[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True

    def DFS(self, startVertex, visited=None):
        if visited is None:
            visited = []
        visited.append(startVertex)
        vertices = self.graph_dict[startVertex]
        for vertex in vertices:
            if vertex not in visited:
                self.DFS(vertex, visited)
        return visited

    def display_graph(self):
        print(self.graph_dict)
