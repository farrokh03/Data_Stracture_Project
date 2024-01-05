class Graph:
    def __init__(self):
        self.graph = {}

    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []

    def add_edge(self, first_vertex, second_vertex):
        self.add_vertex(first_vertex)
        self.add_vertex(second_vertex)
        self.graph[first_vertex].append(second_vertex)
        self.graph[second_vertex].append(first_vertex)

    def remove_edge(self, first_vertex, second_vertex):
        if second_vertex in self.graph[first_vertex]:
            self.graph[first_vertex].remove(second_vertex)
            self.graph[second_vertex].remove(first_vertex)

    def remove_vertex(self, vertex):
        if vertex in self.graph:
            neighbors = self.graph.pop(vertex)
            for neighbor in neighbors:
                self.graph[neighbor].remove(vertex)

    def bfs(self, start_vertex):
        visited = set()
        result = []

        queue = [start_vertex]
        visited.add(start_vertex)

        while queue:
            current_vertex = queue.pop(0)
            result.append(current_vertex)

            for neighbor in self.graph[current_vertex]:
                if neighbor not in visited:
                    queue.append(neighbor)
                    visited.add(neighbor)

        return " -> ".join(result)

    def dfs(self, start_vertex):
        visited = set()
        result = []

        def dfs_recursive(vertex):
            visited.add(vertex)
            result.append(vertex)

            for neighbor in self.graph[vertex]:
                if neighbor not in visited:
                    dfs_recursive(neighbor)

        dfs_recursive(start_vertex)
        return " -> ".join(result)
