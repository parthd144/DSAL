#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Graph {
private:
    Node** adjacencyList;
    int numNodes;

public:
    Graph(int n) {
        numNodes = n;
        adjacencyList = new Node*[numNodes];
        for (int i = 0; i < numNodes; i++) {
            adjacencyList[i] = NULL;
        }
    }

    void addEdge(int source, int destination) {
        Node* newNode = new Node(destination);
        newNode->next = adjacencyList[source];
        adjacencyList[source] = newNode;

        newNode = new Node(source);
        newNode->next = adjacencyList[destination];
        adjacencyList[destination] = newNode;
    }

    void DFS(int startNode) {
        bool* visited = new bool[numNodes];
        for (int i = 0; i < numNodes; i++) {
            visited[i] = false;
        }

        DFSUtil(startNode, visited);

        delete[] visited;
    }

    void BFS(int startNode) {
        bool* visited = new bool[numNodes];
        for (int i = 0; i < numNodes; i++) {
            visited[i] = false;
        }

        visited[startNode] = true;
        cout << startNode << " ";

        Node* queue = new Node(startNode);

        while (queue != NULL) {
            int current = queue->data;
            Node* temp = queue;
            queue = queue->next;
            delete temp;

            Node* neighbor = adjacencyList[current];
            while (neighbor != NULL) {
                if (!visited[neighbor->data]) {
                    visited[neighbor->data] = true;
                    cout << neighbor->data << " ";
                    Node* newNode = new Node(neighbor->data);
                    newNode->next = queue;
                    queue = newNode;
                }
                neighbor = neighbor->next;
            }
        }

        delete[] visited;
    }

private:
    void DFSUtil(int node, bool* visited) {
        visited[node] = true;
        cout << node << " ";

        Node* neighbor = adjacencyList[node];
        while (neighbor != NULL) {
            if (!visited[neighbor->data]) {
                DFSUtil(neighbor->data, visited);
            }
            neighbor = neighbor->next;
        }
    }
};

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    Graph graph(numNodes);

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;
    cout << "DFS traversal starting from node " << startNode << ": ";
    graph.DFS(startNode);
    cout << endl;

    cout << "Enter the starting node for BFS: ";
    cin >> startNode;
    cout << "BFS traversal starting from node " << startNode << ": ";
    graph.BFS(startNode);
    cout << endl;

    return 0;
}
