#pragma once
#include <vector>
#include <map>
#include "Quote.h"

class AdjacencyMatrix
{
private:
    std::map<int, Quote*> order;
    std::vector<std::vector<float>> adjacency_matrix;
public:
    AdjacencyMatrix();
    ~AdjacencyMatrix();
    void insertData();
    void generateEdges();
    void BFS(Quote* source, bool within_category); // Searches only within category if true
    void DFS(Quote* source, bool within_category);
    Quote* generateQuote(float sentiment, std::string category);
};
