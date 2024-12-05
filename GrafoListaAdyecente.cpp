#include <iostream>
#include <windows.h>

using namespace std;

// Estructura del nodo por lista de adyacencia
template <typename T>
struct Node {
    T vertex;
    Node* next;
};

// Clase para representar un grafo
template <typename T>
class graph {
    T V; // Número de vértices
    Node<T>** adjList; // Arreglo de listas de adyacencia
public:
    graph(int V); // Constructor del grafo
    void addEdge(T v, T w); // Función para agregar una arista
    void printGraph(); // Función para imprimir el grafo
    ~graph(); // Destructor del grafo para ahorra memoria
};

// Constructor del grafo
template <typename T>
graph<T>::graph(int V) {
    this->V = V;
    // Se inicializa el array de listas de adyacencia
    adjList = new Node<T>*[V];
    for (int i = 0; i < V; i++) 
        adjList[i] = NULL; // Se inicializa vacia
    }

// Funcion para agregar una arista
template <typename T>
void graph<T>::addEdge(T v, T w) {
    Node<T>* newNode = new Node<T>{w, adjList[v]};
    adjList[v] = newNode;
}

// Funcion para imprimir el grafo
template <typename T>
void graph<T>::printGraph() {
    for (int v = 0; v < V; ++v) {
        Node<T>* temp = adjList[v];
        cout << "\n Lista de adyacencia del vértice " << v << "\n";
        while (temp) {
            cout << " -> " << temp->vertex; // Se imprime el vertice adyacente
            temp = temp->next;
        }
    }
}

// Destructor del grafo para ahorra memoria
template <typename T>
graph<T>::~graph() {
    for (int i = 0; i < V; i++) {
        Node<T>* temp = adjList[i];
        while (temp) {
            Node<T>* toDelete = temp;
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

    graph<int> g(5);
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