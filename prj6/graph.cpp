#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;
class Graph {
private:
    unordered_map<int, list<int>> adjacencyList;

public:
    
    void addVertex(int vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = list<int>();
        }
    }

    
    void addEdge(int vertex1, int vertex2) {
        addVertex(vertex1);
        addVertex(vertex2);

        adjacencyList[vertex1].push_back(vertex2);
        adjacencyList[vertex2].push_back(vertex1);
    }

    void removeEdge(int vertex1, int vertex2) {
        if (adjacencyList.find(vertex1) != adjacencyList.end() &&
            adjacencyList.find(vertex2) != adjacencyList.end()) {
            adjacencyList[vertex1].remove(vertex2);
            adjacencyList[vertex2].remove(vertex1);
        }
    }
    
    void removeVertex(int vertex) {
        if (adjacencyList.find(vertex) != adjacencyList.end()) {
            
            for (int neighbor : adjacencyList[vertex]) {
                adjacencyList[neighbor].remove(vertex);
            }
            adjacencyList.erase(vertex);
        }
    }

    void BFS(int startVertex) {
        unordered_set<int> visited;
        queue<int> q;

        visited.insert(startVertex);
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int neighbor : adjacencyList[currentVertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    void DFS(int startVertex) {
        unordered_set<int> visited;
        DFSUtil(startVertex, visited);
        cout << "\n";
    }

    void DFSUtil(int vertex, unordered_set<int>& visited) {
        visited.insert(vertex);
        cout << vertex << " ";

        for (int neighbor : adjacencyList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void printGraph() {
        for (const auto& pair : adjacencyList) {
            cout << "Vertex " << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
};