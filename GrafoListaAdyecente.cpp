#include <iostream>
#include <windows.h>

using namespace std;

// Estructura del nodo por lista de adyacencia
struct Node {
    int vertex;
    Node* next;
};

// Clase para representar un grafo
class graph {
    int V; // Número de vértices
    Node* *adjList; // Arreglo de listas de adyacencia
public:
    graph(int V); // Constructor del grafo
    void addEdge(int v, int w); // Función para agregar una arista
    void printGraph(); // Función para imprimir el grafo
    ~graph(); // Destructor del grafo para ahorra memoria
};

// Constructor del grafo
graph::graph(int V) {
    this->V = V;
    // Se inicializa el array de listas de adyacencia
    adjList = new Node*[V];
    for (int i = 0; i < V; i++) 
        adjList[i] = NULL; // Se inicializa vacia
    }

// Funcion para agregar una arista
void graph::addEdge(int v, int w) {
    Node* newNode = new Node{w, adjList[v]};
    adjList[v] = newNode;
}

// Funcion para imprimir el grafo
void graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        Node* temp = adjList[v];
        cout << "\n Lista de adyacencia del vértice " << v << "\n";
        while (temp) {
            cout << " -> " << temp->vertex; // Se imprime el vertice adyacente
            temp = temp->next;
        }
        cout << "\n";
    }
}

// Destructor del grafo para ahorra memoria
graph::~graph() {
    for (int i = 0; i < V; i++) {
        Node* temp = adjList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
    delete[] adjList;
}

int main() {

    // Configurar la consola para usar UTF-8
    SetConsoleOutputCP(CP_UTF8); // Establece la salida en UTF-8, caracteres especiales en español
    SetConsoleCP(CP_UTF8);       // Establece la entrada en UTF-8, caracteres especiales en español

    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // Imprimir el grafo
    g.printGraph();
    return 0;
}