#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list for each vertex
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited; // To keep track of visited vertices
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = (struct Node**)malloc(n * sizeof(struct Node*));
    graph->visited = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Initialize visited array to 0 (not visited)
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it's an undirected graph, add edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search (DFS) traversal
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1; // Mark the current vertex as visited
    printf("Visited %d\n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) { // If the connected vertex is not visited
            DFS(graph, connectedVertex); // Recursive call for DFS
        }
        temp = temp->next;
    }
}

int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("Depth-First Search Traversal:\n");
    DFS(graph, 0); // Start DFS from vertex 0

    return 0;
}
