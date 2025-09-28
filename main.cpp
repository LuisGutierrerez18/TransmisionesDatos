#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "kmp.h"

using namespace std;

// Función para leer el contenido de un archivo
string leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    
    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return "";
    }

    // Leer todo el contenido del archivo
    string contenido;
    string linea;
    
    // Leer línea por línea
    while (getline(archivo, linea)) {
        contenido += linea;
        // Se agrega salto de linea pq el programa daba falsos negativos
        if (!archivo.eof()) { // Evitar agregar un salto de línea extra al final 
            contenido += "\n";  // Solo si no es la última línea
        }
    }

    archivo.close();
    return contenido;
}

int main() {
    // Leer archivos de transmisión y código malicioso
    /**/
    string transmission1 = leerArchivo("transmission01.txt");
    string transmission2 = leerArchivo("transmission02.txt");
    string mcode1 = leerArchivo("mcode01.txt");
    string mcode2 = leerArchivo("mcode11.txt");
    string mcode3 = leerArchivo("mcode12.txt");

    /* ---- Parte 1: Archivos de transmisión (6 busquedas) ---- */
    
    vector<string> transmisiones = {transmission1, transmission2};
    vector<string> mcodes = {mcode1, mcode2, mcode3};

    // Realizar las búsquedas y mostrar resultados
    for(int i = 0; i<2; i++){ // Dos archivos de transmisión
        for(int j = 0; j<3; j++){ // Tres archivos de código malicioso
            vector<int> resultados = busquedaSubsecuencia(transmisiones[i], mcodes[j]);
            if(!resultados.empty()){
                cout << "true " << resultados[0] << endl;
            }else{
                cout << "false" << endl;
            }
        }
    }

    /* ---- Acaba Parte 1 ----*/

    // Parte 2: Búsqueda de palíndromos (2 busquedas)


    // Parte 3: Busqueda de substrigs mas comun

    return 0;
}