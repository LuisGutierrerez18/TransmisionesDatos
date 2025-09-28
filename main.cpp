#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
        contenido += linea + "\n";
    }

    archivo.close();
    return contenido;
}

int main() {
    // Leer archivos de transmisión y código malicioso
    string transmission1 = leerArchivo("transmission1.txt");
    string transmission2 = leerArchivo("transmission2.txt");
    string mcode1 = leerArchivo("mcode1.txt");
    string mcode2 = leerArchivo("mcode2.txt");
    string mcode3 = leerArchivo("mcode3.txt");

    // Parte 1: Archivos de transmisión (6 busquedas)

    // Parte 2: Búsqueda de palíndromos (2 busquedas)


    // Parte 3: Busqueda de substrigs mas comun

    return 0;
}