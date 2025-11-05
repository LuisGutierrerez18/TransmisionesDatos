#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <string>
#include <tuple>

// Devuelve las aristras del árbol de expansión mínima usando el algoritmo de Prim como tuplas
std::vector<std::tuple<int, int, int>> prim(const std::vector<std::vector<int>>& graph);

//Devuelve el costo total del árbol de expansión mínima
int primCost(const std::vector<std::vector<int>>& graph);

#endif
