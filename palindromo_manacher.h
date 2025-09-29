#include <iostream>
#include <string>
#include <vector>
using namespace std;

void buscarPalindromo(const string &cadena)
{
    if (cadena.empty())
    {
        cout << "-1 -1" << endl;
        return;
    }

    int tamOriginal = cadena.size();
    int tamProcesado = 2 * tamOriginal + 1;

    vector<char> texto(tamProcesado);
    for (int i = 0; i < tamOriginal; i++)
    {
        texto[2 * i] = '|';
        texto[2 * i + 1] = cadena[i];
    }
    texto[tamProcesado - 1] = '|';

    vector<int> longitudes(tamProcesado, 0);

    int centroActual = 0;
    int bordeActual = 0;

    for (int pos = 0; pos < tamProcesado; pos++)
    {
        int longitudInicial = 0;
        if (pos < bordeActual)
        {
            int posSimetrica = centroActual - (pos - centroActual);
            int distanciaBorde = bordeActual - pos;
            longitudInicial = min(longitudes[posSimetrica], distanciaBorde);
        }

        int izq = pos - longitudInicial - 1;
        int der = pos + longitudInicial + 1;

        while (izq >= 0 && der < tamProcesado && texto[izq] == texto[der])
        {
            longitudInicial++;
            izq--;
            der++;
        }

        longitudes[pos] = longitudInicial;

        int nuevoBorde = pos + longitudInicial;
        if (nuevoBorde > bordeActual)
        {
            centroActual = pos;
            bordeActual = nuevoBorde;
        }
    }

    int longitudMaxima = 0;
    int posicionMaxima = 0;

    for (int i = 0; i < tamProcesado; i++)
    {
        if (longitudes[i] > longitudMaxima)
        {
            longitudMaxima = longitudes[i];
            posicionMaxima = i;
        }
    }

    int inicioOriginal = (posicionMaxima - longitudMaxima) / 2;
    int finOriginal = inicioOriginal + longitudMaxima - 1;

    cout << inicioOriginal << " " << finOriginal << endl;
}
