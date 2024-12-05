#include <iostream>
#include <windows.h>
using namespace std;

// Estructura de un nodo en la lista de adyacencia
template <typename T>
struct Node {
    T vertex;
    Node* next;
};

// Clase para representar un grafo dirigido
template <typename T>
class DirectedGraph {
    T V; // Número de vértices
    Node<T>** adjList; // Arreglo de listas de adyacencia
public:
    // Constructor del grafo
    DirectedGraph(int V) {
        this->V = V;
        // Se inicializa el array de listas de adyacencia
        adjList = new Node<T>*[V];
        for (int i = 0; i < V; ++i) 
            adjList[i] = nullptr; // Se inicializa vacía
    }

    // Función para agregar una arista al grafo dirigido
    void addDirectedEdge(T v, T w) {
        Node<T>* newNode = new Node<T>{w, NULL};
        if (adjList[v] == NULL)
            adjList[v] = newNode;
        else {
            Node<T>* temp = adjList[v];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        } 
    }

    // Función para imprimir el grafo dirigido
    void PrintDirectedGraph() {
        for (int v = 0; v < V; ++v) {
            Node<T>* temp = adjList[v];
            cout << "\n Lista de adyacencia del vértice: " << v << "\n";
            while (temp) {
                cout << " -> " << temp->vertex; // Se imprime el vértice adyacente
                temp = temp->next;
            }
        }
        cout << "\n"; // Salto de línea final para mayor claridad
    }

    // Destructor del grafo dirigido para ahorrar memoria
    ~DirectedGraph() {
        for (int i = 0; i < V; ++i) {
            Node<T>* temp = adjList[i];
            while (temp) {
                Node<T>* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adjList;
    }
};

// Clase para representar un grafo no dirigido
template <typename T>
class UndirectedGraph {
    T V; // Número de vértices
    Node<T>** adjList; // Arreglo de listas de adyacencia
public:
    // Constructor del grafo
    UndirectedGraph(int V) {
        this->V = V;
        // Se inicializa el array de listas de adyacencia
        adjList = new Node<T>*[V];
        for (int i = 0; i < V; i++) 
            adjList[i] = nullptr; // Se inicializa vacía
    }

    // Función para agregar una arista al grafo no dirigido
    void AddUndirectedEdge(T v, T w) {
        Node<T>* newNode = new Node<T>{w, adjList[v]};
        adjList[v] = newNode;
        // Añade v a la lista de w (grafo no dirigido)
        newNode = new Node<T>{v, adjList[w]};
        adjList[w] = newNode;
    }

    // Función para imprimir el grafo no dirigido
    void PrintUndirectedGraph() {
        for (int v = 0; v < V; ++v) {
            Node<T>* temp = adjList[v];
            cout << "\n Lista de adyacencia del vértice: " << v << "\n";
            while (temp) {
                cout << " -> " << temp->vertex; // Se imprime el vértice adyacente
                temp = temp->next;
            }
        }
        cout << "\n"; // Salto de línea final para mayor claridad
    }

    // Destructor del grafo no dirigido para ahorrar memoria
    ~UndirectedGraph() {
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
};

int main() {

    // Configurar la consola para usar UTF-8
    SetConsoleOutputCP(CP_UTF8); // Establece la salida en UTF-8, caracteres especiales en español
    SetConsoleCP(CP_UTF8);       // Establece la entrada en UTF-8, caracteres especiales en español
    
    cout<<"\n";

    cout<<"Grafo dirigido: \n";
    
    // Output para el grafo dirigido
    DirectedGraph<int> g(5);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 4);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(1, 3);
    g.addDirectedEdge(1, 4);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(3, 4);
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