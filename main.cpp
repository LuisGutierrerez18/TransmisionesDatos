#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include "prim.h"
#include "prim.cpp"

int main(){
    vector<vector<int>> distancias = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    cout << "Probando MST para matriz del ejemplo:\n";
    primMST(distancias);

    return 0;
}


