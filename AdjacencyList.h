#pragma once
#include <map>
#include <unordered_set>
#include <stack>
#include <vector>
#include "Quote.h"


class AdjacencyList
{
private:
    float similarity_factor;
    std::map<int, Quote*> quotes;
    std::vector<std::unordered_set<int>> adjacency_list; // Storing indices of values allows us to store graph externally
public:
    AdjacencyList();
    ~AdjacencyList();
    void insertData();
    void generateEdges(); // Create graph manually (SLOW)
    void readEdges(std::string in); // Read graph from file
    std::stack<Quote*> BFS(Quote* source);
    std::stack<Quote*> DFS(Quote* source);

    //Search through quotes and find the one most similar to user-inputted data
    Quote* generateQuote(float sentiment, std::string category, int length = 100);
};

