#include <iostream> 
using namespace std;

// Clase para representar un grafo dirigido
template <typename T>
class DirectedGraph {
    T V; // Número de vértices
    T **adjMatrix; // Puntero a la matriz de adyacencia
public:
    DirectedGraph(int V); // Constructor del grafo
    void addEdge(int i, int j); // Función para agregar una arista
    void PrintDirectedGraph(); // Función para imprimir el grafo
    ~DirectedGraph(); // Destructor del grafo para ahorra memoria
};

// Constructor del grafo dirigido
template <typename T>
DirectedGraph<T>::DirectedGraph(int V) {
    this->V = V;
    // Se crea la matriz de adyacencia
    adjMatrix = new T*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new T[V];
        for (int j = 0; j < V; j++) 
            adjMatrix[i][j] = 0; // Se inicializa el array vacio
    }
}

// Funcion para agregar una arista al grafo dirigido
template <typename T>
void DirectedGraph<T>::addEdge(int i, int j) {
    adjMatrix[i][j] = 1; // i a j
}

// Funcion para imprimir el grafo dirigido
template <typename T>
void DirectedGraph<T>::PrintDirectedGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << " : ";
        for (int j = 0; j < V; j++) 
            cout << adjMatrix[i][j] << " "; // Se imprime la matriz de adyacencia
        cout << "\n"; // Se imprime un salto de línea para separar los vértices
    }
}

// Destructor para el grafo dirigido
template <typename T>
DirectedGraph<T>::~DirectedGraph() {
    for (int i = 0; i < V; i++) 
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

// Clase para representar un grafo dirigido
template <typename T>
class UndirectedGraph {
    T V; // Número de vértices
    T **adjMatrix; // Puntero a la matriz de adyacencia
public:
    UndirectedGraph(int V); // Constructor del grafo
    void AddUndirectedEdge(int i, int j); // Función para agregar una arista
    void PrintUndirectedGraph(); // Función para imprimir el grafo
    ~UndirectedGraph(); // Destructor del grafo para ahorra memoria
};

// Constructor del grafo no dirigido
template <typename T>
UndirectedGraph<T>::UndirectedGraph(int V) {
    this->V = V;
    // Se crea la matriz de adyacencia
    adjMatrix = new T*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new T[V];
        for (int j = 0; j < V; j++) 
            adjMatrix[i][j] = 0; // Se inicializa el array vacio
    }
}

// Funcion para agregar una arista al grafo no dirigido
template <typename T>
void UndirectedGraph<T>::AddUndirectedEdge(int i, int j) {
    adjMatrix[i][j] = 1; // i a j
    adjMatrix[j][i] = 1; // j a i en grafo no dirigido
}

// Funcion para imprimir el grafo dirigido
template <typename T>
void UndirectedGraph<T>::PrintUndirectedGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << " : ";
        for (int j = 0; j < V; j++) 
            cout << adjMatrix[i][j] << " "; // Se imprime la matriz de adyacencia
        cout << "\n"; // Se imprime un salto de línea para separar los vértices
    }
}

// Destructor para el grafo no dirigido
template <typename T>
UndirectedGraph<T>::~UndirectedGraph() {
    for (int i = 0; i < V; i++) 
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

int main() {

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
    // Imprimir
    h.PrintUndirectedGraph();

    return 0;
}