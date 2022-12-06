#pragma once
#include <map>
#include <unordered_set>
#include <stack>
#include <vector>
#include "Quote.h"


class AdjacencyList
{
private:
    std::map<int, Quote*> quotes;
    std::vector<std::unordered_set<int>> adjacency_list; // Storing indices of values allows us to store graph externally
public:
    AdjacencyList();
    ~AdjacencyList();
    void insertData();
    void generateEdges();
    std::stack<Quote*> BFS(Quote* source, bool within_category); // Searches only within category if true
    std::stack<Quote*> DFS(Quote* source, bool within_category);
    Quote* generateQuote(float sentiment, std::string category);
};

