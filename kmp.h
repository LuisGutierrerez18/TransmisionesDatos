/* --- En este archivo se implementa todo lo respectivo a busqueda de subsecuencias */

// Se implementa el algoritmo KMP (Knuth-Morris-Pratt) para la búsqueda eficiente de patrones en un texto.
// Codigo adaptado de geeksforgeeks --> https://www.geeksforgeeks.org/cpp/knuth-morris-pratt-in-c/ 
#ifndef KMP_H
#define KMP_H
#include <vector>
#include <string>
using namespace std;

// Función para construir la matriz LPS
void matrizLPS(string patron, int m, vector<int>& lps){
    int longitud = 0;
    lps[0] = 0; // lps[0] siempre es 0
    int i = 1;

    while(i<m){
        if(patron[i]==patron[longitud]){
            longitud++;
            lps[i] = longitud;
            i++;
        }else{
            if(longitud!=0){
                longitud = lps[longitud - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> busquedaSubsecuencia(const string& texto, const string& patron) {
    int m = patron.size();
    int n = texto.size();

    vector<int> indices; // Para almacenar las posiciones de las ocurrencias
    vector<int> lps(m); // Matriz LPS

    matrizLPS(patron, m, lps);

    int i = 0; // índice para texto
    int j = 0; // indice para patron

    while(i<n){
        if(patron[j] == texto[i]){
            i++;
            j++;
        }

        // if realiza una busqueda de coincidencia y guarda la posicion en donde se encontro
        if(j==m){
            indices.push_back(i-j); // Se encontró una ocurrencia
            j = lps[j-1];
        }
        else if(i<n && patron[j] != texto[i]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return indices; 
}





#endif