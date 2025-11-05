// Codigo adaptado de geeksfor geeks para el algoritmo de Prim
// Link: https://www.geeksforgeeks.org/dsa/prims-minimum-spanning-tree-mst-greedy-algo-5/
#include "prim.h"
#include <limits>
#include <iostream>
using namespace std;

// funcion auxiliar para encontrar el vértice con la clave mínima
int obtenerMinimo(vector<int>& costo, vector<bool>& visitado) {
    int minIndex = -1;
    int minima = numeric_limits<int>::max();

    // Recorre todos los vértices para encontrar el mínimo
    for(int v = 0; v < visitado.size(); v++) {
        if(!visitado[v] && costo[v] < minima) {
            minima = costo[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Imprimimos el MST
void printMST(vector<int>& parent, vector<vector<int>>& dist) {
    int total = 0;
    for(int i = 1; i < dist.size(); i++) {
        int peso = dist[i][parent[i]];
        total+= peso;
        cout << "(" 
             << char('A' + parent[i]) << "," 
             << char('A' + i)
             << ") peso = " << peso << "\n";
    }
    cout << "Peso total del MST: " << total << "\n";
}

//Construccion del arbol MST al utilizar matriz de adyacencia utilizando PRIM
void primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> parent(V); // Almacena el árbol MST
    const int inf = 1e9; // Valor infinito para inicializar las claves
    vector<int> costo(V, inf); // Valores clave para elegir el mínimo
    vector<bool> visitado(V, false); // Vertices incluidos en MST

    costo[0] = 0; // Empezamos desde el primer vértice
    parent[0] = -1; // El primer nodo es la raíz del MST

    //For para encontrar el MST
    for(int count = 0; count < V - 1; count++) {
        int u = -1;
        for(int i = 0; i < V; i++){
            if(!visitado[i] && (u == -1 || costo[i] < costo[u])){
                u = i;
            }
        }
        if(u == -1) break; 
        visitado[u] = true; // Añade el vértice al MST

        // Actualiza los valores clave y el padre de los vértices adyacentes
        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !visitado[v] && graph[u][v] < costo[v]) {
                parent[v] = u;
                costo[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}