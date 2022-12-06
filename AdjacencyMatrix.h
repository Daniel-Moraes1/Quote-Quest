#pragma once
#include <map>
#include <set>
#include <stack>
#include <vector>
#include "Quote.h"


class AdjacencyMatrix
{
private:
    std::map<int, Quote*> order;
    std::vector<std::set<int>> adjacency_list;
public:
    AdjacencyMatrix();
    ~AdjacencyMatrix();
    void insertData();
    void generateEdges();
    std::stack<Quote*> BFS(Quote* source, bool within_category); // Searches only within category if true
    std::stack<Quote*> DFS(Quote* source, bool within_category);
    Quote* generateQuote(float sentiment, std::string category);
};
