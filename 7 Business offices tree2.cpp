#include <iostream>

#define MAX_OFFICES 100

class Graph {
    int numOffices;
    int adjacencyMatrix[MAX_OFFICES][MAX_OFFICES];

public:
    Graph(int numOffices);

    void addConnection(int office1, int office2, int cost);
    void findMinimumCost();
};

Graph::Graph(int numOffices) {
    this->numOffices = numOffices;

    // Initialize the adjacency matrix with large values
    for (int i = 0; i < numOffices; i++) {
        for (int j = 0; j < numOffices; j++) {
            adjacencyMatrix[i][j] = INT_MAX;
        }
    }
}

void Graph::addConnection(int office1, int office2, int cost) {
    // Add connection between two offices with the given cost
    adjacencyMatrix[office1][office2] = cost;
    adjacencyMatrix[office2][office1] = cost;
}

void Graph::findMinimumCost() {
    int selected[MAX_OFFICES];
    int minCost, office1, office2;
    int totalCost = 0;

    // Initialize selected array and set the first office as selected
    for (int i = 0; i < numOffices; i++) {
        selected[i] = 0;
    }
    selected[0] = 1;

    // Repeat until all offices are selected
    for (int count = 0; count < numOffices - 1; count++) {
        minCost = INT_MAX;
        office1 = 0;
        office2 = 0;

        // Find the minimum cost edge that connects a selected office and an unselected office
        for (int i = 0; i < numOffices; i++) {
            if (selected[i]) {
                for (int j = 0; j < numOffices; j++) {
                    if (!selected[j] && adjacencyMatrix[i][j] && adjacencyMatrix[i][j] < minCost) {
                        minCost = adjacencyMatrix[i][j];
                        office1 = i;
                        office2 = j;
                    }
                }
            }
        }

        // Select the office with minimum cost
        selected[office2] = 1;

        // Print the selected edge and its cost
        std::cout << "Office " << office1 << " connected to Office " << office2 << " with cost " << minCost << std::endl;

        // Update the total cost
        totalCost += minCost;
    }

    std::cout << "Total cost for connecting all offices: " << totalCost << std::endl;
}

int main() {
    int numOffices;
    std::cout << "Enter the number of offices: ";
    std::cin >> numOffices;

    Graph graph(numOffices);

    int numConnections;
    std::cout << "Enter the number of connections: ";
    std::cin >> numConnections;

    int office1, office2, cost;
    for (int i = 0; i < numConnections; i++) {
        std::cout << "Enter the details of connection " << i + 1 << ":" << std::endl;
        std::cout << "Office 1: ";
        std::cin >> office1;
        std::cout << "Office 2: ";
        std::cin >> office2;
        std::cout << "Cost: ";
        std::cin >> cost;

        graph.addConnection(office1, office2, cost);
    }

    std::cout << "Finding minimum cost connections..." << std::endl;
    graph.findMinimumCost();

    return 0;
}
