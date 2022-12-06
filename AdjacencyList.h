#pragma once
#include <map>
#include <stack>
#include <vector>
#include "Quote.h"

class AdjacencyList
{
private:
    std::map<int, Quote*> order;
    std::vector<std::map<int, float>> adjacency_list;
public:
    AdjacencyList();
    ~AdjacencyList();
    void insertData();
    void generateEdges();
    std::stack<Quote*> BFS(Quote* source, bool within_category); // Searches only within category if true
    std::stack<Quote*> DFS(Quote* source, bool within_category);
    Quote* generateQuote(float sentiment, std::string category);
};

