/* --- En este archivo se implementa todo lo respectivo a busqueda de subsecuencias */

// Se implementa el algoritmo KMP (Knuth-Morris-Pratt) para la búsqueda eficiente de patrones en un texto.
#ifndef KMP_H
#define KMP_H
#include <vector>
#include <string>
using namespace std;

void matrizLPS(string patron, int m, vector<int>& lps){
    int longitud = 0;
    lps[0] = 0; // lps[0] siempre es 0
    int i = 1;

    while(i<m){
        if(patron[i]==patron[longitud]{
            longitud++;
            lps[i] = longitud;
            i++;
        }else{
            if(longitud!=0){
                longitud = lps
            }
        }
        })
    }
}
int busquedaSubsecuencia(const string& texto, const string& patron);


#endif