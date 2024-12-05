#include <iostream> 
using namespace std;

// Clase para representar un grafo dirigido
template <typename T>
class DirectedGraph {
    T V; // Número de vértices
    T **adjMatrix; // Puntero a la matriz de adyacencia
public:
    // Constructor del grafo
    DirectedGraph(int V) {
        this->V = V;
        // Se crea la matriz de adyacencia
        adjMatrix = new T*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new T[V];
            for (int j = 0; j < V; j++) 
                adjMatrix[i][j] = 0; // Se inicializa el array vacio
        }
    }

    // Función para agregar una arista al grafo dirigido
    void addDirectedEdge(int i, int j) {
        adjMatrix[i][j] = 1; // i a j
    }

    // Función para imprimir el grafo dirigido
    void PrintDirectedGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int j = 0; j < V; j++) 
                cout << adjMatrix[i][j] << " "; // Se imprime la matriz de adyacencia
            cout << "\n"; // Se imprime un salto de línea para separar los vértices
        }
    }
    
    // Destructor para el grafo dirigido
    ~DirectedGraph() {
        for (int i = 0; i < V; i++) 
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

// Clase para representar un grafo no dirigido
template <typename T>
class UndirectedGraph {
    T V; // Número de vértices
    T **adjMatrix; // Puntero a la matriz de adyacencia
public:
    // Constructor del grafo
    UndirectedGraph(int V) {
        this->V = V;
        // Se crea la matriz de adyacencia
        adjMatrix = new T*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new T[V];
            for (int j = 0; j < V; j++) 
                adjMatrix[i][j] = 0; // Se inicializa el array vacio
        }
    }

    // Función para agregar una arista al grafo no dirigido
    void addUndirectedEdge(int i, int j) {
        adjMatrix[i][j] = 1; // i a j
        adjMatrix[j][i] = 1; // j a i en grafo no dirigido
    }

    // Función para imprimir el grafo no dirigido
    void PrintUndirectedGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int j = 0; j < V; j++) 
                cout << adjMatrix[i][j] << " "; // Se imprime la matriz de adyacencia
            cout << "\n"; // Se imprime un salto de línea para separar los vértices
        }
    }

    // Destructor para el grafo no dirigido
    ~UndirectedGraph() {
        for (int i = 0; i < V; i++) 
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {

    // Output para el grafo dirigido
    DirectedGraph<int> g(5);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 4);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(1, 3);
    g.addDirectedEdge(1, 4);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(3, 4);
    
    // Output para el grafo no dirigido
    UndirectedGraph<int> h(5);
    h.addUndirectedEdge(0, 1);
    h.addUndirectedEdge(0, 4);
    h.addUndirectedEdge(1, 2);
    h.addUndirectedEdge(1, 3);
    h.addUndirectedEdge(1, 4);
    h.addUndirectedEdge(2, 3);
    h.addUndirectedEdge(3, 4);
    
    int choice;
    
do {
    
    cout<<"\n";

    cout<<"Seleccione el tipo de grafo: \n";
    cout<<"1. Grafo dirigido \n";
    cout<<"2. Grafo no dirigido \n";
    cout<<"3. Ambos grafos \n";
    cout<<"4. Salir \n";
    cout<<"Opcion: ";
    cin>>choice;

    cout<<"\n";

    switch (choice) {
        case 1: {
            cout<<"Grafo dirigido: \n";
            g.PrintDirectedGraph(); // Imprimir el grafo dirigido
            break;
        }
        case 2: {
            cout<<"Grafo no dirigido: \n";
            h.PrintUndirectedGraph(); // Imprimir el grafo no dirigido
            break;
        }
        case 3: {
            cout<<"Grafo dirigido: \n";
            g.PrintDirectedGraph(); // Imprimir el grafo dirigido
            cout<<"\nGrafo no dirigido: \n";
            h.PrintUndirectedGraph(); // Imprimir el grafo no dirigido
            break;
        }
        case 4: {
            cout<<"Saliendo del programa...\n";
            break;
        }
        default: {
            cout<<"Opcion no valida, intente de nuevo \n";
            break;
        }
    }
} while (choice != 4); // Repetir el menu hasta que se seleccione la opcion 4 (salir)

return 0;
}