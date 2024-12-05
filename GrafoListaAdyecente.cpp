#include <iostream>
#include <windows.h>

using namespace std;

// Estructura del nodo por lista de adyacencia
template <typename T>
struct Node {
    T vertex;
    Node* next;
};

// Clase para representar un grafo dirigido
template <typename T>
class DirectedGraph {
    T V; // Número de vértices
    Node<T>** adjList; // Arreglo de listas de adyacencia
public:
    DirectedGraph(int V); // Constructor del grafo
    void addEdge(T v, T w); // Función para agregar una arista
    void PrintDirectedGraph(); // Función para imprimir el grafo
    ~DirectedGraph(); // Destructor del grafo para ahorra memoria
};

// Constructor del grafo
template <typename T>
DirectedGraph<T>::DirectedGraph(int V) {
    this->V = V;
    // Se inicializa el array de listas de adyacencia
    adjList = new Node<T>*[V];
    for (int i = 0; i < V; i++) 
        adjList[i] = NULL; // Se inicializa vacia
    }

// Funcion para agregar una arista al grafo dirigido
template <typename T>
void DirectedGraph<T>::addEdge(T v, T w) {
    Node<T>* newNode = new Node<T>{w, adjList[v]};
    adjList[v] = newNode;
}

// Funcion para imprimir el grafo dirigido
template <typename T>
void DirectedGraph<T>::printGraph() {
    for (int v = 0; v < V; ++v) {
        Node<T>* temp = adjList[v];
        cout << "\n Lista de adyacencia del vértice: " << v << "\n";
        while (temp) {
            cout << " -> " << temp->vertex; // Se imprime el vertice adyacente
            temp = temp->next;
        }
    }
}

// Destructor del grafo dirigido para ahorra memoria 
template <typename T>
DirectedGraph<T>::~DirectedGraph() {
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

// Clase para representar un grafo no dirigido
template <typename T>
class UndirectedGraph {
    T V; // Número de vértices
    Node<T>** adjList; // Arreglo de listas de adyacencia
public:
    UndirectedGraph(int V); // Constructor del grafo
    void AddUndirectedEdge(T v, T w); // Función para agregar una arista
    void PrintUndirectedGraph(); // Función para imprimir el grafo
    ~UndirectedGraph(); // Destructor del grafo para ahorra memoria
};

// Constructor del grafo no dirigido
template <typename T>
UndirectedGraph<T>::UndirectedGraph(int V) {
    this->V = V;
    // Se inicializa el array de listas de adyacencia
    adjList = new Node<T>*[V];
    for (int i = 0; i < V; i++) 
        adjList[i] = NULL; // Se inicializa vacia
    }

// Funcion para agregar una arista al grafo no dirigido
template <typename T>
void UndirectedGraph<T>::AddUndirectedEdge(T v, T w) {
    Node<T>* newNode = new Node<T>{w, adjList[v]};
    adjList[v] = newNode;
    // Añade v a la lista de w del grafo no dirigido
    newNode = new Node<T>{v, adjList[w]};
    adjList[w] = newNode;
}

// Funcion para imprimir el grafo no dirigido
template <typename T>
void UndirectedGraph<T>::PrintUndirectedGraph() {
    for (int v = 0; v < V; ++v) {
        Node<T>* temp = adjList[v];
        cout << "\n Lista de adyacencia del vértice: " << v << "\n";
        while (temp) {
            cout << " -> " << temp->vertex; // Se imprime el vertice adyacente
            temp = temp->next;
        }
    }
}

// Destructor del grafo dirigido para ahorra memoria 
template <typename T>
UndirectedGraph<T>::~UndirectedGraph() {
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
    
    cout<<"Grafo dirigido: \n";
    
    // Output para el grafo dirigido
    DirectedGraph<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // Imprimir el grafo
    g.PrintDirectedGraph();
    
    cout<<"\n";

    cout<<"Grafo no dirigido: \n";
    
    // Output para el grafo no dirigido
    UndirectedGraph<int> h(5);
    h.AddUndirectedEdge(0, 1);
    h.AddUndirectedEdge(0, 4);
    h.AddUndirectedEdge(1, 2);
    h.AddUndirectedEdge(1, 3);
    h.AddUndirectedEdge(1, 4);
    h.AddUndirectedEdge(2, 3);
    h.AddUndirectedEdge(3, 4);
    // Imprimir el grafo
    h.PrintUndirectedGraph();

    return 0;
}