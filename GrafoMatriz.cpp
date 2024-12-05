#include <iostream> 
using namespace std;

// Clase para representar un grafo
template <typename T>
class graph {
    int V; // Número de vértices
    T **adjMatrix; // Puntero a la matriz de adyacencia
public:
    graph(int V); // Constructor del grafo
    void addEdge(int i, int j); // Función para agregar una arista
    void printGraph(); // Función para imprimir el grafo
    ~graph(); // Destructor del grafo para ahorra memoria
};

// Constructor
template <typename T>
graph<T>::graph(int V) {
    this->V = V;
    // Se crea la matriz de adyacencia
    adjMatrix = new T*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new T[V];
        for (int j = 0; j < V; j++) 
            adjMatrix[i][j] = 0; // Se inicializa el array vacio
    }
}

// Funcion para agregar una arista al grafo
template <typename T>
void graph<T>::addEdge(int i, int j) {
    adjMatrix[i][j] = 1; // i a j
    adjMatrix[j][i] = 1; // j a i
}

// Funcion para imprimir el grafo
template <typename T>
void graph<T>::printGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << " : ";
        for (int j = 0; j < V; j++) 
            cout << adjMatrix[i][j] << " "; // Se imprime la matriz de adyacencia
        cout << "\n"; // Se imprime un salto de línea para separar los vértices
    }
}

// Destructor para el grafo
template <typename T>
graph<T>::~graph() {
    for (int i = 0; i < V; i++) 
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

// Función principal
int main() {
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